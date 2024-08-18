// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Bullet(TEXT("/Script/Engine.StaticMesh'/Game/Effects/Meshes/BulletShells/SM_rifleshell.SM_rifleshell'"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	RootComponent = BoxCollision;

	StaticMesh->SetStaticMesh(SM_Bullet.Object);
	StaticMesh->SetupAttachment(BoxCollision);
	StaticMesh->SetSimulatePhysics(false);
	StaticMesh->SetRelativeScale3D(FVector(10.0f, 10.0f, 10.0f));
	StaticMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 90.0f));

	Speed = 1000.0f;
	SpreadAngle = 20.0f;
	
	bIsLeft = false;
	bIsRight = false;

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	FVector ForwardVector = GetActorForwardVector();
	FVector RightVector = GetActorRightVector();
	FVector Direction;

	if(bIsLeft)
	{
		Direction = ForwardVector + RightVector;
	}
	else if(bIsRight)
	{
		Direction = ForwardVector + RightVector;
	}
	else
	{
		Direction = ForwardVector;
	}

	Direction.Normalize();

	 FVector BulletVelocity = Direction * Speed;


	BoxCollision->SetSimulatePhysics(true);
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxCollision->BodyInstance.bEnableGravity = false;
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollision->SetPhysicsLinearVelocity(BulletVelocity);

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


