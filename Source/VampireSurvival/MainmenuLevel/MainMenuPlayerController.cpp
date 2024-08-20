// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuPlayerController.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"

AMainMenuPlayerController::AMainMenuPlayerController()
{
	bShowMouseCursor = true;


}

void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	BindSocket();
}

void AMainMenuPlayerController::SandLoginData(FString& ID, FString& Password)
{

}

void AMainMenuPlayerController::BindSocket()
{
	ISocketSubsystem* SocketSystem = ISocketSubsystem::Get();
	ServerSocket = SocketSystem->CreateSocket(TEXT("Stream"),TEXT("ServerSocket"));

	FString ServerIP = TEXT("127.0.0.1");
	FIPv4Address IP;
	FIPv4Address::Parse(ServerIP, IP);

	uint32 Port = 10880;

	TSharedRef<FInternetAddr> ServerAddress = SocketSystem->CreateInternetAddr();
	ServerAddress->SetPort(Port);
	ServerAddress->SetIp(IP.Value);

	if(ServerSocket->Connect(*ServerAddress))
	{
		UE_LOG(LogTemp, Error, TEXT("Server Connect Sucess!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Connect Fail!"));
	}
}
