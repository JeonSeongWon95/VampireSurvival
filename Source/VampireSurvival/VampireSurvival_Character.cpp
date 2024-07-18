// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireSurvival_Character.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AVampireSurvival_Character::AVampireSurvival_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraBoom);

	CameraBoom->TargetArmLength = 800;
	

}

// Called when the game starts or when spawned
void AVampireSurvival_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVampireSurvival_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVampireSurvival_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if(EIC)
	{
		EIC->BindAction(IA_EnhancedMove, ETriggerEvent::Triggered, this, &AVampireSurvival_Character::EnhancedMove);
	}

}

void AVampireSurvival_Character::EnhancedMove(const FInputActionValue& Value)
{
	FVector2D NewValue = Value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector() * NewValue.X);
	AddMovementInput(GetActorRightVector() * NewValue.Y);
}

