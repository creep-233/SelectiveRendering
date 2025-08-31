#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPP.h"                 // �ŵ�һ�У�ģ�� PCH��
#include "SelectiveRenderingSPPSubsystem.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHICommandList.h"

// �� Shaders.cpp �ṩʵ�֣�����ֻ������
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
