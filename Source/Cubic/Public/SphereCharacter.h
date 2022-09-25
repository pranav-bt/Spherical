// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerStateMachine.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "SphereCharacter.generated.h"

UCLASS()
class CUBIC_API ASphereCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASphereCharacter();

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
		UParticleSystem* TwirlEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
		UParticleSystem* SoarEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
		UParticleSystem* DiveEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFX")
		USoundCue* TwirlSoundEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFX")
		USoundCue* SoarSoundEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SFX")
		USoundCue* DiveSoundEffect;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// State Machine
	UPlayerStateMachine* StateMachine;


	// Audio Component
	UAudioComponent* AudioComponent;


	// Input Functions

	//Move Forward
	void ForwardAxis(float value);
	float ForwardAxisValue = 0.0f;

	//Move Right
	void RightAxis(float value);
	float RightAxisValue = 0.0f;

	//Soar Ability
	void Soar();
	void SoarRelease();
	float SoarMaxDuration = 2.0f;
	float SoarUsedDuration = 0.0f;
	bool SoarCooldown = false;
	float SoarCooldownDuration = 10.0f;
	float SoarCooldownTimer = 0.0f;
	bool SoarInput = false;

	//Dive Ability
	void Dive();
	void DiveRelease();
	float DiveCooldownDuration = 5.0f;
	float DiveCooldownTimer = 0.0f;
	bool DiveCooldown = false;
	bool DiveInput = false;

	// Slash Ability
	void Twirl();
	void TwirlRelease();
	float TwirlMaxDuration = 5.0f;
	float TwirlUsedDuration = 0.0f;
	bool TwirlCooldown = false;
	float TwirlCooldownDuration = 8.0f;
	float TwirlCooldownTimer = 0.0f;
	bool TwirlInput = false;
	float CollectionRange = 2000.0f;


	// Input Delegates

	FMovement FForwardDelegate;

	// 
	void RestartGame();

	void EndGame();

};
