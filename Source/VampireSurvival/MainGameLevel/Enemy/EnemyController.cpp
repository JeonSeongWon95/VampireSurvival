// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"
#include "NavigationSystem.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "EnemyBlackboardData.h"

AEnemyController::AEnemyController()
{

}

void AEnemyController::OnPossess(APawn* InPawn)
{
	//Super::OnPossess(InPawn);

	//UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());

	//if (NavSystem == nullptr)
	//{
	//	return;
	//}

	//BehaviorTree = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
	//BlackboardData = LoadObject<UEnemyBlackboardData>(this, TEXT("/Script/CoreUObject.Class'/Script/VampireSurvival.EnemyBlackboardData'"));
	////TObjectPtr<>�� ����� ������ �ٷ� ����� �Ұ��ϴ�. Get �Լ��� �̿��ؼ� �����;��Ѵ�.
	//BlackboardComponent = GetBlackboardComponent();

	////UseBlackboard(BlackboardData, BlackboardComponent);
}

void AEnemyController::BeginPlay()
{
	Super::BeginPlay();

	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
		UE_LOG(LogTemp, Error, TEXT("BehaviorTree Run"));
	}
}
