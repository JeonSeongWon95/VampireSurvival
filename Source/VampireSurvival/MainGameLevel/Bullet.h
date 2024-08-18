// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponStruct.h"
#include "Bullet.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	TObjectPtr<class UStaticMeshComponent> StaticMesh;

	UPROPERTY()
	TObjectPtr<class UBoxComponent> BoxCollision;

	UPROPERTY()
	float Speed;

	UPROPERTY()
	float SpreadAngle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bullet", meta = (ExposOnSpawn = true))
	FWeaponStruct WeaponType;

	UPROPERTY()
	uint8 bIsRight;

	UPROPERTY()
	uint8 bIsLeft;

};