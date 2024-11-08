#include "Enemy.h"
#include "EnemyController.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "../GoldActor.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AEnemyController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	USkeletalMesh* NewMesh = LoadObject<USkeletalMesh>(nullptr, TEXT("/Script/Engine.SkeletalMesh'/Game/SeongWon/Animation/Enemy/Character/Zombi_01.Zombi_01'"));
	UClass* CharacterAnimBluePrint = LoadObject<UClass>(nullptr, TEXT("/Script/Engine.AnimBlueprint'/Game/SeongWon/BP/ABP_Enemy.ABP_Enemy_C'"));


	if (NewMesh)
	{
		USkeletalMeshComponent* CharacterMesh = GetMesh();
		CharacterMesh->SetSkeletalMesh(NewMesh);
		CharacterMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
		CharacterMesh->SetRelativeRotation(FRotator(0.0, -90.0f, 0.0f));
		CharacterMesh->SetAnimClass(CharacterAnimBluePrint);
		CharacterMesh->SetCollisionProfileName("Enemy");
	}

	GetCapsuleComponent()->SetCollisionProfileName("Enemy");
	GetCharacterMovement()->MaxWalkSpeed = 500;
	GetCharacterMovement()->SetIsReplicated(true);

	
	bReplicates = true;
	Health = 100;
	IsDead = false;

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> CBT(TEXT("/Script/AIModule.BehaviorTree'/Game/SeongWon/BP/BT_Enemy.BT_Enemy'"));
	if(CBT.Succeeded())
	{
		Tree = CBT.Object;
	}

}

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemy::DestroyActor()
{
	Destroy();
}


void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(AEnemy, Health);

}

UBehaviorTree* AEnemy::GetBehaviorTree()
{
	return Tree;
}

void AEnemy::HitBullet(int32 Damage)
{
	Server_RequestAddDamage(Damage);
}

void AEnemy::Server_RequestAddDamage_Implementation(int32 Damage)
{
	if((Health - Damage) < 0)
	{
		Health = 0;
	}
	else
	{
		Health -= Damage;
	}

	if(HasAuthority())
	{
		OnReq_UpdateHP();
	}
}

void AEnemy::OnReq_UpdateHP()
{
	if (Health > 0)
	{
		UAnimMontage* HitAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Enemy/Animation/Zombie_Reaction_Hit_Montage.Zombie_Reaction_Hit_Montage'"));
		if (HitAnim)
		{
			PlayAnimMontage(HitAnim);
		}
	}
	else
	{
		if (!IsDead)
		{
			IsDead = true;
			DoDeath();
		}
	}
}

void AEnemy::DoDeath()
{
	Server_DoDeath();
}

void AEnemy::CantMove()
{
	GetCharacterMovement()->MaxWalkSpeed = 0;

}

void AEnemy::CanMove()
{
	if (HasAuthority())
	{
		GetCharacterMovement()->MaxWalkSpeed = 500.0;
	}
	else 
	{
		Server_CanMove();
	}
}

void AEnemy::Server_CanMove_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = 500.0;
}

void AEnemy::Req_Attack(UAnimMontage* NewAnim)
{
	Res_Attack(NewAnim);
}

void AEnemy::Clinet_Attack_Implementation(UAnimMontage* NewAnim)
{
	PlayAnimMontage(NewAnim);
}

void AEnemy::Res_Attack_Implementation(UAnimMontage* NewAnim)
{
	Clinet_Attack(NewAnim);
}

void AEnemy::Server_DoDeath_Implementation()
{

	if (HasAuthority())
	{
		GetWorld()->SpawnActor<AGoldActor>(GetActorLocation(), GetActorRotation());
	}

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->MaxWalkSpeed = 0;
	GetWorld()->GetTimerManager().SetTimer(EnemyTimerHandle, this, &AEnemy::DestroyActor, 3.0f, false);
}

