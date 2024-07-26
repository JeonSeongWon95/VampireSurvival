// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/EnemyBehaviorTree.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyBehaviorTree() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UEnemyBehaviorTree();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UEnemyBehaviorTree_NoRegister();
// End Cross Module References

// Begin Class UEnemyBehaviorTree
void UEnemyBehaviorTree::StaticRegisterNativesUEnemyBehaviorTree()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UEnemyBehaviorTree);
UClass* Z_Construct_UClass_UEnemyBehaviorTree_NoRegister()
{
	return UEnemyBehaviorTree::StaticClass();
}
struct Z_Construct_UClass_UEnemyBehaviorTree_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "EnemyBehaviorTree.h" },
		{ "ModuleRelativePath", "EnemyBehaviorTree.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEnemyBehaviorTree>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UEnemyBehaviorTree_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBehaviorTree,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyBehaviorTree_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEnemyBehaviorTree_Statics::ClassParams = {
	&UEnemyBehaviorTree::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEnemyBehaviorTree_Statics::Class_MetaDataParams), Z_Construct_UClass_UEnemyBehaviorTree_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEnemyBehaviorTree()
{
	if (!Z_Registration_Info_UClass_UEnemyBehaviorTree.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEnemyBehaviorTree.OuterSingleton, Z_Construct_UClass_UEnemyBehaviorTree_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEnemyBehaviorTree.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<UEnemyBehaviorTree>()
{
	return UEnemyBehaviorTree::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEnemyBehaviorTree);
UEnemyBehaviorTree::~UEnemyBehaviorTree() {}
// End Class UEnemyBehaviorTree

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBehaviorTree_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEnemyBehaviorTree, UEnemyBehaviorTree::StaticClass, TEXT("UEnemyBehaviorTree"), &Z_Registration_Info_UClass_UEnemyBehaviorTree, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEnemyBehaviorTree), 2040432488U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBehaviorTree_h_3696443670(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBehaviorTree_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_EnemyBehaviorTree_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
