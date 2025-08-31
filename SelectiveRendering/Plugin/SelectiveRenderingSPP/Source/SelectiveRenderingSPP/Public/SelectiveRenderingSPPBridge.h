#pragma once
class USelectiveRenderingSPPSubsystem;

struct FSelectiveBridgeSPP
{
    static void PushFromGameThread(USelectiveRenderingSPPSubsystem* Subsystem);
};
