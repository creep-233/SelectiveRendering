#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/TextureRenderTarget2D.h"
#include "SelectiveRenderingSPPSubsystem.generated.h"

UCLASS()
class SELECTIVERENDERINGSPP_API USelectiveRenderingSPPSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable) void SetEnabled(bool bInEnabled);
    UFUNCTION(BlueprintCallable) void SetMaskRT(UTextureRenderTarget2D* InMaskRT);
    UFUNCTION(BlueprintCallable) void SetLowRT(UTextureRenderTarget2D* InLowRT);
    UFUNCTION(BlueprintCallable) void SetHighRT(UTextureRenderTarget2D* InHighRT);
    UFUNCTION(BlueprintCallable) void PushToRHI();   // 先走一个空的桥接

    bool IsEnabled() const { return bEnabled; }
    UTextureRenderTarget2D* GetMaskRT() const { return MaskRT; }
    UTextureRenderTarget2D* GetLowRT()  const { return LowRT; }
    UTextureRenderTarget2D* GetHighRT() const { return HighRT; }

private:
    UPROPERTY() UTextureRenderTarget2D* MaskRT = nullptr;
    UPROPERTY() UTextureRenderTarget2D* LowRT = nullptr;
    UPROPERTY() UTextureRenderTarget2D* HighRT = nullptr;
    bool bEnabled = false;
};
