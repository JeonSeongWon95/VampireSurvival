// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/VampireSurvival_GameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvival_GameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvival_GameMode();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvival_GameMode_NoRegister();
// End Cross Module References

// Begin Class AVampireSurvival_GameMode
void AVampireSurvival_GameMode::StaticRegisterNativesAVampireSurvival_GameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVampireSurvival_GameMode);
UClass* Z_Construct_UClass_AVampireSurvival_GameMode_NoRegister()
{
	return AVampireSurvival_GameMode::StaticClass();
}
struct Z_Construct_UClass_AVampireSurvival_GameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "VampireSurvival_GameMode.h" },
		{ "ModuleRelativePath", "VampireSurvival_GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvival_GameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AVampireSurvival_GameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvival_GameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVampireSurvival_GameMode_Statics::ClassParams = {
	&AVampireSurvival_GameMode::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvival_GameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AVampireSurvival_GameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVampireSurvival_GameMode()
{
	if (!Z_Registration_Info_UClass_AVampireSurvival_GameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVampireSurvival_GameMode.OuterSingleton, Z_Construct_UClass_AVampireSurvival_GameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVampireSurvival_GameMode.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AVampireSurvival_GameMode>()
{
	return AVampireSurvival_GameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVampireSurvival_GameMode);
AVampireSurvival_GameMode::~AVampireSurvival_GameMode() {}
// End Class AVampireSurvival_GameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_GameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvival_GameMode, AVampireSurvival_GameMode::StaticClass, TEXT("AVampireSurvival_GameMode"), &Z_Registration_Info_UClass_AVampireSurvival_GameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvival_GameMode), 3761690407U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_GameMode_h_436675477(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_GameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_GameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
