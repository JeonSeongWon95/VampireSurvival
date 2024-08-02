// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainmenuLevel/MainMenuPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuPawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuPawn();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuPawn_NoRegister();
// End Cross Module References

// Begin Class AMainMenuPawn
void AMainMenuPawn::StaticRegisterNativesAMainMenuPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainMenuPawn);
UClass* Z_Construct_UClass_AMainMenuPawn_NoRegister()
{
	return AMainMenuPawn::StaticClass();
}
struct Z_Construct_UClass_AMainMenuPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MainmenuLevel/MainMenuPawn.h" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMainMenuPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x012408000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMainMenuPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMainMenuPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMainMenuPawn_Statics::NewProp_Camera,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMainMenuPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuPawn_Statics::ClassParams = {
	&AMainMenuPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMainMenuPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainMenuPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainMenuPawn()
{
	if (!Z_Registration_Info_UClass_AMainMenuPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainMenuPawn.OuterSingleton, Z_Construct_UClass_AMainMenuPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainMenuPawn.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AMainMenuPawn>()
{
	return AMainMenuPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuPawn);
AMainMenuPawn::~AMainMenuPawn() {}
// End Class AMainMenuPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainMenuPawn, AMainMenuPawn::StaticClass, TEXT("AMainMenuPawn"), &Z_Registration_Info_UClass_AMainMenuPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainMenuPawn), 623374709U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPawn_h_83953271(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
