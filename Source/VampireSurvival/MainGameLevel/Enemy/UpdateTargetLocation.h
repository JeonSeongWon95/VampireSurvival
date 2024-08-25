// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "UpdateTargetLocation.generated.h"

/**
 * 
 */
UCLASS()
class VAMPIRESURVIVAL_API UUpdateTargetLocation : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UUpdateTargetLocation();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};