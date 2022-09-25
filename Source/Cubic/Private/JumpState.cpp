// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpState.h"
#include "SphereCharacter.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

void UJumpState::Begin()
{
	SoarTimer = PlayerCharacter->SoarUsedDuration;
	SoarDuration = PlayerCharacter->SoarMaxDuration;
	PlayerCharacter->AudioComponent->SetSound(PlayerCharacter->SoarSoundEffect);
	PlayerCharacter->AudioComponent->Play();
}

void UJumpState::End()
{
	if (CooldownRequired)
	{
		PlayerCharacter->SoarCooldown = true;
		PlayerCharacter->SoarUsedDuration = 0.0f;
	}
	else
	{
		PlayerCharacter->SoarUsedDuration = SoarTimer;
	}
	PlayerCharacter->AudioComponent->Stop();
}

void UJumpState::Update()
{
	SoarTimer += GetWorld()->DeltaTimeSeconds;
	if ((PlayerCharacter->Controller != nullptr))
	{

		// add movement in that direction
		PlayerCharacter->Sphere->AddImpulse(PlayerCharacter->GetActorUpVector() * 30, FName("Name_None"), true);
		UGameplayStatics::SpawnEmitterAttached(PlayerCharacter->SoarEffect, PlayerCharacter->Sphere);

		
	}
	if (SoarTimer > SoarDuration)
	{
		CooldownRequired = true;
		PlayerCharacter->StateMachine->IdleStateTransition();
	}
}
