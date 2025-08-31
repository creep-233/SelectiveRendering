#include "SelectiveRenderingSPP.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"

// UE5.5 ���Կɰ��� ShaderCore.h��ͷ�ļ������� Build.cs �ﲻҪ���� ShaderCore ģ�飻RenderCore �㹻
#include "ShaderCore.h"

void FSelectiveRenderingSPPModule::StartupModule()
{
    const FString BaseDir = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP"))->GetBaseDir();
    const FString ShaderDir = FPaths::Combine(BaseDir, TEXT("Shaders")); // Ŀ¼�������� Shaders

    // ������·�� /SelectiveRenderingSPP ӳ�䵽����
    AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
}

void FSelectiveRenderingSPPModule::ShutdownModule() {}

IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
