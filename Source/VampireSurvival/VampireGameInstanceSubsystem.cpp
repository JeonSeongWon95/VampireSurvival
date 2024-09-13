// Fill out your copyright notice in the Description page of Project Settings.


#include "VampireGameInstanceSubsystem.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Address.h"
#include <string.h>


void UVampireGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ConnectedLoginServer();
}

void UVampireGameInstanceSubsystem::ConnectedLoginServer()
{
	//언리얼에서 제공하는 SocketSubsystem.
	//PLATFORM_SOCKETSUBSYSTEM : 다양한 플랫폼에서 사용가능한 소켓 API
	ISocketSubsystem* SocketSystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	

	ServerSocket = SocketSystem->CreateSocket(TEXT("Stream"), TEXT("ServerSocket"));

	FString ServerIP = TEXT("192.168.3.67");
	FIPv4Address IP;
	FIPv4Address::Parse(ServerIP, IP);

	uint32 Port = 10880;

	TSharedRef<FInternetAddr> ServerAddress = SocketSystem->CreateInternetAddr();
	ServerAddress->SetPort(Port);
	ServerAddress->SetIp(IP.Value);

	if (ServerSocket->Connect(*ServerAddress))
	{
		UE_LOG(LogTemp, Error, TEXT("Server Connected"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Connected Fail"));
	}
}

bool UVampireGameInstanceSubsystem::SendUserData(FString& ID, FString& Password, int IDSize, int PassWordSize, int SendType)
{

	if (!ServerSocket || !ServerSocket->GetConnectionState() == ESocketConnectionState::SCS_Connected)
	{
		UE_LOG(LogTemp, Error, TEXT("Not connected to server"));
		return false;
	}

	UE_LOG(LogTemp, Error, TEXT("Is Connect True"));

	const char* CharID = TCHAR_TO_UTF8(*ID);
	strncpy_s(Packet.UserID, CharID, IDSize);
	Packet.UserID[sizeof(Packet.UserID) - 1] = '\0';

	CharID = TCHAR_TO_UTF8(*Password);
	strncpy_s(Packet.UserPassword, CharID, PassWordSize);
	Packet.UserPassword[sizeof(Packet.UserPassword) - 1] = '\0';


	int32 BytesSend = 0;
	Packet.Type = SendType;

	if (ServerSocket->Send(reinterpret_cast<const uint8*>(&Packet), sizeof(Packet), BytesSend))
	{
		UE_LOG(LogTemp, Error, TEXT("Send to Server Socket"));

		char Buffer[1024] = "";
		int32 BytesRecv = 0;

		if (ServerSocket->Recv(reinterpret_cast<uint8*>(&Buffer), sizeof(Buffer), BytesRecv))
		{
			UE_LOG(LogTemp, Error, TEXT("Recive Byte : %d"), (int)strlen(Buffer));
			UE_LOG(LogTemp, Error, TEXT("Recive to Server Socket"));

			Buffer[BytesRecv] = '\0';

			if (strcmp(Buffer, "OK") == 0)
			{
				UE_LOG(LogTemp, Error, TEXT("Data is Right"));
				return true;
			}
			else if (strcmp(Buffer, "False") == 0)
			{
				UE_LOG(LogTemp, Error, TEXT("Data is Incorrect"));
				return false;
			}

		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("2"));
		}

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("1"));
	}



	return false;
}
