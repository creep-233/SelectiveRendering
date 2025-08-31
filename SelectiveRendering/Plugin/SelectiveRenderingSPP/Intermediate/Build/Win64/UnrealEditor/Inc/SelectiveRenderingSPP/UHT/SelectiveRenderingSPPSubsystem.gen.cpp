// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SelectiveRenderingSPP/Public/SelectiveRenderingSPPSubsystem.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSelectiveRenderingSPPSubsystem() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
SELECTIVERENDERINGSPP_API UClass* Z_Construct_UClass_USelectiveRenderingSPPSubsystem();
SELECTIVERENDERINGSPP_API UClass* Z_Construct_UClass_USelectiveRenderingSPPSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_SelectiveRenderingSPP();
// End Cross Module References

// Begin Class USelectiveRenderingSPPSubsystem Function PushToRHI
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "PushToRHI", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execPushToRHI)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PushToRHI();
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function PushToRHI

// Begin Class USelectiveRenderingSPPSubsystem Function SetEnabled
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics
{
	struct SelectiveRenderingSPPSubsystem_eventSetEnabled_Parms
	{
		bool bInEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static void NewProp_bInEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::NewProp_bInEnabled_SetBit(void* Obj)
{
	((SelectiveRenderingSPPSubsystem_eventSetEnabled_Parms*)Obj)->bInEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::NewProp_bInEnabled = { "bInEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SelectiveRenderingSPPSubsystem_eventSetEnabled_Parms), &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::NewProp_bInEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::NewProp_bInEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SetEnabled", nullptr, nullptr, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::SelectiveRenderingSPPSubsystem_eventSetEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::SelectiveRenderingSPPSubsystem_eventSetEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSetEnabled)
{
	P_GET_UBOOL(Z_Param_bInEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetEnabled(Z_Param_bInEnabled);
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SetEnabled

// Begin Class USelectiveRenderingSPPSubsystem Function SetHighRT
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics
{
	struct SelectiveRenderingSPPSubsystem_eventSetHighRT_Parms
	{
		UTextureRenderTarget2D* InHighRT;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InHighRT;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::NewProp_InHighRT = { "InHighRT", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSetHighRT_Parms, InHighRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::NewProp_InHighRT,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SetHighRT", nullptr, nullptr, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::PropPointers), sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::SelectiveRenderingSPPSubsystem_eventSetHighRT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::SelectiveRenderingSPPSubsystem_eventSetHighRT_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSetHighRT)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_InHighRT);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHighRT(Z_Param_InHighRT);
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SetHighRT

// Begin Class USelectiveRenderingSPPSubsystem Function SetLowRT
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics
{
	struct SelectiveRenderingSPPSubsystem_eventSetLowRT_Parms
	{
		UTextureRenderTarget2D* InLowRT;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InLowRT;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::NewProp_InLowRT = { "InLowRT", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSetLowRT_Parms, InLowRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::NewProp_InLowRT,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SetLowRT", nullptr, nullptr, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::PropPointers), sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::SelectiveRenderingSPPSubsystem_eventSetLowRT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::SelectiveRenderingSPPSubsystem_eventSetLowRT_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSetLowRT)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_InLowRT);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLowRT(Z_Param_InLowRT);
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SetLowRT

// Begin Class USelectiveRenderingSPPSubsystem Function SetMaskRT
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics
{
	struct SelectiveRenderingSPPSubsystem_eventSetMaskRT_Parms
	{
		UTextureRenderTarget2D* InMaskRT;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InMaskRT;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::NewProp_InMaskRT = { "InMaskRT", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSetMaskRT_Parms, InMaskRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::NewProp_InMaskRT,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SetMaskRT", nullptr, nullptr, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::PropPointers), sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::SelectiveRenderingSPPSubsystem_eventSetMaskRT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::SelectiveRenderingSPPSubsystem_eventSetMaskRT_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSetMaskRT)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_InMaskRT);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaskRT(Z_Param_InMaskRT);
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SetMaskRT

// Begin Class USelectiveRenderingSPPSubsystem
void USelectiveRenderingSPPSubsystem::StaticRegisterNativesUSelectiveRenderingSPPSubsystem()
{
	UClass* Class = USelectiveRenderingSPPSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PushToRHI", &USelectiveRenderingSPPSubsystem::execPushToRHI },
		{ "SetEnabled", &USelectiveRenderingSPPSubsystem::execSetEnabled },
		{ "SetHighRT", &USelectiveRenderingSPPSubsystem::execSetHighRT },
		{ "SetLowRT", &USelectiveRenderingSPPSubsystem::execSetLowRT },
		{ "SetMaskRT", &USelectiveRenderingSPPSubsystem::execSetMaskRT },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USelectiveRenderingSPPSubsystem);
UClass* Z_Construct_UClass_USelectiveRenderingSPPSubsystem_NoRegister()
{
	return USelectiveRenderingSPPSubsystem::StaticClass();
}
struct Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SelectiveRenderingSPPSubsystem.h" },
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaskRT_MetaData[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowRT_MetaData[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighRT_MetaData[] = {
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaskRT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LowRT;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HighRT;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_PushToRHI, "PushToRHI" }, // 3231372354
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetEnabled, "SetEnabled" }, // 1704219873
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetHighRT, "SetHighRT" }, // 4064953059
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetLowRT, "SetLowRT" }, // 931231462
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SetMaskRT, "SetMaskRT" }, // 3935519713
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USelectiveRenderingSPPSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::NewProp_MaskRT = { "MaskRT", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USelectiveRenderingSPPSubsystem, MaskRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaskRT_MetaData), NewProp_MaskRT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::NewProp_LowRT = { "LowRT", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USelectiveRenderingSPPSubsystem, LowRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowRT_MetaData), NewProp_LowRT_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::NewProp_HighRT = { "HighRT", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USelectiveRenderingSPPSubsystem, HighRT), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighRT_MetaData), NewProp_HighRT_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::NewProp_MaskRT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::NewProp_LowRT,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::NewProp_HighRT,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_SelectiveRenderingSPP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::ClassParams = {
	&USelectiveRenderingSPPSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_USelectiveRenderingSPPSubsystem()
{
	if (!Z_Registration_Info_UClass_USelectiveRenderingSPPSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USelectiveRenderingSPPSubsystem.OuterSingleton, Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USelectiveRenderingSPPSubsystem.OuterSingleton;
}
template<> SELECTIVERENDERINGSPP_API UClass* StaticClass<USelectiveRenderingSPPSubsystem>()
{
	return USelectiveRenderingSPPSubsystem::StaticClass();
}
USelectiveRenderingSPPSubsystem::USelectiveRenderingSPPSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(USelectiveRenderingSPPSubsystem);
USelectiveRenderingSPPSubsystem::~USelectiveRenderingSPPSubsystem() {}
// End Class USelectiveRenderingSPPSubsystem

// Begin Registration
struct Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USelectiveRenderingSPPSubsystem, USelectiveRenderingSPPSubsystem::StaticClass, TEXT("USelectiveRenderingSPPSubsystem"), &Z_Registration_Info_UClass_USelectiveRenderingSPPSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USelectiveRenderingSPPSubsystem), 3200121752U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_449711574(TEXT("/Script/SelectiveRenderingSPP"),
	Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
