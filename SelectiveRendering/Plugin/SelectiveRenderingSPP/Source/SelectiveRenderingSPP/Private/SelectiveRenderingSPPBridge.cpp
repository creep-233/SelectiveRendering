// Private/SelectiveRenderingSPPBridge.cpp
#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPPShaders.h"     // �� �� Build.cs ������ PrivatePCHHeaderFile�������һ��
#include "SelectiveRenderingSPPSubsystem.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RHICommandList.h"                   // FRHICommandListImmediate

void FSelectiveBridgeSPP::PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys)
{
    if (!Subsys || !Subsys->IsEnabled()) return;

    UTextureRenderTarget2D* OutRT = Subsys->GetHighRT();   // ������������� RT
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
            // �������ԭ���� SelectiveRenderingSPPShaders.h ���Ѿ�����
            EnqueueSelectiveComposite(RHICmdList, OutRHI, LowRHI, HighRHI, SalRHI, Threshold, Boost);
        });
}
