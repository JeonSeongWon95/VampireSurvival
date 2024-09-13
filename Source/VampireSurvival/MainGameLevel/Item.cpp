// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "VampireSurvivalCharacter.h"
#include "Inven/InventoryComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static const FString ContextString(TEXT("Item Data Table"));
	static const FString DataTablePath(TEXT("/Script/Engine.DataTable'/Game/SeongWon/Data/DT_ItemData.DT_ItemData'"));

	UDataTable* DataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *DataTablePath));

	if (DataTable == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Data Table at path: %s"), *DataTablePath);
	}

	const FString RowName = TEXT("Potion"); // 원하는 데이터 행의 이름
	FItemStruct* ItemData = DataTable->FindRow<FItemStruct>(FName(*RowName), ContextString);

	Data = *ItemData;
	bReplicates = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	SetRootComponent(Collision);
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Collision->SetCollisionProfileName("Gold");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetStaticMesh(Data.ItemMesh);
	Mesh->SetupAttachment(Collision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	if(!(Collision->OnComponentBeginOverlap.IsBound()))
	{
		Collision->OnComponentBeginOverlap.AddDynamic(this, &AItem::EventOverlap);
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::EventOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	AVampireSurvivalCharacter* CastCharacter = Cast<AVampireSurvivalCharacter>(OtherActor);

	if (CastCharacter)
	{
		UInventoryComponent* IC = CastCharacter->GetComponentByClass<UInventoryComponent>();

		if (IC)
		{
			IC->AddItem(Data);
			DestoryActor();
		}
	}
}

void AItem::DestoryActor()
{
	Server_DestroyActor();
}

void AItem::Server_DestroyActor_Implementation()
{
	Destroy();
}

