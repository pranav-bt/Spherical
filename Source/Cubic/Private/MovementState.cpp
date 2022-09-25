// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementState.h"
#include "SphereCharacter.h"
#include "Idlestate.h"
#include "PlayerStateMachine.h"

UMovementState::UMovementState()
{
	
}

void UMovementState::Begin()
{
	
	
}

void UMovementState::End()
{
	
}

void UMovementState::Update()
{
	

	if ((PlayerCharacter->Controller != nullptr) && (PlayerCharacter->ForwardAxisValue != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = PlayerCharacter->Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		PlayerCharacter->Sphere->AddTorqueInRadians(FVector(0.0f, PlayerCharacter->ForwardAxisValue * 800000.0f, 0.0f), FName("Name_None"), true);
		//PlayerCharacter->AddMovementInput(Direction, PlayerCharacter->ForwardAxisValue);
	}

	if ((PlayerCharacter->Controller != nullptr) && (PlayerCharacter->RightAxisValue != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = PlayerCharacter->Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		PlayerCharacter->Sphere->AddTorqueInRadians(FVector(-PlayerCharacter->RightAxisValue * 800000.0f, 0.0f, 0.0f),FName("Name_None"), true);
	}
}
