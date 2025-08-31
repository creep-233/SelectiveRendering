using UnrealBuildTool;

public class SelectiveRenderingSPP : ModuleRules
{
    public SelectiveRenderingSPP(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_5; // ���� Upgrade ��ʾ

        PublicDependencyModuleNames.AddRange(new[]
        {
            "Core", "CoreUObject", "Engine",
            "RenderCore", "RHI", "Projects"      
        });

        PrivateDependencyModuleNames.AddRange(new[]
        {
            "Slate", "SlateCore"                
        });
    }
}
