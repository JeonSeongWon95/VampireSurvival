// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvival/MainGameLevel/VSAnimInstance.h"
#include "VampireSurvivalCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "VampireSurvival/MainGameLevel/Weapon.h"

void UVSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Player = Cast<AVampireSurvivalCharacter>(TryGetPawnOwner());

	if(Player)
	{
		Speed = Player->GetCharacterMovement()->Velocity.Size2D();
		bIsFire = Player->bIsfire;
		bIsReload = Player->bIsReload;

		EquipWeapon = Player->EquipWeapon;

		if(EquipWeapon != nullptr)
		{
			bIsEquip = true;
		}
		else
		{
			bIsEquip = false;
		}
	}
	else
	{

	}
}
