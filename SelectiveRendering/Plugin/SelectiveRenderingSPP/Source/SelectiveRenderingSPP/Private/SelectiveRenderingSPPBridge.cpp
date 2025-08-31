#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPP.h"                 // 放第一行（模块 PCH）
#include "SelectiveRenderingSPPSubsystem.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHICommandList.h"

// 由 Shaders.cpp 提供实现，这里只做声明
void EnqueueSelectiveComposite(
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

    FTextureRHIRef OutRHI = OutRT->GetRenderTargetResource()->GetRenderTargetTexture();
    FTextureRHIRef LowRHI = LowRT->GetRenderTargetResource()->GetRenderTargetTexture();
    FTextureRHIRef HighRHI = HighRT->GetRenderTargetResource()->GetRenderTargetTexture();
    FTextureRHIRef SalRHI = MaskRT->GetRenderTargetResource()->GetRenderTargetTexture();

    const float Threshold = Subsys->GetThreshold();
    const float Boost = Subsys->GetBoost();

    ENQUEUE_RENDER_COMMAND(SPP_Composite)(
        [OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost](FRHICommandListImmediate& RHICmdList)
        {
            EnqueueSelectiveComposite(RHICmdList, OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost);
        });
}
