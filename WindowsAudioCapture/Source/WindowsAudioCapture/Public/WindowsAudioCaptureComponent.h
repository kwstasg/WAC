// Windows Audio Capture (WAC) by KwstasG (Kostas Giannakakis)
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

    // Cleans up resources
    ~UWindowsAudioCaptureComponent();

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /**
    * This function will return an Array of Frequencies for all channels, left channel, and right channel.
    * These parameters allow you to customize how the frequencies are calculated and visualized.
    *
    * @param OutFrequencies               Combined frequencies array.
    * @param OutLeftChannelFrequencies    Left channel frequencies array.
    * @param OutRightChannelFrequencies   Right channel frequencies array.
    * @param inFreqLogBase                This controls the base of the logarithm used in the calculation. Increasing this value can make the frequency spectrum appear more compressed. Default: 10
    * @param inFreqMultiplier             This scales the frequency values. Increasing this value will spread out the frequencies more, making it easier to see differences between them. Default: 0.25
    * @param inFreqPower                  This raises the frequency values to the specified power. Higher values can exaggerate differences between frequencies. Default: 6
    * @param inFreqOffset                 This adds an offset to the frequency values. It can be used to adjust the baseline of the spectrum. Default: 0.0
    *
    */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Frequency Array", Keywords = "Get Frequency Array"), Category = "WindowsAudioCapture | Frequency Array")
    static void BP_GetFrequencyArray
    (
        TArray<float>& OutFrequencies,
        TArray<float>& OutLeftChannelFrequencies,
        TArray<float>& OutRightChannelFrequencies,
        float inFreqLogBase = 10.0f,
        float inFreqMultiplier = 0.25f,
        float inFreqPower = 6.0f,
        float inFreqOffset = 0.0f
    );

    /**
    * This function will return the value of a specific frequency and its corresponding value in decibels.
    *
    * @param InFrequencies        Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param InWantedFrequency    The specific frequency you want to keep from the Frequency Array.
    * @param OutFrequencyValue    Float value of the requested frequency.
    * @param OutFrequencyValueDB  Float value of the requested frequency in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Specific Freq Value", Keywords = "Get Specific Freq Value"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetSpecificFrequencyValue(TArray<float> InFrequencies, int32 InWantedFrequency, float& OutFrequencyValue, float& OutFrequencyValueDB);

    /**
    * This function will return the average value for SubBass (20 to 60hz) and its corresponding value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutAverageSubBass        Average value of the frequencies from 20 to 60.
    * @param OutAverageSubBassDB      Average value of the frequencies from 20 to 60 in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Subbass Value", Keywords = "Get Average Subbass Value"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetAverageSubBassValue(TArray<float> InFrequencies, float& OutAverageSubBass, float& OutAverageSubBassDB);

    /**
    * This function will return the average value for Bass (60 to 250hz) and its corresponding value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutAverageBass           Average value of the frequencies from 60 to 250.
    * @param OutAverageBassDB         Average value of the frequencies from 60 to 250 in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Bass Value", Keywords = "Get Average Bass Value"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetAverageBassValue(TArray<float> InFrequencies, float& OutAverageBass, float& OutAverageBassDB);

    /**
    * This function will return the average value for Mid frequencies (250 to 2000hz) and its corresponding value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutAverageMid            Average value of the frequencies from 250 to 2000.
    * @param OutAverageMidDB          Average value of the frequencies from 250 to 2000 in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Mid Value", Keywords = "Get Average Mid Value"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetAverageMidValue(TArray<float> InFrequencies, float& OutAverageMid, float& OutAverageMidDB);

    /**
    * This function will return the average value for High frequencies (2000 to 22000hz) and its corresponding value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutAverageHigh           Average value of the frequencies from 2000 to 22000.
    * @param OutAverageHighDB         Average value of the frequencies from 2000 to 22000 in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average High Value", Keywords = "Get Average High Value"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetAverageHighValue(TArray<float> InFrequencies, float& OutAverageHigh, float& OutAverageHighDB);

    /**
    * This function will return the average value for a given frequency input range e.g., 20 to 60 (SubBass), and its corresponding value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param InStartFrequency         Start Frequency of the Frequency interval.
    * @param InEndFrequency           End Frequency of the Frequency interval.
    * @param OutAverageFrequency      Average value of the requested frequency interval.
    * @param OutAverageFrequencyDB    Average value of the requested frequency interval in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Average Freq Value In Range", Keywords = "Get Average Freq Value In Range"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetAverageFrequencyValueInRange
    (
        TArray<float> InFrequencies, 
        int32 InStartFrequency, 
        int32 InEndFrequency, 
        float& OutAverageFrequency,
        float& OutAverageFrequencyDB
    );

    /**
    * This function will return the total energy of the audio signal across all frequencies and its corresponding value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutTotalEnergy           Total energy of the audio signal.
    * @param OutTotalEnergyDB         Total energy of the audio signal in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Total Energy", Keywords = "Get Total Energy"), Category = "WindowsAudioCapture | Energy")
    static void BP_GetTotalEnergy(TArray<float> InFrequencies, float& OutTotalEnergy, float& OutTotalEnergyDB);

    /**
    * This function will return the peak frequency and its value in decibels.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutPeakFrequency         Frequency with the highest amplitude.
    * @param OutPeakFrequencyDB       Value of the peak frequency in decibels.
    *
    */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Peak Frequency", Keywords = "Get Peak Frequency"), Category = "WindowsAudioCapture | Frequency Values")
    static void BP_GetPeakFrequency(TArray<float> InFrequencies, float& OutPeakFrequency, float& OutPeakFrequencyDB);

    /**
    * This function normalizes the frequency array to a specified range.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutNormalizedFrequencies Normalized frequency array.
    * @param RangeMin                 Minimum value of the normalized range.
    * @param RangeMax                 Maximum value of the normalized range.
    *
    */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Normalize Frequency Array", Keywords = "Normalize Frequency Array"), Category = "WindowsAudioCapture | Frequency Array")
    static void BP_NormalizeFrequencyArray(TArray<float> InFrequencies, TArray<float>& OutNormalizedFrequencies, float RangeMin = 0.0f, float RangeMax = 1.0f);

    /**
    * This function applies dynamic range compression to the frequency array.
    *
    * @param InFrequencies            Array of float values for different frequencies. Can be obtained by using the "Get Frequency Array" function.
    * @param OutCompressedFrequencies Compressed frequency array.
    * @param Threshold                Threshold level for compression.
    * @param Ratio                    Compression ratio.
    *
    */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Apply Dynamic Range Compression", Keywords = "Apply Dynamic Range Compression"), Category = "WindowsAudioCapture | Frequency Array")
    static void BP_ApplyDynamicRangeCompression(TArray<float> InFrequencies, TArray<float>& OutCompressedFrequencies, float Threshold = -24.0f, float Ratio = 4.0f);

    /**
    * This function performs interpolation of a value over time.
    *
    * @param InputValue             The input value of the float.
    * @param InterpSpeed            The interpolation speed lower=smoother, higher=more responsive, if set to 0 returns the input value. 
    * @param DeltaTime              The time since the last tick.
    * @param OutInterpolatedValue   The interpolated float value.
    *
    */
    UFUNCTION(BlueprintCallable, meta = (DisplayName = "Interpolate Value", Keywords = "Interpolate Value"), Category = "WindowsAudioCapture | Utilities")
    static void BP_InterpolateValue(float InputValue, float InterpSpeed, float DeltaTime, float& OutInterpolatedValue);

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

private:
    // Validates frequency calculation parameters
    static bool ValidateFrequencyParameters(float& inFreqLogBase, float& inFreqMultiplier, float& inFreqPower, float& inFreqOffset);
};
