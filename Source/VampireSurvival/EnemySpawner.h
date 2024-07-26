#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	AEnemySpawner();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
	float SpawnTick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Timer")
	float SpawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnActor")
	TObjectPtr<UClass> Actor;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpawnLocation")
	FTransform MyTransform;

public:	
	virtual void Tick(float DeltaTime) override;

};
