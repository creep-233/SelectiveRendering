// Plugins/SelectiveRenderingSPP/Source/SelectiveRenderingSPP/Public/SelectiveRenderingSPPShaders.h
#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphResources.h"

class FSelectiveCompositeCS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);
    SHADER_USE_PARAMETER_STRUCT(FSelectiveCompositeCS, FGlobalShader);

    BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
        SHADER_PARAMETER(FVector2f, OutputSize)
        SHADER_PARAMETER(float, Threshold)
        SHADER_PARAMETER(float, Boost)

        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, LowTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, HighTex)
        SHADER_PARAMETER_RDG_TEXTURE(Texture2D, SalTex)

        SHADER_PARAMETER_SAMPLER(SamplerState, LowTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, HighTexSampler)
        SHADER_PARAMETER_SAMPLER(SamplerState, SalTexSampler)

        SHADER_PARAMETER_RDG_TEXTURE_UAV(RWTexture2D<float4>, OutTex)
    END_SHADER_PARAMETER_STRUCT()

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }
};
