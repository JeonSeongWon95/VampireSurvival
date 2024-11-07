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



</details>

<details>
  <summary> 적 : 적 AI </summary>

</details>
