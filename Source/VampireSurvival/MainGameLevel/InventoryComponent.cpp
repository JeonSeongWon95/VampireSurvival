// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "InventoryWidget.h"
#include "InventoryEntryWidget.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

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


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	CreateInventory();
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryComponent::CreateInventory()
{

	if (InventoryWidget == nullptr)
	{
		InventoryWidget = CreateWidget<UInventoryWidget>(GetWorld(), InventoryWidgetClass);
	}

}

void UInventoryComponent::UpdateInventory()
{
	if (InventoryWidget == nullptr)
	{
		return;
	}

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

void UInventoryComponent::ShowInventory()
{
	UpdateInventory();
	InventoryWidget->AddToViewport();
	UE_LOG(LogTemp, Error, TEXT("Inventory Open"));
}

void UInventoryComponent::CloseInventory()
{
	InventoryWidget->RemoveFromParent();
	UE_LOG(LogTemp, Error, TEXT("Inventory Close"));
}

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
	for (auto findItem : Items)
	{
		if (findItem.ItemName == Item.ItemName)
		{
			findItem.Count++;
			return;
		}
	}

	if (Items.Num() < 9)
	{
		Items.Add(Item);
		return;
	}
}

void UInventoryComponent::RemoveItem(FItemStruct Item)
{
	Server_RemoveItem(Item);
}

void UInventoryComponent::AddGold(uint8 NewGold)
{
	Server_AddGold(NewGold);
}

void UInventoryComponent::Server_AddGold(uint8 NewGold)
{
	Gold += NewGold;
}

void UInventoryComponent::Server_RemoveItem_Implementation(FItemStruct Item)
{
	for (auto findItem : Items)
	{
		if (findItem.ItemName == Item.ItemName)
		{
			if (findItem.Count >= 1)
			{
				findItem.Count--;
			}
			else
			{
				Items.Remove(findItem);
			}
		}
	}

	UE_LOG(LogTemp, Error, TEXT("Don't have Item"));
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryComponent, Items);
	DOREPLIFETIME(UInventoryComponent, Gold);
}

