// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	TObjectPtr<class AEnemy> Player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "State")
	int32 Health;
	
};
