// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VampireGameInstanceSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UVampireGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void ConnectedLoginServer();

	class FSocket* ServerSocket;

	UFUNCTION()
	void SendUserData(FString& ID, FString& Password);
	
};
