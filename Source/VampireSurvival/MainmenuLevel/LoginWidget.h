// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Login;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Quit;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> IDBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> PasswordBox;

	UFUNCTION()
	void SendClientIDAndPassword();

	UFUNCTION()
	void ClickedQuitButton();

	virtual void NativeConstruct() override;

};
