// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereCharacter.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASphereCharacter::ASphereCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StateMachine = CreateDefaultSubobject<UPlayerStateMachine>(TEXT("PlayerStateMachine"));
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	
	Sphere->SetupAttachment(RootComponent);
	StateMachine->SphereCharacter = this;
}

// Called when the game starts or when spawned
void ASphereCharacter::BeginPlay()
{
	Super::BeginPlay();
	AudioComponent = NewObject<UAudioComponent>(this);
}

// Called every frame
void ASphereCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Manage Cooldowns for all abilities

	if (SoarCooldown)
	{
		SoarCooldownTimer += GetWorld()->DeltaTimeSeconds;
		if (SoarCooldownTimer >= SoarCooldownDuration)
		{
			SoarCooldown = false;
			SoarCooldownTimer = 0.0f;
		}
	}

	if (DiveCooldown)
	{
		DiveCooldownTimer += GetWorld()->DeltaTimeSeconds;
		if (DiveCooldownTimer >= DiveCooldownDuration)
		{
			DiveCooldown = false;
			DiveCooldownTimer = 0.0f;
		}
	}

	if (TwirlCooldown)
	{
		TwirlCooldownTimer += GetWorld()->DeltaTimeSeconds;
		if (TwirlCooldownTimer >= TwirlCooldownDuration)
		{
			TwirlCooldown = false;
			TwirlCooldownTimer = 0.0f;
		}
	}
}

// Called to bind functionality to input
void ASphereCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Restart", IE_Pressed,this,&ASphereCharacter::RestartGame);
	PlayerInputComponent->BindAction("Quit", IE_Pressed,this,&ASphereCharacter::EndGame);
	PlayerInputComponent->BindAction("Soar", IE_Pressed,this,&ASphereCharacter::Soar);
	PlayerInputComponent->BindAction("Dive", IE_Pressed,this,&ASphereCharacter::Dive);
	PlayerInputComponent->BindAction("Slash", IE_Pressed,this,&ASphereCharacter::Twirl);
	PlayerInputComponent->BindAction("Soar", IE_Released, this, &ASphereCharacter::SoarRelease);
	PlayerInputComponent->BindAction("Dive", IE_Released, this, &ASphereCharacter::DiveRelease);
	PlayerInputComponent->BindAction("Slash", IE_Released, this, &ASphereCharacter::TwirlRelease);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASphereCharacter::ForwardAxis);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereCharacter::RightAxis);
}

void ASphereCharacter::ForwardAxis(float value)
{
	ForwardAxisValue = value;

	if(value!=0)
		StateMachine->MovementStateTransition(value);
}

void ASphereCharacter::RightAxis(float value)
{
	RightAxisValue = value;

	if (value != 0)
		StateMachine->MovementStateTransition(value);
}

void ASphereCharacter::Soar()
{
	if (!SoarCooldown)
	{
		SoarInput = true;
		StateMachine->JumpStateTransition();
	}
}

void ASphereCharacter::SoarRelease()
{
	SoarInput = false;
	StateMachine->IdleStateTransition();
}

void ASphereCharacter::Dive()
{
	if (!DiveCooldown)
	{
		DiveInput = true;
		StateMachine->DiveTransitionState();
	}
}

void ASphereCharacter::DiveRelease()
{
	DiveInput = false;
	StateMachine->IdleStateTransition();
}

void ASphereCharacter::Twirl()
{
	TwirlInput = true;
	StateMachine->SlashTransitionState();
}

void ASphereCharacter::TwirlRelease()
{
	TwirlInput = false;
	StateMachine->IdleStateTransition();
}

void ASphereCharacter::RestartGame()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

void ASphereCharacter::EndGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit,true);
}

