#pragma once
#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterMacros.h"   // ★ 必须显式包含这个
#include "ShaderParameterStruct.h"

class FSelectiveCompositeCS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);
    SHADER_USE_PARAMETER_STRUCT(FSelectiveCompositeCS, FGlobalShader);

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FVector2f, OutputSize)
        SHADER_PARAMETER(float, Threshold)
        SHADER_PARAMETER(float, Boost)
        SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, OutTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, LowTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, HighTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SalTex)
        SHADER_PARAMETER_SAMPLER(SamplerState, LowTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, HighTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, SalTexSampler)
    END_SHADER_PARAMETER_STRUCT()

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }

    // ★ 不能留空！至少调用基类，确保参数结构绑定/宏定义被注入
    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Params,
        FShaderCompilerEnvironment& OutEnv)
    {
        FGlobalShader::ModifyCompilationEnvironment(Params, OutEnv);
    }
};
