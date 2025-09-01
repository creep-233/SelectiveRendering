#pragma once
#include "CoreMinimal.h"

class USelectiveRenderingSPPSubsystem;

class SELECTIVERENDERINGSPP_API FSelectiveBridgeSPP
{
public:
    static void PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys);
};
