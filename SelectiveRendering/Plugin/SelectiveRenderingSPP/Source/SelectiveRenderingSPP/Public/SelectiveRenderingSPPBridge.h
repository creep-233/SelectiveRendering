#pragma once
#include "CoreMinimal.h"

class USelectiveRenderingSPPSubsystem;

class SELECTIVERENDERINGSPP_API FSelectiveBridgeSPP
{
public:
    // ����Ϸ�̶߳�һ������֡�ϳɡ������Ⱦ�߳�
    static void PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys);
};
