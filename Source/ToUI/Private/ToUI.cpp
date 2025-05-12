#include "ToUI.h"

#include "Styling/SlateStyleMacros.h"
#include "Interfaces/IPluginManager.h"
#include "ToUIEditorStyleSetting.h"
#include "Kismet/KismetMaterialLibrary.h"
#include "Settings/EditorStyleSettings.h"
#include "Subsystems/UnrealEditorSubsystem.h"

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

UMaterial* FToUIModule::LoadMat(FString Path)
{
	return LoadObject<UMaterial>(nullptr, *Path);
}

FSlateBrush* FToUIModule::CreateBrush(const EFlatBrush Type)
{
	FSlateBrush* SlateBrush = new FSlateBrush();
	UMaterial* Material;
	switch (Type)
	{
	case EFlatBrush::HeaderBrush:
		Material = LoadMat(Path_FlatNodeHeaderMat);
		break;
	case EFlatBrush::SelectedRimBrush_VarNode:
	case EFlatBrush::SelectedRimBrush:
		Material = LoadMat(Path_FlatNodeSelectedRim);
		break;
	default:
		Material = nullptr;
	}
	if (!Material) return nullptr;
	UToUIEditorStyleSetting* FlatNodesSettings = GetEditorSettings();
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, FlatNodesSettings);
	DynamicMaterial->AddToRoot();
	SlateBrush->SetResourceObject(DynamicMaterial);
	SlateBrushes.Add(Type, SlateBrush);

	return SlateBrush;
}

#pragma endregion

#pragma region FlatNode

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

	const auto HeaderBrush = CreateBrush(EFlatBrush::HeaderBrush);
	HeaderBrush->Margin = FMargin(0, -1.0f / 32.0f, -3.0f / 20.0f, 0);
	HeaderBrush->DrawAs = ESlateBrushDrawType::Box;
	Style->Set("Graph.Node.ColorSpill", HeaderBrush);

	Style->Set("Graph.Node.TitleHighlight", new BOX_BRUSH("Graph/RegularNode_title_highlight", FMargin(16.0f / 64.0f, 1.0f, 16.0f / 64.0f, 0.0f)));
	
	Style->Set("Graph.Node.ShadowSize", FVector2D(12, 12));
	
	// Style->Set("Graph.Node.ShadowSelected", new BOX_BRUSH("Graph/RegularNode_shadow_selected", FMargin(18.0f / 64.0f)));
	Style->Set("Graph.Node.ShadowSelected", new BOX_BRUSH("Graph/Selected_Rim", FMargin(18.0f / 64.0f)));
	Style->Set("Graph.Node.Shadow", new BOX_BRUSH("Graph/RegularNode_shadow", FMargin(18.0f / 64.0f)));

	Style->Set("Graph.VarNode.Body", new BOX_BRUSH("Graph/VarNode_body", FMargin(16.f / 64.f, 12.f / 28.f)));
	Style->Set("Graph.VarNode.ColorSpill", new IMAGE_BRUSH("Graph/VarNode_color_spill", FVector2D(132, 28)));
	Style->Set("Graph.VarNode.Gloss", new BOX_BRUSH("Graph/VarNode_gloss", FMargin(16.f / 64.f, 16.f / 28.f, 16.f / 64.f, 4.f / 28.f)));

	// Style->Set("Graph.VarNode.ShadowSelected", new BOX_BRUSH("Graph/VarNode_shadow_selected", FMargin(26.0f / 64.0f)));
	Style->Set("Graph.VarNode.ShadowSelected", new BOX_BRUSH("Graph/Selected_Rim", FMargin(26.0f / 64.0f)));
	Style->Set("Graph.VarNode.Shadow", new BOX_BRUSH("Graph/VarNode_shadow", FMargin(26.0f / 64.0f)));

	Style->Set("Graph.CollapsedNode.Body", new BOX_BRUSH("Graph/RegularNode_body", FMargin(16.f / 64.f, 25.f / 64.f, 16.f / 64.f, 16.f / 64.f)));
	Style->Set("Graph.CollapsedNode.BodyColorSpill", new BOX_BRUSH("Graph/CollapsedNode_Body_ColorSpill", FMargin(16.f / 64.f, 25.f / 64.f, 16.f / 64.f, 16.f / 64.f)));

	Style->Set("Graph.ExecPin.Connected", new IMAGE_BRUSH("Graph/ExecPin_Connected", FVector2D(12.0f, 16.0f)));
	Style->Set("Graph.ExecPin.Disconnected", new IMAGE_BRUSH("Graph/ExecPin_Disconnected", FVector2D(12.0f, 16.0f)));
	Style->Set("Graph.ExecPin.ConnectedHovered", new IMAGE_BRUSH("Graph/ExecPin_Connected", FVector2D(12.0f, 16.0f), FLinearColor(0.8f, 0.8f, 0.8f)));
	Style->Set("Graph.ExecPin.DisconnectedHovered", new IMAGE_BRUSH("Graph/ExecPin_Disconnected", FVector2D(12.0f, 16.0f), FLinearColor(0.8f, 0.8f, 0.8f)));

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

void FToUIModule::ApplyMatrixBackgroundEditorStyle(bool bForceUpdate)
{
	if (MatrixBackgroundMat && !bForceUpdate) return;
	if (!GEditor || !GEditor->GetEditorSubsystem<UUnrealEditorSubsystem>()) return;

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
	MatrixBackgroundMat = UKismetMaterialLibrary::CreateDynamicMaterialInstance(nullptr, Material);
	FSlateBrush Brush;
	Brush.SetResourceObject(MatrixBackgroundMat);
	EditorStyleSetting->GraphBackgroundBrush = Brush;
	EditorStyleSetting->bUseGrid = false;
}

bool FToUIModule::GetCurrentGraphInfo()
{
	const auto TabManager = FGlobalTabmanager::Get();
	const auto ActiveTab = TabManager->GetActiveTab();
	if (!ActiveTab.IsValid() || !ActiveTab->IsForeground()) return false;

	TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(ActiveTab->GetContent());
	if (GraphEditor->GetType() != TEXT("SGraphEditor")) return false;

	GraphEditor->GetViewLocation(GraphPosDragCur, GraphZoom);
	//tolog("Pos : " + GraphPosDragCur.ToString() + " Zoom : " + FString::SanitizeFloat(GraphZoom));

	if (GraphPosDragStart.Equals(FVector2D::ZeroVector))
	{
		GraphPosDragStart = GraphPosDragCur;
	}

	return true;
}

void FToUIModule::SetMatrixBackgroundMatParams()
{
	MatrixBackgroundMat->SetVectorParameterValue(K_MatrixBackgroundMat_Params, FLinearColor(DragOffset.X, DragOffset.Y, GraphZoom, CursorEffectStrength));
}

void FToUIModule::UpdateDragOffset(const float DeltaTime)
{
	if (GEditor->bIsSimulatingInEditor || GEditor->PlayWorld || !MatrixBackgroundMat || !GetCurrentGraphInfo()) return;
	if (ToUIInputProcessor->bIsDragging)
	{
		const auto CurDragOffset = (GraphPosDragCur - GraphPosDragStart) * GraphZoom * UToUIEditorStyleSetting::ConvScale(GetEditorSettings()->DragOffsetScale);

		if (DragWarningTimer < DragWarningDuration)
		{
			DragWarningTimer += DeltaTime;
			DragOffset = FMath::Lerp(DragOffset, CurDragOffset, 0.4f);
		}
		else
		{
			DragOffset = CurDragOffset;
		}

		if (!FMath::IsNearlyEqual(CursorEffectStrength, 0))
		{
			CursorEffectStrength = FMath::Lerp(CursorEffectStrength, 0, 0.1f);
		}
	}
	else
	{
		if (!FMath::IsNearlyEqual(CursorEffectStrength, 1.f))
		{
			GraphPosDragStart = FVector2D::ZeroVector;
			DragWarningTimer = 0;
			CursorEffectStrength = FMath::Lerp(CursorEffectStrength, 1, 0.1f);
		}
	}
	SetMatrixBackgroundMatParams();
}

#pragma endregion

bool FToUIModule::Tick(float DeltaTime)
{
	ApplyMatrixBackgroundEditorStyle();
	UpdateDragOffset(DeltaTime);
	return true;
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FToUIModule, ToUI)
