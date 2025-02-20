#pragma once

#include "Framework/Application/IInputProcessor.h"
#include "Modules/ModuleManager.h"

class UDynamicMaterialInstance;
class FBlueprintEditor;
class UMaterialParameterCollection;

DECLARE_LOG_CATEGORY_EXTERN(LogToUI, Log, All);

#define TOLOG(Format, ...) UE_LOG(LogToUI,Warning,TEXT(Format),##__VA_ARGS__)

struct FToUIInputProcessor : public IInputProcessor
{
	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override { return false; }
	virtual bool HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent) override { return false; };
	virtual bool HandleMouseWheelOrGestureEvent(FSlateApplication& SlateApp, const FPointerEvent& InWheelEvent, const FPointerEvent* InGestureEvent) override { return false; }

	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override
	{
	}

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

	enum EFlatBrush
	{
		HeaderBrush, SelectedRimBrush, SelectedRimBrush_VarNode
	};

	TMap<EFlatBrush, FSlateBrush*> SlateBrushes;

	void ApplyFlatNodeEditorStyle();
	void ApplyMatrixBackgroundEditorStyle(bool bForceUpdate = false);

private:
	class UToUIEditorStyleSetting* GetEditorSettings();

	//fast log func
	void tolog(FString msg);

	FToUIInputProcessor* ToUIInputProcessor = nullptr;

#pragma region FlatNode

	const FString Path_FlatNodeHeaderMat = FString("/ToUI/FlatNode/Box.Box");
	const FString Path_FlatNodeSelectedRim = FString("/ToUI/FlatNode/SelectedRim.SelectedRim");
	UMaterial* LoadMat(FString Path);
	FSlateBrush* CreateBrush(EFlatBrush Type);
#pragma endregion

#pragma region MatrixBackground
	const FString Path_MatrixBackgroundDefault = "/ToUI/MatrixBackground/MI_PointBackground.MI_PointBackground";
	const FName K_MatrixBackgroundMat_Params = "DragOffset_Zoom_CursorEffStren";

	TObjectPtr<UMaterialInstanceDynamic> MatrixBackgroundMat;
	void SetMatrixBackgroundMatParams();
	FVector2D DragOffset = FVector2D::ZeroVector;
	float GraphZoom = 1.f;
	float CursorEffectStrength = 1.0f;

	//刚开始拖动，预热阶段
	float DragWarningTimer = 0;
	const float DragWarningDuration = 0.5f; //需要预热的时长

	FVector2D GraphPosDragStart = FVector2D::ZeroVector;
	FVector2D GraphPosDragCur = FVector2D::ZeroVector;
	bool GetCurrentGraphInfo();
	void UpdateDragOffset(float DeltaTime);
#pragma endregion

	FTickerDelegate TickDelegate;
	FTSTicker::FDelegateHandle TickDelegateHandle;
	bool Tick(float DeltaTime);
};
