// Fill out your copyright notice in the Description page of Project Settings.


#include "DashState.h"
#include "SphereCharacter.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Collectible.h"
#include "EngineUtils.h"
#include "Kismet/KismetMathLibrary.h"

void UTwirlState::Begin()
{
	TwirlDuration = PlayerCharacter->TwirlMaxDuration;
	TwirlTimer = PlayerCharacter->TwirlUsedDuration;
	PlayerCharacter->AudioComponent->SetSound(PlayerCharacter->TwirlSoundEffect);
	PlayerCharacter->AudioComponent->Play();

	for (TActorIterator<ACollectible> CrystalItr(GetWorld()); CrystalItr; ++CrystalItr)
	{
		FVector Player = PlayerCharacter->GetActorLocation();
		FVector Crystal = CrystalItr->GetActorLocation();
		float dist = FMath::Sqrt(Player.X * Crystal.X + Player.Y * Crystal.Y + Player.Z * Crystal.Z);
		if (dist < PlayerCharacter->CollectionRange)
			CrystalItr->Destroy();
	}
}

void UTwirlState::End()
{
	if (CooldownRequired)
	{
		PlayerCharacter->TwirlCooldown = true;
		PlayerCharacter->TwirlUsedDuration = 0.0f;
	}
	else
	{
		PlayerCharacter->TwirlUsedDuration = TwirlTimer;
	}
	PlayerCharacter->AudioComponent->Stop();
}

void UTwirlState::Update()
{
	TwirlTimer += GetWorld()->DeltaTimeSeconds;
	
	PlayerCharacter->Sphere->AddTorqueInRadians(FVector(0.0f, 0.0f,  80000.0f), FName("Name_None"), true);
	UGameplayStatics::SpawnEmitterAttached(PlayerCharacter->TwirlEffect, PlayerCharacter->Sphere);
	
	
	

	if (TwirlTimer >= TwirlDuration)
	{
		CooldownRequired = true;
		PlayerCharacter->StateMachine->IdleStateTransition();
	}

}
