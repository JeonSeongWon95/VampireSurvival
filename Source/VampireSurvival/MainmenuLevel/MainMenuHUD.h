

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

	UFUNCTION()
	void ShowSignUpWidget();

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

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "WidgetClass")
	TSubclassOf<class USignUpWidget> SignUpWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<class UJoinWidget> JoinWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<class ULoginWidget> LoginWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TObjectPtr<class USignUpWidget> SignUpWidget;

	
	
};
