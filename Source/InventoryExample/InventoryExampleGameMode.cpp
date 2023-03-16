// Copyright Epic Games, Inc. All Rights Reserved.

#include "InventoryExampleGameMode.h"
#include "InventoryExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AInventoryExampleGameMode::AInventoryExampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
