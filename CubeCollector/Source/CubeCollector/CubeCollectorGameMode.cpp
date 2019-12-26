// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CubeCollectorGameMode.h"
#include "CubeCollectorHUD.h"
#include "CubeCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACubeCollectorGameMode::ACubeCollectorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACubeCollectorHUD::StaticClass();
}
