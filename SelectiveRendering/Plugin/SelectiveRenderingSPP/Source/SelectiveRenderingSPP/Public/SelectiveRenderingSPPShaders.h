#pragma once
#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

/** 计算着色器 */
class FSelectiveCompositeCS : public FGlobalShader
{
public:
    // 这两个宏一定要有：它们会声明/定义 StaticType 等信息
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);
    SHADER_USE_PARAMETER_STRUCT(FSelectiveCompositeCS, FGlobalShader);

    // 参数必须和 .usf 里 cbuffer/资源名字一一对应
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

    // 编译条件（最简单先全平台返回 true）
    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Params)
    {
        return true;
    }
    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Params,
        FShaderCompilerEnvironment& OutEnv)
    {
        // 可留空
    }
};
