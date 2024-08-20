// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainmenuLevel/MainMenuHUD.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuHUD() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_AHUD();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuHUD();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuHUD_NoRegister();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UJoinWidget_NoRegister();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_ULoginWidget_NoRegister();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UMainMenuWidget_NoRegister();
// End Cross Module References

// Begin Class AMainMenuHUD
void AMainMenuHUD::StaticRegisterNativesAMainMenuHUD()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainMenuHUD);
UClass* Z_Construct_UClass_AMainMenuHUD_NoRegister()
{
	return AMainMenuHUD::StaticClass();
}
struct Z_Construct_UClass_AMainMenuHUD_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "MainmenuLevel/MainMenuHUD.h" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainWidgetclass_MetaData[] = {
		{ "Category", "WidgetClass" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainWidget_MetaData[] = {
		{ "Category", "Widget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JoinWidgetclass_MetaData[] = {
		{ "Category", "WidgetClass" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginWidgetClass_MetaData[] = {
		{ "Category", "WidgetClass" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JoinWidget_MetaData[] = {
		{ "Category", "Widget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginWidget_MetaData[] = {
		{ "Category", "Widget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuHUD.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainWidgetclass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MainWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_JoinWidgetclass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoginWidgetClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinWidget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoginWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidgetclass = { "MainWidgetclass", nullptr, (EPropertyFlags)0x0024080000030015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, MainWidgetclass), Z_Construct_UClass_UClass, Z_Construct_UClass_UMainMenuWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainWidgetclass_MetaData), NewProp_MainWidgetclass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidget = { "MainWidget", nullptr, (EPropertyFlags)0x012408000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, MainWidget), Z_Construct_UClass_UMainMenuWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainWidget_MetaData), NewProp_MainWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_JoinWidgetclass = { "JoinWidgetclass", nullptr, (EPropertyFlags)0x0024080000030015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, JoinWidgetclass), Z_Construct_UClass_UClass, Z_Construct_UClass_UJoinWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JoinWidgetclass_MetaData), NewProp_JoinWidgetclass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_LoginWidgetClass = { "LoginWidgetClass", nullptr, (EPropertyFlags)0x0024080000030015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, LoginWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginWidgetClass_MetaData), NewProp_LoginWidgetClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_JoinWidget = { "JoinWidget", nullptr, (EPropertyFlags)0x012408000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, JoinWidget), Z_Construct_UClass_UJoinWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JoinWidget_MetaData), NewProp_JoinWidget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_LoginWidget = { "LoginWidget", nullptr, (EPropertyFlags)0x012408000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, LoginWidget), Z_Construct_UClass_ULoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginWidget_MetaData), NewProp_LoginWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainMenuHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidgetclass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_JoinWidgetclass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_LoginWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_JoinWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_LoginWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuHUD_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMainMenuHUD_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AHUD,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuHUD_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuHUD_Statics::ClassParams = {
	&AMainMenuHUD::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMainMenuHUD_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuHUD_Statics::PropPointers),
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuHUD_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainMenuHUD_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainMenuHUD()
{
	if (!Z_Registration_Info_UClass_AMainMenuHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainMenuHUD.OuterSingleton, Z_Construct_UClass_AMainMenuHUD_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainMenuHUD.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AMainMenuHUD>()
{
	return AMainMenuHUD::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuHUD);
AMainMenuHUD::~AMainMenuHUD() {}
// End Class AMainMenuHUD

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainMenuHUD, AMainMenuHUD::StaticClass, TEXT("AMainMenuHUD"), &Z_Registration_Info_UClass_AMainMenuHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainMenuHUD), 1318482939U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_1682312772(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
