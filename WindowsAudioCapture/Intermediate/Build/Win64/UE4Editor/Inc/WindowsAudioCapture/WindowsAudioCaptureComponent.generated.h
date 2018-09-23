// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef WINDOWSAUDIOCAPTURE_WindowsAudioCaptureComponent_generated_h
#error "WindowsAudioCaptureComponent.generated.h already included, missing '#pragma once' in WindowsAudioCaptureComponent.h"
#endif
#define WINDOWSAUDIOCAPTURE_WindowsAudioCaptureComponent_generated_h

#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBP_GetAverageFrequencyValueInRange) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InStartFrequency); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InEndFrequency); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutAverageFrequency); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetAverageFrequencyValueInRange(Z_Param_InFrequencies,Z_Param_InStartFrequency,Z_Param_InEndFrequency,Z_Param_Out_OutAverageFrequency); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetAverageBassValue) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutAverageBass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetAverageBassValue(Z_Param_InFrequencies,Z_Param_Out_OutAverageBass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetAverageSubBassValue) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutAverageSubBass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetAverageSubBassValue(Z_Param_InFrequencies,Z_Param_Out_OutAverageSubBass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetSpecificFrequencyValue) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InWantedFrequency); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutFrequencyValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetSpecificFrequencyValue(Z_Param_InFrequencies,Z_Param_InWantedFrequency,Z_Param_Out_OutFrequencyValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetFrequencyArray) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqLogBase); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqPower); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=UWindowsAudioCaptureComponent::BP_GetFrequencyArray(Z_Param_inFreqLogBase,Z_Param_inFreqMultiplier,Z_Param_inFreqPower,Z_Param_inFreqOffset); \
		P_NATIVE_END; \
	}


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBP_GetAverageFrequencyValueInRange) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InStartFrequency); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InEndFrequency); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutAverageFrequency); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetAverageFrequencyValueInRange(Z_Param_InFrequencies,Z_Param_InStartFrequency,Z_Param_InEndFrequency,Z_Param_Out_OutAverageFrequency); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetAverageBassValue) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutAverageBass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetAverageBassValue(Z_Param_InFrequencies,Z_Param_Out_OutAverageBass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetAverageSubBassValue) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutAverageSubBass); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetAverageSubBassValue(Z_Param_InFrequencies,Z_Param_Out_OutAverageSubBass); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetSpecificFrequencyValue) \
	{ \
		P_GET_TARRAY(float,Z_Param_InFrequencies); \
		P_GET_PROPERTY(UIntProperty,Z_Param_InWantedFrequency); \
		P_GET_PROPERTY_REF(UFloatProperty,Z_Param_Out_OutFrequencyValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UWindowsAudioCaptureComponent::BP_GetSpecificFrequencyValue(Z_Param_InFrequencies,Z_Param_InWantedFrequency,Z_Param_Out_OutFrequencyValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBP_GetFrequencyArray) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqLogBase); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqMultiplier); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqPower); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_inFreqOffset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=UWindowsAudioCaptureComponent::BP_GetFrequencyArray(Z_Param_inFreqLogBase,Z_Param_inFreqMultiplier,Z_Param_inFreqPower,Z_Param_inFreqOffset); \
		P_NATIVE_END; \
	}


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWindowsAudioCaptureComponent(); \
	friend struct Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics; \
public: \
	DECLARE_CLASS(UWindowsAudioCaptureComponent, UActorComponent, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WindowsAudioCapture"), NO_API) \
	DECLARE_SERIALIZER(UWindowsAudioCaptureComponent)


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUWindowsAudioCaptureComponent(); \
	friend struct Z_Construct_UClass_UWindowsAudioCaptureComponent_Statics; \
public: \
	DECLARE_CLASS(UWindowsAudioCaptureComponent, UActorComponent, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WindowsAudioCapture"), NO_API) \
	DECLARE_SERIALIZER(UWindowsAudioCaptureComponent)


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UWindowsAudioCaptureComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UWindowsAudioCaptureComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWindowsAudioCaptureComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWindowsAudioCaptureComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWindowsAudioCaptureComponent(UWindowsAudioCaptureComponent&&); \
	NO_API UWindowsAudioCaptureComponent(const UWindowsAudioCaptureComponent&); \
public:


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UWindowsAudioCaptureComponent(UWindowsAudioCaptureComponent&&); \
	NO_API UWindowsAudioCaptureComponent(const UWindowsAudioCaptureComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWindowsAudioCaptureComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWindowsAudioCaptureComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWindowsAudioCaptureComponent)


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_PRIVATE_PROPERTY_OFFSET
#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_12_PROLOG
#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_RPC_WRAPPERS \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_INCLASS \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_INCLASS_NO_PURE_DECLS \
	WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID WAC_Plugin_Plugins_WindowsAudioCapture_Source_WindowsAudioCapture_Public_WindowsAudioCaptureComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
