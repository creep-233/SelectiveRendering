#pragma once
#include "CoreMinimal.h"

class USelectiveRenderingSPPSubsystem;

class SELECTIVERENDERINGSPP_API FSelectiveBridgeSPP
{
public:
    // 从游戏线程丢一个“本帧合成”命令到渲染线程
    static void PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsys);
};
