// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishFireNotify.h"
#include "../VampireSurvivalCharacter.h"
#include "Weapon.h"

void UFinishFireNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	AVampireSurvivalCharacter* Character = Cast<AVampireSurvivalCharacter>(MeshComp->GetOwner());

	if (Character)
	{
		Character->ClientRequestFireFalse();
	}
}
