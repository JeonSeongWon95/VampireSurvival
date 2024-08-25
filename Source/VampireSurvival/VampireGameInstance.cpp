// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireGameInstance.h"
#include "VampireGameInstanceSubsystem.h"

void UVampireGameInstance::Init()
{
	Super::Init();

	if(GetSubsystem<UVampireGameInstanceSubsystem>())
	{
		GetSubsystem<UVampireGameInstanceSubsystem>();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't Get Subsystem"));
	}
}

void UVampireGameInstance::SendMessageToServer(FString& ID, FString& Password)
{
	
}
