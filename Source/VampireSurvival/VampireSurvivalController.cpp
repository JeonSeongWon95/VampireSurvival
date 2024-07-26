// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvivalController.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AVampireSurvivalController::BeginPlay()
{
	Super::BeginPlay();
}

void AVampireSurvivalController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if(InputMappingContext)
	{
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())
			->AddMappingContext(InputMappingContext, 0);
	}
}
