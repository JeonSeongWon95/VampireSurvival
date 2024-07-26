// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/VampireSurvivalCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvivalCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter_NoRegister();
// End Cross Module References

// Begin Class AVampireSurvivalCharacter
void AVampireSurvivalCharacter::StaticRegisterNativesAVampireSurvivalCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVampireSurvivalCharacter);
UClass* Z_Construct_UClass_AVampireSurvivalCharacter_NoRegister()
{
	return AVampireSurvivalCharacter::StaticClass();
}
struct Z_Construct_UClass_AVampireSurvivalCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "VampireSurvivalCharacter.h" },
		{ "ModuleRelativePath", "VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "CameraBoom" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_EnhancedMove_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_EnhancedMove;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvivalCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_EnhancedMove = { "IA_EnhancedMove", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_EnhancedMove), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_EnhancedMove_MetaData), NewProp_IA_EnhancedMove_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_EnhancedMove,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AVampireSurvivalCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::ClassParams = {
	&AVampireSurvivalCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVampireSurvivalCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AVampireSurvivalCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AVampireSurvivalCharacter()
{
	if (!Z_Registration_Info_UClass_AVampireSurvivalCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVampireSurvivalCharacter.OuterSingleton, Z_Construct_UClass_AVampireSurvivalCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AVampireSurvivalCharacter.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AVampireSurvivalCharacter>()
{
	return AVampireSurvivalCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVampireSurvivalCharacter);
AVampireSurvivalCharacter::~AVampireSurvivalCharacter() {}
// End Class AVampireSurvivalCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_VampireSurvivalCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvivalCharacter, AVampireSurvivalCharacter::StaticClass, TEXT("AVampireSurvivalCharacter"), &Z_Registration_Info_UClass_AVampireSurvivalCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvivalCharacter), 211176294U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_VampireSurvivalCharacter_h_933380635(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_VampireSurvivalCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_VampireSurvivalCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
