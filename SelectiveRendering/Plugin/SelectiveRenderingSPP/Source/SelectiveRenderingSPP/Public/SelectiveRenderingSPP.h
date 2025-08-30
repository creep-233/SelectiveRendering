//// Copyright Epic Games, Inc. All Rights Reserved.
//
//#pragma once
//
//#include "Modules/ModuleManager.h"
//
//class FSelectiveRenderingSPPModule : public IModuleInterface
//{
//public:
//
//	/** IModuleInterface implementation */
//	virtual void StartupModule() override;
//	virtual void ShutdownModule() override;
//};


#pragma once
#include "Subsystems/GameInstanceSubsystem.h"
#include "Engine/TextureRenderTarget2D.h"
#include "SelectiveRenderingSPPSubsystem.generated.h"

UCLASS()
class SELECTIVERENDERINGSPP_API USelectiveRenderingSPPSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable) void SetEnabled(bool bInEnabled);
    UFUNCTION(BlueprintCallable) void SetMaskRT(UTextureRenderTarget2D* InMaskRT); // RT_MemoryRead
    UFUNCTION(BlueprintCallable) void SetLowRT(UTextureRenderTarget2D* InLowRT);  // ����RT
    UFUNCTION(BlueprintCallable) void SetHighRT(UTextureRenderTarget2D* InHighRT); // �ɿ�
    UFUNCTION(BlueprintCallable) void PushToRHI(); // ��ͼ��ֱ�ӵ���

    bool IsEnabled() const { return bEnabled; }
    UTextureRenderTarget2D* GetMaskRT() const { return MaskRT; }
    UTextureRenderTarget2D* GetLowRT() const { return LowRT; }
    UTextureRenderTarget2D* GetHighRT() const { return HighRT; }

private:
    UPROPERTY() UTextureRenderTarget2D* MaskRT = nullptr;
    UPROPERTY() UTextureRenderTarget2D* LowRT = nullptr;
    UPROPERTY() UTextureRenderTarget2D* HighRT = nullptr;
    bool bEnabled = false;
};
