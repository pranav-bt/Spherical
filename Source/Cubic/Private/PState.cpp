// Fill out your copyright notice in the Description page of Project Settings.


#include "PState.h"
#include "PlayerStateMachine.h"

UPState::UPState()
{
}

UPState::UPState(UPlayerStateMachine* SM)
{
	PlayerCharacter = SM->GetPlayerCharacter();
}

void UPState::Begin()
{
}

void UPState::Update()
{
}

void UPState::End()
{
}
