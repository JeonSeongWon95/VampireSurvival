// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignUpWidget.generated.h"


UCLASS()
class VAMPIRESURVIVAL_API USignUpWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_SignUp;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Quit;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> IDBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> PasswordBox;

	UFUNCTION()
	void ClickedQuitButton();

	UFUNCTION()
	void SendClientIDAndPassword();

	virtual void NativeConstruct() override;
	
};
