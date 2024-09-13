// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "NavigationSystem.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "EnemyBlackboardData.h"
#include "Enemy.h"

AEnemyController::AEnemyController()
{
	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	if(NavSystem == nullptr)
	{
		return;
	}

}

void AEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AEnemy* PossessPawn = Cast<AEnemy>(InPawn);
	
	if(PossessPawn)
	{
		UBehaviorTree* Tree = PossessPawn->GetBehaviorTree();
		UBlackboardComponent* NewBlackboard = nullptr;
		UseBlackboard(Tree->GetBlackboardAsset(), NewBlackboard);

		if (NewBlackboard != nullptr)
		{
			Blackboard = NewBlackboard;
			RunBehaviorTree(Tree);
		}

	}
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}
