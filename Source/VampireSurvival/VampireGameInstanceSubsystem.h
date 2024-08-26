// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VampireGameInstanceSubsystem.generated.h"

#pragma pack(push, 1)
USTRUCT(BlueprintType)
struct FPacket
{
	GENERATED_BODY()

	int Type;
	char UserID[10];
	char UserPassword[10];
};
#pragma pack(pop)

UCLASS()
class VAMPIRESURVIVAL_API UVampireGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION()
	void ConnectedLoginServer();

	class FSocket* ServerSocket;

	UFUNCTION()
	bool SendUserData(FString& ID, FString& Password, int IDSize, int PassWordSize, int SendType);

	FPacket Packet;
	
};
