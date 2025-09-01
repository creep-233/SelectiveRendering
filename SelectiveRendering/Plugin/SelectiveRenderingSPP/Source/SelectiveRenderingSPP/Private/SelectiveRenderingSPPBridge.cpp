#include "SelectiveRenderingSPPBridge.h"          // 放第一行
#include "SelectiveRenderingSPPSubsystem.h"

#include "Engine/TextureRenderTarget2D.h"
#include "Engine/TextureRenderTarget.h"           // 声明 GameThread_GetRenderTargetResource / FTextureRenderTargetResource
#include "RenderResource.h"                        // 定义 FTextureRenderTargetResource
#include "RHI.h"
#include "RHICommandList.h"

// 由 Shaders.cpp 提供实现（只声明）
extern void EnqueueSelectiveComposite(
    FRHICommandListImmediate& RHICmdList,
    const FTextureRHIRef& OutRHI,
    const FTextureRHIRef& LowRHI,
    const FTextureRHIRef& HighRHI,
    const FTextureRHIRef& SalRHI,
    float Threshold,
    float Boost);

void FSelectiveBridgeSPP::PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys)
{
    if (!Subsys || !Subsys->IsEnabled()) return;

    UTextureRenderTarget2D* OutRT = Subsys->GetOutRT();
    UTextureRenderTarget2D* LowRT = Subsys->GetLowRT();
    UTextureRenderTarget2D* HighRT = Subsys->GetHighRT();
    UTextureRenderTarget2D* MaskRT = Subsys->GetMaskRT();
    if (!OutRT || !LowRT || !HighRT || !MaskRT) return;

    // 在 GameThread 上安全拿资源（不会触发 ensure）
    FTextureRenderTargetResource* OutRes = OutRT ? OutRT->GameThread_GetRenderTargetResource() : nullptr;
    FTextureRenderTargetResource* LowRes = LowRT ? LowRT->GameThread_GetRenderTargetResource() : nullptr;
    FTextureRenderTargetResource* HighRes = HighRT ? HighRT->GameThread_GetRenderTargetResource() : nullptr;
    FTextureRenderTargetResource* SalRes = MaskRT ? MaskRT->GameThread_GetRenderTargetResource() : nullptr;

    if (!OutRes || !LowRes || !HighRes || !SalRes)
    {
        UE_LOG(LogTemp, Error, TEXT("[SPP][Bridge] Resource null: Out(%p) Low(%p) High(%p) Mask(%p)"),
            OutRes, LowRes, HighRes, SalRes);
        return;
    }

    FTextureRHIRef OutRHI = OutRes->GetTextureRHI();
    FTextureRHIRef LowRHI = LowRes->GetTextureRHI();
    FTextureRHIRef HighRHI = HighRes->GetTextureRHI();
    FTextureRHIRef SalRHI = SalRes->GetTextureRHI();

    if (!OutRHI.IsValid() || !LowRHI.IsValid() || !HighRHI.IsValid() || !SalRHI.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("[SPP][Bridge] Invalid RHI: Out(%d) Low(%d) High(%d) Mask(%d)"),
            OutRHI.IsValid(), LowRHI.IsValid(), HighRHI.IsValid(), SalRHI.IsValid());
        return;
    }

    const float Threshold = Subsys->GetThreshold();
    const float Boost = Subsys->GetBoost();

    ENQUEUE_RENDER_COMMAND(SPP_Composite)(
        [OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost](FRHICommandListImmediate& RHICmdList)
        {
            EnqueueSelectiveComposite(RHICmdList, OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost);
        });
}
