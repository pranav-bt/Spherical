// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JumpState.h"
#include "AttackState.h"
#include "DiveState.h"
#include "DashState.h"
#include "IdleState.h"
#include "PlayerStateMachine.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FMovement, float);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUBIC_API UPlayerStateMachine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStateMachine();
	//UPlayerStateMachine(ASphereCharacter* ISphereCharacter);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY()
	UPState* CurrentState;

protected:
	

	template <class T>
	void SetState()
	{
		if (CurrentState == NewObject<T>(this))
			return;
		CurrentState->End();
		CurrentState->ConditionalBeginDestroy();
		CurrentState = NewObject<T>(this);
		CurrentState->PlayerCharacter = SphereCharacter;
		CurrentState->Begin();
	}

	//
	


public:
	class ASphereCharacter* SphereCharacter;

	ASphereCharacter* GetPlayerCharacter();

	// Transition Functions

	void MovementStateTransition(float value);

	void IdleStateTransition();

	void JumpStateTransition();

	void DiveTransitionState();

	void SlashTransitionState();
};
