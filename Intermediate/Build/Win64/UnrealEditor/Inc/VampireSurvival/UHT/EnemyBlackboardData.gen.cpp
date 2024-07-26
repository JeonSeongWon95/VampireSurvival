// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/EnemyBlackboardData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyBlackboardData() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter_NoRegister();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UEnemyBlackboardData();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UEnemyBlackboardData_NoRegister();
// End Cross Module References

// Begin Class UEnemyBlackboardData
void UEnemyBlackboardData::StaticRegisterNativesUEnemyBlackboardData()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyBlackboardData);
UClass* Z_Construct_UClass_UEnemyBlackboardData_NoRegister()
{
	return UEnemyBlackboardData::StaticClass();
}
struct Z_Construct_UClass_UEnemyBlackboardData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "Blackboard" },
		{ "IncludePath", "EnemyBlackboardData.h" },
		{ "ModuleRelativePath", "EnemyBlackboardData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "Category", "Target" },
		{ "ModuleRelativePath", "EnemyBlackboardData.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyBlackboardData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEnemyBlackboardData_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEnemyBlackboardData, Target), Z_Construct_UClass_AVampireSurvivalCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEnemyBlackboardData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEnemyBlackboardData_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyBlackboardData_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEnemyBlackboardData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlackboardData,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyBlackboardData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyBlackboardData_Statics::ClassParams = {
	&UEnemyBlackboardData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UEnemyBlackboardData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyBlackboardData_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyBlackboardData_Statics::Class_MetaDataParams), Z_Construct_UClass_UEnemyBlackboardData_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEnemyBlackboardData()
{
	if (!Z_Registration_Info_UClass_UEnemyBlackboardData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyBlackboardData.OuterSingleton, Z_Construct_UClass_UEnemyBlackboardData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEnemyBlackboardData.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<UEnemyBlackboardData>()
{
	return UEnemyBlackboardData::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyBlackboardData);
UEnemyBlackboardData::~UEnemyBlackboardData() {}
// End Class UEnemyBlackboardData

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBlackboardData_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyBlackboardData, UEnemyBlackboardData::StaticClass, TEXT("UEnemyBlackboardData"), &Z_Registration_Info_UClass_UEnemyBlackboardData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyBlackboardData), 3210602853U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBlackboardData_h_1038306096(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBlackboardData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBlackboardData_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
