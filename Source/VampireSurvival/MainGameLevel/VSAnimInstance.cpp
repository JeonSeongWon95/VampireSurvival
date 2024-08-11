// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvival/MainGameLevel/VSAnimInstance.h"
#include "VampireSurvivalCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UVSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Player = Cast<AVampireSurvivalCharacter>(TryGetPawnOwner());

	if(Player)
	{
		Speed = Player->GetCharacterMovement()->Velocity.Size2D();
		bIsOnAim = Player->bIsOnAim;
	}
}
