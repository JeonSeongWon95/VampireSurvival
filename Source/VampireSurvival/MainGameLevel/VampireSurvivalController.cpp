// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvivalController.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"

void AVampireSurvivalController::BeginPlay()
{
	Super::BeginPlay();
}

void AVampireSurvivalController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	InputMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Script/EnhancedInput.InputMappingContext'/Game/SeongWon/Input/IMC_MyMapping.IMC_MyMapping'"));

	if(InputMappingContext)
	{
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())
			->AddMappingContext(InputMappingContext, 0);
	}
}
