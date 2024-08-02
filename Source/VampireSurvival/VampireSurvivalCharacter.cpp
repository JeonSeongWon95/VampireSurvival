#include "VampireSurvivalCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"


AVampireSurvivalCharacter::AVampireSurvivalCharacter()
{
 
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	CameraBoom->TargetArmLength = 800;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

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

void AVampireSurvivalCharacter::EnhancedMove(const FInputActionValue& Value)
{
	FVector2D NewValue = Value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector() * NewValue.X);
	AddMovementInput(GetActorRightVector() * NewValue.Y);
}

