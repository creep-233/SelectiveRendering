//#include "SelectiveRenderingSPPShaders.h"
//#include "CoreMinimal.h"  
//#include "GlobalShader.h"
//#include "RHI.h"
//#include "RHIResources.h"
//#include "RHICommandList.h"
//#include "PipelineStateCache.h"
//#include "Runtime/Launch/Resources/Version.h"
//#include "SelectiveRenderingSPP.h" 
//#include "ShaderParameterStruct.h"
//#include "ShaderParameterUtils.h" 
//
//
//IMPLEMENT_GLOBAL_SHADER(FSelectiveCompositeCS,
//    "/Plugin/SelectiveRenderingSPP/SRComposite.usf", "MainCS", SF_Compute);
//
//IMPLEMENT_GLOBAL_SHADER_PARAMETER_STRUCT(FCompositeCB, "CompositeCB");
//
//// 对外入口
//void EnqueueSelectiveComposite(
//    FRHICommandListImmediate& RHICmdList,
//    const FTextureRHIRef& OutRHI,
//    const FTextureRHIRef& LowRHI,
//    const FTextureRHIRef& HighRHI,
//    const FTextureRHIRef& SalRHI,
//    float Threshold,
//    float Boost)
//{
//    if (!OutRHI.IsValid() || !LowRHI.IsValid() || !HighRHI.IsValid() || !SalRHI.IsValid())
//        return;
//
//    auto Same = [](const FTextureRHIRef& A, const FTextureRHIRef& B) { return A.IsValid() && A == B; };
//    if (Same(OutRHI, LowRHI) || Same(OutRHI, HighRHI) || Same(OutRHI, SalRHI))
//        return;
//
//    TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));
//    if (!CS.IsValid()) return;
//
//    const FIntPoint Extent = OutRHI->GetDesc().Extent;
//
//    // 1) 状态转换：输入→SRV，输出→UAV
//    RHICmdList.Transition({
//        FRHITransitionInfo(LowRHI ,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
//        FRHITransitionInfo(HighRHI,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
//        FRHITransitionInfo(SalRHI ,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
//        FRHITransitionInfo(OutRHI ,  ERHIAccess::Unknown, ERHIAccess::UAVCompute)
//        });
//
//    // 2) 创建 UAV
//    FRHITexture* TextureRHI = OutRHI.GetReference();
//    const FRHITextureDesc& OutDesc = TextureRHI->GetDesc();
//    if (!EnumHasAnyFlags(OutDesc.Flags, TexCreate_UAV))
//    {
//        UE_LOG(LogTemp, Error, TEXT("[SelectiveSPP] OutRHI missing TexCreate_UAV flag!"));
//        return;
//    }
//
//    FRHIViewDesc::FTextureUAV::FInitializer UAVDesc =
//        FRHIViewDesc::CreateTextureUAV()
//        .SetDimensionFromTexture(TextureRHI)
//        .SetMipLevel(0);
//
//    FUnorderedAccessViewRHIRef OutUAV = RHICmdList.CreateUnorderedAccessView(TextureRHI, UAVDesc);
//    if (!OutUAV.IsValid())
//    {
//        UE_LOG(LogTemp, Error, TEXT("[SelectiveSPP] CreateUnorderedAccessView failed."));
//        return;
//    }
//
//    // 3) 绑定 PSO
//    FRHIComputeShader* ShaderRHI = CS.GetComputeShader();
//    SetComputePipelineState(RHICmdList, ShaderRHI);
//
//
//    FCompositeCB CB;
//    CB.OutputSize = FVector2f(Extent);     // (SizeX, SizeY)
//    CB.Threshold = Threshold;
//    CB.Boost = Boost;
//
//    // 立刻创建一个只用于这次 Draw/Dispatch 的 UBO
//    TUniformBufferRef<FCompositeCB> CBRef =
//        TUniformBufferRef<FCompositeCB>::CreateUniformBufferImmediate(CB, UniformBuffer_SingleDraw);
//
//    // 绑定到 Compute Shader 的（slot0）uniform buffer
//    SetUniformBufferParameter(
//        RHICmdList,                         // 提交到 RHICmdList
//        ShaderRHI,                          // 目标 Shader
//        GetUniformBufferParameter<FCompositeCB>(),  // 参数（会定位到 slot0）
//        CBRef                               // 我们刚创建的 UBO
//    );
//
//
//    UE_LOG(LogSPP, Warning, TEXT("[SPP] Enqueue: Out=%p Low=%p High=%p Mask=%p"),
//        OutRHI.GetReference(), LowRHI.GetReference(),
//        HighRHI.GetReference(), SalRHI.GetReference());
//
//
//    // —— 只调用公开的调试接口；不要直接访问 private 成员 ——
//    CS->DebugLogBindings();
//    CS->DebugEnsureBindings();
//
//    // 4) batched 设置所有参数并一次性提交
//    FRHISamplerState* LowS = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
//    FRHISamplerState* HighS = LowS;
//    FRHISamplerState* SalS = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
//
//    FRHIBatchedShaderParameters& Batched = RHICmdList.GetScratchShaderParameters();
//    CS->SetParameters(
//        Batched,
//        Extent, Threshold, Boost,
//        LowRHI.GetReference(), LowS,
//        HighRHI.GetReference(), HighS,
//        SalRHI.GetReference(), SalS,
//        OutUAV.GetReference()
//    );
//    RHICmdList.SetBatchedShaderParameters(ShaderRHI, Batched);
//
//    // 5) Dispatch
//    const uint32 GX = FMath::DivideAndRoundUp((uint32)Extent.X, 8u);
//    const uint32 GY = FMath::DivideAndRoundUp((uint32)Extent.Y, 8u);
//    RHICmdList.DispatchComputeShader(GX, GY, 1);
//
//    // 6) batched 解绑（需要时才做）
//    if (RHICmdList.NeedsShaderUnbinds())
//    {
//        FRHIBatchedShaderUnbinds& Unbinds = RHICmdList.GetScratchShaderUnbinds();
//        CS->UnsetParameters(Unbinds);
//        RHICmdList.SetBatchedShaderUnbinds(ShaderRHI, Unbinds);
//    }
//
//    // 7) 如后续要把 OutRHI 当 SRV 用，转回去
//    RHICmdList.Transition({ FRHITransitionInfo(OutRHI, ERHIAccess::UAVCompute, ERHIAccess::SRVMask) });
//}
//
//// ===== 这两个函数的“类外实现”，一定要放在任何函数体之外！ =====
//void FSelectiveCompositeCS::DebugLogBindings() const
//{
//    UE_LOG(LogTemp, Warning,
//        TEXT("[SRComposite] IsBound Low=%d High=%d Sal=%d Out=%d | BaseIndex Low=%d High=%d Sal=%d Out=%d"),
//        LowTexParam.IsBound() ? 1 : 0,
//        HighTexParam.IsBound() ? 1 : 0,
//        SalTexParam.IsBound() ? 1 : 0,
//        OutTexParam.IsBound() ? 1 : 0,
//        LowTexParam.GetBaseIndex(),
//        HighTexParam.GetBaseIndex(),
//        SalTexParam.GetBaseIndex(),
//        OutTexParam.GetBaseIndex());
//}
//
//void FSelectiveCompositeCS::DebugEnsureBindings() const
//{
//    ensureMsgf(LowTexParam.IsBound(), TEXT("LowTex not bound in shader!"));
//    ensureMsgf(HighTexParam.IsBound(), TEXT("HighTex not bound in shader!"));
//    ensureMsgf(SalTexParam.IsBound(), TEXT("SalTex not bound in shader!"));
//    ensureMsgf(OutTexParam.IsBound(), TEXT("OutTex (UAV) not bound in shader!"));
//}



#include "SelectiveRenderingSPPShaders.h"
#include "SelectiveRenderingSPP.h"

#include "GlobalShader.h"
#include "ShaderParameterUtils.h"
#include "RHI.h"
#include "RHIResources.h"
#include "RHICommandList.h"
#include "PipelineStateCache.h"

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
    {
        UE_LOG(LogSPP, Error, TEXT("[SPP] Some input RHI invalid."));
        return;
    }
    auto Same = [](const FTextureRHIRef& A, const FTextureRHIRef& B) { return A.IsValid() && A == B; };
    if (Same(OutRHI, LowRHI) || Same(OutRHI, HighRHI) || Same(OutRHI, SalRHI))
    {
        UE_LOG(LogSPP, Error, TEXT("[SPP] Out must be different texture."));
        return;
    }

    TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));
    if (!CS.IsValid())
    {
        UE_LOG(LogSPP, Error, TEXT("[SPP] Shader map invalid."));
        return;
    }

    const FIntPoint Extent = OutRHI->GetDesc().Extent;

    // 1) Barrier
    RHICmdList.Transition({
        FRHITransitionInfo(LowRHI ,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
        FRHITransitionInfo(HighRHI,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
        FRHITransitionInfo(SalRHI ,  ERHIAccess::Unknown, ERHIAccess::SRVMask),
        FRHITransitionInfo(OutRHI ,  ERHIAccess::Unknown, ERHIAccess::UAVCompute)
        });

    // 2) 确保 Out 有 UAV
    FRHITexture* TextureRHI = OutRHI.GetReference();
    const FRHITextureDesc& OutDesc = TextureRHI->GetDesc();
    if (!EnumHasAnyFlags(OutDesc.Flags, TexCreate_UAV))
    {
        UE_LOG(LogSPP, Error, TEXT("[SPP] OutRHI missing TexCreate_UAV!"));
        return;
    }
    FRHIViewDesc::FTextureUAV::FInitializer UAVDesc =
        FRHIViewDesc::CreateTextureUAV()
        .SetDimensionFromTexture(TextureRHI)
        .SetMipLevel(0);
    FUnorderedAccessViewRHIRef OutUAV = RHICmdList.CreateUnorderedAccessView(TextureRHI, UAVDesc);
    if (!OutUAV.IsValid())
    {
        UE_LOG(LogSPP, Error, TEXT("[SPP] CreateUnorderedAccessView failed."));
        return;
    }

    // 3) PSO
    FRHIComputeShader* ShaderRHI = CS.GetComputeShader();
    SetComputePipelineState(RHICmdList, ShaderRHI);

    // 4) batched 设置所有参数
    FRHISamplerState* LowS = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
    FRHISamplerState* HighS = LowS;
    FRHISamplerState* SalS = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();

    FRHIBatchedShaderParameters& Batched = RHICmdList.GetScratchShaderParameters();
    CS->SetParameters(
        Batched,
        Extent, Threshold, Boost,
        LowRHI.GetReference(), LowS,
        HighRHI.GetReference(), HighS,
        SalRHI.GetReference(), SalS,
        OutUAV.GetReference()
    );
    RHICmdList.SetBatchedShaderParameters(ShaderRHI, Batched);

    CS->DebugLogBindings();
    CS->DebugEnsureBindings();

    // 5) Dispatch
    const uint32 GX = FMath::DivideAndRoundUp((uint32)Extent.X, 8u);
    const uint32 GY = FMath::DivideAndRoundUp((uint32)Extent.Y, 8u);
    RHICmdList.DispatchComputeShader(GX, GY, 1);

    // 6) 可选解绑
    if (RHICmdList.NeedsShaderUnbinds())
    {
        FRHIBatchedShaderUnbinds& Unbinds = RHICmdList.GetScratchShaderUnbinds();
        CS->UnsetParameters(Unbinds);
        RHICmdList.SetBatchedShaderUnbinds(ShaderRHI, Unbinds);
    }

    // 7) 如果后续立刻把 Out 当 SRV 用
    RHICmdList.Transition({ FRHITransitionInfo(OutRHI, ERHIAccess::UAVCompute, ERHIAccess::SRVMask) });
}

// ----- 调试输出 -----
void FSelectiveCompositeCS::DebugLogBindings() const
{
    UE_LOG(LogSPP, Warning,
        TEXT("[SRComposite] IsBound Low=%d High=%d Sal=%d Out=%d | BaseIndex Low=%d High=%d Sal=%d Out=%d"),
        LowTexParam.IsBound() ? 1 : 0,
        HighTexParam.IsBound() ? 1 : 0,
        SalTexParam.IsBound() ? 1 : 0,
        OutTexParam.IsBound() ? 1 : 0,
        LowTexParam.GetBaseIndex(),
        HighTexParam.GetBaseIndex(),
        SalTexParam.GetBaseIndex(),
        OutTexParam.GetBaseIndex());
}
void FSelectiveCompositeCS::DebugEnsureBindings() const
{
    ensureMsgf(LowTexParam.IsBound(), TEXT("LowTex not bound in shader!"));
    ensureMsgf(HighTexParam.IsBound(), TEXT("HighTex not bound in shader!"));
    ensureMsgf(SalTexParam.IsBound(), TEXT("SalTex not bound in shader!"));
    ensureMsgf(OutTexParam.IsBound(), TEXT("OutTex (UAV) not bound in shader!"));
}
