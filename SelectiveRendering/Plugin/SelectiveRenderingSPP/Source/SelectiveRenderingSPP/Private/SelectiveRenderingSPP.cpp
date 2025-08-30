//// Copyright Epic Games, Inc. All Rights Reserved.
//
//#include "SelectiveRenderingSPP.h"
//
//#define LOCTEXT_NAMESPACE "FSelectiveRenderingSPPModule"
//
//void FSelectiveRenderingSPPModule::StartupModule()
//{
//	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
//}
//
//void FSelectiveRenderingSPPModule::ShutdownModule()
//{
//	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
//	// we call this function before unloading the module.
//}
//
//#undef LOCTEXT_NAMESPACE
//	
//IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)



#include "SelectiveRenderingSPPSubsystem.h"
#include "SelectiveRenderingSPPBridge.h"

void USelectiveRenderingSPPSubsystem::SetEnabled(bool b) { bEnabled = b; }
void USelectiveRenderingSPPSubsystem::SetMaskRT(UTextureRenderTarget2D* In) { MaskRT = In; }
void USelectiveRenderingSPPSubsystem::SetLowRT(UTextureRenderTarget2D* In) { LowRT = In; }
void USelectiveRenderingSPPSubsystem::SetHighRT(UTextureRenderTarget2D* In) { HighRT = In; }
void USelectiveRenderingSPPSubsystem::PushToRHI() { FSelectiveBridgeSPP::PushFromGameThread(this); }
