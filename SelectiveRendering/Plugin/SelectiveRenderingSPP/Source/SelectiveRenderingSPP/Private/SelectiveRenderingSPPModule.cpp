//#include "SelectiveRenderingSPP.h"          // 为了 DEFINE_LOG_CATEGORY
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
//        // 映射 Shader 虚拟目录 -> 实际目录
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
