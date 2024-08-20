// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MainGameLevel/VampireSurvivalCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FInputActionValue;
#ifdef VAMPIRESURVIVAL_VampireSurvivalCharacter_generated_h
#error "VampireSurvivalCharacter.generated.h already included, missing '#pragma once' in VampireSurvivalCharacter.h"
#endif
#define VAMPIRESURVIVAL_VampireSurvivalCharacter_generated_h

#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Client_PressedPickUpWeaponKey_Implementation(AActor* NewWeapon); \
	virtual void Server_PressedPickUpWeaponKey_Implementation(); \
	virtual void Server_RequestReload_Implementation(bool Newbool); \
	virtual void Server_RequestFire_Implementation(bool Newbool); \
	virtual void ChanageMovementSpeed_Implementation(float Speed); \
	virtual void PlayerIsNotRun_Implementation(); \
	virtual void PlayerIsRun_Implementation(); \
	DECLARE_FUNCTION(execClient_PressedPickUpWeaponKey); \
	DECLARE_FUNCTION(execServer_PressedPickUpWeaponKey); \
	DECLARE_FUNCTION(execFindNearWeapon); \
	DECLARE_FUNCTION(execWeaponNotfire); \
	DECLARE_FUNCTION(execServer_RequestReload); \
	DECLARE_FUNCTION(execServer_RequestFire); \
	DECLARE_FUNCTION(execOnReq_Reload); \
	DECLARE_FUNCTION(execOnReq_Fire); \
	DECLARE_FUNCTION(execChanageMovementSpeed); \
	DECLARE_FUNCTION(execPlayerIsNotRun); \
	DECLARE_FUNCTION(execPlayerIsRun); \
	DECLARE_FUNCTION(execWeaponfire); \
	DECLARE_FUNCTION(execZoominMode);


#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_CALLBACK_WRAPPERS
#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVampireSurvivalCharacter(); \
	friend struct Z_Construct_UClass_AVampireSurvivalCharacter_Statics; \
public: \
	DECLARE_CLASS(AVampireSurvivalCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VampireSurvival"), NO_API) \
	DECLARE_SERIALIZER(AVampireSurvivalCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsfire=NETFIELD_REP_START, \
		bIsReload, \
		NETFIELD_REP_END=bIsReload	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AVampireSurvivalCharacter(AVampireSurvivalCharacter&&); \
	AVampireSurvivalCharacter(const AVampireSurvivalCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVampireSurvivalCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVampireSurvivalCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVampireSurvivalCharacter) \
	NO_API virtual ~AVampireSurvivalCharacter();


#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_11_PROLOG
#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_CALLBACK_WRAPPERS \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_INCLASS_NO_PURE_DECLS \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VAMPIRESURVIVAL_API UClass* StaticClass<class AVampireSurvivalCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainGameLevel_VampireSurvivalCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
