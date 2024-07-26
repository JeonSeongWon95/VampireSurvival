#include "Enemy.h"
#include "EnemyController.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AEnemyController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}


void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

