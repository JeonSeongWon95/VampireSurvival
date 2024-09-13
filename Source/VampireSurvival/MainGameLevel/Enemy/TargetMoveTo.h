// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TargetMoveTo.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UTargetMoveTo : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UTargetMoveTo();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
