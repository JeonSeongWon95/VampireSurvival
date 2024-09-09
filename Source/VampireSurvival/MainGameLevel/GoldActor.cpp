// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AGoldActor::AGoldActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Gold(TEXT("/Script/Engine.StaticMesh'/Game/AncientTreasures/Meshes/SM_Gems_01c.SM_Gems_01c'"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	if(SM_Gold.Succeeded())
	{
		Mesh->SetStaticMesh(SM_Gold.Object);
	}
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Mesh);
	BoxCollision->SetBoxExtent(FVector(2.f, 2.f, 2.f));

	bReplicates = true;
}

// Called when the game starts or when spawned
void AGoldActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetWorldScale3D(FVector(10.0f, 10.0f, 10.0f));
}

// Called every frame
void AGoldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

