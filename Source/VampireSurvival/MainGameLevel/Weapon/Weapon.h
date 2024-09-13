// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponStruct.h"
#include "Weapon.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<ACharacter> WeaponOwner;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SetWeaponData(FWeaponStruct Data);

	UFUNCTION()
	FWeaponStruct GetWeaponData();

	UFUNCTION()
	void DoEquipWeapon(ACharacter* OwingCharacter);

	UFUNCTION()
	void DoUnEquipWeapon(ACharacter* OwingCharacter);

	UFUNCTION()
	void FireWeapon();

	UFUNCTION(Server, Reliable)
	void FireWeapon_Server();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponData")
	FWeaponStruct WeaponData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponData")
	TObjectPtr<class UStaticMeshComponent> WeaponMesh;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UPROPERTY()
	int16 Range;
};
