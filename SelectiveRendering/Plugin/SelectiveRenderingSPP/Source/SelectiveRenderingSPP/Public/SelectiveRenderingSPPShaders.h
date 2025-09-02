#pragma once

#include "CoreMinimal.h"
#include "GlobalShader.h"
#include "ShaderParameterUtils.h"    // SetShaderValue / SetTextureParameter / SetUAVParameter
#include "RHIStaticStates.h"
#include "RHICommandList.h"  // 声明 FRHIBatchedShaderParameters / GetScratchShaderParameters


class FSelectiveCompositeCS : public FGlobalShader
{
public:
    DECLARE_GLOBAL_SHADER(FSelectiveCompositeCS);

    FSelectiveCompositeCS() {}
    FSelectiveCompositeCS(const ShaderMetaType::CompiledShaderInitializerType& Init)
        : FGlobalShader(Init)
    {
        // cbuffer 成员
        OutputSizeParam.Bind(Init.ParameterMap, TEXT("OutputSize"));
        ThresholdParam.Bind(Init.ParameterMap, TEXT("Threshold"));
        BoostParam.Bind(Init.ParameterMap, TEXT("Boost"));

        // 资源 / 采样器
        OutTexParam.Bind(Init.ParameterMap, TEXT("OutTex"));

        LowTexParam.Bind(Init.ParameterMap, TEXT("LowTex"));
        HighTexParam.Bind(Init.ParameterMap, TEXT("HighTex"));
        SalTexParam.Bind(Init.ParameterMap, TEXT("SalTex"));

        LowSamplerParam.Bind(Init.ParameterMap, TEXT("LowTexSampler"));
        HighSamplerParam.Bind(Init.ParameterMap, TEXT("HighTexSampler"));
        SalSamplerParam.Bind(Init.ParameterMap, TEXT("SalTexSampler"));
    }

    static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters&) { return true; }

    static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Params,
        FShaderCompilerEnvironment& OutEnv)
    {
        FGlobalShader::ModifyCompilationEnvironment(Params, OutEnv);
        OutEnv.SetDefine(TEXT("THREADGROUP_SIZE_X"), 8);
        OutEnv.SetDefine(TEXT("THREADGROUP_SIZE_Y"), 8);
    }

    // —— 用“批量参数”一次性提交（避免所有重载不匹配问题） ——
    //void SetParameters(
    //    FRHICommandList& RHICmdList,
    //    FRHIComputeShader* ShaderRHI,
    //    FIntPoint OutExtent,
    //    float Threshold, float Boost,
    //    const FTextureRHIRef& LowTex,
    //    const FTextureRHIRef& HighTex,
    //    const FTextureRHIRef& SalTex,
    //    FRHIUnorderedAccessView* OutUAV) const
    //{
    //    FRHIBatchedShaderParameters& Batched = RHICmdList.GetScratchShaderParameters();

    //    SetShaderValue(Batched, OutputSizeParam, FVector2f(OutExtent));
    //    SetShaderValue(Batched, ThresholdParam, Threshold);
    //    SetShaderValue(Batched, BoostParam, Boost);

    //    SetTextureParameter(
    //        Batched, ShaderRHI, LowTexParam, LowSamplerParam,
    //        TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), LowTex);

    //    SetTextureParameter(
    //        Batched, ShaderRHI, HighTexParam, HighSamplerParam,
    //        TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), HighTex);

    //    SetTextureParameter(
    //        Batched, ShaderRHI, SalTexParam, SalSamplerParam,
    //        TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI(), SalTex);

    //    // ！！！UE5.3+ 批量接口是 3 个参数（不要把 ShaderRHI 传进来）
    //    SetUAVParameter(Batched, OutTexParam, OutUAV);

    //    RHICmdList.SetBatchedShaderParameters(ShaderRHI, Batched);
    //}

// 绑定 / 设置所有参数（batched）
    void SetParameters(
        FRHIBatchedShaderParameters& Batched,
        FIntPoint OutExtent,
        float Threshold, float Boost,
        FRHITexture* LowTex, FRHISamplerState* LowSamp,
        FRHITexture* HighTex, FRHISamplerState* HighSamp,
        FRHITexture* SalTex, FRHISamplerState* SalSamp,
        FRHIUnorderedAccessView* OutUAV) const
    {
        // cbuffer 标量
        SetShaderValue(Batched, OutputSizeParam, FVector2f(OutExtent));
        SetShaderValue(Batched, ThresholdParam, Threshold);
        SetShaderValue(Batched, BoostParam, Boost);

        // 纹理 + 采样器
        SetTextureParameter(Batched, LowTexParam, LowSamplerParam, LowSamp, LowTex);
        SetTextureParameter(Batched, HighTexParam, HighSamplerParam, HighSamp, HighTex);
        SetTextureParameter(Batched, SalTexParam, SalSamplerParam, SalSamp, SalTex);

        // UAV（3 参）
        SetUAVParameter(Batched, OutTexParam, OutUAV);
    }

    // 解绑（仅做必须的清理）
    void UnsetParameters(FRHIBatchedShaderUnbinds& Unbinds) const
    {
        UnsetUAVParameter(Unbinds, OutTexParam);
        UnsetSRVParameter(Unbinds, LowTexParam);
        UnsetSRVParameter(Unbinds, HighTexParam);
        UnsetSRVParameter(Unbinds, SalTexParam);
    }



    //void UnbindUAV(FRHICommandList& RHICmdList, FRHIComputeShader* ShaderRHI) const
    //{
    //    FRHIBatchedShaderParameters& Batched = RHICmdList.GetScratchShaderParameters();
    //    SetUAVParameter(Batched, OutTexParam, nullptr);
    //    RHICmdList.SetBatchedShaderParameters(ShaderRHI, Batched);
    //}



private:
    // === cbuffer 成员 ===
    FShaderParameter OutputSizeParam;
    FShaderParameter ThresholdParam;
    FShaderParameter BoostParam;

    // === 资源与采样器 ===
    FShaderResourceParameter OutTexParam;

    FShaderResourceParameter LowTexParam;
    FShaderResourceParameter HighTexParam;
    FShaderResourceParameter SalTexParam;

    FShaderResourceParameter LowSamplerParam;
    FShaderResourceParameter HighSamplerParam;
    FShaderResourceParameter SalSamplerParam;
};
