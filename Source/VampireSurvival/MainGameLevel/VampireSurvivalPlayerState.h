// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "VampireSurvivalPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API AVampireSurvivalPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	AVampireSurvivalPlayerState();
	~AVampireSurvivalPlayerState();


protected:
	UPROPERTY()
	uint8 Health;
};
