// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()


public:
	UPROPERTY()
	TObjectPtr<class UButton> CloseButton;

	UPROPERTY()
	TObjectPtr<class UTileView> ItemBox;



	
};
