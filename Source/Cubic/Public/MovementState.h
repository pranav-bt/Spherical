// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "MovementState.generated.h"

/**
 * 
 */
UCLASS()
class CUBIC_API UMovementState : public UPState
{
	GENERATED_BODY()
	


public:

	UMovementState();

	// Inherited via UPState
	virtual void Begin() override;

	virtual void End() override;


	// Inherited via UPState
	virtual void Update() override;

};
