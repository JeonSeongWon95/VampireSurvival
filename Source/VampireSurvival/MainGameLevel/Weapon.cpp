#include "Weapon.h"
#include "GameFramework/Character.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;
	WeaponMesh->SetSimulatePhysics(true);
	WeaponOwner = nullptr;
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
	UE_LOG(LogTemp, Error, TEXT("Equip Function Start"));

	WeaponOwner = OwingCharacter;

	if(WeaponOwner)
	{
		WeaponOwner->bUseControllerRotationYaw = true;
		FName WeaponName = NAME_None;

		switch (WeaponData.Type)
		{
		case WeaponType::Pistol:
			WeaponName = "Pistol";
			break;
		case WeaponType::Rifle:
			WeaponName = "Rifle";
			break;
		case WeaponType::ShotGun:
			WeaponName = "ShotGun";
			break;
		default:
			break;
		}

		AttachToComponent(WeaponOwner->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponName);
	}
}

void AWeapon::DoUnEquipWeapon(ACharacter* OwingCharacter)
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	WeaponMesh->SetSimulatePhysics(true);
	WeaponOwner->bUseControllerRotationYaw = false;
	WeaponOwner = nullptr;
}

void AWeapon::FireWeapon()
{
}

