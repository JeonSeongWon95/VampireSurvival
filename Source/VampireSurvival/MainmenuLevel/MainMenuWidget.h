// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Login;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Signup;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Quit;

};
