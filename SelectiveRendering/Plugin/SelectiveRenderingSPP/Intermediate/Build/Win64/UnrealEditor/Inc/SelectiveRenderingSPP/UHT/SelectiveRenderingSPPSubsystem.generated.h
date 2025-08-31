// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SelectiveRenderingSPPSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureRenderTarget2D;
#ifdef SELECTIVERENDERINGSPP_SelectiveRenderingSPPSubsystem_generated_h
#error "SelectiveRenderingSPPSubsystem.generated.h already included, missing '#pragma once' in SelectiveRenderingSPPSubsystem.h"
#endif
#define SELECTIVERENDERINGSPP_SelectiveRenderingSPPSubsystem_generated_h

#define FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execSRSPP_CompositeNow); \
	DECLARE_FUNCTION(execSRSPP_SetParams); \
	DECLARE_FUNCTION(execSRSPP_SetTargets);


#define FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSelectiveRenderingSPPSubsystem(); \
	friend struct Z_Construct_UClass_USelectiveRenderingSPPSubsystem_Statics; \
public: \
	DECLARE_CLASS(USelectiveRenderingSPPSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SelectiveRenderingSPP"), NO_API) \
	DECLARE_SERIALIZER(USelectiveRenderingSPPSubsystem)


#define FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USelectiveRenderingSPPSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	USelectiveRenderingSPPSubsystem(USelectiveRenderingSPPSubsystem&&); \
	USelectiveRenderingSPPSubsystem(const USelectiveRenderingSPPSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USelectiveRenderingSPPSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USelectiveRenderingSPPSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USelectiveRenderingSPPSubsystem) \
	NO_API virtual ~USelectiveRenderingSPPSubsystem();


#define FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_6_PROLOG
#define FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_INCLASS_NO_PURE_DECLS \
	FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SELECTIVERENDERINGSPP_API UClass* StaticClass<class USelectiveRenderingSPPSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_project_UE5_SelectiveRendering_SelectiveRendering_Plugins_SelectiveRenderingSPP_Source_SelectiveRenderingSPP_Public_SelectiveRenderingSPPSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
