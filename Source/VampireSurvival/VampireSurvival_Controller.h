// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VampireSurvival_Controller.generated.h"


UCLASS()
class VAMPIRESURVIVAL_API AVampireSurvival_Controller : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Input")
	TObjectPtr<class UInputMappingContext> InputMappingContext;

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* aPawn) override;




	
};
