//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#pragma once

#include "Engine.h"
#include "AudioSink.h"
#include "AudioListener.h"

// KISS Headers
#include "ThirdParty/Kiss_FFT/kiss_fft129/kiss_fft.h"
#include "ThirdParty/Kiss_FFT/kiss_fft129/tools/kiss_fftnd.h"

class FAudioCaptureWorker : public FRunnable
{

public:

	//Singleton instance, can access the thread any time via static accessor, if it is active! 
	static FAudioCaptureWorker* Runnable;

	//Thread to run the worker FRunnable on 
	FRunnableThread* Thread;

	//TArray<float> GetFrequencies();
	TArray<float> GetFrequencyArray(float FreqLogBase, float FreqMultiplier, float FreqPower, float FreqOffset);

private:

	//Stop this thread? Uses Thread Safe Counter 
	FThreadSafeCounter StopTaskCounter;

	// Bool to check if the thread is running
	bool bIsFinished;

	// Counter for the ThreadNames
	static int32 ThreadCounter;

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
	);

	AudioListener	m_listener;
	AudioSink		m_sink;

protected:


public:

	//Constructor / Destructor
	FAudioCaptureWorker();
	~FAudioCaptureWorker();

	// Custom Init function
	static FAudioCaptureWorker* InitializeWorker();

	// Custom Shutdown function
	static void ShutdownWorker();

	// Start FRunnable Interface
	virtual bool Init();
	virtual uint32 Run();
	virtual void Stop();
	virtual void Exit();
	// End FRunnable Interface

	// Make sure Thread completed
	void EnsureCompletion();

	bool IsFinished() const {
		return bIsFinished;
	}
};