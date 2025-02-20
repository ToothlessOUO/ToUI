#pragma once

#include "CoreMinimal.h"
#include "ToUI.h"
#include "Engine/DeveloperSettings.h"
#include "ToUIEditorStyleSetting.generated.h"

UENUM(BlueprintType)
enum class EToUIOffsetScale : uint8
{
	XP5 UMETA(DisplayName = "x0.5"),
	X1 UMETA(DisplayName = "x1"),
	X1P5 UMETA(DisplayName = "x1.5"),
	X2 UMETA(DisplayName = "x2"),
};

UCLASS(config = EditorPerProjectUserSettings)
class TOUI_API UToUIEditorStyleSetting : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
	UToUIEditorStyleSetting();
	
	static float ConvScale(EToUIOffsetScale Scale);

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	//will call after user set settings
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	//Setings
	UPROPERTY(config, EditAnywhere, Category = "MatrixBackground", DisplayName = "UseMatrixBackgroundMat", meta = (ConfigRestartRequired = true))
	bool bUseMatrixBackground = true;
	UPROPERTY(config, EditAnywhere, Category = "MatrixBackground", DisplayName = "MatrixBackgroundMat", meta = (ConfigRestartRequired = true))
	TSoftObjectPtr<UMaterialInterface> MatrixBackgroundMat;
	/**
	 * 和分辨率有关，1080p设置为 x0.5 ; 2k设置为 x1 ; 4k设置为 x1.5
	 */
	UPROPERTY(config, EditAnywhere, Category = "MatrixBackground", DisplayName = "DragOffsetScale", meta = (ConfigRestartRequired = true))
	EToUIOffsetScale DragOffsetScale = EToUIOffsetScale::X1;

	private:
	FToUIModule* ToUIModule;
};
 