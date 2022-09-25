// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovementState.h"
#include "MyState.h"
#include "JumpState.generated.h"

/**
 * 
 */
UCLASS()
class CUBIC_API UJumpState : public UPState
{
	GENERATED_BODY()
	
public:

	float SoarDuration = 6.0f;
	float SoarTimer = 0.0f;
	bool CooldownRequired = false;

	// Inherited via UPState
	virtual void Begin() override;

	virtual void End() override;


	// Inherited via UPState
	virtual void Update() override;

};
