// Private/SelectiveRenderingSPPBridge.cpp
#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPPShaders.h"     // ★ 若 Build.cs 设置了 PrivatePCHHeaderFile，必须第一行
#include "SelectiveRenderingSPPSubsystem.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHICommandList.h"                   // FRHICommandListImmediate

void FSelectiveBridgeSPP::PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys)
{
    if (!Subsys || !Subsys->IsEnabled()) return;

    UTextureRenderTarget2D* OutRT = Subsys->GetHighRT();   // 或你期望的输出 RT
    UTextureRenderTarget2D* LowRT = Subsys->GetLowRT();
    UTextureRenderTarget2D* HighRT = Subsys->GetHighRT();
    UTextureRenderTarget2D* MaskRT = Subsys->GetMaskRT();
    if (!OutRT || !LowRT || !HighRT || !MaskRT) return;

    FTextureRHIRef OutRHI = OutRT->GetRenderTargetResource()->GetRenderTargetTexture();
    FTextureRHIRef LowRHI = LowRT->GetRenderTargetResource()->GetRenderTargetTexture();
    FTextureRHIRef HighRHI = HighRT->GetRenderTargetResource()->GetRenderTargetTexture();
    FTextureRHIRef SalRHI = MaskRT->GetRenderTargetResource()->GetRenderTargetTexture();

    const float Threshold = 0.5f;
    const float Boost = 0.0f;

    ENQUEUE_RENDER_COMMAND(SPP_Composite)(
        [OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost](FRHICommandListImmediate& RHICmdList)
        {
            // 这个函数原型在 SelectiveRenderingSPPShaders.h 里已经声明
            EnqueueSelectiveComposite(RHICmdList, OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost);
        });
}
