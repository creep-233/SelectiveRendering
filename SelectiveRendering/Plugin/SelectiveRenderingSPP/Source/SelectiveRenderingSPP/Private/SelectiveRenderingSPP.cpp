#include "SelectiveRenderingSPP.h"              // �����һ��
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"
#include "Modules/ModuleManager.h"

// ������Ŀ¼�С�Shader�������� Shaders�������� "Shader"
static FString GetShaderDir()
{
    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"));
    return FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shader")); // �� �����ʵ���ļ�������
}

void FSelectiveRenderingSPPModule::StartupModule()
{
    const FString ShaderDir = GetShaderDir();
    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
}

void FSelectiveRenderingSPPModule::ShutdownModule()
{
    // һ�㲻��Ҫ����ӳ��
}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
