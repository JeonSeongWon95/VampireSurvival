# 프로젝트개요
본 프로젝트는 언리얼 엔진으로 만든 탑다운 멀티 슈터 게임입니다.

프로젝트 기간은 약 한달정도 소요되었으며, WinSocket을 활용하여 멤버쉽 기능을 추가하였습니다.

개발 인원은 1인입니다.

[플레이 영상](https://youtu.be/oOUoGfm9e3g?si=gqPIbEi3Gxq5WZfw, "Youtube")


# 구현한 기능

토글을 열어 **자세한 코드**를 확인하실 수 있습니다.


<details>
  <summary> 멤버쉽 기능 : 로그인, 회원가입 </summary>

### 1. Server
```cpp
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in ServerAddress;
	memset(&ServerAddress, 0, sizeof(ServerAddress));

	ServerAddress.sin_addr.s_addr = INADDR_ANY;
	ServerAddress.sin_port = htons(10880);
	ServerAddress.sin_family = AF_INET;

	int Result = bind(ServerSocket, (sockaddr*)&ServerAddress, sizeof(ServerAddress));

	if (Result != 0)
	{
		printf("Bind Error");
		exit(-1);
	}

	Result = listen(ServerSocket, 5);

	if (Result != 0)
	{
		printf("listen Error");
		exit(-1);
	}
```
Server의 Main 함수에서는 WSAData 객체(WinSocket API의 초기화와 종료를 위한 데이터가 들은 구조체)를 생성하고, 2.2 버전으로 설정 및 초기화하였습니다.
socket 함수를 이용하여 주소체계(IPv4), 연결 방식(연결 지향형), 프로토콜(TCP Protocol)를 인자로 Socket을 하나 생성합니다.
IP주소와 Port 주소를 갖을 sockaddr_in 구조체를 선언하고(sockaddr과 동일하나 각 byte 별로 나누어진 구조체) 초기화합니다.

Port 번호는 10880(언리얼 기본 포트), IP는 보통 서버의 IP주소를 쓰는게 일반적이나 모든 IP 주소에서 들어오는 연결을 받기 위해 INADDR_ANY로 선언하였습니다.
주소 체계도 IPv4를 사용할 것이므로, AF_INET로 설정하였습니다.

생성된 Socket과 sockaddr_in 구조체를 서로 연결해줍니다.
연결 후 Server Socket을 Listen 상태로 변경하며, 5명까지 대기가 가능하도록 하였습니다.

```cpp
	fd_set ClientServerSockets;
	FD_ZERO(&ClientServerSockets);
	FD_SET(ServerSocket, &ClientServerSockets);

	fd_set CopySocketList;
	FD_ZERO(&CopySocketList);

	timeval Timer;
	Timer.tv_sec = 0;
	Timer.tv_usec = 10;

	char MainBuffer[1024] = { 0, };
	char Message[1024] = "OK";
	char NoMessage[1024] = "No";
```
파일 디스크립션의 집합체인 ReadSockets를 선언하고, Server를 넣었습니다. 
Select 함수는 인자로 전달한 파일 디스크립션의 집합체를 수정하므로 원본이 아닌 복제본도 선언하였습니다.
검사 시간은 10마이크로(0.00001)초로 설정하였습니다.

미리 Buffer로 사용할 MainBuffer와 일치하면 반환할 Message, 불일치 시 반환할 NoMessage Buffer도 선언하였습니다.

```cpp
while (true)
	{
		CopySocketList = ClientServerSockets;
		int SelectedResult = select(0, &CopySocketList, 0, 0, &Timer);

		if (SelectedResult <= 0)
		{
			continue;
		}
		for (unsigned int i = 0; i < CopySocketList.fd_count; ++i)
		{
			if (CopySocketList.fd_array[i] == ServerSocket)
			{
				struct sockaddr_in ClientAddress;
				memset(&ClientAddress, 0, sizeof(ClientAddress));
				int ClientAddressSize = sizeof(ClientAddress);
				SOCKET ClientSocket = accept(ServerSocket, (sockaddr*)&ClientAddress, &ClientAddressSize);

				if (ClientSocket == INVALID_SOCKET)
				{
					printf("Accept Error\n");
					continue;
				}

				FD_SET(ClientSocket, &ClientServerSockets);
			}
```
반목문을 통해 Select함수를 실행하며 fd_set 내 변화가 있는지 확인합니다.
변화가 있다면 해당 소켓이 Server 소켓과 동일한지 확인하고 동일하다면 Client에서 접속 요청을 한 것이므로 Accept 함수를 호출한 뒤 원본 fd_set에 추가하였습니다.

```cpp
      else
			{
				int ReciveLength = recv(CopySocketList.fd_array[i], MainBuffer, sizeof(MainBuffer), 0);


				if (ReciveLength <= 0)
				{
					printf("Recive Error\n");
				}

				else
				{
					printf("Recive Success\n");
					FPacket UserData;
					memcpy(&UserData, MainBuffer, sizeof(FPacket));
					int SendLength = 0;

					printf("%s , %s , %d\n", UserData.UserID, UserData.UserPassword, UserData.Type);

					FILE* txtFile;

					if(UserData.Type == 1)
					{

						txtFile = fopen("test.txt", "r");
						char Buffer[10] = "";
						const char* User = UserData.UserID;

						if(txtFile == nullptr)
						{
							printf("File open error\n");
							std::cerr << "File open error: " << strerror(errno) << std::endl;
							return false;
						}

						while(fgets(Buffer, 10, txtFile) != nullptr)
						{
							GetLineEnd(Buffer);

							if (strcmp(Buffer, User) == 0)
							{
								if (fgets(Buffer, 10, txtFile))
								{
									GetLineEnd(Buffer);
									User = UserData.UserPassword;

									if (strcmp(Buffer, User) == 0)
									{
										SendLength = send(CopySocketList.fd_array[i], Message, (int)strlen(Message), 0);
										printf("Send Reult to Client \n");
										break;
									}
								}
							}
						}

						SendLength = send(CopySocketList.fd_array[i], NoMessage, (int)strlen(NoMessage), 0);

						fclose(txtFile);

					}

void GetLineEnd(char* str)
{
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

```

```cpp
#pragma pack(push, 1)
struct FPacket
{
	int Type;
	char UserID[10];
	char UserPassword[10];
};
#pragma pack(pop)
```

만약 서버 소켓이 아닌 경우 해당 소켓엣 전달한 데이터가 있는 것이므로 메인 버퍼를 통해 해당 데이터를 수신합니다.
FPack이라는 별도의 객체로 해당 데이터를 받아오며, 받아온 데이터의 변수 Data.Type의 1인 경우는 로그인 로직을 수행합니다.

정보가 적힌 파일을 읽기 모드로 열고 첫 줄을 Buffer로 가져옵니다.
(ID 길이 제한이 10이므로 10만큼 가져오도록 하였습니다.)

가져온 데이터가 0이 아니라면 우선 줄바꿈 문자를 제거하여 문자열만을 비교하도록 GetLineEnd함수를 호출하였습니다.
Buffer의 Data와 User(Data.UserID를 복사한 객체)를 비교하여 같다면, 그 다음줄을 가져옵니다.

마찬가지로 줄바꿈 문자를 제거하며, User에 Data.UserPassword 대입 가져온 다음줄을 비교하도록 하였습니다.
비밀번호까지 같은 경우 해당 Client에게 "OK"라는 문자열을 반환해주며, 다른 경우 "false"라는 문자열을 반환합니다.

```cpp
					else if(UserData.Type == 2)
					{
						txtFile = fopen("test.txt", "a");

						if (txtFile == nullptr)
						{
							printf("File open error\n");
							std::cerr << "File open error: " << strerror(errno) << std::endl;
							return false;
						}

						char Buffer[10] = "";
						fseek(txtFile, 0, SEEK_END);

						fprintf(txtFile, "\n");

						const char* text = UserData.UserID;
						fprintf(txtFile, "%s\n", text);

						text = UserData.UserPassword;
						fprintf(txtFile, "%s\n", text);

						SendLength = send(CopySocketList.fd_array[i], Message, (int)strlen(Message), 0);

						fseek(txtFile, 0, SEEK_SET);
						fclose(txtFile);
					}
					

					if (SendLength <= 0)
					{
						int ErrorCode = WSAGetLastError();
						printf("Send Error: %d\n", ErrorCode);
						closesocket(CopySocketList.fd_array[i]);
						FD_CLR(CopySocketList.fd_array[i], &ClientServerSockets);
					}
					else
					{
						printf("Send Suceed");
					}

				}

```
만약 전달 받은 Data.Type이 2인 경우 회원가입 로직이 실행됩니다.
회원정보가 저장되어 있는 파일을 쓰기모드로 열고 fseek 함수를 통해 가장 마지막 줄로 파일 포인터를 옮깁니다.

그 다음 줄에 UserID와 UserPassword를 기입하고 종료합니다.
전달된 데이터의 값이 0인 경우 해당 소켓을 종료 및 fd_set에서 제외하도록 하였습니다.

### 2. Client
```cpp
void UVampireGameInstance::Init()
{
	Super::Init();

	if(GetSubsystem<UVampireGameInstanceSubsystem>())
	{
		VampireSubSystem = GetSubsystem<UVampireGameInstanceSubsystem>();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Can't Get Subsystem"));
	}
}

bool UVampireGameInstance::SendMessageToServer(FString& ID, FString& Password, int IDSize, int PassWordSize, int SendType)
{
	if(VampireSubSystem)
	{
		if(VampireSubSystem->SendUserData(ID, Password, IDSize, PassWordSize, SendType))
		{
			return true;
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("SubSystem Send User Data Fail"));
		}
	}
	
	return false;
}
```
GameInstance를 상속받는 새로운 GameInstance Class를 설계하고 해당 Instance의 시작 시 회원가입 시스템을 갖는 GameInstanceSubSystem class를 가져와 저장합니다.
전달 받은 UserData를 SubSystem을 통해 넘기는 함수를 재정의하여 외부에서 쉽게 GameInstance를 통해 Data를 넘길 수 있도록 하였습니다.

```cpp
#pragma pack(push, 1)
USTRUCT(BlueprintType)
struct FPacket
{
	GENERATED_BODY()

	int Type;
	char UserID[10];
	char UserPassword[10];
};
#pragma pack(pop)
```

```cpp
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
		UE_LOG(LogTemp, Error, TEXT("Server Connected"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Server Connected Fail"));
	}
}

```
해당 GameInstanceSubSystem에서는 초기화와 Login Server로 연결을 시도합니다.
Unreal에서 제공하는 SocketSubsystem을 사용하여 CreateSocket 함수를 호출 새로운 Socket을 생성합니다.

CreateInternetAddr을 통해 주소 구조체를 생성하고 IP 주소(루프백)와 Port 번호를 대입 및 Socket과 연결해줍니다.

```cpp
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

	}
	return false;
}
```
앞선 GameInstance를 통해 호출되는 SendUserData함수는 전달 받은 인자들(UserID, UserPassword, SendType)을 Packet 객체의 멤버 변수에 각각 할당합니다.
Packet 객체는 Server Socket으로 전달되며 Recv를 통해 결과값을 전달받습니다.

결과값을 "OK", "False" 문자열들과 비교하여 해당 문자열과 같다면 그 결과값을 return하도록 하였습니다.

```cpp
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> IDBox;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> PasswordBox;

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
```
게임 시작 시 MainHUD에 LoginWidget 객체 생성 및 AddToViewPort를 통해 화면에 로그인 창을 띄웁니다.
해당 로그인 창에 있는 UEditableTextBox 2개에서 각각 아이디와 비밀번호를 입력받습니다.

로그인 버튼을 누르면 Button과 Bind된 SendClientIDAndPassword 함수가 EditableTextBox의 값을 String으로 가져옵니다.
가져온 ID와 Password는 GameInstance의 SendMessageToServer 함수를 통해 인자로 넘깁니다.

```cpp
void ULoginWidget::ClikedSignUpButton()
{
	AMainMenuHUD* HUD = Cast<AMainMenuHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

	if(HUD)
	{
		HUD->ShowSignUpWidget();
	}
}

void USignUpWidget::SendClientIDAndPassword()
{
	FString PlayerID = IDBox->GetText().ToString();
	FString PlayerPassword = PasswordBox->GetText().ToString();

	if (!PlayerID.IsEmpty() && !PlayerPassword.IsEmpty())
	{
		UVampireGameInstance* GameInstance = Cast<UVampireGameInstance>(GetGameInstance());
		if (GameInstance)
		{
			if (GameInstance->SendMessageToServer(PlayerID, PlayerPassword, PlayerID.Len(), PlayerPassword.Len(), 2))
			{
				UE_LOG(LogTemp, Error, TEXT("SignUp Success"));
				RemoveFromParent();
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
```
회원가입 버튼을 누르면 SignUpWidget을 AddToViewPort로 화면에 띄웁니다.
회원가입 UI도 Bind된 함수를 이용하여 입력한 아이디와 비밀번호를 GameInstance를 통해 Server로 전달합니다.
</details>

<details>
  <summary> 인벤토리 : 아이템 습득, 아이템 표시, 골드 획득 및 현재 골드량 표시 </summary>

</details>

<details>
  <summary> 애니메이션 : 사격, 총 장착, 달리기 </summary>

</details>

<details>
  <summary> 적 : 적 AI </summary>

</details>
