// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalController.h"
#include "Runtime/Engine/Classes/Engine/TimerHandle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvivalController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalController();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalController_NoRegister();
// End Cross Module References

// Begin Class AVampireSurvivalController
void AVampireSurvivalController::StaticRegisterNativesAVampireSurvivalController()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVampireSurvivalController);
UClass* Z_Construct_UClass_AVampireSurvivalController_NoRegister()
{
	return AVampireSurvivalController::StaticClass();
}
struct Z_Construct_UClass_AVampireSurvivalController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MainGameLevel/VampireSurvivalController.h" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimerHandle_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TimerHandle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvivalController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVampireSurvivalController_Statics::NewProp_TimerHandle = { "TimerHandle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalController, TimerHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimerHandle_MetaData), NewProp_TimerHandle_MetaData) }; // 756291145
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVampireSurvivalController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalController_Statics::NewProp_TimerHandle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVampireSurvivalController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVampireSurvivalController_Statics::ClassParams = {
	&AVampireSurvivalController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AVampireSurvivalController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalController_Statics::Class_MetaDataParams), Z_Construct_UClass_AVampireSurvivalController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVampireSurvivalController()
{
	if (!Z_Registration_Info_UClass_AVampireSurvivalController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVampireSurvivalController.OuterSingleton, Z_Construct_UClass_AVampireSurvivalController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVampireSurvivalController.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AVampireSurvivalController>()
{
	return AVampireSurvivalController::StaticClass();
}
AVampireSurvivalController::AVampireSurvivalController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVampireSurvivalController);
AVampireSurvivalController::~AVampireSurvivalController() {}
// End Class AVampireSurvivalController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvivalController, AVampireSurvivalController::StaticClass, TEXT("AVampireSurvivalController"), &Z_Registration_Info_UClass_AVampireSurvivalController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvivalController), 67008403U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalController_h_1993484171(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
