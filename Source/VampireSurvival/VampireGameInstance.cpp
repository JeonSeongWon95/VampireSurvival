// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireGameInstance.h"
#include "VampireGameInstanceSubsystem.h"

void UVampireGameInstance::Init()
{
	Super::Init();

	if(GetSubsystem<UVampireGameInstanceSubsystem>())
	{
		VampireSubSystem = GetSubsystem<UVampireGameInstanceSubsystem>();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't Get Subsystem"));
	}
}

bool UVampireGameInstance::SendMessageToServer(FString& ID, FString& Password, int IDSize, int PassWordSize, int SendType)
{
	if(VampireSubSystem)
	{
		if(VampireSubSystem->SendUserData(ID, Password, IDSize, PassWordSize, SendType))
		{
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("SubSystem Send User Data Fail"));
		}
	}
	
	return false;
}
