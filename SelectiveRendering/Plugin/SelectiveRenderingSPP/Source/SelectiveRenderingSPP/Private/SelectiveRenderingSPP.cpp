//// Plugins/SelectiveRenderingSPP/Source/SelectiveRenderingSPP/Private/SelectiveRenderingSPP.cpp
//#include "SelectiveRenderingSPP.h"
//#include "Interfaces/IPluginManager.h"
//#include "HAL/FileManager.h"
//#include "Misc/Paths.h"
//#include "ShaderCore.h"
//#include "Modules/ModuleManager.h"
//
//DEFINE_LOG_CATEGORY(LogSPP);  // 日志只在这一处定义
//
//static FString GetShaderDir()
//{
//    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"));
//    return FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
//}
//
//void FSelectiveRenderingSPPModule::StartupModule()
//{
//    const FString ShaderDir = GetShaderDir();
//    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
//
//    const bool bExists = IFileManager::Get().FileExists(*FPaths::Combine(ShaderDir, TEXT("SRComposite.usf")));
//    UE_LOG(LogSPP, Display, TEXT("[SPP] ShaderDir=%s, SRComposite.usf exists=%d"),
//        *ShaderDir, bExists ? 1 : 0);
//}
//
//void FSelectiveRenderingSPPModule::ShutdownModule()
//{
//}
//
//IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)


// Plugins/.../Private/SelectiveRenderingSPP.cpp
#include "SelectiveRenderingSPP.h"
#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "ShaderCore.h"  // 为 AddShaderSourceDirectoryMapping 提供声明

DEFINE_LOG_CATEGORY(LogSPP);

void FSelectiveRenderingSPPModule::StartupModule()
{
    FString ShaderDir;
    if (TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP")))
    {
        ShaderDir = FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
        AddShaderSourceDirectoryMapping(TEXT("/Plugin/SelectiveRenderingSPP"), ShaderDir);

        const bool bExists = IFileManager::Get().FileExists(*FPaths::Combine(ShaderDir, TEXT("SRComposite.usf")));
        UE_LOG(LogSPP, Display, TEXT("[SPP] Map /Plugin/SelectiveRenderingSPP -> %s, SRComposite.usf=%d"),
            *ShaderDir, bExists ? 1 : 0);
    }
    else
    {
        UE_LOG(LogSPP, Warning, TEXT("[SPP] Plugin not found, skip shader dir mapping."));
    }
}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
