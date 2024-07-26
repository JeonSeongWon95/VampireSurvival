// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvivalGameMode.h"
#include "VampireSurvivalCharacter.h"
#include "VampireSurvivalController.h"

AVampireSurvivalGameMode::AVampireSurvivalGameMode()
{

	DefaultPawnClass = AVampireSurvivalCharacter::StaticClass();
	PlayerControllerClass = AVampireSurvivalController::StaticClass();
}
