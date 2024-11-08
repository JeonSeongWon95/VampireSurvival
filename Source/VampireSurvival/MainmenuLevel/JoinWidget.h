// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JoinWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UJoinWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Join;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> IPAddressBox;
};
