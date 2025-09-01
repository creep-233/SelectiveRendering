#include "SelectiveRenderingSPPShaders.h"
#include "SelectiveRenderingSPP.h"   

#include "GlobalShader.h"
#include "RenderGraphUtils.h"
#include "RHIStaticStates.h"

IMPLEMENT_GLOBAL_SHADER(FSelectiveCompositeCS,
    "/Plugin/SelectiveRenderingSPP/SRComposite.usf", "MainCS", SF_Compute);

// 把外部 RHI 纹理注册成 RDG 纹理
static FRDGTextureRef RegisterExtTex(FRDGBuilder& GraphBuilder, const FTextureRHIRef& In, const TCHAR* Name)
{
    check(In.IsValid());
    return GraphBuilder.RegisterExternalTexture(CreateRenderTarget(In, Name));
}

static bool EnsureCompositeCSReady()
{
    FGlobalShaderMap* GSM = GetGlobalShaderMap(GMaxRHIFeatureLevel);
    if (!GSM)
    {
        UE_LOG(LogTemp, Error, TEXT("[SPP] GlobalShaderMap is null."));
        return false;
    }

    // 直接用 TShaderMapRef 检查是否已编译/可用
    TShaderMapRef<FSelectiveCompositeCS> CS(GSM);
    if (!CS.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("[SPP] FSelectiveCompositeCS is not compiled or not registered."));
        return false;
    }
    return true;
}

static void AddSelectiveCompositePass(
    FRDGBuilder& GraphBuilder,
    FRDGTextureRef OutTex,
    FRDGTextureRef LowTex,
    FRDGTextureRef HighTex,
    FRDGTextureRef SalTex,
    float Threshold,
    float Boost)
{
    FSelectiveCompositeCS::FParameters* Params = GraphBuilder.AllocParameters<FSelectiveCompositeCS::FParameters>();
    Params->OutputSize = FVector2f(OutTex->Desc.Extent);
    Params->Threshold = Threshold;
    Params->Boost = Boost;

    Params->OutTex = GraphBuilder.CreateUAV(FRDGTextureUAVDesc(OutTex));
    Params->LowTex = LowTex;
    Params->HighTex = HighTex;
    Params->SalTex = SalTex;

    Params->LowTexSampler = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
    Params->HighTexSampler = TStaticSamplerState<SF_Trilinear, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();
    Params->SalTexSampler = TStaticSamplerState<SF_Point, AM_Clamp, AM_Clamp, AM_Clamp>::GetRHI();

    TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));

    const FIntPoint  Extent = OutTex->Desc.Extent;
    const FIntVector GroupCount(
        FMath::DivideAndRoundUp(Extent.X, 8),
        FMath::DivideAndRoundUp(Extent.Y, 8),
        1);

    FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("SelectiveComposite"), CS, Params, GroupCount);
}

//void EnqueueSelectiveComposite(
//    FRHICommandListImmediate& RHICmdList,
//    const FTextureRHIRef& OutRHI,
//    const FTextureRHIRef& LowRHI,
//    const FTextureRHIRef& HighRHI,
//    const FTextureRHIRef& SalRHI,
//    float Threshold,
//    float Boost)
//{
//    if (!EnsureCompositeCSReady())
//        return;
//
//    FRDGBuilder GraphBuilder(RHICmdList);
//
//    FRDGTextureRef OutTex = RegisterExtTex(GraphBuilder, OutRHI, TEXT("SRP_Out"));
//    FRDGTextureRef LowTex = RegisterExtTex(GraphBuilder, LowRHI, TEXT("SRP_Low"));
//    FRDGTextureRef HighTex = RegisterExtTex(GraphBuilder, HighRHI, TEXT("SRP_High"));
//    FRDGTextureRef SalTex = RegisterExtTex(GraphBuilder, SalRHI, TEXT("SRP_Sal"));
//
//    AddSelectiveCompositePass(GraphBuilder, OutTex, LowTex, HighTex, SalTex, Threshold, Boost);
//    GraphBuilder.Execute();
//}



//void EnqueueSelectiveComposite(
//    FRHICommandListImmediate& RHICmdList,
//    const FTextureRHIRef& OutRHI,
//    const FTextureRHIRef& LowRHI,
//    const FTextureRHIRef& HighRHI,
//    const FTextureRHIRef& SalRHI,
//    float Threshold,
//    float Boost)
//{
//    if (!EnsureCompositeCSReady())
//        return;
//
//    FRDGBuilder GraphBuilder(RHICmdList);
//
//    // 注册输入纹理（只读）
//    FRDGTextureRef LowTex = RegisterExtTex(GraphBuilder, LowRHI, TEXT("SRP_Low"));
//    FRDGTextureRef HighTex = RegisterExtTex(GraphBuilder, HighRHI, TEXT("SRP_High"));
//    FRDGTextureRef SalTex = RegisterExtTex(GraphBuilder, SalRHI, TEXT("SRP_Sal"));
//
//    // 目标尺寸用 OutRHI 的尺寸
//    const FIntPoint Extent = OutRHI->GetDesc().Extent;
//
//    // 1) 在 RDG 里创建“可写的中间纹理”（确保 UAV）
//    FRDGTextureDesc OutDesc = FRDGTextureDesc::Create2D(
//        Extent,
//        PF_FloatRGBA,                                      // UAV 友好
//        FClearValueBinding::None,
//        TexCreate_ShaderResource | TexCreate_UAV);         // 关键：含 UAV/SRV
//    FRDGTextureRef OutRDG = GraphBuilder.CreateTexture(OutDesc, TEXT("SRP_Out_RDG"));
//
//    // 2) 跑合成 pass —— 写 OutRDG（而不是外部 OutRHI）
//    AddSelectiveCompositePass(GraphBuilder, OutRDG, LowTex, HighTex, SalTex, Threshold, Boost);
//
//    // 3) 把 RDG 结果拷回外部 OutRHI
//    FRDGTextureRef OutExternal = RegisterExtTex(GraphBuilder, OutRHI, TEXT("SRP_OutExternal"));
//    AddCopyTexturePass(GraphBuilder, OutRDG, OutExternal);
//
//    GraphBuilder.Execute();
//}


void EnqueueSelectiveComposite(
    FRHICommandListImmediate& RHICmdList,
    const FTextureRHIRef& OutRHI,
    const FTextureRHIRef& LowRHI,
    const FTextureRHIRef& HighRHI,
    const FTextureRHIRef& SalRHI,
    float Threshold,
    float Boost)
{
    // 0) 全面防御：任何一个纹理没就绪，直接返回
    if (!OutRHI.IsValid() || !LowRHI.IsValid() || !HighRHI.IsValid() || !SalRHI.IsValid())
    {
        UE_LOG(LogSPP, Warning, TEXT("[SPP] Skip: some RHI invalid."));
        return;
    }

    // 1) 只要输出格式不是 RGBA16f，或者没 UAV 标志，直接返回（避免 RDG 里触发断言）
    const FRHITextureDesc& OutD = OutRHI->GetDesc();
    const bool bOutUAV = !!(OutD.Flags & TexCreate_UAV);
    const bool bFmtOK = (OutD.Format == PF_FloatRGBA);
    if (!bOutUAV || !bFmtOK)
    {
        UE_LOG(LogSPP, Warning, TEXT("[SPP] Skip composite: OutRHI not ready. Fmt=%d (need PF_FloatRGBA=%d), Flags=0x%x (need UAV)"),
            (int32)OutD.Format, (int32)PF_FloatRGBA, (uint32)OutD.Flags);
        return;
    }

    if (!EnsureCompositeCSReady())
        return;

    // ========= 下面是你原先的 RDG 路径 =========
    FRDGBuilder GraphBuilder(RHICmdList);

    FRDGTextureRef LowTex = RegisterExtTex(GraphBuilder, LowRHI, TEXT("SRP_Low"));
    FRDGTextureRef HighTex = RegisterExtTex(GraphBuilder, HighRHI, TEXT("SRP_High"));
    FRDGTextureRef SalTex = RegisterExtTex(GraphBuilder, SalRHI, TEXT("SRP_Sal"));

    const FIntPoint Extent = OutD.Extent;

    // 用中间 UAV 纹理做计算（确保 UAV）
    FRDGTextureDesc OutDesc = FRDGTextureDesc::Create2D(
        Extent, PF_FloatRGBA, FClearValueBinding::None,
        TexCreate_ShaderResource | TexCreate_UAV);
    FRDGTextureRef OutRDG = GraphBuilder.CreateTexture(OutDesc, TEXT("SRP_Out_RDG"));

    AddSelectiveCompositePass(GraphBuilder, OutRDG, LowTex, HighTex, SalTex, Threshold, Boost);

    // 只有当外部 OutRHI 与 OutRDG 格式一致时才做拷贝（现在我们已经在上面强制检查过是 PF_FloatRGBA）
    FRDGTextureRef OutExternal = RegisterExtTex(GraphBuilder, OutRHI, TEXT("SRP_OutExternal"));
    AddCopyTexturePass(GraphBuilder, OutRDG, OutExternal);

    GraphBuilder.Execute();
}


