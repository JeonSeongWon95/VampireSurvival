// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainmenuLevel/MainMenuPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuPlayerController();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuPlayerController_NoRegister();
// End Cross Module References

// Begin Class AMainMenuPlayerController
void AMainMenuPlayerController::StaticRegisterNativesAMainMenuPlayerController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainMenuPlayerController);
UClass* Z_Construct_UClass_AMainMenuPlayerController_NoRegister()
{
	return AMainMenuPlayerController::StaticClass();
}
struct Z_Construct_UClass_AMainMenuPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MainmenuLevel/MainMenuPlayerController.h" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuPlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMainMenuPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuPlayerController_Statics::ClassParams = {
	&AMainMenuPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainMenuPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainMenuPlayerController()
{
	if (!Z_Registration_Info_UClass_AMainMenuPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainMenuPlayerController.OuterSingleton, Z_Construct_UClass_AMainMenuPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainMenuPlayerController.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AMainMenuPlayerController>()
{
	return AMainMenuPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuPlayerController);
AMainMenuPlayerController::~AMainMenuPlayerController() {}
// End Class AMainMenuPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainMenuPlayerController, AMainMenuPlayerController::StaticClass, TEXT("AMainMenuPlayerController"), &Z_Registration_Info_UClass_AMainMenuPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainMenuPlayerController), 658177942U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_3405559881(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
