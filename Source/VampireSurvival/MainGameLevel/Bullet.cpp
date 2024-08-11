// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Bullet(TEXT("/Script/Engine.StaticMesh'/Game/Effects/Meshes/BulletShells/SM_rifleshell.SM_rifleshell'"));
	UStaticMeshComponent* StaticM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	UBoxComponent* Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));


	if (SM_Bullet.Succeeded())
	{
		switch (WeaponType.Type)
		{
		case WeaponType::Pistol:
		case WeaponType::Rifle:
			if(Box)
			{
				BoxCollisions.Add(Box);
				BoxCollisions[0]->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
				BoxCollisions[0]->SetupAttachment(RootComponent);
			}
			if (StaticM)
			{
				StaticM->SetStaticMesh(SM_Bullet.Object);
				StaticMeshes.Add(StaticM);
				StaticMeshes[0]->SetupAttachment(BoxCollisions[0]);
				StaticMeshes[0]->SetRelativeScale3D(FVector(10.0f, 10.0f, 10.0f));
				StaticMeshes[0]->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
			}
			break;
		case WeaponType::ShotGun:
			if (Box)
			{
				BoxCollisions.Add(Box);
				BoxCollisions.Add(Box);
				BoxCollisions.Add(Box);

				BoxCollisions[0]->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
				BoxCollisions[0]->SetupAttachment(RootComponent);
				BoxCollisions[1]->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
				BoxCollisions[1]->SetupAttachment(RootComponent);
				BoxCollisions[2]->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
				BoxCollisions[2]->SetupAttachment(RootComponent);
			}
			if (StaticM)
			{
				StaticM->SetStaticMesh(SM_Bullet.Object);
				StaticMeshes.Add(StaticM);
				StaticMeshes.Add(StaticM);
				StaticMeshes.Add(StaticM);
				StaticMeshes[0]->SetupAttachment(BoxCollisions[0]);
				StaticMeshes[0]->SetRelativeScale3D(FVector(10.0f, 10.0f, 10.0f));
				StaticMeshes[0]->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
				StaticMeshes[1]->SetupAttachment(BoxCollisions[0]);
				StaticMeshes[1]->SetRelativeScale3D(FVector(10.0f, 10.0f, 10.0f));
				StaticMeshes[1]->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
				StaticMeshes[2]->SetupAttachment(BoxCollisions[0]);
				StaticMeshes[2]->SetRelativeScale3D(FVector(10.0f, 10.0f, 10.0f));
				StaticMeshes[2]->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
			}
			break;
		default:
			break;
		}
	}

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	switch (WeaponType.Type)
	{
	case WeaponType::Pistol:
	case WeaponType::Rifle:
		break;
	case WeaponType::ShotGun:
		break;
	default:
		break;
	}
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


