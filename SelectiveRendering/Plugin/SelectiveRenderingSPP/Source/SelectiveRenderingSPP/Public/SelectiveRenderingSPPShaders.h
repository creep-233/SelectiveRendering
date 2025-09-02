#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"
#include "RHIStaticStates.h"
#include "RHICommandList.h" // FRHIBatchedShaderParameters / Unbinds

class FSelectiveCompositeCS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);

    FSelectiveCompositeCS() {}
    FSelectiveCompositeCS(const ShaderMetaType::CompiledShaderInitializerType& Init)
        : FGlobalShader(Init)
    {
        // cbuffer 字段绑定 —— 名称要和 USF 的字段名一致
        OutputSizeParam.Bind(Init.ParameterMap, TEXT("OutputSize"));
        ThresholdParam.Bind(Init.ParameterMap, TEXT("Threshold"));
        BoostParam.Bind(Init.ParameterMap, TEXT("Boost"));

        // 资源/采样器 —— 名称与 USF 一致
        OutTexParam.Bind(Init.ParameterMap, TEXT("OutTex"));

        LowTexParam.Bind(Init.ParameterMap, TEXT("LowTex"));
        HighTexParam.Bind(Init.ParameterMap, TEXT("HighTex"));
        SalTexParam.Bind(Init.ParameterMap, TEXT("SalTex"));

        LowSamplerParam.Bind(Init.ParameterMap, TEXT("LowTexSampler"));
        HighSamplerParam.Bind(Init.ParameterMap, TEXT("HighTexSampler"));
        SalSamplerParam.Bind(Init.ParameterMap, TEXT("SalTexSampler"));
    }

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Params, FShaderCompilerEnvironment& OutEnv)
    {
        FGlobalShader::ModifyCompilationEnvironment(Params, OutEnv);
        OutEnv.SetDefine(TEXT("THREADGROUP_SIZE_X"), 8);
        OutEnv.SetDefine(TEXT("THREADGROUP_SIZE_Y"), 8);
    }

    // —— batched「绑定」：一次把所有参数写到 Batched 里 —— //
    void SetParameters(
        FRHIBatchedShaderParameters& Batched,
        FIntPoint OutExtent,
        float Threshold, float Boost,
        FRHITexture* LowTex, FRHISamplerState* LowSamp,
        FRHITexture* HighTex, FRHISamplerState* HighSamp,
        FRHITexture* SalTex, FRHISamplerState* SalSamp,
        FRHIUnorderedAccessView* OutUAV) const
    {
        SetShaderValue(Batched, OutputSizeParam, FVector2f(OutExtent));
        SetShaderValue(Batched, ThresholdParam, Threshold);
        SetShaderValue(Batched, BoostParam, Boost);

        SetTextureParameter(Batched, LowTexParam, LowSamplerParam, LowSamp, LowTex);
        SetTextureParameter(Batched, HighTexParam, HighSamplerParam, HighSamp, HighTex);
        SetTextureParameter(Batched, SalTexParam, SalSamplerParam, SalSamp, SalTex);

        SetUAVParameter(Batched, OutTexParam, OutUAV);
    }

    // —— batched「解绑」：只清掉我们自己设过的资源 —— //
    void UnsetParameters(FRHIBatchedShaderUnbinds& Unbinds) const
    {
        UnsetUAVParameter(Unbinds, OutTexParam);
        UnsetSRVParameter(Unbinds, LowTexParam);
        UnsetSRVParameter(Unbinds, HighTexParam);
        UnsetSRVParameter(Unbinds, SalTexParam);
    }

    void DebugLogBindings() const;      // 只打印绑定情况
    void DebugEnsureBindings() const;   // 触发 ensure，谁没绑会直接提示


private:
    // cbuffer 成员
    FShaderParameter OutputSizeParam;
    FShaderParameter ThresholdParam;
    FShaderParameter BoostParam;

    // 纹理/采样器/UAV
    FShaderResourceParameter OutTexParam;

    FShaderResourceParameter LowTexParam;
    FShaderResourceParameter HighTexParam;
    FShaderResourceParameter SalTexParam;

    FShaderResourceParameter LowSamplerParam;
    FShaderResourceParameter HighSamplerParam;
    FShaderResourceParameter SalSamplerParam;
};
