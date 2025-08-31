#include "SelectiveRenderingSPP.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"

// UE5.5 下仍可包含 ShaderCore.h（头文件），但 Build.cs 里不要引用 ShaderCore 模块；RenderCore 足够
#include "ShaderCore.h"

void FSelectiveRenderingSPPModule::StartupModule()
{
    const FString BaseDir = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"))->GetBaseDir();
    const FString ShaderDir = FPaths::Combine(BaseDir, TEXT("Shaders")); // 目录名必须是 Shaders

    // 把虚拟路径 /SelectiveRenderingSPP 映射到磁盘
    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
}

void FSelectiveRenderingSPPModule::ShutdownModule() {}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
