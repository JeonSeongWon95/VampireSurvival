

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
	TSubclassOf<class UMainMenuWidget> MainWidgetclass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<class UMainMenuWidget> MainWidget;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "WidgetClass")
	TSubclassOf<class UJoinWidget> JoinWidgetclass;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "WidgetClass")
	TSubclassOf<class ULoginWidget> LoginWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<class UJoinWidget> JoinWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<class ULoginWidget> LoginWidget;


	
};
