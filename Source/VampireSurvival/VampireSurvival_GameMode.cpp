// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvival_GameMode.h"
#include "VampireSurvival_Character.h"
#include "VampireSurvival_Controller.h"

AVampireSurvival_GameMode::AVampireSurvival_GameMode()
{

	DefaultPawnClass = AVampireSurvival_Character::StaticClass();
	PlayerControllerClass = AVampireSurvival_Controller::StaticClass();
}
