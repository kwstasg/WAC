//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "AudioCaptureWorker.h"
#include "WindowsAudioCapture.h"
#include "HAL/PlatformProcess.h"
#include "Misc/OutputDeviceDebug.h"

FAudioCaptureWorker* FAudioCaptureWorker::Runnable = NULL;
int32 FAudioCaptureWorker::ThreadCounter = 0;

FAudioCaptureWorker::FAudioCaptureWorker() : m_sink(), m_listener(16, WAVE_FORMAT_PCM, 4, 0),Thread(NULL)
{
    // Higher overall ThreadCounter to avoid duplicated names
    FAudioCaptureWorker::ThreadCounter++;

    Thread = FRunnableThread::Create(this, *FString::Printf(TEXT("FAudioCaptureWorker%d"), FAudioCaptureWorker::ThreadCounter), 0, EThreadPriority::TPri_Normal);
}

FAudioCaptureWorker::~FAudioCaptureWorker()
{
    // Make sure to mark Thread as finished
    bIsFinished = true;

    delete Thread;
    Thread = NULL;
}

FAudioCaptureWorker* FAudioCaptureWorker::InitializeWorker()
{
    Runnable = new FAudioCaptureWorker();

    return Runnable;
}

bool FAudioCaptureWorker::Init()
{
    // Make sure the Worker is marked is not finished
    bIsFinished = false;

    return true;
}

uint32 FAudioCaptureWorker::Run()
{
    m_listener.RecordAudioStream(&m_sink, bIsFinished);

    return 0;
}

void FAudioCaptureWorker::Stop()
{
    StopTaskCounter.Increment();
}

void FAudioCaptureWorker::ShutdownWorker()
{
    if (Runnable)
    {
        Runnable->EnsureCompletion();
        delete Runnable;
        Runnable = NULL;
    }
}

void FAudioCaptureWorker::Exit()
{
    // Make sure to mark Thread as finished
    bIsFinished = true;
}

void FAudioCaptureWorker::EnsureCompletion()
{
    Stop();
    // Make sure to mark Thread as finished
    bIsFinished = true;

    if (Thread != NULL)
    {
        Thread->WaitForCompletion();
    }        
}

TArray<float> FAudioCaptureWorker::GetFrequencyArray(float FreqLogBase, float FreqMultiplier, float FreqPower, float FreqOffset)
{
    TArray<float> freqs;
    AudioChunk chunk;

    if (!m_sink.Dequeue(chunk))
    {
        // Log that no audio chunk is available
        // UE_LOG(LogTemp, Warning, TEXT("No audio chunk available."));
        return freqs;
    }

    if (chunk.size <= 0 || chunk.chunk == nullptr)
    {
        // Log invalid chunk size or data
        UE_LOG(LogTemp, Warning, TEXT("Invalid audio chunk: size=%d"), chunk.size);
        return freqs;
    }

    // Calculate Frequency Values
    CalculateFrequencySpectrum(chunk.chunk, 2, chunk.size, FreqLogBase, FreqMultiplier, FreqPower, FreqOffset, freqs);

    // Empty chunk's trash
    m_sink.EmptyQueue(chunk);

    TArray<float> resultFloats;
    float count = freqs.Num() / 2 - 1;

    resultFloats.Reserve(count);

    for (float i = 1; i < freqs.Num() / 2; i++)
    {
        if (freqs[i] < 0)
        {
            freqs[i] = 0;
        }

        resultFloats.Add(freqs[i]);
    }

    return resultFloats;
}

float GetTheFFTInValue(const int16 InSampleValue, const int16 InSampleIndex, const int16 InSampleCount)
{
    float FFTValue = InSampleValue;

    FFTValue *= 0.5f * (1 - FMath::Cos(2 * PI * InSampleIndex / (InSampleCount - 1)));

    return FFTValue;
}

void FAudioCaptureWorker::CalculateFrequencySpectrum
(
    int16* SamplePointer,
    const int32 NumChannels,
    const int32 NumAvailableSamples,
    float FreqLogBase,
    float FreqMultiplier,
    float FreqPower,
    float FreqOffset,
    TArray<float>& OutFrequencies
)
{
    // Clear the Array before continuing
    OutFrequencies.Empty();

    // Make sure the Number of Channels is correct
    if (NumChannels <= 0 || NumChannels > 2)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid number of channels: %d"), NumChannels);
        return;
    }

    // Check if we actually have a Buffer to work with
    if (SamplePointer == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("SamplePointer is null"));
        return;
    }

    // Get Maximum amount of samples in this Sound
    const int32 SampleCount = NumAvailableSamples;

    // An early check if we can create a Sample window
    int32 FirstSample = 0;
    int32 LastSample = SampleCount;

    // Actual amount of samples we gonna read
    int32 SamplesToRead = LastSample - FirstSample;

    if (SamplesToRead < 0)
    {
        UE_LOG(LogTemp, Error, TEXT("CalculateFrequencySpectrum: Number of SamplesToRead is < 0!"));
        return;
    }

    // Shift the window enough so that we get a PowerOfTwo. FFT works better with that
    int32 PoT = 2;

    while (SamplesToRead > PoT)
    {
        PoT *= 2;
    }

    // Now we have a good PowerOfTwo to work with
    SamplesToRead = PoT;

    // Create two 2-dim Arrays for complex numbers | Buffer and Output
    kiss_fft_cpx* Buffer[2] = { 0 };
    kiss_fft_cpx* Output[2] = { 0 };

    // Create 1-dim Array with one slot for SamplesToRead
    int32 Dims[1] = { SamplesToRead };

    kiss_fftnd_cfg STF = kiss_fftnd_alloc(Dims, 1, 0, nullptr, nullptr);

    int16* SamplePtr = SamplePointer;

    // Allocate space in the Buffer and Output Arrays for all the data that FFT returns
    for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ChannelIndex++)
    {
        Buffer[ChannelIndex] = (kiss_fft_cpx*)KISS_FFT_MALLOC(sizeof(kiss_fft_cpx) * SamplesToRead);
        Output[ChannelIndex] = (kiss_fft_cpx*)KISS_FFT_MALLOC(sizeof(kiss_fft_cpx) * SamplesToRead);
    }

    // Shift our SamplePointer to the Current "FirstSample"
    SamplePtr += FirstSample * NumChannels;

    for (int32 SampleIndex = 0; SampleIndex < SamplesToRead; SampleIndex++)
    {
        for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ChannelIndex++)
        {
            // Make sure the Point is Valid and we don't go out of bounds
            if (SamplePtr != NULL && (SampleIndex + FirstSample < SampleCount))
            {
                // Use Window function to get a better result for the Data (Hann Window)
                Buffer[ChannelIndex][SampleIndex].r = GetTheFFTInValue(*SamplePtr, SampleIndex, SamplesToRead);
                Buffer[ChannelIndex][SampleIndex].i = 0.f;
            }
            else
            {
                // Use Window function to get a better result for the Data (Hann Window)
                Buffer[ChannelIndex][SampleIndex].r = 0.f;
                Buffer[ChannelIndex][SampleIndex].i = 0.f;
            }

            // Take the next Sample - Halfed Causes SamplePtr Exception
            if (SamplePtr != NULL && (SampleIndex + FirstSample < SampleCount / 2))
            {
                SamplePtr++;
            }
        }
    }

    // Now that the Buffer is filled, use the FFT
    for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ChannelIndex++)
    {
        if (Buffer[ChannelIndex])
        {
            kiss_fftnd(STF, Buffer[ChannelIndex], Output[ChannelIndex]);
        }
    }

    OutFrequencies.AddZeroed(SamplesToRead);

    for (int32 SampleIndex = 0; SampleIndex < SamplesToRead; ++SampleIndex)
    {
        double ChannelSum = 0.0f;

        for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ++ChannelIndex)
        {
            if (Output[ChannelIndex])
            {
                // With this we get the actual Frequency value for the frequencies from 0hz to ~22000hz
                ChannelSum += FMath::Sqrt(FMath::Square(Output[ChannelIndex][SampleIndex].r) + FMath::Square(Output[ChannelIndex][SampleIndex].i));
            }
        }

        OutFrequencies[SampleIndex] = FMath::Pow((FMath::LogX(FreqLogBase, ChannelSum / NumChannels) * FreqMultiplier), FreqPower) + FreqOffset;
    }

    // Make sure to free up the FFT stuff
    KISS_FFT_FREE(STF);

    for (int32 ChannelIndex = 0; ChannelIndex < NumChannels; ++ChannelIndex)
    {
        KISS_FFT_FREE(Buffer[ChannelIndex]);
        KISS_FFT_FREE(Output[ChannelIndex]);
    }
}
