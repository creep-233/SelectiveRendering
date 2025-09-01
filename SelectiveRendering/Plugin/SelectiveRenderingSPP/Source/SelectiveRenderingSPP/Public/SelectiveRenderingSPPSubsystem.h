#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SelectiveRenderingSPPSubsystem.generated.h"

class UTextureRenderTarget2D;

UCLASS(BlueprintType)
class SELECTIVERENDERINGSPP_API USelectiveRenderingSPPSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "SelectiveRenderingSPP")
    void SRSPP_SetTargets(UTextureRenderTarget2D* Out,
        UTextureRenderTarget2D* Low,
        UTextureRenderTarget2D* High,
        UTextureRenderTarget2D* Mask);

    UFUNCTION(BlueprintCallable, Category = "SelectiveRenderingSPP")
    void SRSPP_SetParams(float InThreshold, float InBoost);

    UFUNCTION(BlueprintCallable, Category = "SelectiveRenderingSPP")
    void SRSPP_CompositeNow();

    FORCEINLINE UTextureRenderTarget2D* GetOutRT()  const { return OutRT.Get(); }
    FORCEINLINE UTextureRenderTarget2D* GetLowRT()  const { return LowRT.Get(); }
    FORCEINLINE UTextureRenderTarget2D* GetHighRT() const { return HighRT.Get(); }
    FORCEINLINE UTextureRenderTarget2D* GetMaskRT() const { return MaskRT.Get(); }
    FORCEINLINE bool  IsEnabled() const { return OutRT.IsValid() && LowRT.IsValid() && HighRT.IsValid() && MaskRT.IsValid(); }
    FORCEINLINE float GetThreshold() const { return Threshold; }
    FORCEINLINE float GetBoost()     const { return Boost; }

private:
    static void RebuildRTResource(UTextureRenderTarget2D* RT);

private:
    TWeakObjectPtr<UTextureRenderTarget2D> OutRT, LowRT, HighRT, MaskRT;
    float Threshold = 0.5f;
    float Boost = 0.0f;
};
