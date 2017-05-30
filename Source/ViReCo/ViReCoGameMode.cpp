// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ViReCoGameMode.h"
#include "ViReCoHUD.h"
#include "ViReCoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AViReCoGameMode::AViReCoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AViReCoHUD::StaticClass();
}
