#pragma once

#include "Framework/Application/IInputProcessor.h"
#include "Modules/ModuleManager.h"

class UMaterialParameterCollection;

DECLARE_LOG_CATEGORY_EXTERN(LogToUI, Log, All);
#define TOLOG(Format, ...) UE_LOG(LogToUI,Warning,TEXT(Format),##__VA_ARGS__)

struct FToUIInputProcessor : public IInputProcessor
{
	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override {return false;}
	virtual bool HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override {return false;}
	virtual bool HandleMouseWheelOrGestureEvent(FSlateApplication& SlateApp, const FPointerEvent& InWheelEvent, const FPointerEvent* InGestureEvent) override {return false;}
	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override {}
	
	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;
	virtual bool HandleMouseButtonUpEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override;
	bool bIsDragging = false;
};

class FToUIModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	TMap<FString, FSlateBrush*> SlateBrushes;

	void ApplyFlatNodeEditorStyle();
	void ApplyMatrixBackgroundEditorStyle();
	
private:

	class UToUIEditorStyleSetting* GetEditorSettings();
	
	//FlattenNode
	const FString Path_FlatNodeHeaderMat = FString("/ToUI/FlatNode/Box.Box");
	FSlateBrush* CreateHeaderBrush();
	
	//MatrixBackground
	const FString Path_MatrixBackgroundDefault = "/ToUI/MatrixBackground/MI_PointBackground.MI_PointBackground";
	const FString Path_MatrixBackgroundMPC = "/ToUI/MaterialParamCollection/MPC_MatrixBackground.MPC_MatrixBackground";
	const FName K_DragAndOffset = "DragOffsetAndScale";
	const FName K_CursorEffectStrength = "CursorEffectStrength";
	TObjectPtr<UMaterialParameterCollection> MPC_MatrixBackground;
	TObjectPtr<UMaterialParameterCollection> GetMatrixBackgroundMPC();
	FVector2D DragOffset = FVector2D::ZeroVector;
	float CursorEffectStrength = 1.0f;
	FToUIInputProcessor* ToUIInputProcessor = nullptr;
	void UpdateDragOffset(float DeltaTime);
	
	FTickerDelegate TickDelegate;
	FTSTicker::FDelegateHandle TickDelegateHandle;
	bool Tick(float DeltaTime);
	
};

