#pragma once
#include "Modules/ModuleManager.h"

class FSelectiveRenderingSPPModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
