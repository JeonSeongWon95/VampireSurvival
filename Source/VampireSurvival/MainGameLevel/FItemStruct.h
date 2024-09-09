// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FItemStruct.generated.h"


USTRUCT(BlueprintType)
struct VAMPIRESURVIVAL_API FItemStruct : public FTableRowBase
{
	GENERATED_BODY()

public:
	FItemStruct();
	~FItemStruct();

	bool operator==(const FItemStruct& Other) const
	{
		return ItemName == Other.ItemName;
	};

	UPROPERTY()
	FString ItemName;

	UPROPERTY()
	uint32 SellingCost;

	UPROPERTY()
	uint32 ByingCost;

	UPROPERTY()
	uint16 Count;

	UPROPERTY()
	TObjectPtr<class UImage> ItemImage;

	UPROPERTY()
	TObjectPtr<class UStaticMesh> ItemMesh;

};
