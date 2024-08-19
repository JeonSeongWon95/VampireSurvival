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
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuHUD();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuHUD_NoRegister();
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
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_MainWidgetclass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MainWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidgetclass = { "MainWidgetclass", nullptr, (EPropertyFlags)0x0024080000030015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, MainWidgetclass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainWidgetclass_MetaData), NewProp_MainWidgetclass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidget = { "MainWidget", nullptr, (EPropertyFlags)0x012408000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuHUD, MainWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainWidget_MetaData), NewProp_MainWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainMenuHUD_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidgetclass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuHUD_Statics::NewProp_MainWidget,
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
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainMenuHUD, AMainMenuHUD::StaticClass, TEXT("AMainMenuHUD"), &Z_Registration_Info_UClass_AMainMenuHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainMenuHUD), 2109444144U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_3063013205(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuHUD_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
