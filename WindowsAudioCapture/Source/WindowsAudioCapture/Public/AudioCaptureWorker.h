// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#pragma once

#include "Engine.h"
#include "AudioSink.h"
#include "AudioListener.h"
#include <atomic>
#include <memory>
#include <mutex>

// KISS Headers
#include "ThirdParty/Kiss_FFT/kiss_fft129/kiss_fft.h"
#include "ThirdParty/Kiss_FFT/kiss_fft129/tools/kiss_fftnd.h"

class FAudioCaptureWorker : public FRunnable
{
public:
    // Singleton instance, can access the thread any time via static accessor, if it is active! 
    static std::unique_ptr<FAudioCaptureWorker> Runnable;

    // Thread to run the worker FRunnable on 
    FRunnableThread* Thread;

    //TArray<float> GetFrequencies();
    void GetFrequencyArray(float FreqLogBase, float FreqMultiplier, float FreqPower, float FreqOffset, TArray<float>& OutFrequencies, TArray<float>& OutLeftChannelFrequencies, TArray<float>& OutRightChannelFrequencies);

private:
    // Stop this thread? Uses Thread Safe Counter 
    FThreadSafeCounter StopTaskCounter;

    // Bool to check if the thread is running
    std::atomic<bool> bIsFinished;

    // Counter for the ThreadNames
    static std::atomic<int32> ThreadCounter;

    // Function to calculate the frequency spectrum
    void CalculateFrequencySpectrum
    (
        int16* SamplePointer,
        const int32 NumChannels,
        const int32 NumAvailableSamples,
        float FreqLogBase,
        float FreqMultiplier,
        float FreqPower,
        float FreqOffset,
        TArray<float>& OutFrequencies,
        TArray<float>& OutLeftChannelFrequencies,
        TArray<float>& OutRightChannelFrequencies
    );

    AudioListener m_listener;
    AudioSink m_sink;

    // Mutex for thread safety
    static std::mutex workerMutex;

protected:
public:
    // Constructor / Destructor
    FAudioCaptureWorker();
    ~FAudioCaptureWorker();

    // Custom Init function
    static FAudioCaptureWorker* InitializeWorker();

    // Custom Shutdown function
    static void ShutdownWorker();

    // Start FRunnable Interface
    virtual bool Init() override;
    virtual uint32 Run() override;
    virtual void Stop() override;
    virtual void Exit() override;
    // End FRunnable Interface

    // Make sure Thread completed
    void EnsureCompletion();

    bool IsFinished() const {
        return bIsFinished.load();
    }
};
