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

### 1. 아이템
```cpp
USTRUCT(BlueprintType)
struct VAMPIRESURVIVAL_API FItemStruct : public FTableRowBase
{
	GENERATED_BODY()

public:
	FItemStruct();
	~FItemStruct();

	bool operator==(const FItemStruct& Other) const
	{
		return ItemName == Other.ItemName;
	};

	UPROPERTY()
	FString ItemName;

	UPROPERTY()
	uint32 SellingCost;

	UPROPERTY()
	uint32 ByingCost;

	UPROPERTY()
	uint16 Count;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<class UTexture2D> ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<class UStaticMesh> ItemMesh;

};
```
하나의 아이템 정보를 구성할 이미지, 가격, 수량, 해당 아이템 메쉬를 갖는 구조체를 선언하였습니다.

+ 아이템 컴포넌트
```cpp
class VAMPIRESURVIVAL_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TSubclassOf<class UInventoryWidget> InventoryWidgetClass;
	UPROPERTY()
	TSubclassOf<class UInventoryEntryWidget> InventoryEntryWidgetClass;

	UPROPERTY()
	TObjectPtr<class UInventoryWidget> InventoryWidget;
	UPROPERTY()
	TObjectPtr<class UInventoryEntryWidget> InventoryEntryWidget;

	UPROPERTY(Replicated)
	TArray<FItemStruct> Items;

	UPROPERTY(Replicated)
	uint16 Gold;


void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryComponent, Items);
	DOREPLIFETIME(UInventoryComponent, Gold);
}
```
실제로 아이템을 관리할 컴포넌트를 선언하고, 해당 컴포넌트를 원하는 Actor에 붙이도록 설계하였습니다.
이 컴포넌트에서는 아이템 구조체를 배열(Items)로 갖으며, 서버 기준으로 항상 동기화되어야 하기 때문에 Replicated 매크로를 사용하였습니다.

컴포넌트에서 인벤토리 열거나(ShowInventory) 닫는(CloseInventory) 기능을 구현하였으며, 아이템 추가(AddItem) 기능도 구현하였습니다.
서버와 동기화가 되야하는 변수들은 GetLifetimeReplicatedProps 함수를 통해 서버로 보내는 데이터를 정의하였습니다.


```cpp
UInventoryComponent::UInventoryComponent()
{
	static ConstructorHelpers::FClassFinder<UInventoryWidget> FindInventoryClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/InventoryComponent/WG_InventoryWidget.WG_InventoryWidget_C'"));
	static ConstructorHelpers::FClassFinder<UInventoryEntryWidget> FindInventoryEntryClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/SeongWon/InventoryComponent/WG_InventorEntryWidget.WG_InventorEntryWidget_C'"));

	if (FindInventoryClass.Succeeded())
	{
		InventoryWidgetClass = FindInventoryClass.Class;
	}
	if (FindInventoryEntryClass.Succeeded())
	{
		InventoryEntryWidgetClass = FindInventoryEntryClass.Class;
	}

	InventoryWidget = nullptr;
	InventoryEntryWidget = nullptr;
	Gold = 0;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	CreateInventory();
}

void UInventoryComponent::CreateInventory()
{

	if (InventoryWidget == nullptr)
	{
		InventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), InventoryWidgetClass);
	}

}
```
생성 시 Inventory Component는 화면에 띄울 인벤토리 Widget의 Class를 미리 가져옵니다.
그리고 시작 시 가져온 class를 바탕으로 Widget을 생성합니다.

```cpp
void UInventoryComponent::ShowInventory()
{
	InventoryWidget->SetGold(Gold);
	InventoryWidget->AddToViewport();
}

void UInventoryComponent::CloseInventory()
{
	InventoryWidget->RemoveFromParent();
}
```
해당 컴포넌트의 ShowInventory 함수가 호출되면(i키를 누름) Inventory를 화면에 띄우며, 이미 띄워진 경우 화면에서 Remove합니다.

```cpp
bool UInventoryComponent::AddItem(FItemStruct Item)
{
	if(Items.Num() > 9)
	{
		return false;
	}

	Server_AddItem(Item);

	return true;
}

void UInventoryComponent::Server_AddItem_Implementation(FItemStruct Item)
{
	UE_LOG(LogTemp, Error, TEXT("Item Add"));
	

	for (auto findItem : Items)
	{
		if (findItem.ItemName == Item.ItemName)
		{
			findItem.Count++;
			UpdateInventory(Items);
			return;
		}
	}

	if (Items.Num() < 9)
	{
		Items.Add(Item);
		UE_LOG(LogTemp, Error, TEXT("Item Count : %d"), Items.Num());
		UpdateInventory(Items);
		return;
	}
}
```
아이템 Object와 overlap되면 아이템은 본인이 가진 Item 구조체를 인자로 하여 Component의 AddItem함수를 호출합니다.
AddItem 함수에서는 인벤토리가 가득찬 경우 false를 반환하며, 그렇지 않은 경우 UFUNCTION(Server, Reliable)로 설정된 Server_AddItem 함수를 호출합니다.

Items을 확인하여 동일한 Item이 있는 경우 해당 Item의 갯수를 증가시키며, 아닌 경우는 Items 배열에 추가하였습니다.
그리고 이와 같이 변동이 있는 경우 Update함수를 통해 TileView의 Entry Widget을 Update하도록 하였습니다.

```cpp
void UInventoryComponent::UpdateInventory_Implementation(const TArray<FItemStruct>& NewItems)
{
	if (InventoryWidget == nullptr)
	{
		return;
	}

	Items = NewItems;

	ClearInventory();

	for (auto Item : Items)
	{
		InventoryEntryWidget = CreateWidget<UInventoryEntryWidget>(GetWorld(), InventoryEntryWidgetClass);
		InventoryEntryWidget->SetData(Item.Count, Item.ItemName, Item.ItemImage);
		InventoryWidget->AddTileView(InventoryEntryWidget);
	}

	InventoryWidget->SetGold(Gold);
}

void UInventoryComponent::ClearInventory()
{
	InventoryWidget->ClearTileView();
}
```
Update함수는 Client, Reliable로 설정되어 있어 해당 Actor의 소유자만 본인의 게임에서 이 함수를 실행하게 됩니다.
Inventory Widget의 TileView를 지우고, 다시 Items 배열에 따라 Entry Widget을 생성 및 TileView에 추가하였습니다.

```cpp
void UInventoryEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UInventoryEntryWidget* CastObject = Cast<UInventoryEntryWidget>(ListItemObject);

	if (CastObject)
	{
		CastObject->ItemName = ItemName;
		CastObject->ItemCount = ItemCount;
		CastObject->ItemImage = ItemImage;
	}
}

void UInventoryEntryWidget::SetData(uint16 Count, FString Name, UImage* Image)
{
	ItemCount->SetText(FText::AsNumber(Count));
	ItemName->SetText(FText::FromString(Name));
	ItemImage = *Image;
}
```
Entry Widget은 들어온 인자를 바탕으로 본인의 Imager, Text 들을 설정합니다.
그리고 TileView의 경우 실제로 보여지는 Widget과 생성된 Widget간의 데이터 동기화를 위해 NativeOnListItemObjectSet 함수를 override하여 들어온 데이터를 보여지는 Widget에도 설정되도록 업데이트합니다.

```cpp
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();

	if(HasAuthority())
	{
		GetWorld()->SpawnActor<AItem>(nullptr, GetActorLocation(), GetActorRotation());
	}
	
}
```
아이템은 Level에 배치된 ItemSpawner를 통해 생성되며, 서버(HasAuthority)에서만 생성하도록 하였습니다.

```cpp
AItem::AItem()
{
	static const FString ContextString(TEXT("Item Data Table"));
	static const FString DataTablePath(TEXT("/Script/Engine.DataTable'/Game/SeongWon/Data/DT_ItemData.DT_ItemData'"));

	UDataTable* DataTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *DataTablePath));
	if (DataTable == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Data Table at path: %s"), *DataTablePath);
	}

	const FString RowName = TEXT("Potion");
	FItemStruct* ItemData = DataTable->FindRow<FItemStruct>(FName(*RowName), ContextString);

	Data = *ItemData;
	bReplicates = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	SetRootComponent(Collision);
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Collision->SetCollisionProfileName("Gold");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetStaticMesh(Data.ItemMesh);
	Mesh->SetupAttachment(Collision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}
```
Item은 앞서 정의한 FItemStruct를 변수로 갖습니다.
생성자에서 우선 Data Table의 경로에서 해당 Data Table을 가져온 뒤 해당 Table의 "potion"이라는 RowName의 Data를 찾아옵니다.

가져온 데이터로 본인의 FItemStruct 변수에 할당하며, 플레이어와 충돌을 감지할 Collision과 Level에서 보일 Mesh를 설정합니다.
```cpp
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	if(!(Collision->OnComponentBeginOverlap.IsBound()))
	{
		Collision->OnComponentBeginOverlap.AddDynamic(this, &AItem::EventOverlap);
	}
}

void AItem::EventOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
	bool bFromSweep, const FHitResult& SweepResult)
{
	AVampireSurvivalCharacter* CastCharacter = Cast<AVampireSurvivalCharacter>(OtherActor);

	if (CastCharacter)
	{
		UInventoryComponent* IC = CastCharacter->GetComponentByClass<UInventoryComponent>();

		if (IC)
		{
			IC->AddItem(Data);
			DestoryActor();
		}
	}
}

void AItem::DestoryActor()
{
	Server_DestroyActor();
}

void AItem::Server_DestroyActor_Implementation()
{
	Destroy();
}
```
게임이 시작되면 EventOverlap함수를 연결하여 플레이어가 Overlap되면 해당 함수가 호출되도록 하였습니다.
해당 함수내에서는 플레이어인지 확인하여 동일한 경우 해당 Actor의 Inventory Component를 가져와 AddItem 함수와 본인의 DestoryActor함수를 호출합니다.
DestoryActor 함수는 서버에서 동작하는 Server_DestroyActor함수를 요청하며, 이로 인해 서버에서 객체를 지워주게 됩니다.

### 2. 골드
```cpp

void AEnemy::DoDeath()
{
	Server_DoDeath();
}
void AEnemy::Server_DoDeath_Implementation()
{

	if (HasAuthority())
	{
		GetWorld()->SpawnActor<AGoldActor>(GetActorLocation(), GetActorRotation());
	}

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->MaxWalkSpeed = 0;
	GetWorld()->GetTimerManager().SetTimer(EnemyTimerHandle, this, &AEnemy::DestroyActor, 3.0f, false);
}
```
골드는 Enemy가 사망하면 Server 기준으로 GoldActor를 Spawn합니다.

```cpp
AGoldActor::AGoldActor()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Gold(TEXT("/Script/Engine.StaticMesh'/Game/AncientTreasures/Meshes/SM_Gems_01c.SM_Gems_01c'"));
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	if(SM_Gold.Succeeded())
	{
		Mesh->SetStaticMesh(SM_Gold.Object);
	}
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(Mesh);

	Mesh->SetSimulatePhysics(true);
	Mesh->SetCollisionProfileName("Gold");
	bReplicates = true;
}

void AGoldActor::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetWorldScale3D(FVector(5.f, 5.f, 5.f));
	BoxCollision->SetBoxExtent(FVector(5.f, 5.f, 5.f));

	if(!(BoxCollision->OnComponentBeginOverlap.IsBound()))
	{
		BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AGoldActor::EventOverlap);
	}
}
```
GoldActor는 생성 시 보석 모양의 Mesh를 가져와 StaticMesh로 설정하며, BoxCollision을 추가하여 플레이어와의 충돌을 체크하였습니다.
게임이 시작되면 크기를 키워 쉽게 보이게 하였으며, Overlap 함수를 연결하였습니다.

```cpp
void AGoldActor::EventOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	AVampireSurvivalCharacter* CastCharacter = Cast<AVampireSurvivalCharacter>(OtherActor);

	if(CastCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Overlap Actor : %s"), *CastCharacter->GetName());
		UInventoryComponent* IC = CastCharacter->GetComponentByClass<UInventoryComponent>();

		if(IC)
		{
			IC->AddGold(100);
			DestoryActor();
		}
	}
}

void AGoldActor::DestoryActor()
{
	Server_DestoryActor();
}

void AGoldActor::Server_DestoryActor_Implementation()
{
	Destroy();
}
```
Item과 마찬가지로 Overlap되면 해당 캐릭터의 Inventory Component의 AddGold 함수를 실행하며, Server_DestoryActor를 호출하여 서버에서 지워지도록 하였습니다.
</details>

<details>
  <summary> 애니메이션 : 사격, 총 장착, 달리기 </summary>

### 1. Anim Instance
```cpp
void UVSAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Player = Cast<AVampireSurvivalCharacter>(TryGetPawnOwner());

	if(Player)
	{
		Speed = Player->GetCharacterMovement()->Velocity.Size2D();
		bIsFire = Player->bIsfire;
		bIsReload = Player->bIsReload;
		bIsOnAim = Player->bIsOnAim;

		EquipWeapon = Player->EquipWeapon;

		if(EquipWeapon != nullptr)
		{
			bIsEquip = true;
		}
		else
		{
			bIsEquip = false;
		}
	}
}
```
애니메이션에서 사용될 변수들은 Player의 변수들을 가져와 할당하였습니다.
달리는 애니메이션은 점프와 다르므로 Player의 Velocity를 z축을 제외한 2개의 축만 가져오도록 하였습니다.(Size2D)

![1](https://github.com/user-attachments/assets/f5f94d97-0bc2-4a14-9b35-e4b6fe81b2d4)


Main Pose는 장비의 장착여부로 구성된 총 6개의 State를 가지고 있습니다.

![2](https://github.com/user-attachments/assets/3bdc1f22-0ba8-4842-9abe-513adf6d0d75)
![3](https://github.com/user-attachments/assets/c786fd22-9510-461d-9740-8f8c52390a32)
![4](https://github.com/user-attachments/assets/aa62e3ee-f3c5-4aea-9b0b-56070009f637)

각 State는 앞서 설정한 변수에 따라 State가 변경됩니다.

![5](https://github.com/user-attachments/assets/d4312149-051e-44a8-a1e9-1dd9ffb00eec)

사격의 경우 총을 장착한 상태에서 조준 변수가 true로 되면 상체의 Animation만 변경되도록 Blend Poses를 사용하였습니다.
각 애니메이션은 라이라 프로젝트에서 리소스를 받아 사용하였습니다.
</details>


<details>
  <summary> 무기 : 습득, 장착, 사격 </summary>

### 1. 무기 구조체 선언
```cpp
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WeaponStruct.generated.h"

UENUM()
enum class WeaponType : uint8
{
	None UMETA(DisplayName = "None"),
	Pistol UMETA(DisplayName = "Pistol"),
	Rifle UMETA(DisplayName = "Rifle"),
	ShotGun UMETA(DisplayName = "ShotGun"),
	MAX UMETA(DisplayName = "Max")

};


USTRUCT(BlueprintType)
struct FWeaponStruct : public FTableRowBase
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
	WeaponType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	TObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Demage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float FireRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	TObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	TObjectPtr<UParticleSystem> Effect;

};
```
무기는 아이템과 마찬가지로 가장 기본이 되는 데미지, 총탄, 발사속도 등과 같은 정보를 갖는 구조체를 선언하였습니다.

```cpp
AWeaponSpawner::AWeaponSpawner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	static ConstructorHelpers::FClassFinder<AWeapon> Weapon_Pistol(TEXT("/Script/Engine.Blueprint'/Game/SeongWon/BP/BP_Pistol.BP_Pistol_C'"));

	if(Weapon_Pistol.Succeeded())
	{
		WeaponClass = Weapon_Pistol.Class;
	}

	bReplicates = true;

}
```
Level에 존재하는 Spawner를 통해 Spawn되며, Spawner는 생성 시 Weapon의 Pistol class를 가져와 미리 저장해놓습니다.
또한, Spawn은 모든 Client와 동기화가 되어야 하므로 bReplicates 변수를 true로 선언하였습니다.

```cpp
void AWeaponSpawner::BeginPlay()
{
	Super::BeginPlay();

	if(HasAuthority())
	{
		AWeapon* SpawnedWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponClass, GetActorLocation(), GetActorRotation());
		SpawnedWeapon->SetOwner(this);
	}
	
}
```
게임이 시작되면 서버(HasAuthority)에서 미리 저장한 Class를 바탕으로 Weapon객체를 생성하고 소유권을 Server로 합니다.

```cpp
AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("Weapon");
	WeaponMesh->SetCollisionProfileName("Weapon");
	WeaponMesh->SetSimulatePhysics(true);
	WeaponMesh->SetWorldScale3D(FVector(2.0, 2.0, 2.0));
	SetRootComponent(WeaponMesh);

	bReplicates = true;
	Range = 1000;
}
```
생성된 Weapon 객체는 Mesh, 크기를 조정합니다.

```cpp
void AVampireSurvivalCharacter::PressedPickUpKey(const FInputActionValue& Value)
{
	Server_PressedPickUpWeaponKey();
}

void AVampireSurvivalCharacter::Server_PressedPickUpWeaponKey_Implementation()
{
	AActor* NearWeapon = FindNearWeapon();

	if (false == IsValid(NearWeapon))
	{
		return;
	}
	if (EquipWeapon != nullptr)
	{
		EquipWeapon->SetOwner(nullptr);
	}

	if (HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("Weapon Owner Set"));
		NearWeapon->SetOwner(GetController());
	}

	Client_PressedPickUpWeaponKey(NearWeapon);
}
```
Character에서 PickUp Key를 누르면 서버로 함수 요청이 가며(Server_PressedPickUpWeaponKey), 해당 함수는 서버 기준으로 가장 가까운 Weapon을 찾는 NearWeapon 함수를 호출합니다.
다만, 함수 호출 전 이미 장착한 무기가 있는 경우 해당 무기를 버릴 수 있도록 Owner 설정을 변경합니다.

```cpp
AActor* AVampireSurvivalCharacter::FindNearWeapon()
{
	TArray<AActor*> Actors;
	GetCapsuleComponent()->GetOverlappingActors(Actors, AWeapon::StaticClass());

	if (Actors.Num() <= 0)
	{

	}
	double Distance = 999999.0f;
	AActor* NearActor = nullptr;

	for (AActor* TargetActor : Actors)
	{
		if (EquipWeapon == TargetActor)
		{
			continue;
		}

		double ActorDistance = FVector::Distance(GetActorLocation(), TargetActor->GetActorLocation());

		if (ActorDistance >= Distance)
		{
			continue;
		}

		Distance = ActorDistance;
		NearActor = TargetActor;
	}

	return NearActor;
}
```
FindNearWeapon 함수에서는 현재 플레이어의 Capsule COmponent와 Overlap된 모든 Actor 중 Weapon Class만을 배열로 가져옵니다.
기본 거리를 최대한 높게 설정하고 범위기반 반복문을 통해 해당 거리보다 가까운 Weapon 객체가 있다면 그것을 Near Actor에 할당하고, 해당 Actor와의 거리를 Distance에 대입합니다.

이렇게 해서 가장 가까운 Weapon Actor를 찾아 반환합니다.

```cpp
void AVampireSurvivalCharacter::Client_PressedPickUpWeaponKey_Implementation(AActor* NewWeapon)
{
	AWeapon* NewEquipWeapon = Cast<AWeapon>(NewWeapon);

	if (NewEquipWeapon)
	{
		if (EquipWeapon != nullptr)
		{

			EquipWeapon->DoUnEquipWeapon(this);
			EquipWeapon = nullptr;

		}

		EquipWeapon = NewEquipWeapon;
		EquipWeapon->DoEquipWeapon(this);
	}

}
```
서버에서 해당 Weapon을 찾아 넘겨주면 그 다음부터는 Client에서 처리되도록 NetMulticast, Reliable로 설정된 Client_PressedPickUpWeaponKey_Implementation함수가 호출됩니다.
Client가 아닌 NetMulticast를 속성을 통해 해당 Actor가 모든 Client의 게임 속에서 실행되며, 서버 기준 가장 가까운 Weapon을 인자로 넘겨 받아 해당 Weapon을 장착 무기 변수에 할당합니다.
그 후 Weapon의 DoEquipWeapon 함수에 플레이어 본인을 넣어 실행합니다.
(기존에 장착되었던 무기는 DoUnEquipWeapon 함수를 호출합니다.)

```cpp
void AWeapon::DoUnEquipWeapon(ACharacter* OwingCharacter)
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	WeaponMesh->SetSimulatePhysics(true);
	WeaponOwner = nullptr;
}

void AWeapon::DoEquipWeapon(ACharacter* OwingCharacter)
{

	WeaponOwner = OwingCharacter;

	if (WeaponOwner)
	{
		WeaponMesh->SetSimulatePhysics(false);
		AttachToComponent(WeaponOwner->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("Pistol"));
	}
}
```
DoUnEquipWeapon 함수는 DetachFormActor 함수를 통해 플레이어로부터 Detach 시키며, 다시 물리 연산을 동작시킵니다.
EquipWeapon 함수에서는 플레이어의 Mesh에 Socket Name을 통해 해당 위치로 Attach 시키며 장착되었을때는 땅에 떨어지거나 회전 등 물리 연산을 받아선 안되므로 SimulatePhysics를 끕니다.


### 2. 무기 조준, 발사
```cpp
void AVampireSurvivalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputMappingContext = LoadObject<UInputMappingContext>(nullptr, TEXT("/Script/EnhancedInput.InputMappingContext'/Game/SeongWon/Input/IMC_MyMapping.IMC_MyMapping'"));

	if (InputMappingContext)
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}


	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (EIC)
	{
		EIC->BindAction(IA_EnhancedMove, ETriggerEvent::Triggered, this, &AVampireSurvivalCharacter::EnhancedMove);
		EIC->BindAction(IA_Run, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedRun);
		EIC->BindAction(IA_Run, ETriggerEvent::Completed, this, &AVampireSurvivalCharacter::ReleasedRun);
		EIC->BindAction(IA_PickUpWeapon, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedPickUpKey);
		EIC->BindAction(IA_Fire, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::Weaponfire);
		EIC->BindAction(IA_OnAim, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedAim);
		EIC->BindAction(IA_OnAim, ETriggerEvent::Completed, this, &AVampireSurvivalCharacter::ReleaseAim);
		EIC->BindAction(IA_OpenInventory, ETriggerEvent::Started, this, &AVampireSurvivalCharacter::PressedOpenInventory);
	}

}

void AVampireSurvivalCharacter::PressedAim(const FInputActionValue& Value)
{
	Server_RequestAimMode();
}

void AVampireSurvivalCharacter::ReleaseAim(const FInputActionValue& Value)
{
	Server_RequestAimModeFasle();
}
```
무기 조준은 조준키를 누르면 서버로 함수요청을 하도록 하였으며, 반대로 버튼에서 손을 떼면 다시 Release 되도록 두 개의 함수를 Bind 하였습니다.

```cpp
void AVampireSurvivalCharacter::Server_RequestAimMode_Implementation()
{
	bIsOnAim = true;
}
void AVampireSurvivalCharacter::Server_RequestAimModeFasle_Implementation()
{
	bIsOnAim = false;
}

void AVampireSurvivalCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AVampireSurvivalCharacter, bIsfire);
	DOREPLIFETIME(AVampireSurvivalCharacter, bIsReload);
	DOREPLIFETIME(AVampireSurvivalCharacter, bIsOnAim);
}
```
각 두 개의 함수는 캐릭터 class에 선언된 변수를 서버 기준 변경을 하도록 하였으며, GetLifetimeReplicatedProps함수를 통해 해당 변수들을 복제, 동기화하도록 설정하였습니다.
해당 변수의 값에 따라 Animation Blue Print에서 Blend per를 통해 조준하는 Animation이 실행되거나, 실행 취소가 됩니다.

![1](https://github.com/user-attachments/assets/7751a1de-599e-459e-a3b7-3fcc1b0f8dd0) ![2](https://github.com/user-attachments/assets/f7f85987-310c-41e2-9461-413a9a5d36d0)

```cpp
void AVampireSurvivalCharacter::Weaponfire(const FInputActionValue& Value)
{
	if (EquipWeapon != nullptr)
	{
		Server_RequestFire();
	}
}

void AVampireSurvivalCharacter::Server_RequestFire_Implementation()
{
	if (!bIsfire)
	{
		bIsfire = true;
		UAnimMontage* FireAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Pistol/MM_Pistol_Fire_Montage.MM_Pistol_Fire_Montage'"));
		if (HasAuthority())
		{
			UE_LOG(LogTemp, Error, TEXT("Play Anim"));
			PlayAnimMontage(FireAnim);
		}
	}
}
```
장착한 무기가 있는 경우 특정 키를 눌러 Fire 함수를 호출할 수 있으며, 해당 함수는 서버로 요청하여 서버 기준 bIsfire 변수를 true로 만든 후 Anim Montage를 실행시킵니다.

```cpp
void UFireAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, 
	const FAnimNotifyEventReference& EventReference)
{
	AVampireSurvivalCharacter* Character = Cast<AVampireSurvivalCharacter>(MeshComp->GetOwner());

    if (Character)
    {
        if (Character->HasAuthority())
        {
            Character->EquipWeapon->FireWeapon();
        }
    }
}
```
FireAnim Montage가 실행되면 해당 Montage의 초기부분에 위치한 UFireAnimNotify가 호출됩니다.
해당 Notify에서는 EquipWeapon의 FireWeapon 함수를 호출합니다.

```cpp
void AWeapon::FireWeapon()
{
	FireWeapon_Server();
}

void AWeapon::FireWeapon_Server_Implementation()
{
	if (WeaponOwner != nullptr)
	{
		FVector Location = WeaponMesh->GetSocketLocation(FName("Muzzle"));
		FVector WeaponRange = Location + (WeaponOwner->GetActorForwardVector() * Range);

		FHitResult HitResult;
		bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Location, WeaponRange, ECC_Visibility);

		if (bHit)
		{
			AEnemy* HitActor = Cast<AEnemy>(HitResult.GetActor());
			HitActor->HitBullet(50);
		}
	}


}
```
Notify는 해당 Weapon의 Server 함수를 호출할 권한이 없으므로, Weapon의 일반 함수를 호출하고 해당 함수 내에서 Weapon이 본인의 Server 함수를 호출하도록 하였습니다.
Weapon의 Socket을 가져와 해당 Socket의 위치 값에서 LineTrace를 발사하며, 해당 LineTrace에 Hit 결과 중 해당 Actor가 적인 경우에 데미지를 주는 HitBullet 함수를 호출합니다.

```cpp
void AEnemy::HitBullet(int32 Damage)
{
	Server_RequestAddDamage(Damage);
}

void AEnemy::Server_RequestAddDamage_Implementation(int32 Damage)
{
	if((Health - Damage) < 0)
	{
		Health = 0;
	}
	else
	{
		Health -= Damage;
	}

	if(HasAuthority())
	{
		OnReq_UpdateHP();
	}
}
```
Enemy에서는 전달받은 Damager를 다시 서버 함수로 전달하여 서버 기준 본인이 Health를 변경합니다.

```cpp
void UFinishFireNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	AVampireSurvivalCharacter* Character = Cast<AVampireSurvivalCharacter>(MeshComp->GetOwner());

	if (Character)
	{
		Character->ClientRequestFireFalse();
	}
}
```
마지막으로 계속 해서 Fire가 되지 않도록 bIsfire가 false일 경우에만 fire가 되는데 이는 해당 Anim Montage가 끝날때 호출되는 UFinishFireNotify에서 다시 false로 변경해주도록 설계하였습니다.
</details>

<details>
  <summary> 적 : 적 AI </summary>

### 1. Behavior Tree


![3](https://github.com/user-attachments/assets/ddf0d5d3-333b-4658-b30f-e7e445162abc)

적은 미리 설계한 Behavior Tree의 Task를 순차적으로 실행합니다.


```cpp
EBTNodeResult::Type UBTTask_FindNearPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

    UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
    if (BlackboardComp)
    {
        FVector CurrentLocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
        AActor* NearestPlayer = FindNearestPlayer(CurrentLocation);

        if (NearestPlayer)
        {
            BlackboardComp->SetValueAsObject(TEXT("Target"), NearestPlayer);
            return EBTNodeResult::Succeeded;
        }
    }

    return EBTNodeResult::Failed;
}

AActor* UBTTask_FindNearPlayer::FindNearestPlayer(FVector Location)
{
    AActor* NearestPlayer = nullptr;
    double NearestDistance = TNumericLimits<double>::Max();

    TArray<APlayerState*> PlayerArray = GetWorld()->GetGameState()->PlayerArray;
    for (APlayerState* PlayerState : PlayerArray)
    {

        AActor* PlayerPawn = PlayerState->GetOwningController()->GetPawn();

        if (PlayerPawn)
        {
            FVector PlayerLocation = PlayerPawn->GetActorLocation();
            double Distance = FVector::Distance(Location, PlayerLocation);

            if (Distance < NearestDistance)
            {
                NearestDistance = Distance;
                NearestPlayer = PlayerPawn;
            }
        }
    }

    return NearestPlayer;
}
```
첫번째로 Enemy는 가장 가까이에 위치한 Player를 찾습니다.
GameState에 저장된 PlayerArray를 통해 Level에 존재하는 모든 Player를 배열로 가져옵니다.
그 후 범위기반 반복문을 통해 일전에 가장 가까운 Weapon을 찾아낸 것과 같이 동일하게 가장 가까운 Player를 찾아 반환합니다.

찾으면 반환된 Actor를 연결된 BlackBoard의 Target 값에 할당합니다.

```cpp
EBTNodeResult::Type UUpdateTargetLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BBC = OwnerComp.GetBlackboardComponent();

	if(BBC)
	{
		AActor* Player = Cast<AActor>(BBC->GetValueAsObject(TEXT("Target")));

		if(Player)
		{
			BBC->SetValueAsVector(TEXT("TargetLocation"), Player->GetActorLocation());
			return EBTNodeResult::Succeeded;
		}
		else
		{
			return EBTNodeResult::Failed;
		}

	}
	else
	{
		return EBTNodeResult::Failed;
	}
}
```
그 다음 Target에 설정된 Actor의 Location을 가져와 TargetLocation을 업데이트 해줍니다.

```cpp
EBTNodeResult::Type UTargetMoveTo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	AEnemy* CastEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());

	if (!(CastEnemy->IsDead))
	{

		if (BlackboardComp)
		{
			AVampireSurvivalCharacter* Character = Cast<AVampireSurvivalCharacter>(BlackboardComp->GetValueAsObject(TEXT("Target")));

			if (Character)
			{
				FVector TargetLocation = Character->GetActorLocation();
				FVector ALocation = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();

				double Distance = FVector::Distance(ALocation, TargetLocation);

				if (Distance < 200)
				{
					return EBTNodeResult::Succeeded;
				}
				else
				{
					OwnerComp.GetAIOwner()->MoveToLocation(TargetLocation);
				}

			}

		}
	}

	return EBTNodeResult::Failed;
}
```
Location이 업데이트 되면, 해당 Location으로 움직입니다.
우선 해당 Target Location과 거리를 계산하여 200보다 큰 경우는 MoveToLocation을 통해 이동하고, 작은 경우는 Succeeded를 반환하여 다음 Task를 실행되도록 합니다.

```cpp
EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AEnemy* CastEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());

	if (!(CastEnemy->IsDead))
	{
		uint8 RandomAttack = rand() % 2;
		UAnimMontage* AttackAnim = nullptr;

		switch (RandomAttack)
		{
		case 1:
			AttackAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Enemy/Animation/Zombie_Attack__1__Montage.Zombie_Attack__1__Montage'"));
			break;
		default:
			AttackAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Enemy/Animation/Zombie_Attack_Montage.Zombie_Attack_Montage'"));
			break;
		}


		CastEnemy->CantMove();
		CastEnemy->Req_Attack(AttackAnim);
	}

	return EBTNodeResult::Succeeded;
}
```
2개의 Animation 중 하나가 실행되도록 랜덤한 값을 계산하여 Switch/case 문을 통한 각기 다른 Anim Montage를 실행킵니다.
공격 시에는 움직이지 않도록 CantMove 함수를 통해 변수를 변경하여, 공격 Anim Montage에서는 멈춘 적이 다시 움직이도록 speed 변수를 바꿀 EndAttack Notify가 실행됩니다.

```cpp
void UEndAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	AEnemy* Character = Cast<AEnemy>(MeshComp->GetOwner());

	if (Character)
	{
		Character->CanMove();
	}
}
```
해당 Anim Montage가 실행되고 종료될 때쯤 EndAttack Notify가 실행되며, 여기서 다시 적이 움직일 수 있도록 speed 변수를 변경합니다.

```cpp
void AEnemy::OnReq_UpdateHP()
{
	if (Health > 0)
	{
		UAnimMontage* HitAnim = LoadObject<UAnimMontage>(nullptr, TEXT("/Script/Engine.AnimMontage'/Game/SeongWon/Animation/Enemy/Animation/Zombie_Reaction_Hit_Montage.Zombie_Reaction_Hit_Montage'"));
		if (HitAnim)
		{
			PlayAnimMontage(HitAnim);
		}
	}
	else
	{
		if (!IsDead)
		{
			IsDead = true;
			DoDeath();
		}
	}
}

void AEnemy::DoDeath()
{
	Server_DoDeath();
}

void AEnemy::Server_DoDeath_Implementation()
{

	if (HasAuthority())
	{
		GetWorld()->SpawnActor<AGoldActor>(GetActorLocation(), GetActorRotation());
	}

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetCharacterMovement()->MaxWalkSpeed = 0;
	GetWorld()->GetTimerManager().SetTimer(EnemyTimerHandle, this, &AEnemy::DestroyActor, 3.0f, false);
}
```
마지막으로 적이 총의 Line Trace에 의해 Hit한 경우 Hit Anim Montage가 실행되며, 체력이 0인 경우 DoDeath 함수를 호출합니다.
해당 함수는 서버의 Server_DoDeath 함수를 호출하며, Server 기준 Gold를 위치에 생성하고 Enemy는 Mesh, Collision, Speed 값을 바꾸고 일정 시간 후 DestroyActor가 호출되도록 하였습니다.
</details>
