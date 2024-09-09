// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "InventoryEntryWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UInventoryEntryWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ItemName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ItemCount;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UImage> ItemImage;

	UFUNCTION()
	void SetData(uint16 Count, FString Name, UImage* Image);

	
};
