// Fill out your copyright notice in the Description page of Project Settings.


#include "StoreEntryWidget.h"
#include "Components/Button.h"


void UStoreEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UStoreEntryWidget* CastWidget = Cast<UStoreEntryWidget>(ListItemObject);

	if(CastWidget)
	{
		ItemName = CastWidget->ItemName;
		ItemImage = CastWidget->ItemImage;
		ItemCost = CastWidget->ItemCost;
	}

	if(!(BuyButton->OnClicked.IsBound()))
	{
		BuyButton->OnClicked.AddDynamic(this, &UStoreEntryWidget::ClickedBuyButton);
	}
}

void UStoreEntryWidget::ClickedBuyButton()
{

}
