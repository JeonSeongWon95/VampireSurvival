

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"


UCLASS()
class VAMPIRESURVIVAL_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	AMainMenuHUD();

protected:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "WidgetClass")
	TSubclassOf<UUserWidget> MainWidgetclass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<UUserWidget> MainWidget;

	virtual void BeginPlay() override;
	
};
