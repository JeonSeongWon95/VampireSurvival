// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/Enemy/EnemySpawner.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemySpawner() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AEnemySpawner();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AEnemySpawner_NoRegister();
// End Cross Module References

// Begin Class AEnemySpawner Function SpawnEnemy
struct EnemySpawner_eventSpawnEnemy_Parms
{
	float DeltaTime;
};
static FName NAME_AEnemySpawner_SpawnEnemy = FName(TEXT("SpawnEnemy"));
void AEnemySpawner::SpawnEnemy(float DeltaTime)
{
	EnemySpawner_eventSpawnEnemy_Parms Parms;
	Parms.DeltaTime=DeltaTime;
	ProcessEvent(FindFunctionChecked(NAME_AEnemySpawner_SpawnEnemy),&Parms);
}
struct Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EnemySpawner_eventSpawnEnemy_Parms, DeltaTime), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::NewProp_DeltaTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemySpawner, nullptr, "SpawnEnemy", nullptr, nullptr, Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::PropPointers), sizeof(EnemySpawner_eventSpawnEnemy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::Function_MetaDataParams) };
static_assert(sizeof(EnemySpawner_eventSpawnEnemy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEnemySpawner_SpawnEnemy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemySpawner_SpawnEnemy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEnemySpawner::execSpawnEnemy)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DeltaTime);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnEnemy_Implementation(Z_Param_DeltaTime);
	P_NATIVE_END;
}
// End Class AEnemySpawner Function SpawnEnemy

// Begin Class AEnemySpawner
void AEnemySpawner::StaticRegisterNativesAEnemySpawner()
{
	UClass* Class = AEnemySpawner::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SpawnEnemy", &AEnemySpawner::execSpawnEnemy },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemySpawner);
UClass* Z_Construct_UClass_AEnemySpawner_NoRegister()
{
	return AEnemySpawner::StaticClass();
}
struct Z_Construct_UClass_AEnemySpawner_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MainGameLevel/Enemy/EnemySpawner.h" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnTick_MetaData[] = {
		{ "Category", "Timer" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnTime_MetaData[] = {
		{ "Category", "Timer" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[] = {
		{ "Category", "SpawnActor" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MyTransform_MetaData[] = {
		{ "Category", "SpawnLocation" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainGameLevel/Enemy/EnemySpawner.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnTick;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnTime;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Actor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MyTransform;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemySpawner_SpawnEnemy, "SpawnEnemy" }, // 2678937412
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemySpawner>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemySpawner_Statics::NewProp_SpawnTick = { "SpawnTick", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemySpawner, SpawnTick), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnTick_MetaData), NewProp_SpawnTick_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemySpawner_Statics::NewProp_SpawnTime = { "SpawnTime", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemySpawner, SpawnTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnTime_MetaData), NewProp_SpawnTime_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AEnemySpawner_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Class | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemySpawner, Actor), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Actor_MetaData), NewProp_Actor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEnemySpawner_Statics::NewProp_MyTransform = { "MyTransform", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemySpawner, MyTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MyTransform_MetaData), NewProp_MyTransform_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemySpawner_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemySpawner, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneComponent_MetaData), NewProp_SceneComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemySpawner_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemySpawner_Statics::NewProp_SpawnTick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemySpawner_Statics::NewProp_SpawnTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemySpawner_Statics::NewProp_Actor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemySpawner_Statics::NewProp_MyTransform,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemySpawner_Statics::NewProp_SceneComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawner_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemySpawner_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawner_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemySpawner_Statics::ClassParams = {
	&AEnemySpawner::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEnemySpawner_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawner_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemySpawner_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemySpawner_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemySpawner()
{
	if (!Z_Registration_Info_UClass_AEnemySpawner.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemySpawner.OuterSingleton, Z_Construct_UClass_AEnemySpawner_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemySpawner.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AEnemySpawner>()
{
	return AEnemySpawner::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemySpawner);
AEnemySpawner::~AEnemySpawner() {}
// End Class AEnemySpawner

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemySpawner_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemySpawner, AEnemySpawner::StaticClass, TEXT("AEnemySpawner"), &Z_Registration_Info_UClass_AEnemySpawner, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemySpawner), 1264608907U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemySpawner_h_1195734959(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemySpawner_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_EnemySpawner_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
