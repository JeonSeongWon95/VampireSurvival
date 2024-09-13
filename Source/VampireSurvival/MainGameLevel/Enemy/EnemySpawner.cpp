// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(SceneComponent);

	static ConstructorHelpers::FClassFinder<AEnemy> EnemyClass(TEXT("/Script/CoreUObject.Class'/Script/VampireSurvival.Enemy'"));

	if(EnemyClass.Succeeded())
	{
		Actor = EnemyClass.Class;
	}

	bReplicates = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnTime = 0.0f;
	SpawnTick = 10.0f;
	MyTransform = GetTransform();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		SpawnEnemy(DeltaTime);
	}

}

void AEnemySpawner::SpawnEnemy_Implementation(float DeltaTime)
{
	SpawnTime += DeltaTime;

	if (SpawnTime >= SpawnTick)
	{
		if (Actor != nullptr)
		{
			GetWorld()->SpawnActor<AEnemy>(Actor, MyTransform);
			SpawnTime = 0;
		}
	}
}

void AEnemySpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

