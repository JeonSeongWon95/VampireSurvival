// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "VampireSurvivalCharacter.h"
#include "Inven/InventoryComponent.h"
#include "Net/UnrealNetwork.h"

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

	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionProfileName("Gold");
	bReplicates = true;

}

// Called when the game starts or when spawned
void AGoldActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetWorldScale3D(FVector(5.f, 5.f, 5.f));
	BoxCollision->SetBoxExtent(FVector(5.f, 5.f, 5.f));

	if(!(BoxCollision->OnComponentBeginOverlap.IsBound()))
	{
		BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AGoldActor::EventOverlap);
	}
}

// Called every frame
void AGoldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGoldActor::EventOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AVampireSurvivalCharacter* CastCharacter = Cast<AVampireSurvivalCharacter>(OtherActor);

	if(CastCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Overlap Actor : %s"), *CastCharacter->GetName());
		UInventoryComponent* IC = CastCharacter->GetComponentByClass<UInventoryComponent>();

		if(IC)
		{
			IC->AddGold(100);
			DestoryActor();
		}
	}
}

void AGoldActor::DestoryActor()
{
	Server_DestoryActor();
}

void AGoldActor::Server_DestoryActor_Implementation()
{
	Destroy();
}





