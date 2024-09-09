// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalCharacter.h"
#include "EnhancedInput/Public/InputActionValue.h"
#include "Runtime/Engine/Classes/Engine/TimerHandle.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVampireSurvivalCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AVampireSurvivalCharacter_NoRegister();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AWeapon_NoRegister();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_UInventoryComponent_NoRegister();
// End Cross Module References

// Begin Class AVampireSurvivalCharacter Function ChanageMovementSpeed
struct VampireSurvivalCharacter_eventChanageMovementSpeed_Parms
{
	float Speed;
};
static FName NAME_AVampireSurvivalCharacter_ChanageMovementSpeed = FName(TEXT("ChanageMovementSpeed"));
void AVampireSurvivalCharacter::ChanageMovementSpeed(float Speed)
{
	VampireSurvivalCharacter_eventChanageMovementSpeed_Parms Parms;
	Parms.Speed=Speed;
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_ChanageMovementSpeed),&Parms);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::NewProp_Speed = { "Speed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VampireSurvivalCharacter_eventChanageMovementSpeed_Parms, Speed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::NewProp_Speed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "ChanageMovementSpeed", nullptr, nullptr, Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::PropPointers), sizeof(VampireSurvivalCharacter_eventChanageMovementSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::Function_MetaDataParams) };
static_assert(sizeof(VampireSurvivalCharacter_eventChanageMovementSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execChanageMovementSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Speed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ChanageMovementSpeed_Implementation(Z_Param_Speed);
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function ChanageMovementSpeed

// Begin Class AVampireSurvivalCharacter Function Client_PressedPickUpWeaponKey
struct VampireSurvivalCharacter_eventClient_PressedPickUpWeaponKey_Parms
{
	AActor* NewWeapon;
};
static FName NAME_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey = FName(TEXT("Client_PressedPickUpWeaponKey"));
void AVampireSurvivalCharacter::Client_PressedPickUpWeaponKey(AActor* NewWeapon)
{
	VampireSurvivalCharacter_eventClient_PressedPickUpWeaponKey_Parms Parms;
	Parms.NewWeapon=NewWeapon;
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey),&Parms);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NewWeapon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::NewProp_NewWeapon = { "NewWeapon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VampireSurvivalCharacter_eventClient_PressedPickUpWeaponKey_Parms, NewWeapon), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::NewProp_NewWeapon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Client_PressedPickUpWeaponKey", nullptr, nullptr, Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::PropPointers), sizeof(VampireSurvivalCharacter_eventClient_PressedPickUpWeaponKey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00024CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::Function_MetaDataParams) };
static_assert(sizeof(VampireSurvivalCharacter_eventClient_PressedPickUpWeaponKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execClient_PressedPickUpWeaponKey)
{
	P_GET_OBJECT(AActor,Z_Param_NewWeapon);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Client_PressedPickUpWeaponKey_Implementation(Z_Param_NewWeapon);
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Client_PressedPickUpWeaponKey

// Begin Class AVampireSurvivalCharacter Function ClientRequestFireFalse
struct Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "ClientRequestFireFalse", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execClientRequestFireFalse)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRequestFireFalse();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function ClientRequestFireFalse

// Begin Class AVampireSurvivalCharacter Function FindNearWeapon
struct Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics
{
	struct VampireSurvivalCharacter_eventFindNearWeapon_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VampireSurvivalCharacter_eventFindNearWeapon_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "FindNearWeapon", nullptr, nullptr, Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::VampireSurvivalCharacter_eventFindNearWeapon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::VampireSurvivalCharacter_eventFindNearWeapon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execFindNearWeapon)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->FindNearWeapon();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function FindNearWeapon

// Begin Class AVampireSurvivalCharacter Function OnReq_Fire
struct Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "OnReq_Fire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execOnReq_Fire)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnReq_Fire();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function OnReq_Fire

// Begin Class AVampireSurvivalCharacter Function OnReq_Reload
struct Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "OnReq_Reload", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execOnReq_Reload)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnReq_Reload();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function OnReq_Reload

// Begin Class AVampireSurvivalCharacter Function PlayerIsNotRun
static FName NAME_AVampireSurvivalCharacter_PlayerIsNotRun = FName(TEXT("PlayerIsNotRun"));
void AVampireSurvivalCharacter::PlayerIsNotRun()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_PlayerIsNotRun),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "PlayerIsNotRun", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execPlayerIsNotRun)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayerIsNotRun_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function PlayerIsNotRun

// Begin Class AVampireSurvivalCharacter Function PlayerIsRun
static FName NAME_AVampireSurvivalCharacter_PlayerIsRun = FName(TEXT("PlayerIsRun"));
void AVampireSurvivalCharacter::PlayerIsRun()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_PlayerIsRun),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "PlayerIsRun", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execPlayerIsRun)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayerIsRun_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function PlayerIsRun

// Begin Class AVampireSurvivalCharacter Function Server_ChangeFireFalse
static FName NAME_AVampireSurvivalCharacter_Server_ChangeFireFalse = FName(TEXT("Server_ChangeFireFalse"));
void AVampireSurvivalCharacter::Server_ChangeFireFalse()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Server_ChangeFireFalse),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Server_ChangeFireFalse", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execServer_ChangeFireFalse)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_ChangeFireFalse_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Server_ChangeFireFalse

// Begin Class AVampireSurvivalCharacter Function Server_PressedPickUpWeaponKey
static FName NAME_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey = FName(TEXT("Server_PressedPickUpWeaponKey"));
void AVampireSurvivalCharacter::Server_PressedPickUpWeaponKey()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Server_PressedPickUpWeaponKey", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execServer_PressedPickUpWeaponKey)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_PressedPickUpWeaponKey_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Server_PressedPickUpWeaponKey

// Begin Class AVampireSurvivalCharacter Function Server_RequestAimMode
static FName NAME_AVampireSurvivalCharacter_Server_RequestAimMode = FName(TEXT("Server_RequestAimMode"));
void AVampireSurvivalCharacter::Server_RequestAimMode()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Server_RequestAimMode),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Server_RequestAimMode", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execServer_RequestAimMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_RequestAimMode_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Server_RequestAimMode

// Begin Class AVampireSurvivalCharacter Function Server_RequestAimModeFasle
static FName NAME_AVampireSurvivalCharacter_Server_RequestAimModeFasle = FName(TEXT("Server_RequestAimModeFasle"));
void AVampireSurvivalCharacter::Server_RequestAimModeFasle()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Server_RequestAimModeFasle),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Server_RequestAimModeFasle", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execServer_RequestAimModeFasle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_RequestAimModeFasle_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Server_RequestAimModeFasle

// Begin Class AVampireSurvivalCharacter Function Server_RequestFire
static FName NAME_AVampireSurvivalCharacter_Server_RequestFire = FName(TEXT("Server_RequestFire"));
void AVampireSurvivalCharacter::Server_RequestFire()
{
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Server_RequestFire),NULL);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Server_RequestFire", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execServer_RequestFire)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_RequestFire_Implementation();
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Server_RequestFire

// Begin Class AVampireSurvivalCharacter Function Server_RequestReload
struct VampireSurvivalCharacter_eventServer_RequestReload_Parms
{
	bool Newbool;
};
static FName NAME_AVampireSurvivalCharacter_Server_RequestReload = FName(TEXT("Server_RequestReload"));
void AVampireSurvivalCharacter::Server_RequestReload(bool Newbool)
{
	VampireSurvivalCharacter_eventServer_RequestReload_Parms Parms;
	Parms.Newbool=Newbool ? true : false;
	ProcessEvent(FindFunctionChecked(NAME_AVampireSurvivalCharacter_Server_RequestReload),&Parms);
}
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static void NewProp_Newbool_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Newbool;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::NewProp_Newbool_SetBit(void* Obj)
{
	((VampireSurvivalCharacter_eventServer_RequestReload_Parms*)Obj)->Newbool = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::NewProp_Newbool = { "Newbool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VampireSurvivalCharacter_eventServer_RequestReload_Parms), &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::NewProp_Newbool_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::NewProp_Newbool,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Server_RequestReload", nullptr, nullptr, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::PropPointers), sizeof(VampireSurvivalCharacter_eventServer_RequestReload_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::Function_MetaDataParams) };
static_assert(sizeof(VampireSurvivalCharacter_eventServer_RequestReload_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execServer_RequestReload)
{
	P_GET_UBOOL(Z_Param_Newbool);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Server_RequestReload_Implementation(Z_Param_Newbool);
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Server_RequestReload

// Begin Class AVampireSurvivalCharacter Function Weaponfire
struct Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics
{
	struct VampireSurvivalCharacter_eventWeaponfire_Parms
	{
		FInputActionValue Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VampireSurvivalCharacter_eventWeaponfire_Parms, Value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVampireSurvivalCharacter, nullptr, "Weaponfire", nullptr, nullptr, Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::VampireSurvivalCharacter_eventWeaponfire_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::VampireSurvivalCharacter_eventWeaponfire_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AVampireSurvivalCharacter::execWeaponfire)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Weaponfire(Z_Param_Out_Value);
	P_NATIVE_END;
}
// End Class AVampireSurvivalCharacter Function Weaponfire

// Begin Class AVampireSurvivalCharacter
void AVampireSurvivalCharacter::StaticRegisterNativesAVampireSurvivalCharacter()
{
	UClass* Class = AVampireSurvivalCharacter::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ChanageMovementSpeed", &AVampireSurvivalCharacter::execChanageMovementSpeed },
		{ "Client_PressedPickUpWeaponKey", &AVampireSurvivalCharacter::execClient_PressedPickUpWeaponKey },
		{ "ClientRequestFireFalse", &AVampireSurvivalCharacter::execClientRequestFireFalse },
		{ "FindNearWeapon", &AVampireSurvivalCharacter::execFindNearWeapon },
		{ "OnReq_Fire", &AVampireSurvivalCharacter::execOnReq_Fire },
		{ "OnReq_Reload", &AVampireSurvivalCharacter::execOnReq_Reload },
		{ "PlayerIsNotRun", &AVampireSurvivalCharacter::execPlayerIsNotRun },
		{ "PlayerIsRun", &AVampireSurvivalCharacter::execPlayerIsRun },
		{ "Server_ChangeFireFalse", &AVampireSurvivalCharacter::execServer_ChangeFireFalse },
		{ "Server_PressedPickUpWeaponKey", &AVampireSurvivalCharacter::execServer_PressedPickUpWeaponKey },
		{ "Server_RequestAimMode", &AVampireSurvivalCharacter::execServer_RequestAimMode },
		{ "Server_RequestAimModeFasle", &AVampireSurvivalCharacter::execServer_RequestAimModeFasle },
		{ "Server_RequestFire", &AVampireSurvivalCharacter::execServer_RequestFire },
		{ "Server_RequestReload", &AVampireSurvivalCharacter::execServer_RequestReload },
		{ "Weaponfire", &AVampireSurvivalCharacter::execWeaponfire },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Inven_MetaData[] = {
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_EnhancedMove_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_PickUpWeapon_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_Reload_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IA_OpenInventory_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterTimer_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOpen_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EquipWeapon_MetaData[] = {
		{ "Category", "EquipWeapon" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VSCharacterMovement_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsfire_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsReload_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOnAim_MetaData[] = {
		{ "ModuleRelativePath", "MainGameLevel/VampireSurvivalCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Inven;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_EnhancedMove;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Run;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_OnAim;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Fire;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_PickUpWeapon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_Reload;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IA_OpenInventory;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterTimer;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FireRate;
	static const UECodeGen_Private::FBytePropertyParams NewProp_bIsOpen;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EquipWeapon;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VSCharacterMovement;
	static void NewProp_bIsfire_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsfire;
	static void NewProp_bIsReload_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReload;
	static void NewProp_bIsOnAim_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnAim;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_ChanageMovementSpeed, "ChanageMovementSpeed" }, // 2451645743
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Client_PressedPickUpWeaponKey, "Client_PressedPickUpWeaponKey" }, // 4140316836
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_ClientRequestFireFalse, "ClientRequestFireFalse" }, // 2990627071
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_FindNearWeapon, "FindNearWeapon" }, // 200955537
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Fire, "OnReq_Fire" }, // 3592403789
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_OnReq_Reload, "OnReq_Reload" }, // 4265836618
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsNotRun, "PlayerIsNotRun" }, // 1430601094
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_PlayerIsRun, "PlayerIsRun" }, // 3508734660
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_ChangeFireFalse, "Server_ChangeFireFalse" }, // 959594593
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_PressedPickUpWeaponKey, "Server_PressedPickUpWeaponKey" }, // 1776604652
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimMode, "Server_RequestAimMode" }, // 2108775026
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestAimModeFasle, "Server_RequestAimModeFasle" }, // 3881666089
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestFire, "Server_RequestFire" }, // 3570723606
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Server_RequestReload, "Server_RequestReload" }, // 2780591193
		{ &Z_Construct_UFunction_AVampireSurvivalCharacter_Weaponfire, "Weaponfire" }, // 4028082610
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVampireSurvivalCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraBoom_MetaData), NewProp_CameraBoom_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Inven = { "Inven", nullptr, (EPropertyFlags)0x01240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, Inven), Z_Construct_UClass_UInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Inven_MetaData), NewProp_Inven_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_EnhancedMove = { "IA_EnhancedMove", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_EnhancedMove), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_EnhancedMove_MetaData), NewProp_IA_EnhancedMove_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Run = { "IA_Run", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_Run), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Run_MetaData), NewProp_IA_Run_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_OnAim = { "IA_OnAim", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_OnAim), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_OnAim_MetaData), NewProp_IA_OnAim_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Fire = { "IA_Fire", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_Fire), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Fire_MetaData), NewProp_IA_Fire_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_PickUpWeapon = { "IA_PickUpWeapon", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_PickUpWeapon), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_PickUpWeapon_MetaData), NewProp_IA_PickUpWeapon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0124080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InputMappingContext_MetaData), NewProp_InputMappingContext_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Reload = { "IA_Reload", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_Reload), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_Reload_MetaData), NewProp_IA_Reload_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_OpenInventory = { "IA_OpenInventory", nullptr, (EPropertyFlags)0x0124080000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, IA_OpenInventory), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IA_OpenInventory_MetaData), NewProp_IA_OpenInventory_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CharacterTimer = { "CharacterTimer", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, CharacterTimer), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterTimer_MetaData), NewProp_CharacterTimer_MetaData) }; // 756291145
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, FireRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireRate_MetaData), NewProp_FireRate_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOpen = { "bIsOpen", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, bIsOpen), nullptr, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOpen_MetaData), NewProp_bIsOpen_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_EquipWeapon = { "EquipWeapon", nullptr, (EPropertyFlags)0x0114000000020005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, EquipWeapon), Z_Construct_UClass_AWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EquipWeapon_MetaData), NewProp_EquipWeapon_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_VSCharacterMovement = { "VSCharacterMovement", nullptr, (EPropertyFlags)0x011400000008000d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVampireSurvivalCharacter, VSCharacterMovement), Z_Construct_UClass_UCharacterMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VSCharacterMovement_MetaData), NewProp_VSCharacterMovement_MetaData) };
void Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsfire_SetBit(void* Obj)
{
	((AVampireSurvivalCharacter*)Obj)->bIsfire = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsfire = { "bIsfire", "OnReq_Fire", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVampireSurvivalCharacter), &Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsfire_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsfire_MetaData), NewProp_bIsfire_MetaData) };
void Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsReload_SetBit(void* Obj)
{
	((AVampireSurvivalCharacter*)Obj)->bIsReload = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsReload = { "bIsReload", "OnReq_Reload", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVampireSurvivalCharacter), &Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsReload_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsReload_MetaData), NewProp_bIsReload_MetaData) };
void Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim_SetBit(void* Obj)
{
	((AVampireSurvivalCharacter*)Obj)->bIsOnAim = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim = { "bIsOnAim", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVampireSurvivalCharacter), &Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOnAim_MetaData), NewProp_bIsOnAim_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVampireSurvivalCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CameraBoom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_Inven,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_EnhancedMove,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Run,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_OnAim,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Fire,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_PickUpWeapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_InputMappingContext,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_Reload,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_IA_OpenInventory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_CharacterTimer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_FireRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOpen,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_EquipWeapon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_VSCharacterMovement,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsfire,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsReload,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVampireSurvivalCharacter_Statics::NewProp_bIsOnAim,
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
void AVampireSurvivalCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static const FName Name_bIsfire(TEXT("bIsfire"));
	static const FName Name_bIsReload(TEXT("bIsReload"));
	static const FName Name_bIsOnAim(TEXT("bIsOnAim"));
	const bool bIsValid = true
		&& Name_bIsfire == ClassReps[(int32)ENetFields_Private::bIsfire].Property->GetFName()
		&& Name_bIsReload == ClassReps[(int32)ENetFields_Private::bIsReload].Property->GetFName()
		&& Name_bIsOnAim == ClassReps[(int32)ENetFields_Private::bIsOnAim].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AVampireSurvivalCharacter"));
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AVampireSurvivalCharacter);
AVampireSurvivalCharacter::~AVampireSurvivalCharacter() {}
// End Class AVampireSurvivalCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AVampireSurvivalCharacter, AVampireSurvivalCharacter::StaticClass, TEXT("AVampireSurvivalCharacter"), &Z_Registration_Info_UClass_AVampireSurvivalCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVampireSurvivalCharacter), 3404873452U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_3568066274(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Unreal_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
