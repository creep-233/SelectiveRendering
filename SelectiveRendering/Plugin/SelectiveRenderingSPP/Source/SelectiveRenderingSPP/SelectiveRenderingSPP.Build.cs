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

using UnrealBuildTool;

public class SelectiveRenderingSPP : ModuleRules
{
    public SelectiveRenderingSPP(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5;

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine",
            "RHI", "RenderCore", "Projects"
        });

        // 用了 RDG / RenderGraphUtils 必须加 Renderer
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Renderer", "Slate", "SlateCore"
        });

        // 先不要配置 PrivatePCHHeaderFile，避免再次“全项目爆红”
        // PrivatePCHHeaderFile = "...";  // 先别用
        // bUseUnity = true;              // 保持默认
    }
}
