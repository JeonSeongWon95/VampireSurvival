// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"
#include "Components/TileView.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if(CloseButton)
	{
		if (!CloseButton->OnClicked.IsBound())
		{
			CloseButton->OnClicked.AddDynamic(this, &UInventoryWidget::ClickedCloseButton);
		}
	}
}

void UInventoryWidget::ClickedCloseButton()
{
	RemoveFromParent();
}

void UInventoryWidget::ClearTileView()
{
	ItemBox->ClearListItems();
}

void UInventoryWidget::AddTileView(UObject* NewItem)
{
	ItemBox->AddItem(NewItem);
}

void UInventoryWidget::SetGold(uint16 NewGold)
{
	Gold->SetText(FText::AsNumber(NewGold));
}
