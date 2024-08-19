// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MainmenuLevel/MainMenuWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VAMPIRESURVIVAL_MainMenuWidget_generated_h
#error "MainMenuWidget.generated.h already included, missing '#pragma once' in MainMenuWidget.h"
#endif
#define VAMPIRESURVIVAL_MainMenuWidget_generated_h

#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClickedQuitGame); \
	DECLARE_FUNCTION(execClickedJoinGame); \
	DECLARE_FUNCTION(execClickedCreateGame);


#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMainMenuWidget(); \
	friend struct Z_Construct_UClass_UMainMenuWidget_Statics; \
public: \
	DECLARE_CLASS(UMainMenuWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VampireSurvival"), NO_API) \
	DECLARE_SERIALIZER(UMainMenuWidget)


#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMainMenuWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMainMenuWidget(UMainMenuWidget&&); \
	UMainMenuWidget(const UMainMenuWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMainMenuWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMainMenuWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMainMenuWidget) \
	NO_API virtual ~UMainMenuWidget();


#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_12_PROLOG
#define FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VAMPIRESURVIVAL_API UClass* StaticClass<class UMainMenuWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
