#include "ToUI.h"

#include "BlueprintEditor.h"
#include "MaterialEditorUtilities.h"
#include "Styling/SlateStyleMacros.h"
#include "Interfaces/IPluginManager.h"
#include "ToUIEditorStyleSetting.h"
#include "Editor/MaterialEditor/Private/MaterialEditor.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Settings/EditorStyleSettings.h"
#include "Subsystems/UnrealEditorSubsystem.h"
#include "Materials/MaterialParameterCollection.h"

class UUnrealEditorSubsystem;
DEFINE_LOG_CATEGORY(LogToUI);

#define LOCTEXT_NAMESPACE "FToUIModule"
#define RootToContentDir Style->RootToContentDir

#pragma region Input

bool FToUIInputProcessor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	bIsDragging = MouseEvent.IsMouseButtonDown(EKeys::RightMouseButton);
	return false;
}

bool FToUIInputProcessor::HandleMouseButtonUpEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
	bIsDragging = false;
	return false;
}

#pragma endregion

#pragma region MouduleFuncs
void FToUIModule::StartupModule()
{
	TickDelegate = FTickerDelegate::CreateRaw(this, &FToUIModule::Tick);
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(TickDelegate);
	ToUIInputProcessor = new FToUIInputProcessor();
	FSlateApplication::Get().RegisterInputPreProcessor(MakeShareable(ToUIInputProcessor));
	if (GIsEditor && !IsRunningCommandlet())
	{
		ApplyFlatNodeEditorStyle();
		ApplyMatrixBackgroundEditorStyle();
	}
}

void FToUIModule::ShutdownModule()
{
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(MakeShareable(ToUIInputProcessor));
	}
}

UToUIEditorStyleSetting* FToUIModule::GetEditorSettings()
{
	return GetMutableDefault<UToUIEditorStyleSetting>();
}

void FToUIModule::tolog(FString msg)
{
	TOLOG("%s", *msg);
}

#pragma endregion

#pragma region FlatNode

FSlateBrush* FToUIModule::CreateHeaderBrush()
{
	FSlateBrush* SlateBrush = new FSlateBrush();

	UMaterial* Material = LoadObject<UMaterial>(nullptr, *Path_FlatNodeHeaderMat);
	UToUIEditorStyleSetting* FlatNodesSettings = GetEditorSettings();
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, FlatNodesSettings);

	//DynamicMaterial->SetVectorParameterValue("Color", FVector(HeaderBrightness, HeaderBrightness, HeaderBrightness));
	DynamicMaterial->AddToRoot();

	SlateBrush->SetResourceObject(DynamicMaterial);
	SlateBrushes.Add("HeaderBrush", SlateBrush);

	return SlateBrush;
}

void FToUIModule::ApplyFlatNodeEditorStyle()
{
	FSlateStyleSet* Style = (FSlateStyleSet*)&FAppStyle::Get();
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("ToUI")->GetBaseDir() / TEXT("Resources"));

	UToUIEditorStyleSetting* FlatNodesSettings = GetMutableDefault<UToUIEditorStyleSetting>();
	//const bool bHeaderUseGradient = FlatNodesSettings->bHeaderUseGradient;


	Style->Set("Graph.PlayInEditor", new BOX_BRUSH("Graph/RegularNode_shadow_selected", FMargin(18.0f / 64.0f)));

	Style->Set("Graph.Node.Body", new BOX_BRUSH("Graph/RegularNode_body", FMargin(16.f / 64.f, 25.f / 64.f, 16.f / 64.f, 16.f / 64.f)));
	Style->Set("Graph.Node.TintedBody", new BOX_BRUSH("Graph/TintedNode_body", FMargin(16.f / 64.f, 25.f / 64.f, 16.f / 64.f, 16.f / 64.f)));
	Style->Set("Graph.Node.TitleGloss", new BOX_BRUSH("Graph/RegularNode_title_gloss", FMargin(12.0f / 64.0f)));
	FSlateBrush* HeaderBrush = CreateHeaderBrush();
	HeaderBrush->Margin = FMargin(0, -1.0f / 32.0f, -3.0f / 20.0f, 0);
	HeaderBrush->DrawAs = ESlateBrushDrawType::Box;
	Style->Set("Graph.Node.ColorSpill", HeaderBrush);

	Style->Set("Graph.Node.TitleHighlight", new BOX_BRUSH("Graph/RegularNode_title_highlight", FMargin(16.0f / 64.0f, 1.0f, 16.0f / 64.0f, 0.0f)));

	Style->Set("Graph.Node.ShadowSize", FVector2D(12, 12));
	Style->Set("Graph.Node.ShadowSelected", new BOX_BRUSH("Graph/RegularNode_shadow_selected", FMargin(18.0f / 64.0f)));
	Style->Set("Graph.Node.Shadow", new BOX_BRUSH("Graph/RegularNode_shadow", FMargin(18.0f / 64.0f)));

	Style->Set("Graph.VarNode.Body", new BOX_BRUSH("Graph/VarNode_body", FMargin(16.f / 64.f, 12.f / 28.f)));
	Style->Set("Graph.VarNode.ColorSpill", new IMAGE_BRUSH("Graph/VarNode_color_spill", FVector2D(132, 28)));
	Style->Set("Graph.VarNode.Gloss", new BOX_BRUSH("Graph/VarNode_gloss", FMargin(16.f / 64.f, 16.f / 28.f, 16.f / 64.f, 4.f / 28.f)));

	Style->Set("Graph.VarNode.ShadowSelected", new BOX_BRUSH("Graph/VarNode_shadow_selected", FMargin(26.0f / 64.0f)));
	Style->Set("Graph.VarNode.Shadow", new BOX_BRUSH("Graph/VarNode_shadow", FMargin(26.0f / 64.0f)));

	Style->Set("Graph.CollapsedNode.Body", new BOX_BRUSH("Graph/RegularNode_body", FMargin(16.f / 64.f, 25.f / 64.f, 16.f / 64.f, 16.f / 64.f)));
	Style->Set("Graph.CollapsedNode.BodyColorSpill", new BOX_BRUSH("Graph/CollapsedNode_Body_ColorSpill", FMargin(16.f / 64.f, 25.f / 64.f, 16.f / 64.f, 16.f / 64.f)));

	Style->Set("Graph.ExecPin.Connected", new IMAGE_BRUSH("Old/Graph/ExecPin_Connected", FVector2D(12.0f, 16.0f)));
	Style->Set("Graph.ExecPin.Disconnected", new IMAGE_BRUSH("Old/Graph/ExecPin_Disconnected", FVector2D(12.0f, 16.0f)));
	Style->Set("Graph.ExecPin.ConnectedHovered", new IMAGE_BRUSH("Old/Graph/ExecPin_Connected", FVector2D(12.0f, 16.0f), FLinearColor(0.8f, 0.8f, 0.8f)));
	Style->Set("Graph.ExecPin.DisconnectedHovered", new IMAGE_BRUSH("Old/Graph/ExecPin_Disconnected", FVector2D(12.0f, 16.0f), FLinearColor(0.8f, 0.8f, 0.8f)));

	Style->Set("KismetExpression.ReadVariable.Body", new BOX_BRUSH("/Graph/Linear_VarNode_Background", FMargin(16.f / 64.f, 12.f / 28.f)));
	//Style->Set("KismetExpression.ReadVariable.Gloss", new BOX_BRUSH("/Graph/Linear_VarNode_Gloss", FMargin(16.f / 64.f, 12.f / 28.f)));
	Style->Set("KismetExpression.ReadAutogeneratedVariable.Body", new BOX_BRUSH("/Graph/Linear_VarNode_Background", FMargin(16.f / 64.f, 12.f / 28.f)));

	Style->Set("PhysicsAssetEditor.Graph.Node.Shadow", new BOX_BRUSH("Graph/RegularNode_shadow", FMargin(18.0f / 64.0f)));

	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

#pragma endregion

#pragma region MatrixBackground

void FToUIModule::ApplyMatrixBackgroundEditorStyle()
{
	const auto Settings = GetEditorSettings();
	const auto EditorStyleSetting = GetMutableDefault<UEditorStyleSettings>();

	if (!Settings->bUseMatrixBackground)
	{
		EditorStyleSetting->bUseGrid = true;
		EditorStyleSetting->GraphBackgroundBrush = FSlateBrush();
		return;
	}
	UMaterialInterface* Material;
	if (Settings->MatrixBackgroundMat.IsValid())
	{
		Material = Settings->MatrixBackgroundMat.Get();
	}
	else
	{
		//No Setting ,Set as default
		Material = LoadObject<UMaterialInterface>(nullptr, *Path_MatrixBackgroundDefault);
		if (Material == nullptr) return;
	}
	FSlateBrush Brush;
	Brush.SetResourceObject(Material);
	EditorStyleSetting->GraphBackgroundBrush = Brush;
	EditorStyleSetting->bUseGrid = false;
	EditorStyleSetting->SaveConfig();
}

TObjectPtr<UMaterialParameterCollection> FToUIModule::GetMatrixBackgroundMPC()
{
	if (MPC_MatrixBackground == nullptr)
	{
		MPC_MatrixBackground = LoadObject<UMaterialParameterCollection>(nullptr, *Path_MatrixBackgroundMPC);
	}
	return MPC_MatrixBackground;
}

bool FToUIModule::GetCurrentGraphInfo()
{
	const auto TabManager = FGlobalTabmanager::Get();
	const auto ActiveTab = TabManager->GetActiveTab();
	if (!ActiveTab.IsValid() || !ActiveTab->IsForeground()) return false;

	//tolog(ActiveTab->GetTypeAsString());
	TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(ActiveTab->GetContent());
	
	GraphEditor->GetViewLocation(GraphPosDragCur, GraphZoom);

	if (GraphPosDragStart.Equals(FVector2D::ZeroVector))
	{
		GraphPosDragStart = GraphPosDragCur;
	}

	return true;
}

void FToUIModule::UpdateDragOffset(const float DeltaTime)
{
	if (GEditor->bIsSimulatingInEditor || GEditor->PlayWorld) return;
	const auto EditorSys = GEditor->GetEditorSubsystem<UUnrealEditorSubsystem>();
	if (ToUIInputProcessor->bIsDragging)
	{
		if (!GetCurrentGraphInfo()) return;
		const auto DragOffset = (GraphPosDragStart - GraphPosDragCur) * GraphZoom;
		
		auto Cur = FLinearColor(DragOffset.X, DragOffset.Y, 0, 0);
		auto Last = UKismetMaterialLibrary::GetVectorParameterValue(
			EditorSys->GetEditorWorld(),
			GetMatrixBackgroundMPC(),
			K_DragAndOffset);

		if (DragWarningTimer < DragWarningDuration)
		{
			DragWarningTimer += DeltaTime;
			Cur = FMath::Lerp(Last, Cur, 0.3f);
		}
		//适应UI像素偏移
		Cur = FLinearColor((int)Cur.R, (int)Cur.G, Cur.B, Cur.A);
		UKismetMaterialLibrary::SetVectorParameterValue(
			EditorSys->GetEditorWorld(),
			GetMatrixBackgroundMPC(),
			K_DragAndOffset,
			Cur);

		if (FMath::IsNearlyEqual(CursorEffectStrength, 0)) return;
		CursorEffectStrength = FMath::Lerp(CursorEffectStrength, 0, 0.1f);
		UKismetMaterialLibrary::SetScalarParameterValue(
			EditorSys->GetEditorWorld(),
			GetMatrixBackgroundMPC(),
			K_CursorEffectStrength,
			CursorEffectStrength);
	}
	else
	{
		GraphPosDragStart = FVector2D::ZeroVector;
		DragWarningTimer = 0;

		if (FMath::IsNearlyEqual(CursorEffectStrength, 1.f)) return;
		CursorEffectStrength = FMath::Lerp(CursorEffectStrength, 1, 0.1f);
		UKismetMaterialLibrary::SetScalarParameterValue(
			EditorSys->GetEditorWorld(),
			GetMatrixBackgroundMPC(),
			K_CursorEffectStrength,
			CursorEffectStrength);
	}
}

#pragma endregion


bool FToUIModule::Tick(float DeltaTime)
{
	UpdateDragOffset(DeltaTime);
	return true;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FToUIModule, ToUI)
