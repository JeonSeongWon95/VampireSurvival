
#include "MainMenuHUD.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "VampireSurvival/MainmenuLevel/MainMenuWidget.h"
#include "VampireSurvival/MainmenuLevel/LoginWidget.h"
#include "VampireSurvival/MainmenuLevel/JoinWidget.h"
#include "VampireSurvival/MainmenuLevel/SignUpWidget.h"

AMainMenuHUD::AMainMenuHUD()
{
	static ConstructorHelpers::FClassFinder<UMainMenuWidget> MyMain(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/Widget/MainMenu/BP_MainMenuWidget.BP_MainMenuWidget_C'"));
	static ConstructorHelpers::FClassFinder<ULoginWidget> Login(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/Widget/MainMenu/WG_LoginWidget.WG_LoginWidget_C'"));
	static ConstructorHelpers::FClassFinder<UJoinWidget> Join(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/Widget/MainMenu/WG_JoinGameWidget.WG_JoinGameWidget_C'"));
	static ConstructorHelpers::FClassFinder<USignUpWidget> Signup(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/Widget/MainMenu/WG_SignUpWidget.WG_SignUpWidget_C'"));
	


	if(MyMain.Succeeded() && Login.Succeeded() && Join.Succeeded() && Signup.Succeeded())
	{
		MainWidgetclass = MyMain.Class;
		JoinWidgetclass = Join.Class;
		LoginWidgetClass = Login.Class;
		SignUpWidgetClass = Signup.Class;
	}
}

void AMainMenuHUD::ShowSignUpWidget()
{
	if(SignUpWidget)
	{
		SignUpWidget->AddToViewport();
	}
}

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	check(MainWidgetclass)
	check(JoinWidgetclass)
	check(LoginWidgetClass)
	check(SignUpWidgetClass)

	MainWidget = Cast<UMainMenuWidget>(CreateWidget(GetWorld(), MainWidgetclass));
	JoinWidget = Cast<UJoinWidget>(CreateWidget(GetWorld(), JoinWidgetclass));
	LoginWidget = Cast<ULoginWidget>(CreateWidget(GetWorld(), LoginWidgetClass));
	SignUpWidget = Cast<USignUpWidget>(CreateWidget(GetWorld(), SignUpWidgetClass));

	LoginWidget->AddToViewport();
}
