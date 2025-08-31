// 必须第一行
#include "SelectiveRenderingSPP.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"
#include "Modules/ModuleManager.h"
#include "HAL/FileManager.h"

static FString GetShaderDir()
{
    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"));
    // 你的文件夹已改名为 “Shaders”
    return FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
}

void FSelectiveRenderingSPPModule::StartupModule()
{
    const FString ShaderDir = GetShaderDir();

    // 1) 把磁盘目录映射到虚拟目录
    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);

    // 2) 在这里打日志（务必在函数内部）
    const bool bExists = IFileManager::Get().FileExists(*(ShaderDir / TEXT("SRComposite.usf")));
    UE_LOG(LogTemp, Display, TEXT("[SPP] ShaderDir=%s, SRComposite.usf exists=%d"),
        *ShaderDir, bExists ? 1 : 0);
}

void FSelectiveRenderingSPPModule::ShutdownModule()
{
    // 一般无需清理
}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
