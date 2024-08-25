// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/Enemy/EnemyController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyController() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_AAIController();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AEnemyController();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AEnemyController_NoRegister();
// End Cross Module References

// Begin Class AEnemyController
void AEnemyController::StaticRegisterNativesAEnemyController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemyController);
UClass* Z_Construct_UClass_AEnemyController_NoRegister()
{
	return AEnemyController::StaticClass();
}
struct Z_Construct_UClass_AEnemyController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MainGameLevel/Enemy/EnemyController.h" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemyController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEnemyController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AAIController,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemyController_Statics::ClassParams = {
	&AEnemyController::StaticClass,
	"Engine",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyController_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemyController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemyController()
{
	if (!Z_Registration_Info_UClass_AEnemyController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemyController.OuterSingleton, Z_Construct_UClass_AEnemyController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemyController.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AEnemyController>()
{
	return AEnemyController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyController);
AEnemyController::~AEnemyController() {}
// End Class AEnemyController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemyController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemyController, AEnemyController::StaticClass, TEXT("AEnemyController"), &Z_Registration_Info_UClass_AEnemyController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemyController), 1618275424U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemyController_h_4002393837(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemyController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemyController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
