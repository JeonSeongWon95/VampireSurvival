// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvivalGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalGameMode();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalGameMode_NoRegister();
// End Cross Module References

// Begin Class AVampireSurvivalGameMode
void AVampireSurvivalGameMode::StaticRegisterNativesAVampireSurvivalGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVampireSurvivalGameMode);
UClass* Z_Construct_UClass_AVampireSurvivalGameMode_NoRegister()
{
	return AVampireSurvivalGameMode::StaticClass();
}
struct Z_Construct_UClass_AVampireSurvivalGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MainGameLevel/VampireSurvivalGameMode.h" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvivalGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AVampireSurvivalGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVampireSurvivalGameMode_Statics::ClassParams = {
	&AVampireSurvivalGameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AVampireSurvivalGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVampireSurvivalGameMode()
{
	if (!Z_Registration_Info_UClass_AVampireSurvivalGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVampireSurvivalGameMode.OuterSingleton, Z_Construct_UClass_AVampireSurvivalGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVampireSurvivalGameMode.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AVampireSurvivalGameMode>()
{
	return AVampireSurvivalGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVampireSurvivalGameMode);
AVampireSurvivalGameMode::~AVampireSurvivalGameMode() {}
// End Class AVampireSurvivalGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvivalGameMode, AVampireSurvivalGameMode::StaticClass, TEXT("AVampireSurvivalGameMode"), &Z_Registration_Info_UClass_AVampireSurvivalGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvivalGameMode), 3058045341U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalGameMode_h_3350043056(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
