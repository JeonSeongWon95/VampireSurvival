// Fill out your copyright notice in the Description page of Project Settings.


#include "UpdateTargetLocation.h"
#include "BehaviorTree/BlackboardComponent.h"

UUpdateTargetLocation::UUpdateTargetLocation()
{
	NodeName = "Update Target Location";
}

EBTNodeResult::Type UUpdateTargetLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BBC = OwnerComp.GetBlackboardComponent();

	if(BBC)
	{
		AActor* Player = Cast<AActor>(BBC->GetValueAsObject(TEXT("Target")));

		if(Player)
		{
			BBC->SetValueAsVector(TEXT("TargetLocation"), Player->GetActorLocation());
			return EBTNodeResult::Succeeded;
		}
		else
		{
			return EBTNodeResult::Failed;
		}

	}
	else
	{
		return EBTNodeResult::Failed;
	}


}
