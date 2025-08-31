// �����һ��
#include "SelectiveRenderingSPP.h"

#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"
#include "Modules/ModuleManager.h"
#include "HAL/FileManager.h"

static FString GetShaderDir()
{
    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"));
    // ����ļ����Ѹ���Ϊ ��Shaders��
    return FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
}

void FSelectiveRenderingSPPModule::StartupModule()
{
    const FString ShaderDir = GetShaderDir();

    // 1) �Ѵ���Ŀ¼ӳ�䵽����Ŀ¼
    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);

    // 2) ���������־������ں����ڲ���
    const bool bExists = IFileManager::Get().FileExists(*(ShaderDir / TEXT("SRComposite.usf")));
    UE_LOG(LogTemp, Display, TEXT("[SPP] ShaderDir=%s, SRComposite.usf exists=%d"),
        *ShaderDir, bExists ? 1 : 0);
}

void FSelectiveRenderingSPPModule::ShutdownModule()
{
    // һ����������
}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
