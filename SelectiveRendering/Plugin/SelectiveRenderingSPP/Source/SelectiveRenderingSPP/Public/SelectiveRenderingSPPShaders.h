// Plugins/SelectiveRenderingSPP/Source/SelectiveRenderingSPP/Public/SelectiveRenderingSPPShaders.h
#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphResources.h"   // RDG 参数/资源
#include "RHICommandList.h"
#include "RHIResources.h"

class FSelectiveCompositeCS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);
    SHADER_USE_PARAMETER_STRUCT(FSelectiveCompositeCS, FGlobalShader);

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FVector2f, OutputSize)
        SHADER_PARAMETER(float, Threshold)
        SHADER_PARAMETER(float, Boost)

        //  全部改成 RDG 版
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, LowTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, HighTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SalTex)

        SHADER_PARAMETER_SAMPLER(SamplerState, LowTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, HighTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, SalTexSampler)

        SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D, OutTex) //  RDG UAV
    END_SHADER_PARAMETER_STRUCT()

    using FPermutationDomain = FShaderPermutationNone; // UE5.5 用这个类型名

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }
    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters&, FShaderCompilerEnvironment&) {}
};
