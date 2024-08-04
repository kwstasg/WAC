// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "WindowsAudioCaptureComponent.h"
#include "WindowsAudioCapture.h"
#include <cmath>

// Sets default values for this component's properties
UWindowsAudioCaptureComponent::UWindowsAudioCaptureComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

UWindowsAudioCaptureComponent::~UWindowsAudioCaptureComponent()
{
    if (FAudioCaptureWorker::Runnable != NULL)
    {
        FAudioCaptureWorker::Runnable->ShutdownWorker();
    }
}

// Called when the game starts
void UWindowsAudioCaptureComponent::BeginPlay()
{
    Super::BeginPlay();

    if (FAudioCaptureWorker::Runnable == NULL)
    {
        // Init new Worker 
        FAudioCaptureWorker::Runnable->InitializeWorker();
    }
}

// Called every frame
void UWindowsAudioCaptureComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

// Validates frequency calculation parameters
bool UWindowsAudioCaptureComponent::ValidateFrequencyParameters(float& inFreqLogBase, float& inFreqMultiplier, float& inFreqPower, float& inFreqOffset)
{
    bool isValid = true;

    if (inFreqLogBase <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid inFreqLogBase: %f. It must be greater than 0. Using default value 10."), inFreqLogBase);
        inFreqLogBase = 10.0f;
        isValid = false;
    }

    if (inFreqMultiplier <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid inFreqMultiplier: %f. It must be greater than 0. Using default value 0.25."), inFreqMultiplier);
        inFreqMultiplier = 0.25f;
        isValid = false;
    }

    if (inFreqPower <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid inFreqPower: %f. It must be greater than 0. Using default value 6."), inFreqPower);
        inFreqPower = 6.0f;
        isValid = false;
    }

    if (inFreqOffset < 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("Invalid inFreqOffset: %f. It must be 0 or greater. Using default value 0."), inFreqOffset);
        inFreqOffset = 0.0f;
        isValid = false;
    }

    return isValid;
}

// This function will return Arrays of Frequencies for all channels, left channel, and right channel.
void UWindowsAudioCaptureComponent::BP_GetFrequencyArray(TArray<float>& OutFrequencies, TArray<float>& OutLeftChannelFrequencies, TArray<float>& OutRightChannelFrequencies, float inFreqLogBase, float inFreqMultiplier, float inFreqPower, float inFreqOffset)
{
    if (ValidateFrequencyParameters(inFreqLogBase, inFreqMultiplier, inFreqPower, inFreqOffset))
    {
        if (FAudioCaptureWorker::Runnable)
        {
            FAudioCaptureWorker::Runnable->GetFrequencyArray(inFreqLogBase, inFreqMultiplier, inFreqPower, inFreqOffset, OutFrequencies, OutLeftChannelFrequencies, OutRightChannelFrequencies);
        }
    }
}

// This function will return the value of a specific frequency and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetSpecificFrequencyValue(TArray<float> InFrequencies, int32 InWantedFrequency, float& OutFrequencyValue, float& OutFrequencyValueDB)
{
    // Initialize the return values
    OutFrequencyValue = 0.0f;
    OutFrequencyValueDB = 0.0f;

    // Check if the input frequency array is empty
    if (InFrequencies.Num() == 0)
    {
        return;
    }

    // Total number of samples corresponds to the size of InFrequencies array times 2
    int32 TotalSamples = InFrequencies.Num() * 2;

    // Nyquist frequency (half of the total samples, assuming the sample rate is twice the highest frequency in the array)
    float NyquistFrequency = TotalSamples / 2.0f;

    // Calculate the index in the frequency array
    int32 FrequencyIndex = static_cast<int32>(InWantedFrequency / NyquistFrequency * InFrequencies.Num());

    // Handle out-of-range indices by clamping
    FrequencyIndex = FMath::Clamp(FrequencyIndex, 0, InFrequencies.Num() - 1);

    // Retrieve the specific frequency value
    if (InFrequencies.Num() > 0)
    {
        OutFrequencyValue = InFrequencies[FrequencyIndex];

        // Calculate the frequency value in DB
        if (OutFrequencyValue > 0)
        {
            OutFrequencyValueDB = 20.0f * FMath::LogX(10.0f, OutFrequencyValue);
        }
    }
}

// This function will return the average value for SubBass (20 to 60 Hz) and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetAverageSubBassValue(TArray<float> InFrequencies, float& OutAverageSubBass, float& OutAverageSubBassDB)
{
    BP_GetAverageFrequencyValueInRange(InFrequencies, 20, 60, OutAverageSubBass, OutAverageSubBassDB);
}

// This function will return the average value for Bass (60 to 250 Hz) and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetAverageBassValue(TArray<float> InFrequencies, float& OutAverageBass, float& OutAverageBassDB)
{
    BP_GetAverageFrequencyValueInRange(InFrequencies, 60, 250, OutAverageBass, OutAverageBassDB);
}

// This function will return the average value for Mid frequencies (250 to 2000 Hz) and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetAverageMidValue(TArray<float> InFrequencies, float& OutAverageMid, float& OutAverageMidDB)
{
    BP_GetAverageFrequencyValueInRange(InFrequencies, 250, 2000, OutAverageMid, OutAverageMidDB);
}

// This function will return the average value for High frequencies (2000 to 22000 Hz) and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetAverageHighValue(TArray<float> InFrequencies, float& OutAverageHigh, float& OutAverageHighDB)
{
    BP_GetAverageFrequencyValueInRange(InFrequencies, 2000, 22000, OutAverageHigh, OutAverageHighDB);
}

// This function will return the average value for a given frequency input range e.g., 20 to 60 (SubBass), and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetAverageFrequencyValueInRange
(
    TArray<float> InFrequencies,
    int32 InStartFrequency,
    int32 InEndFrequency,
    float& OutAverageFrequency,
    float& OutAverageFrequencyDB
)
{
    // Initialize the return values
    OutAverageFrequency = 0.0f;
    OutAverageFrequencyDB = 0.0f;

    // Check if the input frequency array is empty
    if (InFrequencies.Num() == 0)
    {
        return;
    }

    // Total number of samples corresponds to the size of InFrequencies array times 2
    int32 TotalSamples = InFrequencies.Num() * 2;

    // Nyquist frequency (half of the total samples, assuming the sample rate is twice the highest frequency in the array)
    float NyquistFrequency = TotalSamples / 2.0f;

    // Calculate start and end indices in the frequency array
    int32 FStart = static_cast<int32>(InStartFrequency / NyquistFrequency * InFrequencies.Num());
    int32 FEnd = static_cast<int32>(InEndFrequency / NyquistFrequency * InFrequencies.Num());

    // Handle out-of-range indices by clamping
    FStart = FMath::Clamp(FStart, 0, InFrequencies.Num() - 1);
    FEnd = FMath::Clamp(FEnd, 0, InFrequencies.Num() - 1);

    if (FStart > FEnd)
    {
        Swap(FStart, FEnd);
    }

    int32 NumberOfFrequencies = FEnd - FStart + 1;

    // Sum the values within the specified frequency range
    float ValueSum = 0.0f;
    for (int32 i = FStart; i <= FEnd; ++i)
    {
        ValueSum += InFrequencies[i];
    }

    // Calculate the average frequency value
    OutAverageFrequency = (NumberOfFrequencies > 0) ? ValueSum / NumberOfFrequencies : 0.0f;

    // Calculate the average frequency value in DB
    if (OutAverageFrequency > 0)
    {
        OutAverageFrequencyDB = 20.0f * FMath::LogX(10.0f, OutAverageFrequency);
    }
}

// This function will return the total energy of the audio signal across all frequencies and its corresponding value in decibels.
void UWindowsAudioCaptureComponent::BP_GetTotalEnergy(TArray<float> InFrequencies, float& OutTotalEnergy, float& OutTotalEnergyDB)
{
    // Initialize the return values
    OutTotalEnergy = 0.0f;
    OutTotalEnergyDB = 0.0f;

    // Check if the input frequency array is empty
    if (InFrequencies.Num() == 0)
    {
        return;
    }

    // Sum the values of all frequencies
    for (float FrequencyValue : InFrequencies)
    {
        OutTotalEnergy += FrequencyValue;
    }

    // Calculate the total energy in DB
    if (OutTotalEnergy > 0)
    {
        OutTotalEnergyDB = 20.0f * FMath::LogX(10.0f, OutTotalEnergy);
    }
}

// This function will return the peak frequency and its value in decibels.
void UWindowsAudioCaptureComponent::BP_GetPeakFrequency(TArray<float> InFrequencies, float& OutPeakFrequency, float& OutPeakFrequencyDB)
{
    // Initialize the return values
    OutPeakFrequency = 0.0f;
    OutPeakFrequencyDB = 0.0f;

    // Check if the input frequency array is empty
    if (InFrequencies.Num() == 0)
    {
        return;
    }

    float PeakValue = 0.0f;

    // Find the peak frequency value
    for (int32 i = 0; i < InFrequencies.Num(); ++i)
    {
        if (InFrequencies[i] > PeakValue)
        {
            PeakValue = InFrequencies[i];
            OutPeakFrequency = static_cast<float>(i);
        }
    }

    // Calculate the peak frequency value in DB
    if (PeakValue > 0)
    {
        OutPeakFrequencyDB = 20.0f * FMath::LogX(10.0f, PeakValue);
    }
}

// This function normalizes the frequency array to a specified range.
void UWindowsAudioCaptureComponent::BP_NormalizeFrequencyArray(TArray<float> InFrequencies, TArray<float>& OutNormalizedFrequencies, float RangeMin, float RangeMax)
{
    OutNormalizedFrequencies.Empty(InFrequencies.Num());

    float MinValue = TNumericLimits<float>::Max();
    float MaxValue = TNumericLimits<float>::Lowest();

    // Find the min and max values in the array
    for (float FrequencyValue : InFrequencies)
    {
        if (FrequencyValue < MinValue) MinValue = FrequencyValue;
        if (FrequencyValue > MaxValue) MaxValue = FrequencyValue;
    }

    // Normalize the values to the specified range
    for (float FrequencyValue : InFrequencies)
    {
        float NormalizedValue = (FrequencyValue - MinValue) / (MaxValue - MinValue) * (RangeMax - RangeMin) + RangeMin;
        OutNormalizedFrequencies.Add(NormalizedValue);
    }
}

// This function applies dynamic range compression to the frequency array.
void UWindowsAudioCaptureComponent::BP_ApplyDynamicRangeCompression(TArray<float> InFrequencies, TArray<float>& OutCompressedFrequencies, float Threshold, float Ratio)
{
    OutCompressedFrequencies.Empty(InFrequencies.Num());

    float LinearThreshold = FMath::Pow(10.0f, Threshold / 20.0f);

    // Apply compression
    for (float FrequencyValue : InFrequencies)
    {
        float CompressedValue = FrequencyValue;
        if (FrequencyValue > LinearThreshold)
        {
            CompressedValue = LinearThreshold + (FrequencyValue - LinearThreshold) / Ratio;
        }
        OutCompressedFrequencies.Add(CompressedValue);
    }
}

// This function performs interpolation of a value over time.
void UWindowsAudioCaptureComponent::BP_InterpolateValue(float InputValue, float InterpSpeed, float DeltaTime, float& OutInterpolatedValue)
{
    static float CurrentInterpolatedValue = 0.0f;
    CurrentInterpolatedValue = FMath::FInterpTo(CurrentInterpolatedValue, InputValue, DeltaTime, InterpSpeed);
    OutInterpolatedValue = CurrentInterpolatedValue;
}
