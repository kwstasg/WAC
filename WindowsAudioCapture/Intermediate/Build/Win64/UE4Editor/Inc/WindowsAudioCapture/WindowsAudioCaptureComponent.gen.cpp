// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WindowsAudioCapture/Public/WindowsAudioCaptureComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWindowsAudioCaptureComponent() {}
// Cross Module References
	WINDOWSAUDIOCAPTURE_API UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent_NoRegister();
	WINDOWSAUDIOCAPTURE_API UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_WindowsAudioCapture();
	WINDOWSAUDIOCAPTURE_API UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue();
	WINDOWSAUDIOCAPTURE_API UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange();
	WINDOWSAUDIOCAPTURE_API UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue();
	WINDOWSAUDIOCAPTURE_API UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray();
	WINDOWSAUDIOCAPTURE_API UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue();
// End Cross Module References
	void UWindowsAudioCaptureComponent::StaticRegisterNativesUWindowsAudioCaptureComponent()
	{
		UClass* Class = UWindowsAudioCaptureComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BP_GetAverageBassValue", &UWindowsAudioCaptureComponent::execBP_GetAverageBassValue },
			{ "BP_GetAverageFrequencyValueInRange", &UWindowsAudioCaptureComponent::execBP_GetAverageFrequencyValueInRange },
			{ "BP_GetAverageSubBassValue", &UWindowsAudioCaptureComponent::execBP_GetAverageSubBassValue },
			{ "BP_GetFrequencyArray", &UWindowsAudioCaptureComponent::execBP_GetFrequencyArray },
			{ "BP_GetSpecificFrequencyValue", &UWindowsAudioCaptureComponent::execBP_GetSpecificFrequencyValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics
	{
		struct WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms
		{
			TArray<float> InFrequencies;
			float OutAverageBass;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OutAverageBass;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InFrequencies;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InFrequencies_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::NewProp_OutAverageBass = { UE4CodeGen_Private::EPropertyClass::Float, "OutAverageBass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms, OutAverageBass), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::NewProp_InFrequencies = { UE4CodeGen_Private::EPropertyClass::Array, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms, InFrequencies), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::NewProp_InFrequencies_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::NewProp_OutAverageBass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::NewProp_InFrequencies,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::NewProp_InFrequencies_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "WindowsAudioCapture | Frequency Values" },
		{ "DisplayName", "Get Average Bass Value" },
		{ "Keywords", "Get Average Bass Value" },
		{ "ModuleRelativePath", "Public/WindowsAudioCaptureComponent.h" },
		{ "ToolTip", "This function will return the average value for Bass (60 to 250hz)\n\n@param        InFrequencies   Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        OutAverageBass  Average value of the frequencies from 60 to 250." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWindowsAudioCaptureComponent, "BP_GetAverageBassValue", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms), Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics
	{
		struct WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms
		{
			TArray<float> InFrequencies;
			int32 InStartFrequency;
			int32 InEndFrequency;
			float OutAverageFrequency;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OutAverageFrequency;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InEndFrequency;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InStartFrequency;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InFrequencies;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InFrequencies_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_OutAverageFrequency = { UE4CodeGen_Private::EPropertyClass::Float, "OutAverageFrequency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms, OutAverageFrequency), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InEndFrequency = { UE4CodeGen_Private::EPropertyClass::Int, "InEndFrequency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms, InEndFrequency), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InStartFrequency = { UE4CodeGen_Private::EPropertyClass::Int, "InStartFrequency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms, InStartFrequency), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InFrequencies = { UE4CodeGen_Private::EPropertyClass::Array, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms, InFrequencies), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InFrequencies_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_OutAverageFrequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InEndFrequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InStartFrequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InFrequencies,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::NewProp_InFrequencies_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::Function_MetaDataParams[] = {
		{ "Category", "WindowsAudioCapture | Frequency Values" },
		{ "DisplayName", "Get Average Freq Value In Range" },
		{ "Keywords", "Get Average Freq Value In Range" },
		{ "ModuleRelativePath", "Public/WindowsAudioCaptureComponent.h" },
		{ "ToolTip", "This function will return the average value for a given frequency input range e.g.: 20 to 60 (SubBass)\n\n@param        InFrequencies           Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        InStartFrequency        Start Frequency of the Frequency interval.\n@param        InEndFrequency          End Frequency of the Frequency interval.\n@param        OutAverageFrequency     Average value of the requested frequency interval." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWindowsAudioCaptureComponent, "BP_GetAverageFrequencyValueInRange", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms), Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics
	{
		struct WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms
		{
			TArray<float> InFrequencies;
			float OutAverageSubBass;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OutAverageSubBass;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InFrequencies;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InFrequencies_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::NewProp_OutAverageSubBass = { UE4CodeGen_Private::EPropertyClass::Float, "OutAverageSubBass", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms, OutAverageSubBass), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::NewProp_InFrequencies = { UE4CodeGen_Private::EPropertyClass::Array, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms, InFrequencies), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::NewProp_InFrequencies_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::NewProp_OutAverageSubBass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::NewProp_InFrequencies,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::NewProp_InFrequencies_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "WindowsAudioCapture | Frequency Values" },
		{ "DisplayName", "Get Average Subbass Value" },
		{ "Keywords", "Get Average Subbass Value" },
		{ "ModuleRelativePath", "Public/WindowsAudioCaptureComponent.h" },
		{ "ToolTip", "This function will return the average value for SubBass (20 to 60hz)\n\n@param        InFrequencies   Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        OutAverageSubBass Average value of the frequencies from 20 to 60." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWindowsAudioCaptureComponent, "BP_GetAverageSubBassValue", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms), Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics
	{
		struct WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms
		{
			float inFreqLogBase;
			float inFreqMultiplier;
			float inFreqPower;
			float inFreqOffset;
			TArray<float> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_inFreqOffset;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_inFreqPower;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_inFreqMultiplier;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_inFreqLogBase;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqOffset = { UE4CodeGen_Private::EPropertyClass::Float, "inFreqOffset", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms, inFreqOffset), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqPower = { UE4CodeGen_Private::EPropertyClass::Float, "inFreqPower", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms, inFreqPower), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqMultiplier = { UE4CodeGen_Private::EPropertyClass::Float, "inFreqMultiplier", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms, inFreqMultiplier), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqLogBase = { UE4CodeGen_Private::EPropertyClass::Float, "inFreqLogBase", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms, inFreqLogBase), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqPower,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::NewProp_inFreqLogBase,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "WindowsAudioCapture | Frequency Array" },
		{ "CPP_Default_inFreqLogBase", "10.000000" },
		{ "CPP_Default_inFreqMultiplier", "0.250000" },
		{ "CPP_Default_inFreqOffset", "0.000000" },
		{ "CPP_Default_inFreqPower", "6.000000" },
		{ "DisplayName", "Get Frequency Array" },
		{ "Keywords", "Get Frequency Array" },
		{ "ModuleRelativePath", "Public/WindowsAudioCaptureComponent.h" },
		{ "ToolTip", "This function will return an Array of Frequencies. Frequency = (LogX(FreqLogBase, Frequency) * FreqMultiplier)^FreqPower + FreqOffset.  e.g.: Frequency = (LogX(10, Frequency) * 0.25)^6 + 0.0\n\n@param        inFreqLogBase                   Log Base of the Result Frequency.       Default: 10\n@param        inFreqMultiplier                Multiplier of the Result Frequency.     Default: 0.25\n@param        inFreqPower                             Power of the Result Frequency.          Default: 6\n@param        inFreqOffset                    Offset of the Result Frequency.         Default: 0.0" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWindowsAudioCaptureComponent, "BP_GetFrequencyArray", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms), Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics
	{
		struct WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms
		{
			TArray<float> InFrequencies;
			int32 InWantedFrequency;
			float OutFrequencyValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OutFrequencyValue;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_InWantedFrequency;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InFrequencies;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_InFrequencies_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_OutFrequencyValue = { UE4CodeGen_Private::EPropertyClass::Float, "OutFrequencyValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms, OutFrequencyValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_InWantedFrequency = { UE4CodeGen_Private::EPropertyClass::Int, "InWantedFrequency", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms, InWantedFrequency), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_InFrequencies = { UE4CodeGen_Private::EPropertyClass::Array, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms, InFrequencies), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_InFrequencies_Inner = { UE4CodeGen_Private::EPropertyClass::Float, "InFrequencies", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_OutFrequencyValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_InWantedFrequency,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_InFrequencies,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::NewProp_InFrequencies_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "WindowsAudioCapture | Frequency Values" },
		{ "DisplayName", "Get Specific Freq Value" },
		{ "Keywords", "Get Specific Freq Value" },
		{ "ModuleRelativePath", "Public/WindowsAudioCaptureComponent.h" },
		{ "ToolTip", "This function will return the value of a specific frequency. It's needs a Frequency Array from the \"Get Frequency Array\" function.\n\n@param        InFrequencies           Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        InWantedFrequency       The specific frequency you want to keep from the Frequency Array.\n@param        OutFrequencyValue       Float value of the requested frequency." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWindowsAudioCaptureComponent, "BP_GetSpecificFrequencyValue", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14422401, sizeof(WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms), Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent_NoRegister()
	{
		return UWindowsAudioCaptureComponent::StaticClass();
	}
	struct Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_WindowsAudioCapture,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue, "BP_GetAverageBassValue" }, // 799296183
		{ &Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange, "BP_GetAverageFrequencyValueInRange" }, // 4132456710
		{ &Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue, "BP_GetAverageSubBassValue" }, // 3255540546
		{ &Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray, "BP_GetFrequencyArray" }, // 3181950819
		{ &Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue, "BP_GetSpecificFrequencyValue" }, // 3429407020
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Audio" },
		{ "DisplayName", "Windows Audio Capture" },
		{ "IncludePath", "WindowsAudioCaptureComponent.h" },
		{ "ModuleRelativePath", "Public/WindowsAudioCaptureComponent.h" },
		{ "ToolTip", "This Component starts a Listener that captures frequency information from the Windows Default Audio Device.\nYou need to have it inside your Blueprint in order to call \"Get Frequency Array\" function." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWindowsAudioCaptureComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::ClassParams = {
		&UWindowsAudioCaptureComponent::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x00B000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWindowsAudioCaptureComponent, 1113320612);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWindowsAudioCaptureComponent(Z_Construct_UClass_UWindowsAudioCaptureComponent, &UWindowsAudioCaptureComponent::StaticClass, TEXT("/Script/WindowsAudioCapture"), TEXT("UWindowsAudioCaptureComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWindowsAudioCaptureComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
