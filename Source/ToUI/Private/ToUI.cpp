// Copyright Epic Games, Inc. All Rights Reserved.

#include "ToUI.h"

#define LOCTEXT_NAMESPACE "FToUIModule"

void FToUIModule::StartupModule()
{

	TickDelegate = FTickerDelegate::CreateRaw(this,&FToUIModule::Tick);
}

void FToUIModule::ShutdownModule()
{
	
}

bool FToUIModule::Tick(float DeltaTime)
{
	
	return true;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FToUIModule, ToUI)