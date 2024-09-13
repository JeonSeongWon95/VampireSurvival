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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	FString ItemName;

	UPROPERTY(EditAnywhere, Category = "Cost")
	uint16 SellingCost;

	UPROPERTY(EditAnywhere, Category = "Cost")
	uint16 ByingCost;

	UPROPERTY(EditAnywhere, Category = "Count")
	uint16 Count;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<class UTexture2D> ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class UStaticMesh> ItemMesh;

};
