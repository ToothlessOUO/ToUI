// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FToUIModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
private:

	FTickerDelegate TickDelegate;
	bool Tick(float DeltaTime);

	TObjectPtr<UMaterialParameterCollection> MPC_PointBackground;
	const FString MPC_PointBackgroundPath = "/Script/Engine.MaterialParameterCollection'/CrystalNodes/Materials/Utils/MP_CrystalEditorParams.MP_CrystalEditorParams'";
	
};
