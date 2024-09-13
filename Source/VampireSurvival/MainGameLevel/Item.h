// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FItemStruct.h"
#include "Item.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY()
	TObjectPtr<class UBoxComponent> Collision;

	UPROPERTY()
	FItemStruct Data;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EventOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void DestoryActor();

	UFUNCTION(Server, Reliable)
	void Server_DestroyActor();

};
