// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoldActor.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AGoldActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoldActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<class UStaticMeshComponent> Mesh;

	UPROPERTY()
	TObjectPtr<class UBoxComponent> BoxCollision;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
