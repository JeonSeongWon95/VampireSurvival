#include "VampireSurvivalCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapon/Weapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "InputMappingContext.h"
#include "VampireSurvival/MainGameLevel/VampireSurvivalPlayerState.h"
#include "Net/UnrealNetwork.h"
#include "Components/CapsuleComponent.h"
#include "Inven/InventoryComponent.h"

AVampireSurvivalCharacter::AVampireSurvivalCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	Inven = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inven"));

	CameraBoom->TargetArmLength = 1000;
	CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritRoll = true;
	CameraBoom->bInheritYaw = false;
	CameraBoom->SetRelativeRotation(FRotator(-40.0f, 0.0f, 0.0f));

	VSCharacterMovement = GetCharacterMovement<UCharacterMovementComponent>();
	VSCharacterMovement->MaxWalkSpeed = 290.0f;
	VSCharacterMovement->bUseControllerDesiredRotation = true;
	VSCharacterMovement->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

	//bIsOnAim = false;

	USkeletalMesh* CharacterMesh = LoadObject<USkeletalMesh>(nullptr, TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Quinn_Simple.SKM_Quinn_Simple'"));
	UClass* CharacterAnimBluePrint = LoadObject<UClass>(nullptr, TEXT("/Script/Engine.AnimBlueprint'/Game/SeongWon/BP/ABP_VampireSurvivalCharacterAnimation.ABP_VampireSurvivalCharacterAnimation_C'"));

	if (CharacterMesh && CharacterAnimBluePrint)
	{
		USkeletalMeshComponent* thisCharacterMesh = GetMesh();
		thisCharacterMesh->SetSkeletalMesh(CharacterMesh);
		thisCharacterMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
		thisCharacterMesh->SetRelativeRotation(FRotator(0.0, -90.0f, 0.0f));
		thisCharacterMesh->SetAnimClass(CharacterAnimBluePrint);
	}

	IA_EnhancedMove = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_EnhancedMove.IA_EnhancedMove'"));
	IA_Run = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_Run.IA_Run'"));
	IA_Fire = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_Fire.IA_Fire'"));
	IA_PickUpWeapon = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_PickUpWeapon.IA_PickUpWeapon'"));
	IA_OnAim = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_OnAim.IA_OnAim'"));
	IA_OpenInventory = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_OpenInventory.IA_OpenInventory'"));

	FireRate = 0.0;
	EquipWeapon = nullptr;
	bReplicates = true;
	bIsfire = false;
	bIsReload = false;
	bIsOnAim = false;
	bIsOpen = 0;

}


void AVampireSurvivalCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void AVampireSurvivalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVampireSurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Script/EnhancedInput.InputMappingContext'/Game/SeongWon/Input/IMC_MyMapping.IMC_MyMapping'"));

	if (InputMappingContext)
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}


	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EIC)
	{
		EIC->BindAction(IA_EnhancedMove, ETriggerEvent::Triggered, this, &AVampireSurvivalCharacter::EnhancedMove);
		EIC->BindAction(IA_Run, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedRun);
		EIC->BindAction(IA_Run, ETriggerEvent::Completed, this, &AVampireSurvivalCharacter::ReleasedRun);
		EIC->BindAction(IA_PickUpWeapon, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedPickUpKey);
		EIC->BindAction(IA_Fire, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::Weaponfire);
		EIC->BindAction(IA_OnAim, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedAim);
		EIC->BindAction(IA_OnAim, ETriggerEvent::Completed, this, &AVampireSurvivalCharacter::ReleaseAim);
		EIC->BindAction(IA_OpenInventory, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedOpenInventory);
	}

}

void AVampireSurvivalCharacter::EnhancedMove(const FInputActionValue& Value)
{
	if (!bIsfire && !bIsReload)
	{
		FVector2D NewValue = Value.Get<FVector2D>();

		FRotator ControlRotator = GetControlRotation();

		FVector RightVector = UKismetMathLibrary::GetRightVector(FRotator(0.0, ControlRotator.Yaw, ControlRotator.Roll));
		FVector ForwardVector = UKismetMathLibrary::GetForwardVector(FRotator(0.0, ControlRotator.Yaw, 0.0f));

		AddMovementInput(ForwardVector, NewValue.X);
		AddMovementInput(RightVector, NewValue.Y);
	}
}


void AVampireSurvivalCharacter::PressedRun(const FInputActionValue& Value)
{
	PlayerIsRun();
}

void AVampireSurvivalCharacter::ReleasedRun(const FInputActionValue& Value)
{
	PlayerIsNotRun();
}

void AVampireSurvivalCharacter::PressedPickUpKey(const FInputActionValue& Value)
{
	Server_PressedPickUpWeaponKey();
}

void AVampireSurvivalCharacter::PressedAim(const FInputActionValue& Value)
{
	Server_RequestAimMode();
}

void AVampireSurvivalCharacter::ReleaseAim(const FInputActionValue& Value)
{
	Server_RequestAimModeFasle();
}

void AVampireSurvivalCharacter::PressedOpenInventory(const FInputActionValue& Value)
{
	if (bIsOpen == 0)
	{
		Inven->ShowInventory();
		bIsOpen = 1;
	}
	else
	{
		Inven->CloseInventory();
		bIsOpen = 0;
	}
}

void AVampireSurvivalCharacter::Weaponfire(const FInputActionValue& Value)
{
	if (EquipWeapon != nullptr)
	{
		Server_RequestFire();
	}
}

AActor* AVampireSurvivalCharacter::FindNearWeapon()
{
	TArray<AActor*> Actors;
	GetCapsuleComponent()->GetOverlappingActors(Actors, AWeapon::StaticClass());

	if (Actors.Num() <= 0)
	{

	}
	double Distance = 999999.0f;
	AActor* NearActor = nullptr;

	for (AActor* TargetActor : Actors)
	{
		if (EquipWeapon == TargetActor)
		{
			continue;
		}

		double ActorDistance = FVector::Distance(GetActorLocation(), TargetActor->GetActorLocation());

		if (ActorDistance >= Distance)
		{
			continue;
		}

		Distance = ActorDistance;
		NearActor = TargetActor;
	}

	return NearActor;
}

void AVampireSurvivalCharacter::ClientRequestFireFalse()
{
	if (HasAuthority())
	{
		Server_ChangeFireFalse();
	}
}

void AVampireSurvivalCharacter::Server_RequestAimMode_Implementation()
{
	bIsOnAim = true;
}

void AVampireSurvivalCharacter::Server_RequestAimModeFasle_Implementation()
{
	bIsOnAim = false;
}

void AVampireSurvivalCharacter::Server_ChangeFireFalse_Implementation()
{
	bIsfire = false;
}

void AVampireSurvivalCharacter::Server_PressedPickUpWeaponKey_Implementation()
{
	AActor* NearWeapon = FindNearWeapon();

	if (false == IsValid(NearWeapon))
	{
		return;
	}
	if (EquipWeapon != nullptr)
	{
		EquipWeapon->SetOwner(nullptr);
	}

	if (HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("Weapon Owner Set"));
		NearWeapon->SetOwner(GetController());
	}

	Client_PressedPickUpWeaponKey(NearWeapon);
}

void AVampireSurvivalCharacter::Client_PressedPickUpWeaponKey_Implementation(AActor* NewWeapon)
{
	AWeapon* NewEquipWeapon = Cast<AWeapon>(NewWeapon);

	if (NewEquipWeapon)
	{
		if (EquipWeapon != nullptr)
		{

			EquipWeapon->DoUnEquipWeapon(this);
			EquipWeapon = nullptr;

		}

		EquipWeapon = NewEquipWeapon;
		EquipWeapon->DoEquipWeapon(this);
	}

}

void AVampireSurvivalCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AVampireSurvivalCharacter, bIsfire);
	DOREPLIFETIME(AVampireSurvivalCharacter, bIsReload);
	DOREPLIFETIME(AVampireSurvivalCharacter, bIsOnAim);
}

void AVampireSurvivalCharacter::ChanageMovementSpeed_Implementation(float Speed)
{
	VSCharacterMovement->MaxWalkSpeed = Speed;
}

void AVampireSurvivalCharacter::PlayerIsRun_Implementation()
{
	ChanageMovementSpeed(600.0f);
}

void AVampireSurvivalCharacter::PlayerIsNotRun_Implementation()
{
	ChanageMovementSpeed(290.0f);
}

void AVampireSurvivalCharacter::OnReq_Reload()
{
}

void AVampireSurvivalCharacter::Server_RequestFire_Implementation()
{
	if (!bIsfire)
	{
		bIsfire = true;
		UAnimMontage* FireAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Pistol/MM_Pistol_Fire_Montage.MM_Pistol_Fire_Montage'"));
		if (HasAuthority())
		{
			UE_LOG(LogTemp, Error, TEXT("Play Anim"));
			PlayAnimMontage(FireAnim);
		}
	}
}

void AVampireSurvivalCharacter::Server_RequestReload_Implementation(bool Newbool)
{

}
