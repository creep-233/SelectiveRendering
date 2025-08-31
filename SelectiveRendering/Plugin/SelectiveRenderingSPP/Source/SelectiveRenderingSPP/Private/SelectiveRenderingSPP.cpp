#include "SelectiveRenderingSPP.h"              // 必须第一个
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"
#include "Modules/ModuleManager.h"

// 如果你的目录叫“Shader”（不是 Shaders），就用 "Shader"
static FString GetShaderDir()
{
    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"));
    return FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shader")); // ← 按你的实际文件夹名改
}

void FSelectiveRenderingSPPModule::StartupModule()
{
    const FString ShaderDir = GetShaderDir();
    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
}

void FSelectiveRenderingSPPModule::ShutdownModule()
{
    // 一般不需要清理映射
}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
