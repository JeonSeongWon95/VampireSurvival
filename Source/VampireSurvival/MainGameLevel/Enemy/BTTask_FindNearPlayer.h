#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindNearPlayer.generated.h"

/**
 * Task to find the nearest player in the game
 */
UCLASS()
class VAMPIRESURVIVAL_API UBTTask_FindNearPlayer : public UBTTask_BlackboardBase
{
    GENERATED_BODY()

public:
    UBTTask_FindNearPlayer();
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
    AActor* FindNearestPlayer(FVector Location);

    bool bHasExecuted;
};
