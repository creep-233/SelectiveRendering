// Private/SelectiveRenderingSPPShaders.h
#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"

// 这些类型用于 Pass/接口声明，需要在头里可见
#include "RenderGraphBuilder.h"
#include "RenderGraphResources.h"
#include "RHIResources.h" // FTextureRHIRef
#include "RHICommandList.h" // FRHICommandListImmediate

// ====== 计算着色器类型声明（只声明，不实现）======
class FSelectiveCompositeCS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);
    SHADER_USE_PARAMETER_STRUCT(FSelectiveCompositeCS, FGlobalShader);

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FVector2f, OutputSize)
        SHADER_PARAMETER(float, Threshold)
        SHADER_PARAMETER(float, Boost)

        SHADER_PARAMETER_SAMPLER(SamplerState, LowTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, HighTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, SalTexSampler)

        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, LowTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, HighTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SalTex)
        SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, OutTex)
    END_SHADER_PARAMETER_STRUCT()

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }
};

// ====== 对外函数声明（实现放 .cpp）======
void AddSelectiveCompositePass(
    FRDGBuilder& GraphBuilder,
    FRDGTextureRef    OutTex,
    FRDGTextureRef    LowTex,
    FRDGTextureRef    HighTex,
    FRDGTextureRef    SalTex,
    float             Threshold,
    float             Boost);

void EnqueueSelectiveComposite(
    FRHICommandListImmediate& RHICmdList,
    const FTextureRHIRef& OutRHI,
    const FTextureRHIRef& LowRHI,
    const FTextureRHIRef& HighRHI,
    const FTextureRHIRef& SalRHI,
    float                     Threshold,
    float                     Boost);
