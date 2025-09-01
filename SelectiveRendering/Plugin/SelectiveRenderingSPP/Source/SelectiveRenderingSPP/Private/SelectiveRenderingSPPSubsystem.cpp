#include "SelectiveRenderingSPPSubsystem.h"
#include "SelectiveRenderingSPP.h"              // LogSPP
#include "SelectiveRenderingSPPBridge.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHI.h"
#include "RenderCore.h"

void USelectiveRenderingSPPSubsystem::RebuildRTResource(UTextureRenderTarget2D* RT)
{
    if (!RT) return;
    RT->UpdateResourceImmediate(false);
}

void USelectiveRenderingSPPSubsystem::SRSPP_SetTargets(
    UTextureRenderTarget2D* Out,
    UTextureRenderTarget2D* Low,
    UTextureRenderTarget2D* High,
    UTextureRenderTarget2D* Mask)
{
    OutRT = Out; LowRT = Low; HighRT = High; MaskRT = Mask;

    RebuildRTResource(Out);
    RebuildRTResource(Low);
    RebuildRTResource(High);
    RebuildRTResource(Mask);
    FlushRenderingCommands();

    UE_LOG(LogSPP, Log, TEXT("[SPP] SetTargets Out=%s Low=%s High=%s Mask=%s"),
        Out ? *Out->GetName() : TEXT("None"),
        Low ? *Low->GetName() : TEXT("None"),
        High ? *High->GetName() : TEXT("None"),
        Mask ? *Mask->GetName() : TEXT("None"));
}

void USelectiveRenderingSPPSubsystem::SRSPP_SetParams(float InThreshold, float InBoost)
{
    Threshold = InThreshold;
    Boost = InBoost;
}

void USelectiveRenderingSPPSubsystem::SRSPP_CompositeNow()
{
    if (!IsEnabled())
    {
        UE_LOG(LogSPP, Warning, TEXT("[SPP] CompositeNow called but targets not set."));
        return;
    }

    RebuildRTResource(OutRT.Get());
    RebuildRTResource(LowRT.Get());
    RebuildRTResource(HighRT.Get());
    RebuildRTResource(MaskRT.Get());
    FlushRenderingCommands();

    FSelectiveBridgeSPP::PushFromGameThread(this);
}
