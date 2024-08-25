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
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
};
