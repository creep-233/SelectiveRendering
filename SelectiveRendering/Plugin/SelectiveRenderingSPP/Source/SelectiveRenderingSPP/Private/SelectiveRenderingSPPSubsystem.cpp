#include "SelectiveRenderingSPPSubsystem.h"
#include "SelectiveRenderingSPPBridge.h" // ���� PushFromGameThread

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

    // ������Ⱦ�̣߳�Bridge ���ץȡ��Щ RT ������ Compute Shader��
    FSelectiveBridgeSPP::PushFromGameThread(this);
}
