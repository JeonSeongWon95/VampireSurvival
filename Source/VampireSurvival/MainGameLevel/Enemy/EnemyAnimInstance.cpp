// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "Enemy.h"
#include "GameFramework/CharacterMovementComponent.h"

void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Player = Cast<AEnemy>(TryGetPawnOwner());

	if (Player)
	{
		Speed = Player->GetCharacterMovement()->Velocity.Size2D();
		Health = Player->Health;

	}
	else
	{

	}
}
