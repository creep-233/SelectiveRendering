// �� �Ȱ����� .cpp ͬ����ͷ�������Expected SelectiveRenderingSPPSubsystem.h to be first header included��
#include "SelectiveRenderingSPPSubsystem.h"

// �� �ٰ���ģ�� PCH����Щ����Ҫ������ŵ�һ������˳���� 5.3/5.5 ���ܹ���
#include "SelectiveRenderingSPP.h"

#include "SelectiveRenderingSPPBridge.h"    // ���� FSelectiveBridgeSPP::PushFromGameThread
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

    // �ѹ���������Ⱦ�̣߳�Bridge ��ץȡ 4 �� RT + ������Ȼ����� Compute Shader��
    FSelectiveBridgeSPP::PushFromGameThread(this);
}
