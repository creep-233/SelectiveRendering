//using UnrealBuildTool;

//public class SelectiveRenderingSPP : ModuleRules
//{
//    public SelectiveRenderingSPP(ReadOnlyTargetRules Target) : base(Target)
//    {
//        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
//        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5; // 消掉 Upgrade 提示

//        PublicDependencyModuleNames.AddRange(new[]
//        {
//            "Core", "CoreUObject", "Engine",
//            "RenderCore", "RHI", "Projects", "Renderer"
//        });

//        PrivateDependencyModuleNames.AddRange(new[]
//        {
//            "Slate", "SlateCore"
//        });
//    }
//}

//// Plugins/SelectiveRenderingSPP/Source/SelectiveRenderingSPP/SelectiveRenderingSPP.Build.cs
//using UnrealBuildTool;
//using System.IO;

//public class SelectiveRenderingSPP : ModuleRules
//{
//    public SelectiveRenderingSPP(ReadOnlyTargetRules Target) : base(Target)
//    {
//        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
//        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;

//        // 公共依赖
//        PublicDependencyModuleNames.AddRange(new[] {
//            "Core", "CoreUObject", "Engine",
//            "RHI", "RenderCore", "Projects"
//        });

//        // 私有依赖：用到了 RDG/RenderGraphUtils，带上 Renderer 更保险
//        PrivateDependencyModuleNames.AddRange(new[] {
//            "Renderer"
//            // 如果你没有 Slate UI，就不要加 "Slate","SlateCore"
//        });

//        // 让 UE 能找到 /SelectiveRenderingSPP/SRComposite.usf
//        string pluginDir = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));
//        string shaderDir = Path.Combine(pluginDir, "Shaders");
//        if (Directory.Exists(shaderDir))
//        {
//            AdditionalShaderDirectories.Add(shaderDir);
//        }
//    }
//}



// Plugins/SelectiveRenderingSPP/Source/SelectiveRenderingSPP/SelectiveRenderingSPP.Build.cs
using UnrealBuildTool;

public class SelectiveRenderingSPP : ModuleRules
{
    public SelectiveRenderingSPP(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;

        PublicDependencyModuleNames.AddRange(new[] {
            "Core", "CoreUObject", "Engine",
            "RHI", "RenderCore"
        });

        // 用了 RDG/RenderGraphUtils 要 "Renderer"；要用 IPluginManager 则必须 "Projects"
        PrivateDependencyModuleNames.AddRange(new[] {
            "Renderer", "Projects"
        });
    }
}


