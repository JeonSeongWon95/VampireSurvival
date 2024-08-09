// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalCharacter.h"
<<<<<<< HEAD
#include "Runtime/Engine/Classes/Engine/TimerHandle.h"
=======
>>>>>>> ca43513 (git 수정)
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvivalCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter_NoRegister();
// End Cross Module References

<<<<<<< HEAD
// Begin Class AVampireSurvivalCharacter Function Weaponfire
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics
=======
// Begin Class AVampireSurvivalCharacter Function ZoominMode
struct Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode_Statics
>>>>>>> ca43513 (git 수정)
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
<<<<<<< HEAD
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Weaponfire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire()
=======
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "ZoominMode", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode()
>>>>>>> ca43513 (git 수정)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
<<<<<<< HEAD
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execWeaponfire)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Weaponfire();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Weaponfire
=======
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execZoominMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ZoominMode();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function ZoominMode
>>>>>>> ca43513 (git 수정)

// Begin Class AVampireSurvivalCharacter
void AVampireSurvivalCharacter::StaticRegisterNativesAVampireSurvivalCharacter()
{
	UClass* Class = AVampireSurvivalCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
<<<<<<< HEAD
		{ "Weaponfire", &AVampireSurvivalCharacter::execWeaponfire },
=======
		{ "ZoominMode", &AVampireSurvivalCharacter::execZoominMode },
>>>>>>> ca43513 (git 수정)
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
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
		{ "IncludePath", "MainGameLevel/VampireSurvivalCharacter.h" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
		{ "Category", "CameraBoom" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_EnhancedMove_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
<<<<<<< HEAD
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Run_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_OnAim_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Fire_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterTimer_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOnAim_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VSCharacterMovement_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
=======
>>>>>>> ca43513 (git 수정)
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_EnhancedMove;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Run;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_OnAim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Fire;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterTimer;
	static void NewProp_bIsOnAim_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnAim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VSCharacterMovement;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
<<<<<<< HEAD
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire, "Weaponfire" }, // 2717613170
=======
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_ZoominMode, "ZoominMode" }, // 1328208230
>>>>>>> ca43513 (git 수정)
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvivalCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_EnhancedMove = { "IA_EnhancedMove", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_EnhancedMove), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_EnhancedMove_MetaData), NewProp_IA_EnhancedMove_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Run = { "IA_Run", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_Run), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Run_MetaData), NewProp_IA_Run_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_OnAim = { "IA_OnAim", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_OnAim), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_OnAim_MetaData), NewProp_IA_OnAim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Fire = { "IA_Fire", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_Fire), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Fire_MetaData), NewProp_IA_Fire_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CharacterTimer = { "CharacterTimer", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, CharacterTimer), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterTimer_MetaData), NewProp_CharacterTimer_MetaData) }; // 756291145
void Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim_SetBit(void* Obj)
{
	((AVampireSurvivalCharacter*)Obj)->bIsOnAim = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim = { "bIsOnAim", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVampireSurvivalCharacter), &Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOnAim_MetaData), NewProp_bIsOnAim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_VSCharacterMovement = { "VSCharacterMovement", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, VSCharacterMovement), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VSCharacterMovement_MetaData), NewProp_VSCharacterMovement_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_EnhancedMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Run,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_OnAim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Fire,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CharacterTimer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_VSCharacterMovement,
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
	FuncInfo,
	Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
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
<<<<<<< HEAD
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvivalCharacter, AVampireSurvivalCharacter::StaticClass, TEXT("AVampireSurvivalCharacter"), &Z_Registration_Info_UClass_AVampireSurvivalCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvivalCharacter), 99183661U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_3948502203(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics::ClassInfo),
=======
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvivalCharacter, AVampireSurvivalCharacter::StaticClass, TEXT("AVampireSurvivalCharacter"), &Z_Registration_Info_UClass_AVampireSurvivalCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvivalCharacter), 3784334049U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_148622011(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics::ClassInfo),
>>>>>>> ca43513 (git 수정)
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
