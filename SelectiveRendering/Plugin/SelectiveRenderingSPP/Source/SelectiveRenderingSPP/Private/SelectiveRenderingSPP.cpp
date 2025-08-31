#include "SelectiveRenderingSPP.h"
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "Logging/LogMacros.h"

DEFINE_LOG_CATEGORY_STATIC(LogSelectiveRenderingSPP, Log, All);

class FSelectiveRenderingSPPModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        const FString BaseDir = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"))->GetBaseDir();
        const FString ShaderDir = FPaths::Combine(BaseDir, TEXT("Shader"));

        AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
        UE_LOG(LogSelectiveRenderingSPP, Display, TEXT("Map /SelectiveRenderingSPP -> %s"), *ShaderDir);
    }

    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
