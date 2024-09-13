#include "BTTask_FindNearPlayer.h"
#include "EnemyController.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindNearPlayer::UBTTask_FindNearPlayer()
{
    NodeName = "Find Nearest Player";
}

EBTNodeResult::Type UBTTask_FindNearPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp)
    {
        FVector CurrentLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
        AActor* NearestPlayer = FindNearestPlayer(CurrentLocation);

        if (NearestPlayer)
        {
            BlackboardComp->SetValueAsObject(TEXT("Target"), NearestPlayer);
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}

AActor* UBTTask_FindNearPlayer::FindNearestPlayer(FVector Location)
{
    AActor* NearestPlayer = nullptr;
    double NearestDistance = TNumericLimits<double>::Max();

    TArray<APlayerState*> PlayerArray = GetWorld()->GetGameState()->PlayerArray;
    for (APlayerState* PlayerState : PlayerArray)
    {

        AActor* PlayerPawn = PlayerState->GetOwningController()->GetPawn();

        if (PlayerPawn)
        {
            FVector PlayerLocation = PlayerPawn->GetActorLocation();
            double Distance = FVector::Distance(Location, PlayerLocation);

            if (Distance < NearestDistance)
            {
                NearestDistance = Distance;
                NearestPlayer = PlayerPawn;
            }
        }
    }

    return NearestPlayer;
}

