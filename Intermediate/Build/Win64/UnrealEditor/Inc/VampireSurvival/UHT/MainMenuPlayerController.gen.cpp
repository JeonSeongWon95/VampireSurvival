// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VampireSurvival/MainmenuLevel/MainMenuPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuPlayerController() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
UPackage* Z_Construct_UPackage__Script_VampireSurvival();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuPlayerController();
VAMPIRESURVIVAL_API UClass* Z_Construct_UClass_AMainMenuPlayerController_NoRegister();
// End Cross Module References

// Begin Class AMainMenuPlayerController Function BindSocket
struct Z_Construct_UFunction_AMainMenuPlayerController_BindSocket_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainMenuPlayerController_BindSocket_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainMenuPlayerController, nullptr, "BindSocket", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainMenuPlayerController_BindSocket_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainMenuPlayerController_BindSocket_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMainMenuPlayerController_BindSocket()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainMenuPlayerController_BindSocket_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainMenuPlayerController::execBindSocket)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BindSocket();
	P_NATIVE_END;
}
// End Class AMainMenuPlayerController Function BindSocket

// Begin Class AMainMenuPlayerController Function SandLoginData
struct Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics
{
	struct MainMenuPlayerController_eventSandLoginData_Parms
	{
		FString ID;
		FString Password;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainMenuPlayerController_eventSandLoginData_Parms, ID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MainMenuPlayerController_eventSandLoginData_Parms, Password), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::NewProp_ID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::NewProp_Password,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMainMenuPlayerController, nullptr, "SandLoginData", nullptr, nullptr, Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::MainMenuPlayerController_eventSandLoginData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::MainMenuPlayerController_eventSandLoginData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMainMenuPlayerController::execSandLoginData)
{
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ID);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Password);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SandLoginData(Z_Param_Out_ID,Z_Param_Out_Password);
	P_NATIVE_END;
}
// End Class AMainMenuPlayerController Function SandLoginData

// Begin Class AMainMenuPlayerController
void AMainMenuPlayerController::StaticRegisterNativesAMainMenuPlayerController()
{
	UClass* Class = AMainMenuPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BindSocket", &AMainMenuPlayerController::execBindSocket },
		{ "SandLoginData", &AMainMenuPlayerController::execSandLoginData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMainMenuPlayerController);
UClass* Z_Construct_UClass_AMainMenuPlayerController_NoRegister()
{
	return AMainMenuPlayerController::StaticClass();
}
struct Z_Construct_UClass_AMainMenuPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "MainmenuLevel/MainMenuPlayerController.h" },
		{ "ModuleRelativePath", "MainmenuLevel/MainMenuPlayerController.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMainMenuPlayerController_BindSocket, "BindSocket" }, // 2696541237
		{ &Z_Construct_UFunction_AMainMenuPlayerController_SandLoginData, "SandLoginData" }, // 2868617148
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMainMenuPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_VampireSurvival,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuPlayerController_Statics::ClassParams = {
	&AMainMenuPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMainMenuPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AMainMenuPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMainMenuPlayerController()
{
	if (!Z_Registration_Info_UClass_AMainMenuPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMainMenuPlayerController.OuterSingleton, Z_Construct_UClass_AMainMenuPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMainMenuPlayerController.OuterSingleton;
}
template<> VAMPIRESURVIVAL_API UClass* StaticClass<AMainMenuPlayerController>()
{
	return AMainMenuPlayerController::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuPlayerController);
AMainMenuPlayerController::~AMainMenuPlayerController() {}
// End Class AMainMenuPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMainMenuPlayerController, AMainMenuPlayerController::StaticClass, TEXT("AMainMenuPlayerController"), &Z_Registration_Info_UClass_AMainMenuPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMainMenuPlayerController), 105578893U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_291739719(TEXT("/Script/VampireSurvival"),
	Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Ureal_Engine_VampireSurvival_VampireSurvival_Source_VampireSurvival_MainmenuLevel_MainMenuPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
