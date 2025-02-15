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
		
		if (PropertyName == GET_MEMBER_NAME_CHECKED(UToUIEditorStyleSetting, MatrixBackgroundMat))
		{
			ToUIModule->ApplyMatrixBackgroundEditorStyle();
		}
	}
}
#endif

#undef LOCTEXT_NAMESPACE
