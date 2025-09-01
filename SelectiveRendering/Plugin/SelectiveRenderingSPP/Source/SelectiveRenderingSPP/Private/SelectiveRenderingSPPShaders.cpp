#include "SelectiveRenderingSPPShaders.h"
#include "RenderGraphUtils.h"
#include "RHIStaticStates.h"
#include "ShaderCompilerCore.h"

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
    TShaderMapRef<FSelectiveCompositeCS> CS(GetGlobalShaderMap(GMaxRHIFeatureLevel));
    if (!CS.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("[SPP] FSelectiveCompositeCS NOT in GlobalShaderMap. Check mapping and SRComposite.usf path."));
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

    // ✅ 与 FParameters 一致：RDG UAV / RDG SRV
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

void EnqueueSelectiveComposite(
    FRHICommandListImmediate& RHICmdList,
    const FTextureRHIRef& OutRHI,
    const FTextureRHIRef& LowRHI,
    const FTextureRHIRef& HighRHI,
    const FTextureRHIRef& SalRHI,
    float Threshold,
    float Boost)
{
    if (!EnsureCompositeCSReady())
        return;

    FRDGBuilder GraphBuilder(RHICmdList);

    FRDGTextureRef OutTex = RegisterExtTex(GraphBuilder, OutRHI, TEXT("SRP_Out"));
    FRDGTextureRef LowTex = RegisterExtTex(GraphBuilder, LowRHI, TEXT("SRP_Low"));
    FRDGTextureRef HighTex = RegisterExtTex(GraphBuilder, HighRHI, TEXT("SRP_High"));
    FRDGTextureRef SalTex = RegisterExtTex(GraphBuilder, SalRHI, TEXT("SRP_Sal"));

    AddSelectiveCompositePass(GraphBuilder, OutTex, LowTex, HighTex, SalTex, Threshold, Boost);
    GraphBuilder.Execute();
}
