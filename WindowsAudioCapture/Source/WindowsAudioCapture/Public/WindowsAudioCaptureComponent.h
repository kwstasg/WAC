//Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
#pragma once

#include "Components/ActorComponent.h"
#include "AudioCaptureWorker.h"
#include "WindowsAudioCaptureComponent.generated.h"

/**
* This Component starts a Listener that captures frequency information from the Windows Default Audio Device.
* You need to have it inside your Blueprint in order to call "Get Frequency Array" function.
*/
UCLASS(ClassGroup = (Audio), meta = (BlueprintSpawnableComponent), meta = (DisplayName = "Windows Audio Capture"))
class WINDOWSAUDIOCAPTURE_API UWindowsAudioCaptureComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWindowsAudioCaptureComponent();

	// Cleans up stuff
	~UWindowsAudioCaptureComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	/**
	* This function will return an Array of Frequencies. Frequency = (LogX(FreqLogBase, Frequency) * FreqMultiplier)^FreqPower + FreqOffset.  e.g.: Frequency = (LogX(10, Frequency) * 0.25)^6 + 0.0
	*
	* @param	inFreqLogBase			Log Base of the Result Frequency.	Default: 10
	* @param	inFreqMultiplier		Multiplier of the Result Frequency.	Default: 0.25
	* @param	inFreqPower				Power of the Result Frequency.		Default: 6
	* @param	inFreqOffset			Offset of the Result Frequency.		Default: 0.0
	*
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Frequency Array", Keywords = "Get Frequency Array"), Category = "WindowsAudioCapture | Frequency Array")
	static TArray<float> BP_GetFrequencyArray
	(
		float inFreqLogBase = 10.0,
		float inFreqMultiplier = 0.25,
		float inFreqPower = 6.0,
		float inFreqOffset = 0.0
	);


	/**
	* This function will return the value of a specific frequency. It's needs a Frequency Array from the "Get Frequency Array" function.
	*
	* @param	InFrequencies		Array of float values for different frequencies from 0 to 22000. Can be get by using the "Get Frequency Array" function.
	* @param	InWantedFrequency	The specific frequency you want to keep from the Frequency Array.
	* @param	OutFrequencyValue	Float value of the requested frequency.
	*
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Specific Freq Value", Keywords = "Get Specific Freq Value"), Category = "WindowsAudioCapture | Frequency Values")
	static void BP_GetSpecificFrequencyValue(TArray<float> InFrequencies, int32 InWantedFrequency, float& OutFrequencyValue);


	/**
	* This function will return the average value for SubBass (20 to 60hz)
	*
	* @param	InFrequencies	Array of float values for different frequencies from 0 to 22000. Can be get by using the "Get Frequency Array" function.
	* @param	OutAverageSubBass Average value of the frequencies from 20 to 60.
	*
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Subbass Value", Keywords = "Get Average Subbass Value"), Category = "WindowsAudioCapture | Frequency Values")
	static void BP_GetAverageSubBassValue(TArray<float> InFrequencies, float& OutAverageSubBass);


	/**
	* This function will return the average value for Bass (60 to 250hz)
	*
	* @param	InFrequencies	Array of float values for different frequencies from 0 to 22000. Can be get by using the "Get Frequency Array" function.
	* @param	OutAverageBass	Average value of the frequencies from 60 to 250.
	*
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Bass Value", Keywords = "Get Average Bass Value"), Category = "WindowsAudioCapture | Frequency Values")
	static void BP_GetAverageBassValue(TArray<float> InFrequencies,float& OutAverageBass);


	/**
	* This function will return the average value for a given frequency input range e.g.: 20 to 60 (SubBass)
	*
	* @param	InFrequencies		Array of float values for different frequencies from 0 to 22000. Can be get by using the "Get Frequency Array" function.
	* @param	InStartFrequency	Start Frequency of the Frequency interval.
	* @param	InEndFrequency		End Frequency of the Frequency interval.
	* @param	OutAverageFrequency	Average value of the requested frequency interval.
	*
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Freq Value In Range", Keywords = "Get Average Freq Value In Range"), Category = "WindowsAudioCapture | Frequency Values")
	static void BP_GetAverageFrequencyValueInRange
	(
		TArray<float> InFrequencies, 
		int32 InStartFrequency, 
		int32 InEndFrequency, 
		float& OutAverageFrequency
	);


protected:

	// Called when the game starts
	virtual void BeginPlay() override;


private:


};
