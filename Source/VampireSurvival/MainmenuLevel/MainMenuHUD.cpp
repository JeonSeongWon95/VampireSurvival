
#include "MainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AMainMenuHUD::AMainMenuHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MyMain(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/Widget/MainMenu/BP_MainMenuWidget.BP_MainMenuWidget'_C"));

	if(MyMain.Succeeded())
	{
		MainWidgetclass = MyMain.Class;
	}
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	MainWidget = CreateWidget(GetWorld(), MainWidgetclass);
	MainWidget->AddToViewport();

}
