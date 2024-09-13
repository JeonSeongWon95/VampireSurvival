// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryEntryWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

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

void UInventoryEntryWidget::SetData(uint16 Count, FString Name, UTexture2D* Image)
{
	ItemCount->SetText(FText::AsNumber(Count));
	ItemName->SetText(FText::FromString(Name));

	FSlateBrush Brush;
	Brush.SetResourceObject(Image);
	ItemImage->SetBrush(Brush);
}

