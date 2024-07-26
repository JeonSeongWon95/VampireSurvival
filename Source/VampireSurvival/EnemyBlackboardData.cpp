
#include "EnemyBlackboardData.h"
#include "Kismet/GameplayStatics.h"
#include "VampireSurvivalCharacter.h"


UEnemyBlackboardData::UEnemyBlackboardData()
{
	AVampireSurvivalCharacter* Player = Cast<AVampireSurvivalCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if(Player)
	{
		Target = Player;
	}
}
