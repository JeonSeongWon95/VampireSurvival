// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "MainMenuHUD.h"
#include "MainMenuPawn.h"

AMainMenuGameMode::AMainMenuGameMode()
{
	DefaultPawnClass = AMainMenuPawn::StaticClass();
}
