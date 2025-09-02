#include "SelectiveRenderingSPPShaders.h"
#include "GlobalShader.h"
#include "RHI.h"
#include "RHIResources.h"
#include "RHICommandList.h"          // ← 必须：FRHICommandListImmediate / CreateUnorderedAccessView(…)
#include "PipelineStateCache.h"      // SetComputePipelineState
#include "Runtime/Launch/Resources/Version.h"


IMPLEMENT_GLOBAL_SHADER(FSelectiveCompositeCS,
    "/Plugin/SelectiveRenderingSPP/SRComposite.usf", "MainCS", SF_Compute);

// 对外入口
void EnqueueSelectiveComposite(
    FRHICommandListImmediate& RHICmdList,
    const FTextureRHIRef& OutRHI,
    const FTextureRHIRef& LowRHI,
    const FTextureRHIRef& HighRHI,
    const FTextureRHIRef& SalRHI,
    float Threshold,
    float Boost)
{
    if (!OutRHI.IsValid() || !LowRHI.IsValid() || !HighRHI.IsValid() || !SalRHI.IsValid())
        return;

    // 防止读写同图
    auto Same = [](const FTextureRHIRef& A, const FTextureRHIRef& B) { return A.IsValid() && (A == B); };
    if (Same(OutRHI, LowRHI) || Same(OutRHI, HighRHI) || Same(OutRHI, SalRHI))
        return;

    TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));
    if (!CS.IsValid()) return;

    const FIntPoint Extent = OutRHI->GetDesc().Extent;

    // 1) 状态转换
    RHICmdList.Transition({
        FRHITransitionInfo(LowRHI ,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
        FRHITransitionInfo(HighRHI,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
        FRHITransitionInfo(SalRHI ,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
        FRHITransitionInfo(OutRHI ,  ERHIAccess::Unknown, ERHIAccess::UAVCompute)
        });

    // 2) 创建 UAV（注意 UE 版本差异）
    // 
    //FUnorderedAccessViewRHIRef OutUAV;                  // ← 只在这里声明一次
    //FRHITexture* TextureRHI = OutRHI.GetReference();

    //auto UAVDesc = FRHIViewDesc::CreateTextureUAV()
    //    .SetDimensionFromTexture(TextureRHI)  // 与 OutRHI 维度一致
    //    .SetMipLevel(0);                      // 写入 mip 0

    //OutUAV = RHICmdList.CreateUnorderedAccessView(TextureRHI, UAVDesc); // ← 赋值，不要再写类型



    //FRHIViewDesc::FTextureUAV::FInitializer UAVDesc =
    //    FRHIViewDesc::CreateTextureUAV()
    //    .SetDimensionFromTexture(TextureRHI)   // 维度跟 OutRHI 一致
    //    .SetMipLevel(0);                       // 要写的 mip，一般是 0

    //OutUAV = RHICmdList.CreateUnorderedAccessView(TextureRHI, UAVDesc);

    FUnorderedAccessViewRHIRef OutUAV;
    FRHITexture* TextureRHI = OutRHI.GetReference();

    FRHIViewDesc::FTextureUAV::FInitializer UAVDesc =
        FRHIViewDesc::CreateTextureUAV()
        .SetDimensionFromTexture(TextureRHI)   // 跟 OutRHI 维度一致
        .SetMipLevel(0);                       // 写 mip 0

    OutUAV = RHICmdList.CreateUnorderedAccessView(TextureRHI, UAVDesc);




    // 3) 绑定 PSO
    FRHIComputeShader* ShaderRHI = CS.GetComputeShader();
    SetComputePipelineState(RHICmdList, ShaderRHI);

    // 4) 设置所有参数（批量接口）
    //CS->SetParameters(RHICmdList, ShaderRHI, Extent, Threshold, Boost, LowRHI, HighRHI, SalRHI, OutUAV.GetReference());
    // 采样器
    FRHISamplerState* LowS = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
    FRHISamplerState* HighS = LowS;
    FRHISamplerState* SalS = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();

    // 取 batched（注意是“引用”）
    FRHIBatchedShaderParameters& Batched = RHICmdList.GetScratchShaderParameters();

    // 调你的 batched 版本 SetParameters（传裸指针，不要传 TRef）
    CS->SetParameters(
        Batched,
        Extent, Threshold, Boost,
        LowRHI.GetReference(), LowS,
        HighRHI.GetReference(), HighS,
        SalRHI.GetReference(), SalS,
        OutUAV.GetReference()
    );

    // 一次性提交 batched
    RHICmdList.SetBatchedShaderParameters(ShaderRHI, Batched);



    // 5) 调度
    const uint32 GX = FMath::DivideAndRoundUp((uint32)Extent.X, 8u);
    const uint32 GY = FMath::DivideAndRoundUp((uint32)Extent.Y, 8u);
    RHICmdList.DispatchComputeShader(GX, GY, 1);

    // 6) 解绑 UAV，避免后续 PASS 报占用
    //CS->UnbindUAV(RHICmdList, ShaderRHI);
    // 6) Batched 解绑（需要时才做）
    if (RHICmdList.NeedsShaderUnbinds())
    {
        FRHIBatchedShaderUnbinds& Unbinds = RHICmdList.GetScratchShaderUnbinds();
        CS->UnsetParameters(Unbinds);
        RHICmdList.SetBatchedShaderUnbinds(ShaderRHI, Unbinds);
    }


    // 7) 若 OutRHI 后面要当 SRV 用，记得转回
    RHICmdList.Transition({ FRHITransitionInfo(OutRHI, ERHIAccess::UAVCompute, ERHIAccess::SRVMask) });
}
