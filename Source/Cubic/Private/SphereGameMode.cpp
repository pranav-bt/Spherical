// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereGameMode.h"

ASphereGameMode::ASphereGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SphereGame/BP_SphereCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
