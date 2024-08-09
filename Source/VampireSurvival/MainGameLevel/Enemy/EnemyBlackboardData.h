#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "EnemyBlackboardData.generated.h"


UCLASS()
class VAMPIRESURVIVAL_API UEnemyBlackboardData : public UBlackboardData
{
	GENERATED_BODY()

public:
	UEnemyBlackboardData();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	TObjectPtr<class AVampireSurvivalCharacter> Target;
	
};
