
#include "MainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "VampireSurvival/MainmenuLevel/MainMenuWidget.h"

AMainMenuHUD::AMainMenuHUD()
{
	static ConstructorHelpers::FClassFinder<UMainMenuWidget> MyMain(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/Widget/MainMenu/BP_MainMenuWidget.BP_MainMenuWidget_C'"));

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
