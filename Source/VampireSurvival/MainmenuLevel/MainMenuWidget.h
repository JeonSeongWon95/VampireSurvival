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
	TObjectPtr<class UButton> Button_CreateGame;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_JoinGame;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Quit;


public:
	UFUNCTION()
	void ClickedCreateGame();

	UFUNCTION()
	void ClickedJoinGame();

	UFUNCTION()
	void ClickedQuitGame();

	virtual void NativeConstruct() override;

};
