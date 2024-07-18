// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvival_Controller.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AVampireSurvival_Controller::BeginPlay()
{
	Super::BeginPlay();
}

void AVampireSurvival_Controller::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if(InputMappingContext)
	{
	/*	ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer())
			->AddMappingContext();*/


	}
}
