#include "Weapon.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "VampireSurvivalCharacter.h"
#include "Net/UnrealNetwork.h"
#include "bullet.h"
#include "Engine/StaticMeshSocket.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	WeaponMesh->SetCollisionProfileName("Weapon");
	WeaponMesh->SetSimulatePhysics(true);
	WeaponMesh->SetWorldScale3D(FVector(2.0, 2.0, 2.0));
	SetRootComponent(WeaponMesh);

	bReplicates = true;
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
	if(HasAuthority())
	{

	}
	else
	{
		FireWeapon_Server();
	}
}

void AWeapon::FireWeapon_Server_Implementation()
{
	if (HasAuthority())
	{
		ABullet* Bullet = GetWorld()->SpawnActor<ABullet>(WeaponMesh->GetSocketLocation(FName("Muzzle")),
			WeaponMesh->GetSocketRotation(FName("Muzzle")));

		if (Bullet && WeaponOwner)
		{
			Bullet->SetOwner(WeaponOwner->GetController());
			UE_LOG(LogTemp, Error, TEXT("Buller SetOwner : %s"), *WeaponOwner->GetController()->GetName());
		}
	}
}

void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
