#include "VampireSurvivalCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"


AVampireSurvivalCharacter::AVampireSurvivalCharacter()
{
 
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	CameraBoom->TargetArmLength = 1000;
	CameraBoom->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = true;
	CameraBoom->bInheritRoll = true;
	CameraBoom->bInheritYaw = false;
	CameraBoom->SetRelativeRotation(FRotator(-40.0f, 0.0f, 0.0f));

	VSCharacterMovement = GetCharacterMovement<UCharacterMovementComponent>();
	VSCharacterMovement->MaxWalkSpeed = 300.0f;
	VSCharacterMovement->bUseControllerDesiredRotation = true;
	VSCharacterMovement->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

	bIsOnAim = false;

	USkeletalMesh* CharacterMesh = LoadObject<USkeletalMesh>(nullptr, TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Mannequin_UE4/Meshes/SK_Mannequin.SK_Mannequin'"));
	UClass* CharacterAnimBluePrint = LoadObject<UClass>(nullptr, TEXT("/Script/Engine.AnimBlueprint'/Game/SeongWon/BP/ABP_VampireSurvivalCharacterAnimation.ABP_VampireSurvivalCharacterAnimation_C'"));

	if(CharacterMesh && CharacterAnimBluePrint)
	{
		USkeletalMeshComponent* thisCharacterMesh = GetMesh();
		thisCharacterMesh->SetSkeletalMesh(CharacterMesh);
		thisCharacterMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
		thisCharacterMesh->SetRelativeRotation(FRotator(0.0, -90.0f, 0.0f));
		thisCharacterMesh->SetAnimClass(CharacterAnimBluePrint);
	}

	IA_EnhancedMove = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_EnhancedMove.IA_EnhancedMove'"));
	IA_Run = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_Run.IA_Run'"));
	IA_OnAim = LoadObject<UInputAction>(nullptr, TEXT("/Script/EnhancedInput.InputAction'/Game/SeongWon/Input/IA_OnAim.IA_OnAim'"));


}


void AVampireSurvivalCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void AVampireSurvivalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bIsOnAim)
	{
		AimMode();
	}
	else
	{

	}
}

void AVampireSurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if(EIC)
	{
		EIC->BindAction(IA_EnhancedMove, ETriggerEvent::Triggered, this, &AVampireSurvivalCharacter::EnhancedMove);
		EIC->BindAction(IA_Run, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedRun);
		EIC->BindAction(IA_Run, ETriggerEvent::Completed, this, &AVampireSurvivalCharacter::ReleasedRun);
		EIC->BindAction(IA_OnAim, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedAim);
		EIC->BindAction(IA_OnAim, ETriggerEvent::Completed, this, &AVampireSurvivalCharacter::ReleasedAim);
		EIC->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &AVampireSurvivalCharacter::Weaponfire);
	}

}

void AVampireSurvivalCharacter::EnhancedMove(const FInputActionValue& Value)
{
	FVector2D NewValue = Value.Get<FVector2D>();

	FRotator ControlRotator = GetControlRotation();

	FVector RightVector = UKismetMathLibrary::GetRightVector(FRotator(0.0, ControlRotator.Yaw, ControlRotator.Roll));
	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(FRotator(0.0, ControlRotator.Yaw, 0.0f));

	AddMovementInput(ForwardVector, NewValue.X);
	AddMovementInput(RightVector, NewValue.Y);
}

void AVampireSurvivalCharacter::PressedRun(const FInputActionValue& Value)
{
	 bool IsRun = Value.Get<bool>();
	 if(IsRun)
	 {
		 VSCharacterMovement->MaxWalkSpeed = 600.0f;
	 }
}

void AVampireSurvivalCharacter::ReleasedRun(const FInputActionValue& Value)
{
	bool IsRun = Value.Get<bool>();

	if (!IsRun)
	{
		VSCharacterMovement->MaxWalkSpeed = 300.0f;
	}
}

void AVampireSurvivalCharacter::PressedAim(const FInputActionValue& Value)
{
	bIsOnAim = true;
}

void AVampireSurvivalCharacter::ReleasedAim(const FInputActionValue& Value)
{
	bIsOnAim = false;
	APlayerController* thisPlayerController = Cast<APlayerController>(GetController());
	thisPlayerController->bShowMouseCursor = false;
}

void AVampireSurvivalCharacter::Weaponfire()
{
}

void AVampireSurvivalCharacter::AimMode()
{
	APlayerController* thisPlayerController = Cast<APlayerController>(GetController());
	thisPlayerController->bShowMouseCursor = true;

	FHitResult MouseHitResult;
	thisPlayerController->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), true, MouseHitResult);

	FVector ImpactLocation = MouseHitResult.ImpactPoint;
	FRotator ActorRotation = GetActorRotation();
	FVector ActorLocation = GetActorLocation();

	FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(FVector(0.0, 0.0, 0.0), UKismetMathLibrary::Subtract_VectorVector(ImpactLocation, ActorLocation));
	FRotator FinalRotation = UKismetMathLibrary::RInterpTo(ActorRotation, TargetRotation, GetWorld()->DeltaTimeSeconds, 500.0f);
	SetActorRotation(FRotator(ActorRotation.Pitch, FinalRotation.Yaw, ActorRotation.Roll));
}

