#include "SelectiveRenderingSPPSubsystem.h"
#include "SelectiveRenderingSPPBridge.h" // 声明 PushFromGameThread

#include "Engine/TextureRenderTarget2D.h"

void USelectiveRenderingSPPSubsystem::SRSPP_SetTargets(
    UTextureRenderTarget2D* Out,
    UTextureRenderTarget2D* Low,
    UTextureRenderTarget2D* High,
    UTextureRenderTarget2D* Mask)
{
    OutRT = Out;
    LowRT = Low;
    HighRT = High;
    MaskRT = Mask;
}

void USelectiveRenderingSPPSubsystem::SRSPP_SetParams(float InThreshold, float InBoost)
{
    Threshold = InThreshold;
    Boost = InBoost;
}

void USelectiveRenderingSPPSubsystem::SRSPP_CompositeNow()
{
    if (!IsEnabled()) return;

    // 丢给渲染线程（Bridge 里会抓取这些 RT 并调用 Compute Shader）
    FSelectiveBridgeSPP::PushFromGameThread(this);
}
