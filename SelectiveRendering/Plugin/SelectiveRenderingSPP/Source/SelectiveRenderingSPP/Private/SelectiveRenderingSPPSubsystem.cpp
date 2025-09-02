#include "SelectiveRenderingSPPSubsystem.h"
#include "SelectiveRenderingSPP.h"              // LogSPP
#include "SelectiveRenderingSPPBridge.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHI.h"
#include "RenderCore.h"
#include "PixelFormat.h"

static void SPP_DumpRT(const TCHAR* Tag, class UTextureRenderTarget2D* RT);

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

    SPP_DumpRT(TEXT("Out"), OutRT.Get());
    SPP_DumpRT(TEXT("Low"), LowRT.Get());
    SPP_DumpRT(TEXT("High"), HighRT.Get());
    SPP_DumpRT(TEXT("Mask"), MaskRT.Get());
    FlushRenderingCommands(); 

    FSelectiveBridgeSPP::PushFromGameThread(this);
}

static void SPP_DumpRT(const TCHAR* Tag, UTextureRenderTarget2D* RT)
{
    if (!RT)
    {
        UE_LOG(LogSPP, Error, TEXT("[%s] RT = null"), Tag);
        return;
    }

    FTextureRenderTargetResource* Res = RT->GameThread_GetRenderTargetResource();
    FTextureRHIRef Tex = Res ? Res->GetTextureRHI() : FTextureRHIRef();

    ENQUEUE_RENDER_COMMAND(SPP_Dump)(
        [TagStr = FString(Tag), Tex](FRHICommandListImmediate& RHICmdList)
        {
            if (!Tex.IsValid())
            {
                UE_LOG(LogSPP, Error, TEXT("[%s] RHI Tex invalid"), *TagStr);
                return;
            }

            const FRHITextureDesc& D = Tex->GetDesc();
            UE_LOG(LogSPP, Warning,
                TEXT("[%s] Extent=%dx%d Format=%s Mips=%u Flags=0x%08x SRV=%d UAV=%d"),
                *TagStr, D.Extent.X, D.Extent.Y, GPixelFormats[D.Format].Name, D.NumMips,
                (uint32)D.Flags,
                EnumHasAnyFlags(D.Flags, TexCreate_ShaderResource) ? 1 : 0,
                EnumHasAnyFlags(D.Flags, TexCreate_UAV) ? 1 : 0);
        });
}


