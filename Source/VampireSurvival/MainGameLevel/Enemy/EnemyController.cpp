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

	//BehaviorTree = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTree"));
	//TObjectPtr<>로 선언된 변수는 바로 사용이 불가하다. Get 함수를 이용해서 가져와야한다.
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

	//UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	//if (NavSystem == nullptr)
	//{
	//	return;
	//}

	//BehaviorTree = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
	//BlackboardData = LoadObject<UEnemyBlackboardData>(this, TEXT("/Script/CoreUObject.Class'/Script/VampireSurvival.EnemyBlackboardData'"));
	//BlackboardComponent = GetBlackboardComponent();

	////UseBlackboard(BlackboardData, BlackboardComponent);
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();
}
