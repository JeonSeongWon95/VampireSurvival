// Fill out your copyright notice in the Description page of Project Settings.


#include "HitStartNotify.h"
#include "Enemy.h"

void UHitStartNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	AEnemy* Character = Cast<AEnemy>(MeshComp->GetOwner());

	if (Character)
	{
		Character->CantMove();
	}
}
