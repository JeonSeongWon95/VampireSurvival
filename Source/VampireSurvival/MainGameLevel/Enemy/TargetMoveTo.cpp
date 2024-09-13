// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetMoveTo.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Controller.h"
#include "../VampireSurvivalCharacter.h"
#include "Enemy.h"


EBTNodeResult::Type UTargetMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	AEnemy* CastEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());

	if (!(CastEnemy->IsDead))
	{

		if (BlackboardComp)
		{
			AVampireSurvivalCharacter* Character = Cast<AVampireSurvivalCharacter>(BlackboardComp->GetValueAsObject(TEXT("Target")));

			if (Character)
			{
				FVector TargetLocation = Character->GetActorLocation();
				FVector ALocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();

				double Distance = FVector::Distance(ALocation, TargetLocation);

				if (Distance < 200)
				{
					return EBTNodeResult::Succeeded;
				}
				else
				{
					OwnerComp.GetAIOwner()->MoveToLocation(TargetLocation);
				}

			}

		}
	}

	return EBTNodeResult::Failed;
}

UTargetMoveTo::UTargetMoveTo()
{
}
