// Fill out your copyright notice in the Description page of Project Settings.


#include "EndAttackNotify.h"
#include "Enemy.h"

void UEndAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	AEnemy* Character = Cast<AEnemy>(MeshComp->GetOwner());

	if (Character)
	{
		Character->CanMove();
	}
}
