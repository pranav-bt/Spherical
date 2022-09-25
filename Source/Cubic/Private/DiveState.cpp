// Fill out your copyright notice in the Description page of Project Settings.


#include "DiveState.h"
#include "SphereCharacter.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

void UDiveState::Begin()
{
	PlayerCharacter->Sphere->AddImpulse(-PlayerCharacter->GetActorUpVector() * 5000, FName("Name_None"), true);
	UGameplayStatics::SpawnEmitterAttached(PlayerCharacter->DiveEffect, PlayerCharacter->Sphere);
	PlayerCharacter->AudioComponent->SetSound(PlayerCharacter->DiveSoundEffect);
	PlayerCharacter->AudioComponent->Play();
}

void UDiveState::End()
{
	PlayerCharacter->DiveCooldown = true;
	PlayerCharacter->AudioComponent->Stop();
}

void UDiveState::Update()
{
	
}
