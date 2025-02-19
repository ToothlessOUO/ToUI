// Fill out your copyright notice in the Description page of Project Settings.


#include "ToUIEditorStyleSetting.h"

#define LOCTEXT_NAMESPACE "ToUI"

UToUIEditorStyleSetting::UToUIEditorStyleSetting()
{
	CategoryName = TEXT("Plugins");
	SectionName = TEXT("ToUI");

	ToUIModule = FModuleManager::Get().GetModulePtr<FToUIModule>("ToUI");
	if (ToUIModule)
	{
		ToUIModule->ApplyMatrixBackgroundEditorStyle();
	}
}

float UToUIEditorStyleSetting::ConvScale(EToUIOffsetScale Scale)
{
	switch (Scale)
	{
	default:
	case EToUIOffsetScale::X1:
		return 1.f;
	case EToUIOffsetScale::X1P5:
		return 1.5f;
	case EToUIOffsetScale::X2:
		return 2.f;
		
	}
}

#if WITH_EDITOR
FText UToUIEditorStyleSetting::GetSectionText() const
{
	return LOCTEXT("UserSettingsDisplayName", "ToUI");
}

void UToUIEditorStyleSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property)
	{
		if (!ToUIModule)
		{
			ToUIModule = FModuleManager::Get().GetModulePtr<FToUIModule>("ToUI");
			if (!ToUIModule) return;
		}
		const FName PropertyName = PropertyChangedEvent.GetPropertyName();

		if (PropertyName == GET_MEMBER_NAME_CHECKED(UToUIEditorStyleSetting, MatrixBackgroundMat) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(UToUIEditorStyleSetting, bUseMatrixBackground))
		{
			ToUIModule->ApplyMatrixBackgroundEditorStyle();
		}
	}
}
#endif

#undef LOCTEXT_NAMESPACE
