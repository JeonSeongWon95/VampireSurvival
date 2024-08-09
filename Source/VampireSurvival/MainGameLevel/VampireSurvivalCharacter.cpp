#include "VampireSurvivalCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"


AVampireSurvivalCharacter::AVampireSurvivalCharacter()
{
 
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	CameraBoom->TargetArmLength = 800;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, 0.0, 0.0));
	CameraBoom->SetRelativeLocation(FVector(0.0, 0.0, 300.0f));

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

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if(EIC)
	{
		EIC->BindAction(IA_EnhancedMove, ETriggerEvent::Triggered, this, &AVampireSurvivalCharacter::EnhancedMove);
	}

}

void AVampireSurvivalCharacter::ZoominMode()
{
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

