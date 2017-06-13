// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/WindowsAudioCapture.h"
#include "WindowsAudioCapture.generated.dep.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1WindowsAudioCapture() {}
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	ENGINE_API class UClass* Z_Construct_UClass_UActorComponent();

	WINDOWSAUDIOCAPTURE_API class UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue();
	WINDOWSAUDIOCAPTURE_API class UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange();
	WINDOWSAUDIOCAPTURE_API class UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue();
	WINDOWSAUDIOCAPTURE_API class UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray();
	WINDOWSAUDIOCAPTURE_API class UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue();
	WINDOWSAUDIOCAPTURE_API class UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent_NoRegister();
	WINDOWSAUDIOCAPTURE_API class UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent();
	WINDOWSAUDIOCAPTURE_API class UPackage* Z_Construct_UPackage__Script_WindowsAudioCapture();
	void UWindowsAudioCaptureComponent::StaticRegisterNativesUWindowsAudioCaptureComponent()
	{
		UClass* Class = UWindowsAudioCaptureComponent::StaticClass();
		static const TNameNativePtrPair<ANSICHAR> AnsiFuncs[] = {
			{ "BP_GetAverageBassValue", (Native)&UWindowsAudioCaptureComponent::execBP_GetAverageBassValue },
			{ "BP_GetAverageFrequencyValueInRange", (Native)&UWindowsAudioCaptureComponent::execBP_GetAverageFrequencyValueInRange },
			{ "BP_GetAverageSubBassValue", (Native)&UWindowsAudioCaptureComponent::execBP_GetAverageSubBassValue },
			{ "BP_GetFrequencyArray", (Native)&UWindowsAudioCaptureComponent::execBP_GetFrequencyArray },
			{ "BP_GetSpecificFrequencyValue", (Native)&UWindowsAudioCaptureComponent::execBP_GetSpecificFrequencyValue },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, AnsiFuncs, 5);
	}
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue()
	{
		struct WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms
		{
			TArray<float> InFrequencies;
			float OutAverageBass;
		};
		UObject* Outer=Z_Construct_UClass_UWindowsAudioCaptureComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BP_GetAverageBassValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14422401, 65535, sizeof(WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms));
			UProperty* NewProp_OutAverageBass = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OutAverageBass"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OutAverageBass, WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms), 0x0010000000000180);
			UProperty* NewProp_InFrequencies = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(InFrequencies, WindowsAudioCaptureComponent_eventBP_GetAverageBassValue_Parms), 0x0010000000000080);
			UProperty* NewProp_InFrequencies_Inner = new(EC_InternalUseOnlyConstructor, NewProp_InFrequencies, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("WindowsAudioCapture | Frequency Values"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Get Average Bass Value"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Get Average Bass Value"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/WindowsAudioCaptureComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function will return the average value for Bass (60 to 250hz)\n\n@param        InFrequencies   Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        OutAverageBass  Average value of the frequencies from 60 to 250."));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange()
	{
		struct WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms
		{
			TArray<float> InFrequencies;
			int32 InStartFrequency;
			int32 InEndFrequency;
			float OutAverageFrequency;
		};
		UObject* Outer=Z_Construct_UClass_UWindowsAudioCaptureComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BP_GetAverageFrequencyValueInRange"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14422401, 65535, sizeof(WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms));
			UProperty* NewProp_OutAverageFrequency = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OutAverageFrequency"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OutAverageFrequency, WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms), 0x0010000000000180);
			UProperty* NewProp_InEndFrequency = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InEndFrequency"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(InEndFrequency, WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms), 0x0010000000000080);
			UProperty* NewProp_InStartFrequency = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InStartFrequency"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(InStartFrequency, WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms), 0x0010000000000080);
			UProperty* NewProp_InFrequencies = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(InFrequencies, WindowsAudioCaptureComponent_eventBP_GetAverageFrequencyValueInRange_Parms), 0x0010000000000080);
			UProperty* NewProp_InFrequencies_Inner = new(EC_InternalUseOnlyConstructor, NewProp_InFrequencies, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("WindowsAudioCapture | Frequency Values"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Get Average Freq Value In Range"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Get Average Freq Value In Range"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/WindowsAudioCaptureComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function will return the average value for a given frequency input range e.g.: 20 to 60 (SubBass)\n\n@param        InFrequencies           Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        InStartFrequency        Start Frequency of the Frequency interval.\n@param        InEndFrequency          End Frequency of the Frequency interval.\n@param        OutAverageFrequency     Average value of the requested frequency interval."));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue()
	{
		struct WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms
		{
			TArray<float> InFrequencies;
			float OutAverageSubBass;
		};
		UObject* Outer=Z_Construct_UClass_UWindowsAudioCaptureComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BP_GetAverageSubBassValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14422401, 65535, sizeof(WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms));
			UProperty* NewProp_OutAverageSubBass = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OutAverageSubBass"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OutAverageSubBass, WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms), 0x0010000000000180);
			UProperty* NewProp_InFrequencies = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(InFrequencies, WindowsAudioCaptureComponent_eventBP_GetAverageSubBassValue_Parms), 0x0010000000000080);
			UProperty* NewProp_InFrequencies_Inner = new(EC_InternalUseOnlyConstructor, NewProp_InFrequencies, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("WindowsAudioCapture | Frequency Values"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Get Average Subbass Value"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Get Average Subbass Value"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/WindowsAudioCaptureComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function will return the average value for SubBass (20 to 60hz)\n\n@param        InFrequencies   Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        OutAverageSubBass Average value of the frequencies from 20 to 60."));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray()
	{
		struct WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms
		{
			float inFreqLogBase;
			float inFreqMultiplier;
			float inFreqPower;
			float inFreqOffset;
			TArray<float> ReturnValue;
		};
		UObject* Outer=Z_Construct_UClass_UWindowsAudioCaptureComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BP_GetFrequencyArray"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x04022401, 65535, sizeof(WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms));
			UProperty* NewProp_ReturnValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(ReturnValue, WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms), 0x0010000000000580);
			UProperty* NewProp_ReturnValue_Inner = new(EC_InternalUseOnlyConstructor, NewProp_ReturnValue, TEXT("ReturnValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			UProperty* NewProp_inFreqOffset = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("inFreqOffset"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(inFreqOffset, WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms), 0x0010000000000080);
			UProperty* NewProp_inFreqPower = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("inFreqPower"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(inFreqPower, WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms), 0x0010000000000080);
			UProperty* NewProp_inFreqMultiplier = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("inFreqMultiplier"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(inFreqMultiplier, WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms), 0x0010000000000080);
			UProperty* NewProp_inFreqLogBase = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("inFreqLogBase"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(inFreqLogBase, WindowsAudioCaptureComponent_eventBP_GetFrequencyArray_Parms), 0x0010000000000080);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("WindowsAudioCapture | Frequency Array"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_inFreqLogBase"), TEXT("10.000000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_inFreqMultiplier"), TEXT("0.250000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_inFreqOffset"), TEXT("0.000000"));
			MetaData->SetValue(ReturnFunction, TEXT("CPP_Default_inFreqPower"), TEXT("6.000000"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Get Frequency Array"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Get Frequency Array"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/WindowsAudioCaptureComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function will return an Array of Frequencies. Frequency = (LogX(FreqLogBase, Frequency) * FreqMultiplier)^FreqPower + FreqOffset.  e.g.: Frequency = (LogX(10, Frequency) * 0.25)^6 + 0.0\n\n@param        inFreqLogBase                   Log Base of the Result Frequency.       Default: 10\n@param        inFreqMultiplier                Multiplier of the Result Frequency.     Default: 0.25\n@param        inFreqPower                             Power of the Result Frequency.          Default: 6\n@param        inFreqOffset                    Offset of the Result Frequency.         Default: 0.0"));
#endif
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue()
	{
		struct WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms
		{
			TArray<float> InFrequencies;
			int32 InWantedFrequency;
			float OutFrequencyValue;
		};
		UObject* Outer=Z_Construct_UClass_UWindowsAudioCaptureComponent();
		static UFunction* ReturnFunction = NULL;
		if (!ReturnFunction)
		{
			ReturnFunction = new(EC_InternalUseOnlyConstructor, Outer, TEXT("BP_GetSpecificFrequencyValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFunction(FObjectInitializer(), NULL, 0x14422401, 65535, sizeof(WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms));
			UProperty* NewProp_OutFrequencyValue = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("OutFrequencyValue"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(OutFrequencyValue, WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms), 0x0010000000000180);
			UProperty* NewProp_InWantedFrequency = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InWantedFrequency"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(InWantedFrequency, WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms), 0x0010000000000080);
			UProperty* NewProp_InFrequencies = new(EC_InternalUseOnlyConstructor, ReturnFunction, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UArrayProperty(CPP_PROPERTY_BASE(InFrequencies, WindowsAudioCaptureComponent_eventBP_GetSpecificFrequencyValue_Parms), 0x0010000000000080);
			UProperty* NewProp_InFrequencies_Inner = new(EC_InternalUseOnlyConstructor, NewProp_InFrequencies, TEXT("InFrequencies"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(FObjectInitializer(), EC_CppProperty, 0, 0x0000000000000000);
			ReturnFunction->Bind();
			ReturnFunction->StaticLink();
#if WITH_METADATA
			UMetaData* MetaData = ReturnFunction->GetOutermost()->GetMetaData();
			MetaData->SetValue(ReturnFunction, TEXT("Category"), TEXT("WindowsAudioCapture | Frequency Values"));
			MetaData->SetValue(ReturnFunction, TEXT("DisplayName"), TEXT("Get Specific Freq Value"));
			MetaData->SetValue(ReturnFunction, TEXT("Keywords"), TEXT("Get Specific Freq Value"));
			MetaData->SetValue(ReturnFunction, TEXT("ModuleRelativePath"), TEXT("Public/WindowsAudioCaptureComponent.h"));
			MetaData->SetValue(ReturnFunction, TEXT("ToolTip"), TEXT("This function will return the value of a specific frequency. It's needs a Frequency Array from the \"Get Frequency Array\" function.\n\n@param        InFrequencies           Array of float values for different frequencies from 0 to 22000. Can be get by using the \"Get Frequency Array\" function.\n@param        InWantedFrequency       The specific frequency you want to keep from the Frequency Array.\n@param        OutFrequencyValue       Float value of the requested frequency."));
#endif
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent_NoRegister()
	{
		return UWindowsAudioCaptureComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UWindowsAudioCaptureComponent()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UActorComponent();
			Z_Construct_UPackage__Script_WindowsAudioCapture();
			OuterClass = UWindowsAudioCaptureComponent::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20B00080;

				OuterClass->LinkChild(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue());
				OuterClass->LinkChild(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange());
				OuterClass->LinkChild(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue());
				OuterClass->LinkChild(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray());
				OuterClass->LinkChild(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue());

				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageBassValue(), "BP_GetAverageBassValue"); // 4183276061
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageFrequencyValueInRange(), "BP_GetAverageFrequencyValueInRange"); // 242818258
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetAverageSubBassValue(), "BP_GetAverageSubBassValue"); // 3847257641
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetFrequencyArray(), "BP_GetFrequencyArray"); // 3854392994
				OuterClass->AddFunctionToFunctionMapWithOverriddenName(Z_Construct_UFunction_UWindowsAudioCaptureComponent_BP_GetSpecificFrequencyValue(), "BP_GetSpecificFrequencyValue"); // 1637369946
				static TCppClassTypeInfo<TCppClassTypeTraits<UWindowsAudioCaptureComponent> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("BlueprintSpawnableComponent"), TEXT(""));
				MetaData->SetValue(OuterClass, TEXT("ClassGroupNames"), TEXT("Audio"));
				MetaData->SetValue(OuterClass, TEXT("DisplayName"), TEXT("Windows Audio Capture"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("WindowsAudioCaptureComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Public/WindowsAudioCaptureComponent.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("This Component starts a Listener that captures frequency information from the Windows Default Audio Device.\nYou need to have it inside your Blueprint in order to call \"Get Frequency Array\" function."));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWindowsAudioCaptureComponent, 3125659910);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWindowsAudioCaptureComponent(Z_Construct_UClass_UWindowsAudioCaptureComponent, &UWindowsAudioCaptureComponent::StaticClass, TEXT("/Script/WindowsAudioCapture"), TEXT("UWindowsAudioCaptureComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWindowsAudioCaptureComponent);
	UPackage* Z_Construct_UPackage__Script_WindowsAudioCapture()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), nullptr, FName(TEXT("/Script/WindowsAudioCapture")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000080);
			FGuid Guid;
			Guid.A = 0x1CEF2D12;
			Guid.B = 0xE81968EA;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
