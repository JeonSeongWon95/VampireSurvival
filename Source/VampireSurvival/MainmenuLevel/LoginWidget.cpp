// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "VampireSurvival/MainmenuLevel/MainMenuPlayerController.h"

void ULoginWidget::SendClientIDAndPassword()
{
	FString PlayerID = IDBox->GetText().ToString();
	FString PlayerPassword = PasswordBox->GetText().ToString();

	if(!PlayerID.IsEmpty() && !PlayerPassword.IsEmpty())
	{
		AMainMenuPlayerController* PlayerController = Cast<AMainMenuPlayerController>(GetWorld()->GetFirstPlayerController());

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("You don't Write ID and Password!"));
	}
}

void ULoginWidget::ClickedQuitButton()
{
	
}

void ULoginWidget::NativeConstruct()
{
	if(Button_Login)
	{
		Button_Login->OnClicked.AddDynamic(this, &ULoginWidget::SendClientIDAndPassword);
	}
	if(Button_Quit)
	{
		Button_Quit->OnClicked.AddDynamic(this, &ULoginWidget::ClickedQuitButton);
	}
}
