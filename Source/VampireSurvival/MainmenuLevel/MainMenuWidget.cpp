// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UMainMenuWidget::ClickedCreateGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Stage01"), true, "listen");
}

void UMainMenuWidget::ClickedJoinGame()
{
	FString ServerAddress = TEXT("127.0.0.1");
	GetWorld()->GetFirstPlayerController()->ClientTravel(ServerAddress, ETravelType::TRAVEL_Absolute);
}

void UMainMenuWidget::ClickedQuitGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}

void UMainMenuWidget::NativeConstruct()
{
	if(!(Button_CreateGame->OnClicked.IsBound()))
	{
		Button_CreateGame->OnClicked.AddDynamic(this, &UMainMenuWidget::ClickedCreateGame);
	}
	if (!(Button_JoinGame->OnClicked.IsBound()))
	{
		Button_JoinGame->OnClicked.AddDynamic(this, &UMainMenuWidget::ClickedJoinGame);
	}
	if (!(Button_Quit->OnClicked.IsBound()))
	{
		Button_Quit->OnClicked.AddDynamic(this, &UMainMenuWidget::ClickedQuitGame);
	}
}
