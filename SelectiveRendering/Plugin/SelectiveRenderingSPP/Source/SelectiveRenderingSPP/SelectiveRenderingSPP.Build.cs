//using UnrealBuildTool;

//public class SelectiveRenderingSPP : ModuleRules
//{
//    public SelectiveRenderingSPP(ReadOnlyTargetRules Target) : base(Target)
//    {
//        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
//        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5; // ���� Upgrade ��ʾ

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

//        // ��������
//        PublicDependencyModuleNames.AddRange(new[] {
//            "Core", "CoreUObject", "Engine",
//            "RHI", "RenderCore", "Projects"
//        });

//        // ˽���������õ��� RDG/RenderGraphUtils������ Renderer ������
//        PrivateDependencyModuleNames.AddRange(new[] {
//            "Renderer"
//            // �����û�� Slate UI���Ͳ�Ҫ�� "Slate","SlateCore"
//        });

//        // �� UE ���ҵ� /SelectiveRenderingSPP/SRComposite.usf
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

        // ���� RDG/RenderGraphUtils Ҫ "Renderer"��Ҫ�� IPluginManager ����� "Projects"
        PrivateDependencyModuleNames.AddRange(new[] {
            "Renderer", "Projects"
        });
    }
}


