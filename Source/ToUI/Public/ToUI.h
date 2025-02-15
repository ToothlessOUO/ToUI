#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogToUI, Log, All);
#define TOLOG(Format, ...) UE_LOG(LogToUI,Warning,TEXT(Format),##__VA_ARGS__)

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
	const FString Path_MatrixBackgroundDefault = FString("/ToUI/MatrixBackground/MI_PointBackground.MI_PointBackground");
	FVector2D DragOffset = FVector2D::ZeroVector;
	void UpdateDragOffset();
	
	FTickerDelegate TickDelegate;
	bool Tick(float DeltaTime);

	TObjectPtr<UMaterialParameterCollection> MPC_PointBackground;
	const FString MPC_PointBackgroundPath = "/Script/Engine.MaterialParameterCollection'/CrystalNodes/Materials/Utils/MP_CrystalEditorParams.MP_CrystalEditorParams'";
	
};
