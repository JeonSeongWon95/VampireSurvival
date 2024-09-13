#include "Weapon.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "../VampireSurvivalCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Engine/StaticMeshSocket.h"
#include "../Enemy/Enemy.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	WeaponMesh->SetCollisionProfileName("Weapon");
	WeaponMesh->SetSimulatePhysics(true);
	WeaponMesh->SetWorldScale3D(FVector(2.0, 2.0, 2.0));
	SetRootComponent(WeaponMesh);

	bReplicates = true;
	Range = 1000;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::SetWeaponData(FWeaponStruct Data)
{
	WeaponData = Data;
	WeaponMesh->SetStaticMesh(Data.Mesh);
}

FWeaponStruct AWeapon::GetWeaponData()
{
	return WeaponData;
}

void AWeapon::DoEquipWeapon(ACharacter* OwingCharacter)
{

	WeaponOwner = OwingCharacter;

	if (WeaponOwner)
	{
		WeaponMesh->SetSimulatePhysics(false);
		AttachToComponent(WeaponOwner->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Pistol"));
	}
}

void AWeapon::DoUnEquipWeapon(ACharacter* OwingCharacter)
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	WeaponMesh->SetSimulatePhysics(true);
	WeaponOwner = nullptr;
}

void AWeapon::FireWeapon()
{
	FireWeapon_Server();
}

void AWeapon::FireWeapon_Server_Implementation()
{
	if (WeaponOwner != nullptr)
	{
		FVector Location = WeaponMesh->GetSocketLocation(FName("Muzzle"));
		FVector WeaponRange = Location + (WeaponOwner->GetActorForwardVector() * Range);

		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Location, WeaponRange, ECC_Visibility);

		if (bHit)
		{
			AEnemy* HitActor = Cast<AEnemy>(HitResult.GetActor());
			HitActor->HitBullet(50);
		}
	}


}


void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
