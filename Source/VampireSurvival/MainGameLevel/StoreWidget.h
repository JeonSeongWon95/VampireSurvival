// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UStoreWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> CloseButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UListView> ItemBox;

public:
	void NativeConstruct() override;

	UFUNCTION()
	void ClickedCloseButton();

	UFUNCTION()
	void ClearListView();

	UFUNCTION()
	void AddListView(UObject* NewItem);
	
};
