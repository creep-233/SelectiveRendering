#include "SelectiveRenderingSPPSubsystem.h"
#include "SelectiveRenderingSPPBridge.h"

void USelectiveRenderingSPPSubsystem::SetEnabled(bool b) { bEnabled = b; }
void USelectiveRenderingSPPSubsystem::SetMaskRT(UTextureRenderTarget2D* In) { MaskRT = In; }
void USelectiveRenderingSPPSubsystem::SetLowRT(UTextureRenderTarget2D* In) { LowRT = In; }
void USelectiveRenderingSPPSubsystem::SetHighRT(UTextureRenderTarget2D* In) { HighRT = In; }
void USelectiveRenderingSPPSubsystem::PushToRHI() { FSelectiveBridgeSPP::PushFromGameThread(this); }
