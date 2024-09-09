// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FItemStruct.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VAMPIRESURVIVAL_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TSubclassOf<class UInventoryWidget> InventoryWidgetClass;
	UPROPERTY()
	TSubclassOf<class UInventoryEntryWidget> InventoryEntryWidgetClass;

	UPROPERTY()
	TObjectPtr<class UInventoryWidget> InventoryWidget;
	UPROPERTY()
	TObjectPtr<class UInventoryEntryWidget> InventoryEntryWidget;

	UPROPERTY(Replicated)
	TArray<FItemStruct> Items;

	UPROPERTY(Replicated)
	uint16 Gold;

public:
	UInventoryComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void CreateInventory();

	UFUNCTION()
	void UpdateInventory();

	UFUNCTION()
	void ClearInventory();

	UFUNCTION()
	void ShowInventory();

	UFUNCTION()
	void CloseInventory();

	UFUNCTION()
	bool AddItem(FItemStruct Item);

	UFUNCTION(Server, Reliable)
	void Server_AddItem(FItemStruct Item);

	UFUNCTION()
	void RemoveItem(FItemStruct Item);

	UFUNCTION(Server, Reliable)
	void Server_RemoveItem(FItemStruct Item);

	UFUNCTION()
	void AddGold(uint8 NewGold);

	UFUNCTION()
	void Server_AddGold(uint8 NewGold);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
};
