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

    //TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));

    //const FIntPoint  Extent = OutTex->Desc.Extent;
    //const FIntVector GroupCount(
    //    FMath::DivideAndRoundUp(Extent.X, 8),
    //    FMath::DivideAndRoundUp(Extent.Y, 8),
    //    1);

    //FComputeShaderUtils::AddPass(GraphBuilder, RDG_EVENT_NAME("SelectiveComposite"), CS, Params, GroupCount);
    

    TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));

    const FIntPoint  Extent = OutTex->Desc.Extent;
    const FIntVector GroupCount(
        FMath::DivideAndRoundUp(Extent.X, 8),
        FMath::DivideAndRoundUp(Extent.Y, 8),
        1);

    // 关键：让未使用的参数从反射里清理掉，避免“未绑定 UBO/未声明参数”误报
    ClearUnusedGraphResources(CS, Params);

    // 可选日志，方便确认真的在调度
    UE_LOG(LogTemp, Log, TEXT("[SPP] Dispatch SelectiveComposite %dx%d"), Extent.X, Extent.Y);


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
    // 0) 基本有效性
    if (!OutRHI.IsValid() || !LowRHI.IsValid() || !HighRHI.IsValid() || !SalRHI.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("[SPP] Skip: some RHI invalid."));
        return;
    }

    // 1) ★ 防读写同图（把 Out 当作输入会在 Dispatch 时崩）
    auto Same = [](const FTextureRHIRef& A, const FTextureRHIRef& B) { return A.IsValid() && (A == B); };
    if (Same(OutRHI, LowRHI) || Same(OutRHI, HighRHI) || Same(OutRHI, SalRHI))
    {
        UE_LOG(LogTemp, Error, TEXT("[SPP] OutRHI must NOT equal any input (Low/High/Sal)."));
        return;
    }

    // 2) OutRHI 只检查格式（我们用中间 RDG + Copy，外部不要求 UAV）
    const FRHITextureDesc& OutD = OutRHI->GetDesc();
    if (OutD.Format != PF_FloatRGBA)
    {
        UE_LOG(LogTemp, Warning, TEXT("[SPP] Skip: OutRHI format=%d (needs PF_FloatRGBA=%d for CopyTexture)."),
            (int32)OutD.Format, (int32)PF_FloatRGBA);
        return;
    }

    if (!EnsureCompositeCSReady())
        return;

    // ========= RDG 路径 =========
    FRDGBuilder GraphBuilder(RHICmdList);

    // 输入注册（SRV）
    FRDGTextureRef LowTex = RegisterExtTex(GraphBuilder, LowRHI, TEXT("SRP_Low"));
    FRDGTextureRef HighTex = RegisterExtTex(GraphBuilder, HighRHI, TEXT("SRP_High"));
    FRDGTextureRef SalTex = RegisterExtTex(GraphBuilder, SalRHI, TEXT("SRP_Sal"));

    const FIntPoint Extent = OutD.Extent;

    // 中间可写纹理（UAV）
    FRDGTextureDesc OutDesc = FRDGTextureDesc::Create2D(
        Extent, PF_FloatRGBA, FClearValueBinding::None,
        TexCreate_ShaderResource | TexCreate_UAV);
    FRDGTextureRef OutRDG = GraphBuilder.CreateTexture(OutDesc, TEXT("SRP_Out_RDG"));

    // 合成（会在 AddSelectiveCompositePass 内做 ClearUnusedGraphResources + 日志）
    AddSelectiveCompositePass(GraphBuilder, OutRDG, LowTex, HighTex, SalTex, Threshold, Boost);

    // 拷回外部（同格式）
    FRDGTextureRef OutExternal = RegisterExtTex(GraphBuilder, OutRHI, TEXT("SRP_OutExternal"));
    AddCopyTexturePass(GraphBuilder, OutRDG, OutExternal);

    GraphBuilder.Execute();
}



