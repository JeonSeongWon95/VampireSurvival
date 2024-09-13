// Fill out your copyright notice in the Description page of Project Settings.


#include "FireAnimNotify.h"
#include "../VampireSurvivalCharacter.h"
#include "Weapon.h"

void UFireAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, 
	const FAnimNotifyEventReference& EventReference)
{
	AVampireSurvivalCharacter* Character = Cast<AVampireSurvivalCharacter>(MeshComp->GetOwner());

    if (Character)
    {
        if (Character->HasAuthority())
        {
            Character->EquipWeapon->FireWeapon();
        }
    }
}
