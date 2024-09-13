// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnemyController.h"
#include "GameFramework/Controller.h"
#include "../VampireSurvivalCharacter.h"
#include "Enemy.h"

UBTTask_Attack::UBTTask_Attack()
{
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemy* CastEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());

	if (!(CastEnemy->IsDead))
	{
		uint8 RandomAttack = rand() % 2;
		UAnimMontage* AttackAnim = nullptr;

		switch (RandomAttack)
		{
		case 1:
			AttackAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Enemy/Animation/Zombie_Attack__1__Montage.Zombie_Attack__1__Montage'"));
			break;
		default:
			AttackAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Enemy/Animation/Zombie_Attack_Montage.Zombie_Attack_Montage'"));
			break;
		}


		CastEnemy->CantMove();
		CastEnemy->Req_Attack(AttackAnim);
	}

	return EBTNodeResult::Succeeded;
}
