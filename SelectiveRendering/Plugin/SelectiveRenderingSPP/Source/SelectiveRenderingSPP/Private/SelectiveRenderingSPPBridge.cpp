#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPPSubsystem.h"
#include "RHI.h"
#include "RHICommandList.h"

void FSelectiveBridgeSPP::PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsystem)
{
    if (!Subsystem) return;

    ENQUEUE_RENDER_COMMAND(SR_NoOp)(
        [](FRHICommandListImmediate& RHICmdList)
        {
            // �����գ������ٰ� RDG/CS ����������
        });
}
