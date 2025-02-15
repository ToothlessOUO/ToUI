#pragma once

#include "CoreMinimal.h"
#include "ToUI.h"
#include "Engine/DeveloperSettings.h"
#include "ToUIEditorStyleSetting.generated.h"

UCLASS(config = EditorPerProjectUserSettings)
class TOUI_API UToUIEditorStyleSetting : public UDeveloperSettings
{
	GENERATED_BODY()

	public:
	UToUIEditorStyleSetting();

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
	//will call after user set settings
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

	UPROPERTY(config, EditAnywhere, Category = "Header", DisplayName = "MatrixBackgroundMat", meta = (ConfigRestartRequired = true))
	TSoftObjectPtr<UMaterialInterface> MatrixBackgroundMat;

	private:
	FToUIModule* ToUIModule;
};
