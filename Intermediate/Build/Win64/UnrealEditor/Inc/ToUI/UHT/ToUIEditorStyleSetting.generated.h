// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ToUIEditorStyleSetting.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TOUI_ToUIEditorStyleSetting_generated_h
#error "ToUIEditorStyleSetting.generated.h already included, missing '#pragma once' in ToUIEditorStyleSetting.h"
#endif
#define TOUI_ToUIEditorStyleSetting_generated_h

#define FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUToUIEditorStyleSetting(); \
	friend struct Z_Construct_UClass_UToUIEditorStyleSetting_Statics; \
public: \
	DECLARE_CLASS(UToUIEditorStyleSetting, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ToUI"), NO_API) \
	DECLARE_SERIALIZER(UToUIEditorStyleSetting) \
	static const TCHAR* StaticConfigName() {return TEXT("EditorPerProjectUserSettings");} \



#define FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UToUIEditorStyleSetting(UToUIEditorStyleSetting&&); \
	UToUIEditorStyleSetting(const UToUIEditorStyleSetting&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UToUIEditorStyleSetting); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UToUIEditorStyleSetting); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UToUIEditorStyleSetting) \
	NO_API virtual ~UToUIEditorStyleSetting();


#define FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_17_PROLOG
#define FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_20_INCLASS_NO_PURE_DECLS \
	FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TOUI_API UClass* StaticClass<class UToUIEditorStyleSetting>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PluginDemo_Plugins_ToUI_Source_ToUI_Public_ToUIEditorStyleSetting_h


#define FOREACH_ENUM_ETOUIOFFSETSCALE(op) \
	op(EToUIOffsetScale::XP5) \
	op(EToUIOffsetScale::X1) \
	op(EToUIOffsetScale::X1P5) \
	op(EToUIOffsetScale::X2) 

enum class EToUIOffsetScale : uint8;
template<> struct TIsUEnumClass<EToUIOffsetScale> { enum { Value = true }; };
template<> TOUI_API UEnum* StaticEnum<EToUIOffsetScale>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
