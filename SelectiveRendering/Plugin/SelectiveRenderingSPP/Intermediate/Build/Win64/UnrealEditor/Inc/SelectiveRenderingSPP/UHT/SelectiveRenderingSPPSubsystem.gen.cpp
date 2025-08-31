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

// Begin Class USelectiveRenderingSPPSubsystem Function SRSPP_CompositeNow
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SelectiveRenderingSPP" },
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SRSPP_CompositeNow", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSRSPP_CompositeNow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SRSPP_CompositeNow();
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SRSPP_CompositeNow

// Begin Class USelectiveRenderingSPPSubsystem Function SRSPP_SetParams
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics
{
	struct SelectiveRenderingSPPSubsystem_eventSRSPP_SetParams_Parms
	{
		float InThreshold;
		float InBoost;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SelectiveRenderingSPP" },
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InThreshold;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InBoost;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::NewProp_InThreshold = { "InThreshold", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSRSPP_SetParams_Parms, InThreshold), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::NewProp_InBoost = { "InBoost", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSRSPP_SetParams_Parms, InBoost), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::NewProp_InThreshold,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::NewProp_InBoost,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SRSPP_SetParams", nullptr, nullptr, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::PropPointers), sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::SelectiveRenderingSPPSubsystem_eventSRSPP_SetParams_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::SelectiveRenderingSPPSubsystem_eventSRSPP_SetParams_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSRSPP_SetParams)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InThreshold);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InBoost);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SRSPP_SetParams(Z_Param_InThreshold,Z_Param_InBoost);
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SRSPP_SetParams

// Begin Class USelectiveRenderingSPPSubsystem Function SRSPP_SetTargets
struct Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics
{
	struct SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms
	{
		UTextureRenderTarget2D* Out;
		UTextureRenderTarget2D* Low;
		UTextureRenderTarget2D* High;
		UTextureRenderTarget2D* Mask;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SelectiveRenderingSPP" },
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Out;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Low;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_High;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mask;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_Out = { "Out", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms, Out), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_Low = { "Low", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms, Low), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_High = { "High", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms, High), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_Mask = { "Mask", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms, Mask), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_Out,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_Low,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_High,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::NewProp_Mask,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USelectiveRenderingSPPSubsystem, nullptr, "SRSPP_SetTargets", nullptr, nullptr, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::PropPointers), sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::SelectiveRenderingSPPSubsystem_eventSRSPP_SetTargets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USelectiveRenderingSPPSubsystem::execSRSPP_SetTargets)
{
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_Out);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_Low);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_High);
	P_GET_OBJECT(UTextureRenderTarget2D,Z_Param_Mask);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SRSPP_SetTargets(Z_Param_Out,Z_Param_Low,Z_Param_High,Z_Param_Mask);
	P_NATIVE_END;
}
// End Class USelectiveRenderingSPPSubsystem Function SRSPP_SetTargets

// Begin Class USelectiveRenderingSPPSubsystem
void USelectiveRenderingSPPSubsystem::StaticRegisterNativesUSelectiveRenderingSPPSubsystem()
{
	UClass* Class = USelectiveRenderingSPPSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SRSPP_CompositeNow", &USelectiveRenderingSPPSubsystem::execSRSPP_CompositeNow },
		{ "SRSPP_SetParams", &USelectiveRenderingSPPSubsystem::execSRSPP_SetParams },
		{ "SRSPP_SetTargets", &USelectiveRenderingSPPSubsystem::execSRSPP_SetTargets },
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
		{ "BlueprintType", "true" },
		{ "IncludePath", "SelectiveRenderingSPPSubsystem.h" },
		{ "ModuleRelativePath", "Public/SelectiveRenderingSPPSubsystem.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_CompositeNow, "SRSPP_CompositeNow" }, // 3652186414
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetParams, "SRSPP_SetParams" }, // 3167916586
		{ &Z_Construct_UFunction_USelectiveRenderingSPPSubsystem_SRSPP_SetTargets, "SRSPP_SetTargets" }, // 2349568963
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USelectiveRenderingSPPSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
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
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
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
		{ Z_Construct_UClass_USelectiveRenderingSPPSubsystem, USelectiveRenderingSPPSubsystem::StaticClass, TEXT("USelectiveRenderingSPPSubsystem"), &Z_Registration_Info_UClass_USelectiveRenderingSPPSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USelectiveRenderingSPPSubsystem), 1425904817U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_3331668273(TEXT("/Script/SelectiveRenderingSPP"),
	Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
