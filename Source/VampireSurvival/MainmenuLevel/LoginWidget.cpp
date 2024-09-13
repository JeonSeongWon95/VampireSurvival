// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "VampireSurvival/MainmenuLevel/MainMenuPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "VampireSurvival/VampireGameInstance.h"
#include "VampireSurvival/MainmenuLevel/MainMenuHUD.h"
#include "VampireSurvival/MainmenuLevel/SignUpWidget.h"

void ULoginWidget::SendClientIDAndPassword()
{
	FString PlayerID = IDBox->GetText().ToString();
	FString PlayerPassword = PasswordBox->GetText().ToString();

	if(!PlayerID.IsEmpty() && !PlayerPassword.IsEmpty())
	{
		UVampireGameInstance* GameInstance = Cast<UVampireGameInstance>(GetGameInstance());
		if(GameInstance)
		{
			if(GameInstance->SendMessageToServer(PlayerID, PlayerPassword, PlayerID.Len(), PlayerPassword.Len(), 1))
			{
				RemoveFromParent();

				AMainMenuHUD* HUD = Cast<AMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

				if (HUD)
				{
					HUD->LoginSuccess();
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("SendMessage Fail"));
			}
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("You don't Write ID and Password!"));
	}
}

void ULoginWidget::ClickedQuitButton()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}

void ULoginWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(Button_Login)
	{
		Button_Login->OnClicked.AddDynamic(this, &ULoginWidget::SendClientIDAndPassword);
	}
	if(Button_Quit)
	{
		Button_Quit->OnClicked.AddDynamic(this, &ULoginWidget::ClickedQuitButton);
	}
	if(Button_SignUp)
	{
		Button_SignUp->OnClicked.AddDynamic(this, &ULoginWidget::ClikedSignUpButton);
	}
}

void ULoginWidget::ClikedSignUpButton()
{
	AMainMenuHUD* HUD = Cast<AMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

	if(HUD)
	{
		HUD->ShowSignUpWidget();
	}
}
