//#include "SelectiveRenderingSPP.h"          // Ϊ�� DEFINE_LOG_CATEGORY
//#include "Modules/ModuleManager.h"
//#include "Interfaces/IPluginManager.h"
//#include "ShaderCore.h"                     // AddShaderSourceDirectoryMapping
//
//DEFINE_LOG_CATEGORY(LogSPP);
//
//class FSelectiveRenderingSPPModule : public IModuleInterface
//{
//public:
//    virtual void StartupModule() override
//    {
//        // ӳ�� Shader ����Ŀ¼ -> ʵ��Ŀ¼
//        if (TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("SelectiveRenderingSPP")))
//        {
//            const FString ShaderDir = FPaths::Combine(Plugin->GetBaseDir(), TEXT("Shaders"));
//            AddShaderSourceDirectoryMapping(TEXT("/SelectiveRenderingSPP"), ShaderDir);
//            UE_LOG(LogSPP, Log, TEXT("SelectiveRenderingSPP mapped shaders at: %s"), *ShaderDir);
//        }
//    }
//    virtual void ShutdownModule() override {}
//};
//
//IMPLEMENT_MODULE(FSelectiveRenderingSPPModule, SelectiveRenderingSPP)
