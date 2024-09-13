// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Merchant.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AMerchant : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMerchant();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<class USkeletalMeshComponent> Mesh;

	UPROPERTY()
	TObjectPtr<class UBoxComponent> BoxCollision;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
