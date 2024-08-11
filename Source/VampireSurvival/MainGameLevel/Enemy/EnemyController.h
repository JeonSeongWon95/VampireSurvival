#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyController();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BehaviorTree")
	TObjectPtr<class UBehaviorTree> BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BlackboardComponent")
	TObjectPtr<class UBlackboardComponent> BlackboardComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BlackboardComponent")
	TObjectPtr<class UBlackboardData> BlackboardData;
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
};
