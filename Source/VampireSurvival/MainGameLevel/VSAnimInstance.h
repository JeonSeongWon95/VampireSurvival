// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "VSAnimInstance.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API UVSAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	TObjectPtr<class AVampireSurvivalCharacter> Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsOnAim;

	
};
