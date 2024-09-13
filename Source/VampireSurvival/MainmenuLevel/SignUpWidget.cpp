#include "SignUpWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "VampireSurvival/MainmenuLevel/MainMenuPlayerController.h"
#include "Kismet/KismetSystemLibrary.h"
#include "VampireSurvival/VampireGameInstance.h"

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

void USignUpWidget::ClickedQuitButton()
{
	RemoveFromParent();
}

void USignUpWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!(Button_SignUp->OnClicked.IsBound()))
	{
		Button_SignUp->OnClicked.AddDynamic(this, &USignUpWidget::SendClientIDAndPassword);
	}
	if (!(Button_Quit->OnClicked.IsBound()))
	{
		Button_Quit->OnClicked.AddDynamic(this, &USignUpWidget::ClickedQuitButton);
	}
}
