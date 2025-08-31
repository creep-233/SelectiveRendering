#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPPSubsystem.h"
#include "RHICommandList.h"

void FSelectiveRenderingSPPBridge::PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys)
{
    if (!Subsys) return;

    // ֻ�ǰѲ���������Ⱦ�̣߳���ʱ�����κλ��ƣ�ȷ�����ܱ���ͨ����
    ENQUEUE_RENDER_COMMAND(SR_NoOp)(
        [Mask = Subsys->GetMaskRT(), Low = Subsys->GetLowRT(), High = Subsys->GetHighRT()](FRHICommandListImmediate& RHICmdList)
        {
            // TODO: ֮��������/��ViewExtension��� RDG Pass
        }
        );
}
