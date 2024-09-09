// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainmenuLevel/MainMenuGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuGameMode();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuGameMode_NoRegister();
// End Cross Module References

// Begin Class AMainMenuGameMode
void AMainMenuGameMode::StaticRegisterNativesAMainMenuGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainMenuGameMode);
UClass* Z_Construct_UClass_AMainMenuGameMode_NoRegister()
{
	return AMainMenuGameMode::StaticClass();
}
struct Z_Construct_UClass_AMainMenuGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MainmenuLevel/MainMenuGameMode.h" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMainMenuGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuGameMode_Statics::ClassParams = {
	&AMainMenuGameMode::StaticClass,
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
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainMenuGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainMenuGameMode()
{
	if (!Z_Registration_Info_UClass_AMainMenuGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainMenuGameMode.OuterSingleton, Z_Construct_UClass_AMainMenuGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainMenuGameMode.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AMainMenuGameMode>()
{
	return AMainMenuGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuGameMode);
AMainMenuGameMode::~AMainMenuGameMode() {}
// End Class AMainMenuGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainMenuGameMode, AMainMenuGameMode::StaticClass, TEXT("AMainMenuGameMode"), &Z_Registration_Info_UClass_AMainMenuGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainMenuGameMode), 393910834U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuGameMode_h_3621551478(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
