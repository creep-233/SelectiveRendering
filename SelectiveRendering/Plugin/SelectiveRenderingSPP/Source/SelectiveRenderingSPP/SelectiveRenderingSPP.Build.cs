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

        // ���� RDG / RenderGraphUtils ����� Renderer
        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Renderer", "Slate", "SlateCore"
        });

        // �Ȳ�Ҫ���� PrivatePCHHeaderFile�������ٴΡ�ȫ��Ŀ���족
        // PrivatePCHHeaderFile = "...";  // �ȱ���
        // bUseUnity = true;              // ����Ĭ��
    }
}
