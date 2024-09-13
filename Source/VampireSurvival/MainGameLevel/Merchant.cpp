// Fill out your copyright notice in the Description page of Project Settings.


#include "Merchant.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AMerchant::AMerchant()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM_Mesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SetRootComponent(BoxCollision);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxCollision);

	if(SM_Mesh.Succeeded())
	{
		Mesh->SetSkeletalMesh(SM_Mesh.Object);
	}

}

// Called when the game starts or when spawned
void AMerchant::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMerchant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

