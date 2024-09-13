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
	void NativeConstruct() override;

	UFUNCTION()
	void ClickedCloseButton();

	UFUNCTION()
	void ClearTileView();

	UFUNCTION()
	void AddTileView(UObject* NewItem);

	UFUNCTION()
	void SetGold(uint16 NewGold);


private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> CloseButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTileView> ItemBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> Gold;



	
};
