// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSpawner.h"
#include "Weapon.h"

// Sets default values
AWeaponSpawner::AWeaponSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FClassFinder<AWeapon> Weapon_Pistol(TEXT("/Script/Engine.Blueprint'/Game/SeongWon/BP/BP_Pistol.BP_Pistol_C'"));

	if(Weapon_Pistol.Succeeded())
	{
		WeaponClass = Weapon_Pistol.Class;
	}

	bReplicates = true;

}

// Called when the game starts or when spawned
void AWeaponSpawner::BeginPlay()
{
	Super::BeginPlay();

	if(HasAuthority())
	{
		AWeapon* SpawnedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, GetActorLocation(), GetActorRotation());
		SpawnedWeapon->SetOwner(this);
	}
	
}

// Called every frame
void AWeaponSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

