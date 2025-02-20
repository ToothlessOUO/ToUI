// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ToUI/Public/ToUIEditorStyleSetting.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeToUIEditorStyleSetting() {}

// Begin Cross Module References
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
TOUI_API UClass* Z_Construct_UClass_UToUIEditorStyleSetting();
TOUI_API UClass* Z_Construct_UClass_UToUIEditorStyleSetting_NoRegister();
TOUI_API UEnum* Z_Construct_UEnum_ToUI_EToUIOffsetScale();
UPackage* Z_Construct_UPackage__Script_ToUI();
// End Cross Module References

// Begin Enum EToUIOffsetScale
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EToUIOffsetScale;
static UEnum* EToUIOffsetScale_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EToUIOffsetScale.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EToUIOffsetScale.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_ToUI_EToUIOffsetScale, (UObject*)Z_Construct_UPackage__Script_ToUI(), TEXT("EToUIOffsetScale"));
	}
	return Z_Registration_Info_UEnum_EToUIOffsetScale.OuterSingleton;
}
template<> TOUI_API UEnum* StaticEnum<EToUIOffsetScale>()
{
	return EToUIOffsetScale_StaticEnum();
}
struct Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ToUIEditorStyleSetting.h" },
		{ "X1.DisplayName", "x1" },
		{ "X1.Name", "EToUIOffsetScale::X1" },
		{ "X1P5.DisplayName", "x1.5" },
		{ "X1P5.Name", "EToUIOffsetScale::X1P5" },
		{ "X2.DisplayName", "x2" },
		{ "X2.Name", "EToUIOffsetScale::X2" },
		{ "XP5.DisplayName", "x0.5" },
		{ "XP5.Name", "EToUIOffsetScale::XP5" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EToUIOffsetScale::XP5", (int64)EToUIOffsetScale::XP5 },
		{ "EToUIOffsetScale::X1", (int64)EToUIOffsetScale::X1 },
		{ "EToUIOffsetScale::X1P5", (int64)EToUIOffsetScale::X1P5 },
		{ "EToUIOffsetScale::X2", (int64)EToUIOffsetScale::X2 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_ToUI,
	nullptr,
	"EToUIOffsetScale",
	"EToUIOffsetScale",
	Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics::Enum_MetaDataParams), Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_ToUI_EToUIOffsetScale()
{
	if (!Z_Registration_Info_UEnum_EToUIOffsetScale.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EToUIOffsetScale.InnerSingleton, Z_Construct_UEnum_ToUI_EToUIOffsetScale_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EToUIOffsetScale.InnerSingleton;
}
// End Enum EToUIOffsetScale

// Begin Class UToUIEditorStyleSetting
void UToUIEditorStyleSetting::StaticRegisterNativesUToUIEditorStyleSetting()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UToUIEditorStyleSetting);
UClass* Z_Construct_UClass_UToUIEditorStyleSetting_NoRegister()
{
	return UToUIEditorStyleSetting::StaticClass();
}
struct Z_Construct_UClass_UToUIEditorStyleSetting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ToUIEditorStyleSetting.h" },
		{ "ModuleRelativePath", "Public/ToUIEditorStyleSetting.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bUseMatrixBackground_MetaData[] = {
		{ "Category", "MatrixBackground" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Setings\n" },
#endif
		{ "ConfigRestartRequired", "TRUE" },
		{ "DisplayName", "UseMatrixBackgroundMat" },
		{ "ModuleRelativePath", "Public/ToUIEditorStyleSetting.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Setings" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatrixBackgroundMat_MetaData[] = {
		{ "Category", "MatrixBackground" },
		{ "ConfigRestartRequired", "TRUE" },
		{ "DisplayName", "MatrixBackgroundMat" },
		{ "ModuleRelativePath", "Public/ToUIEditorStyleSetting.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DragOffsetScale_MetaData[] = {
		{ "Category", "MatrixBackground" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * \xe5\x92\x8c\xe5\x88\x86\xe8\xbe\xa8\xe7\x8e\x87\xe6\x9c\x89\xe5\x85\xb3\xef\xbc\x8c""1080p\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xba x0.5 ; 2k\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xba x1 ; 4k\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xba x1.5\n\x09 */" },
#endif
		{ "ConfigRestartRequired", "TRUE" },
		{ "DisplayName", "DragOffsetScale" },
		{ "ModuleRelativePath", "Public/ToUIEditorStyleSetting.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x92\x8c\xe5\x88\x86\xe8\xbe\xa8\xe7\x8e\x87\xe6\x9c\x89\xe5\x85\xb3\xef\xbc\x8c""1080p\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xba x0.5 ; 2k\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xba x1 ; 4k\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xba x1.5" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bUseMatrixBackground_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseMatrixBackground;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_MatrixBackgroundMat;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DragOffsetScale_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DragOffsetScale;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UToUIEditorStyleSetting>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_bUseMatrixBackground_SetBit(void* Obj)
{
	((UToUIEditorStyleSetting*)Obj)->bUseMatrixBackground = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_bUseMatrixBackground = { "bUseMatrixBackground", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UToUIEditorStyleSetting), &Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_bUseMatrixBackground_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bUseMatrixBackground_MetaData), NewProp_bUseMatrixBackground_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_MatrixBackgroundMat = { "MatrixBackgroundMat", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToUIEditorStyleSetting, MatrixBackgroundMat), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatrixBackgroundMat_MetaData), NewProp_MatrixBackgroundMat_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_DragOffsetScale_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_DragOffsetScale = { "DragOffsetScale", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UToUIEditorStyleSetting, DragOffsetScale), Z_Construct_UEnum_ToUI_EToUIOffsetScale, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DragOffsetScale_MetaData), NewProp_DragOffsetScale_MetaData) }; // 4170125959
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UToUIEditorStyleSetting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_bUseMatrixBackground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_MatrixBackgroundMat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_DragOffsetScale_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UToUIEditorStyleSetting_Statics::NewProp_DragOffsetScale,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToUIEditorStyleSetting_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UToUIEditorStyleSetting_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ToUI,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UToUIEditorStyleSetting_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UToUIEditorStyleSetting_Statics::ClassParams = {
	&UToUIEditorStyleSetting::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UToUIEditorStyleSetting_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UToUIEditorStyleSetting_Statics::PropPointers),
	0,
	0x001000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UToUIEditorStyleSetting_Statics::Class_MetaDataParams), Z_Construct_UClass_UToUIEditorStyleSetting_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UToUIEditorStyleSetting()
{
	if (!Z_Registration_Info_UClass_UToUIEditorStyleSetting.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UToUIEditorStyleSetting.OuterSingleton, Z_Construct_UClass_UToUIEditorStyleSetting_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UToUIEditorStyleSetting.OuterSingleton;
}
template<> TOUI_API UClass* StaticClass<UToUIEditorStyleSetting>()
{
	return UToUIEditorStyleSetting::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UToUIEditorStyleSetting);
UToUIEditorStyleSetting::~UToUIEditorStyleSetting() {}
// End Class UToUIEditorStyleSetting

// Begin Registration
struct Z_CompiledInDeferFile_FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EToUIOffsetScale_StaticEnum, TEXT("EToUIOffsetScale"), &Z_Registration_Info_UEnum_EToUIOffsetScale, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4170125959U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UToUIEditorStyleSetting, UToUIEditorStyleSetting::StaticClass, TEXT("UToUIEditorStyleSetting"), &Z_Registration_Info_UClass_UToUIEditorStyleSetting, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UToUIEditorStyleSetting), 3310110570U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_3309026200(TEXT("/Script/ToUI"),
	Z_CompiledInDeferFile_FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
