// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VampireGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UVampireGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	
	UFUNCTION()
	bool SendMessageToServer(FString& ID, FString& Password, int IDSize, int PassWordSize, int SendType);

	UPROPERTY()
	TObjectPtr<class UVampireGameInstanceSubsystem> VampireSubSystem;
};
