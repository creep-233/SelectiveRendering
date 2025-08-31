#include "SelectiveRenderingSPPBridge.h"
#include "SelectiveRenderingSPPSubsystem.h"
#include "RHICommandList.h"

void FSelectiveRenderingSPPBridge::PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys)
{
    if (!Subsys) return;

    // 只是把参数捕获到渲染线程，暂时不做任何绘制（确保先能编译通过）
    ENQUEUE_RENDER_COMMAND(SR_NoOp)(
        [Mask = Subsys->GetMaskRT(), Low = Subsys->GetLowRT(), High = Subsys->GetHighRT()](FRHICommandListImmediate& RHICmdList)
        {
            // TODO: 之后在这里/或ViewExtension里加 RDG Pass
        }
        );
}
