// ① 先包含与 .cpp 同名的头（解决：Expected SelectiveRenderingSPPSubsystem.h to be first header included）
#include "SelectiveRenderingSPPSubsystem.h"

// ② 再包含模块 PCH（有些配置要求这个放第一；这种顺序在 5.3/5.5 都能过）
#include "SelectiveRenderingSPP.h"

#include "SelectiveRenderingSPPBridge.h"    // 声明 FSelectiveBridgeSPP::PushFromGameThread
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

    // 把工作丢到渲染线程（Bridge 会抓取 4 个 RT + 参数，然后调用 Compute Shader）
    FSelectiveBridgeSPP::PushFromGameThread(this);
}
