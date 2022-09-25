// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStateMachine.h"

UPlayerStateMachine::UPlayerStateMachine()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UPlayerStateMachine::BeginPlay()
{
	Super::BeginPlay();
	CurrentState = NewObject<UIdleState>(this);
	// ...
	
}


// Called every frame
void UPlayerStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (CurrentState)
	{
		CurrentState->Update();
	}
	// ...
}

ASphereCharacter* UPlayerStateMachine::GetPlayerCharacter()
{
	return SphereCharacter;
}

void UPlayerStateMachine::MovementStateTransition(float value)
{
	if (Cast<UMovementState>(CurrentState) || !Cast<UIdleState>(CurrentState))
	{
		return;
	}
	SetState<UMovementState>();
}

void UPlayerStateMachine::IdleStateTransition()
{
	if (Cast<UIdleState>(CurrentState))
	{
		return;
	}
	SetState<UIdleState>();
}

void UPlayerStateMachine::JumpStateTransition()
{
	if (Cast<UJumpState>(CurrentState))
	{
		return;
	}
	SetState<UJumpState>();
}

void UPlayerStateMachine::DiveTransitionState()
{
	if (Cast<UDiveState>(CurrentState))
	{
		return;
	}
	SetState<UDiveState>();
}

void UPlayerStateMachine::SlashTransitionState()
{
	if (Cast<UTwirlState>(CurrentState))
	{
		return;
	}
	SetState<UTwirlState>();
}

