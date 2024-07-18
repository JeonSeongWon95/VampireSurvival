// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/VampireSurvival_Controller.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvival_Controller() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvival_Controller();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvival_Controller_NoRegister();
// End Cross Module References

// Begin Class AVampireSurvival_Controller
void AVampireSurvival_Controller::StaticRegisterNativesAVampireSurvival_Controller()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVampireSurvival_Controller);
UClass* Z_Construct_UClass_AVampireSurvival_Controller_NoRegister()
{
	return AVampireSurvival_Controller::StaticClass();
}
struct Z_Construct_UClass_AVampireSurvival_Controller_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "VampireSurvival_Controller.h" },
		{ "ModuleRelativePath", "VampireSurvival_Controller.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "VampireSurvival_Controller.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvival_Controller>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvival_Controller_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvival_Controller, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVampireSurvival_Controller_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvival_Controller_Statics::NewProp_InputMappingContext,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvival_Controller_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVampireSurvival_Controller_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvival_Controller_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVampireSurvival_Controller_Statics::ClassParams = {
	&AVampireSurvival_Controller::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AVampireSurvival_Controller_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvival_Controller_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvival_Controller_Statics::Class_MetaDataParams), Z_Construct_UClass_AVampireSurvival_Controller_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVampireSurvival_Controller()
{
	if (!Z_Registration_Info_UClass_AVampireSurvival_Controller.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVampireSurvival_Controller.OuterSingleton, Z_Construct_UClass_AVampireSurvival_Controller_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVampireSurvival_Controller.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AVampireSurvival_Controller>()
{
	return AVampireSurvival_Controller::StaticClass();
}
AVampireSurvival_Controller::AVampireSurvival_Controller(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVampireSurvival_Controller);
AVampireSurvival_Controller::~AVampireSurvival_Controller() {}
// End Class AVampireSurvival_Controller

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_Controller_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvival_Controller, AVampireSurvival_Controller::StaticClass, TEXT("AVampireSurvival_Controller"), &Z_Registration_Info_UClass_AVampireSurvival_Controller, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvival_Controller), 1002385752U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_Controller_h_2855569371(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_Controller_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_L20240704_VampireSurvival_Source_VampireSurvival_VampireSurvival_Controller_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
