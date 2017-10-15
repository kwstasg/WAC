//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#include "WindowsAudioCapture.h"
#include "WindowsAudioCaptureComponent.h"

// Sets default values for this component's properties
UWindowsAudioCaptureComponent::UWindowsAudioCaptureComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

UWindowsAudioCaptureComponent::~UWindowsAudioCaptureComponent()
{
	if (!FAudioCaptureWorker::Runnable == NULL)
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

// This function will return an Array of Frequencies.
TArray<float> UWindowsAudioCaptureComponent::BP_GetFrequencyArray(float inFreqLogBase, float inFreqMultiplier, float inFreqPower, float inFreqOffset)
{
	TArray<float> FrequencyArray;

	if (FAudioCaptureWorker::Runnable)
	{
		FrequencyArray = FAudioCaptureWorker::Runnable->GetFrequencyArray(inFreqLogBase, inFreqMultiplier, inFreqPower, inFreqOffset);
	}

	return FrequencyArray;
}

// This function will return the value of a specific frequency.
void UWindowsAudioCaptureComponent::BP_GetSpecificFrequencyValue(TArray<float> InFrequencies, int32 InWantedFrequency, float& OutFrequencyValue)
{
	// Init the Return Value
	OutFrequencyValue = 0.0f;

	if (InWantedFrequency < 0 || InWantedFrequency > 22000)
		return;

	if (InFrequencies.Num() > 0 && (int32)(InWantedFrequency * InFrequencies.Num() * 2 / 48000) < InFrequencies.Num())
	{
		OutFrequencyValue = InFrequencies[(int32)(InWantedFrequency * InFrequencies.Num() * 2 / 48000)];
	}
}

// This function will return the average value for SubBass
void UWindowsAudioCaptureComponent::BP_GetAverageSubBassValue(TArray<float> InFrequencies, float& OutAverageSubBass)
{
	BP_GetAverageFrequencyValueInRange(InFrequencies, 20, 60, OutAverageSubBass);
}


// This function will return the average value for Bass (60 to 250hz)
void UWindowsAudioCaptureComponent::BP_GetAverageBassValue(TArray<float> InFrequencies,float& OutAverageBass)
{
	BP_GetAverageFrequencyValueInRange(InFrequencies, 60, 250, OutAverageBass);
}



void UWindowsAudioCaptureComponent::BP_GetAverageFrequencyValueInRange
(
	TArray<float> InFrequencies,
	int32 InStartFrequency,
	int32 InEndFrequency,
	float& OutAverageFrequency
)
{
	// Init the Return Value
	OutAverageFrequency = 0.0f;

	if (InStartFrequency >= InEndFrequency || InStartFrequency < 0 || InEndFrequency > 22000)
	return;

	int32 FStart	= (int32)(InStartFrequency  * InFrequencies.Num() * 2 / 48000);
	int32 FEnd		= (int32)(InEndFrequency * InFrequencies.Num() * 2 / 48000);

	if (FStart < 0 || FEnd >= InFrequencies.Num())
	return;

	int32 NumberOfFrequencies = 0;

	float ValueSum = 0.0f;

	for (int i = FStart; i <= FEnd; i++)
	{
		NumberOfFrequencies++;

		ValueSum += InFrequencies[i];
	}

	OutAverageFrequency = ValueSum / NumberOfFrequencies;
}
