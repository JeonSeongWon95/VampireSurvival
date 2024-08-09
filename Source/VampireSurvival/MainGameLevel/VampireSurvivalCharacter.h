// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "WeaponStruct.h"
#include "VampireSurvivalCharacter.generated.h"

UCLASS()
class VAMPIRESURVIVAL_API AVampireSurvivalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVampireSurvivalCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<class UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CameraBoom")
	TObjectPtr<class USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<class UInputAction> IA_EnhancedMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<class UInputAction> IA_Run;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<class UInputAction> IA_OnAim;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<class UInputAction> IA_Fire;

	UPROPERTY()
	FTimerHandle CharacterTimer;

public:

	UFUNCTION()
	void ZoominMode();

	void EnhancedMove(const FInputActionValue& Value);

	void PressedRun(const FInputActionValue& Value);

	void ReleasedRun(const FInputActionValue& Value);

	void PressedAim(const FInputActionValue& Value);

	void ReleasedAim(const FInputActionValue& Value);

	UFUNCTION()
	void Weaponfire();

	void AimMode();

	UPROPERTY()
	bool bIsOnAim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	TObjectPtr<class UCharacterMovementComponent> VSCharacterMovement;

};
