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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<class UInputAction> IA_PickUpWeapon;

	UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Input")
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Input")
	TObjectPtr<class UInputAction> IA_Reload;

	UPROPERTY()
	FTimerHandle CharacterTimer;

	UPROPERTY()
	float FireRate;

public:

	void EnhancedMove(const FInputActionValue& Value);

	void PressedRun(const FInputActionValue& Value);

	void ReleasedRun(const FInputActionValue& Value);

	void PressedPickUpKey(const FInputActionValue& Value);

	void PressedAim(const FInputActionValue& Value);

	void ReleaseAim(const FInputActionValue& Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EquipWeapon")
	TObjectPtr<class AWeapon> EquipWeapon;

	UFUNCTION()
	void Weaponfire(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	TObjectPtr<class UCharacterMovementComponent> VSCharacterMovement;

	UFUNCTION(Server, Reliable)
	void PlayerIsRun();

	UFUNCTION(Server, Reliable)
	void PlayerIsNotRun();

	UFUNCTION(NetMulticast, Reliable)
	void ChanageMovementSpeed(float Speed);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = OnReq_Fire)
	bool bIsfire;

	UPROPERTY(ReplicatedUsing = OnReq_Reload)
	bool bIsReload;

	UFUNCTION()
	void OnReq_Fire();

	UFUNCTION()
	void OnReq_Reload();

	UFUNCTION(Server, Reliable)
	void Server_RequestFire();

	UFUNCTION(Server, Reliable)
	void Server_RequestReload(bool Newbool);

	//UFUNCTION()
	//void WeaponNotfire(const FInputActionValue& Value);

	UFUNCTION()
	AActor* FindNearWeapon();

	UFUNCTION(Server, Reliable)
	void Server_PressedPickUpWeaponKey();

	UFUNCTION(NetMulticast, Reliable)
	void Client_PressedPickUpWeaponKey(AActor* NewWeapon);

	UFUNCTION(Server, Reliable)
	void Server_ChangeFireFalse();

	UPROPERTY(Replicated)
	bool bIsOnAim;

	UFUNCTION(Server, Reliable)
	void Server_RequestAimMode();

	UFUNCTION(Server, Reliable)
	void Server_RequestAimModeFasle();

	UFUNCTION()
	void ClientRequestFireFalse();

	bool operator==(const AVampireSurvivalCharacter& other) const = default;

	
};
