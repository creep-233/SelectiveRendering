#pragma once
#include "CoreMinimal.h"
class USelectiveRenderingSPPSubsystem;

class FSelectiveRenderingSPPBridge
{
public:
    static void PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys);
};
