// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DestroyActor();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	UBehaviorTree* GetBehaviorTree();

	UFUNCTION()
	void HitBullet(int32 Damage);

	UFUNCTION(Server, Reliable)
	void Server_RequestAddDamage(int32 Damage);

	UFUNCTION()
	void OnReq_UpdateHP();

	UPROPERTY(ReplicatedUsing = OnReq_UpdateHP)
	int32 Health;

	UPROPERTY()
	TObjectPtr<class UBehaviorTree> Tree;

	UFUNCTION()
	void DoDeath();

	UFUNCTION(Server, Reliable)
	void Server_DoDeath();

	FTimerHandle EnemyTimerHandle;

	UFUNCTION()
	void CantMove();

	UFUNCTION()
	void CanMove();

};
