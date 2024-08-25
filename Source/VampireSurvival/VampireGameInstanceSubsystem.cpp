// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireGameInstanceSubsystem.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"

void UVampireGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ConnectedLoginServer();
}

void UVampireGameInstanceSubsystem::ConnectedLoginServer()
{
	ISocketSubsystem* SocketSystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	ServerSocket = SocketSystem->CreateSocket(TEXT("Stream"), TEXT("ServerSocket"));

	FString ServerIP = TEXT("127.0.0.1");
	FIPv4Address IP;
	FIPv4Address::Parse(ServerIP, IP);

	uint32 Port = 10880;

	TSharedRef<FInternetAddr> ServerAddress = SocketSystem->CreateInternetAddr();
	ServerAddress->SetPort(Port);
	ServerAddress->SetIp(IP.Value);

	if (ServerSocket->Connect(*ServerAddress))
	{
		char Message[1024] = "Hello Server! I'm Unreal Gamer";
		UE_LOG(LogTemp, Error, TEXT("Server Connect Success!"));

		int32 BytesSend = 0;
		int32 MessageSize = strlen(Message);

		ServerSocket->Send(reinterpret_cast<const uint8*>(Message), MessageSize, BytesSend);

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Connect Fail!"));
	}

}

void UVampireGameInstanceSubsystem::SendUserData(FString& ID, FString& Password)
{
}
