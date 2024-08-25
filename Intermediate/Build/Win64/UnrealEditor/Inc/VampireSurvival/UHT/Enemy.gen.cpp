// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/Enemy/Enemy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemy() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AEnemy();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AEnemy_NoRegister();
// End Cross Module References

// Begin Class AEnemy Function DoDeath
struct Z_Construct_UFunction_AEnemy_DoDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_DoDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "DoDeath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_DoDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemy_DoDeath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEnemy_DoDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_DoDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemy::execDoDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DoDeath();
	P_NATIVE_END;
}
// End Class AEnemy Function DoDeath

// Begin Class AEnemy Function GetBehaviorTree
struct Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics
{
	struct Enemy_eventGetBehaviorTree_Parms
	{
		UBehaviorTree* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Enemy_eventGetBehaviorTree_Parms, ReturnValue), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "GetBehaviorTree", nullptr, nullptr, Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::Enemy_eventGetBehaviorTree_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::Enemy_eventGetBehaviorTree_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEnemy_GetBehaviorTree()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_GetBehaviorTree_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemy::execGetBehaviorTree)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UBehaviorTree**)Z_Param__Result=P_THIS->GetBehaviorTree();
	P_NATIVE_END;
}
// End Class AEnemy Function GetBehaviorTree

// Begin Class AEnemy Function HitBullet
struct Z_Construct_UFunction_AEnemy_HitBullet_Statics
{
	struct Enemy_eventHitBullet_Parms
	{
		int32 Damage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEnemy_HitBullet_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Enemy_eventHitBullet_Parms, Damage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemy_HitBullet_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_HitBullet_Statics::NewProp_Damage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_HitBullet_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_HitBullet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "HitBullet", nullptr, nullptr, Z_Construct_UFunction_AEnemy_HitBullet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_HitBullet_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEnemy_HitBullet_Statics::Enemy_eventHitBullet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_HitBullet_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemy_HitBullet_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AEnemy_HitBullet_Statics::Enemy_eventHitBullet_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEnemy_HitBullet()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_HitBullet_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemy::execHitBullet)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Damage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HitBullet(Z_Param_Damage);
	P_NATIVE_END;
}
// End Class AEnemy Function HitBullet

// Begin Class AEnemy Function OnReq_UpdateHP
struct Z_Construct_UFunction_AEnemy_OnReq_UpdateHP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_OnReq_UpdateHP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "OnReq_UpdateHP", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_OnReq_UpdateHP_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemy_OnReq_UpdateHP_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEnemy_OnReq_UpdateHP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_OnReq_UpdateHP_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemy::execOnReq_UpdateHP)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnReq_UpdateHP();
	P_NATIVE_END;
}
// End Class AEnemy Function OnReq_UpdateHP

// Begin Class AEnemy Function Server_DoDeath
static FName NAME_AEnemy_Server_DoDeath = FName(TEXT("Server_DoDeath"));
void AEnemy::Server_DoDeath()
{
	ProcessEvent(FindFunctionChecked(NAME_AEnemy_Server_DoDeath),NULL);
}
struct Z_Construct_UFunction_AEnemy_Server_DoDeath_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_Server_DoDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "Server_DoDeath", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Server_DoDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemy_Server_DoDeath_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AEnemy_Server_DoDeath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_Server_DoDeath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemy::execServer_DoDeath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_DoDeath_Implementation();
	P_NATIVE_END;
}
// End Class AEnemy Function Server_DoDeath

// Begin Class AEnemy Function Server_RequestAddDamage
struct Enemy_eventServer_RequestAddDamage_Parms
{
	int32 Damage;
};
static FName NAME_AEnemy_Server_RequestAddDamage = FName(TEXT("Server_RequestAddDamage"));
void AEnemy::Server_RequestAddDamage(int32 Damage)
{
	Enemy_eventServer_RequestAddDamage_Parms Parms;
	Parms.Damage=Damage;
	ProcessEvent(FindFunctionChecked(NAME_AEnemy_Server_RequestAddDamage),&Parms);
}
struct Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Damage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Enemy_eventServer_RequestAddDamage_Parms, Damage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::NewProp_Damage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemy, nullptr, "Server_RequestAddDamage", nullptr, nullptr, Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::PropPointers), sizeof(Enemy_eventServer_RequestAddDamage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::Function_MetaDataParams) };
static_assert(sizeof(Enemy_eventServer_RequestAddDamage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEnemy_Server_RequestAddDamage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemy_Server_RequestAddDamage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemy::execServer_RequestAddDamage)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Damage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_RequestAddDamage_Implementation(Z_Param_Damage);
	P_NATIVE_END;
}
// End Class AEnemy Function Server_RequestAddDamage

// Begin Class AEnemy
void AEnemy::StaticRegisterNativesAEnemy()
{
	UClass* Class = AEnemy::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DoDeath", &AEnemy::execDoDeath },
		{ "GetBehaviorTree", &AEnemy::execGetBehaviorTree },
		{ "HitBullet", &AEnemy::execHitBullet },
		{ "OnReq_UpdateHP", &AEnemy::execOnReq_UpdateHP },
		{ "Server_DoDeath", &AEnemy::execServer_DoDeath },
		{ "Server_RequestAddDamage", &AEnemy::execServer_RequestAddDamage },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemy);
UClass* Z_Construct_UClass_AEnemy_NoRegister()
{
	return AEnemy::StaticClass();
}
struct Z_Construct_UClass_AEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MainGameLevel/Enemy/Enemy.h" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Tree_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/Enemy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Health;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Tree;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemy_DoDeath, "DoDeath" }, // 1298180404
		{ &Z_Construct_UFunction_AEnemy_GetBehaviorTree, "GetBehaviorTree" }, // 1353545247
		{ &Z_Construct_UFunction_AEnemy_HitBullet, "HitBullet" }, // 2742965570
		{ &Z_Construct_UFunction_AEnemy_OnReq_UpdateHP, "OnReq_UpdateHP" }, // 3621165456
		{ &Z_Construct_UFunction_AEnemy_Server_DoDeath, "Server_DoDeath" }, // 346757147
		{ &Z_Construct_UFunction_AEnemy_Server_RequestAddDamage, "Server_RequestAddDamage" }, // 3863660729
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_Health = { "Health", "OnReq_UpdateHP", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemy, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemy_Statics::NewProp_Tree = { "Tree", nullptr, (EPropertyFlags)0x0114000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemy, Tree), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Tree_MetaData), NewProp_Tree_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemy_Statics::NewProp_Tree,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemy_Statics::ClassParams = {
	&AEnemy::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEnemy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemy()
{
	if (!Z_Registration_Info_UClass_AEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemy.OuterSingleton, Z_Construct_UClass_AEnemy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemy.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AEnemy>()
{
	return AEnemy::StaticClass();
}
void AEnemy::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_Health(TEXT("Health"));
	const bool bIsValid = true
		&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AEnemy"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemy);
AEnemy::~AEnemy() {}
// End Class AEnemy

// Begin Registration
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemy, AEnemy::StaticClass, TEXT("AEnemy"), &Z_Registration_Info_UClass_AEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemy), 1016991052U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_1176765879(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
