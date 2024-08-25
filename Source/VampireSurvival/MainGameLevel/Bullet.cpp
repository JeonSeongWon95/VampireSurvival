// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Enemy/Enemy.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Bullet(TEXT("/Script/Engine.StaticMesh'/Game/Effects/Meshes/BulletShells/SM_rifleshell.SM_rifleshell'"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	if (SM_Bullet.Succeeded())
	{
		StaticMesh->SetStaticMesh(SM_Bullet.Object);
	}
	StaticMesh->SetRelativeScale3D(FVector(20.f, 20.f, 20.f));
	StaticMesh->SetCollisionProfileName("Bullet");
	SetRootComponent(StaticMesh);
	Movement->ProjectileGravityScale = 0.0f;

	Speed = 8000.0f;
	bReplicates = true;
	SetLifeSpan(3.0f);
	StaticMesh->OnComponentHit.AddDynamic(this, &ABullet::HitBullet);

}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	Movement->Velocity = GetActorForwardVector() * Speed;

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void ABullet::HitBullet_Server_Implementation(AActor* OtherActor)
{
	AEnemy* HitActor = Cast<AEnemy>(OtherActor);

	if (HitActor)
	{
		HitActor->HitBullet(30);
	}

}

void ABullet::HitBullet(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

	HitBullet_Server(OtherActor);
}




