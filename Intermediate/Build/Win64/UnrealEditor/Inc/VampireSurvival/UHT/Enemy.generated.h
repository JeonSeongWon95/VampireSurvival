// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MainGameLevel/Enemy/Enemy.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBehaviorTree;
#ifdef VAMPIRESURVIVAL_Enemy_generated_h
#error "Enemy.generated.h already included, missing '#pragma once' in Enemy.h"
#endif
#define VAMPIRESURVIVAL_Enemy_generated_h

#define FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Server_DoDeath_Implementation(); \
	virtual void Server_RequestAddDamage_Implementation(int32 Damage); \
	DECLARE_FUNCTION(execCanMove); \
	DECLARE_FUNCTION(execCantMove); \
	DECLARE_FUNCTION(execServer_DoDeath); \
	DECLARE_FUNCTION(execDoDeath); \
	DECLARE_FUNCTION(execOnReq_UpdateHP); \
	DECLARE_FUNCTION(execServer_RequestAddDamage); \
	DECLARE_FUNCTION(execHitBullet); \
	DECLARE_FUNCTION(execGetBehaviorTree);


#define FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_CALLBACK_WRAPPERS
#define FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy(); \
	friend struct Z_Construct_UClass_AEnemy_Statics; \
public: \
	DECLARE_CLASS(AEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VampireSurvival"), NO_API) \
	DECLARE_SERIALIZER(AEnemy) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		NETFIELD_REP_END=Health	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEnemy(AEnemy&&); \
	AEnemy(const AEnemy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemy) \
	NO_API virtual ~AEnemy();


#define FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_9_PROLOG
#define FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_CALLBACK_WRAPPERS \
	FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_INCLASS_NO_PURE_DECLS \
	FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VAMPIRESURVIVAL_API UClass* StaticClass<class AEnemy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Work_Ureal_Engine_MyProject2_VampireSurvival_Source_VampireSurvival_MainGameLevel_Enemy_Enemy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
