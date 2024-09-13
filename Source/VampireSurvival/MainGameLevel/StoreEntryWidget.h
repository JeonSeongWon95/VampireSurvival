// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "StoreEntryWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UStoreEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ItemName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ItemCost;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> BuyButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> ItemImage;

	UFUNCTION()
	void ClickedBuyButton();


};
