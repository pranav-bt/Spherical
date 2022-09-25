// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PState.h"
#include "DashState.generated.h"

/**
 * 
 */
UCLASS()
class CUBIC_API UTwirlState : public UPState
{
	GENERATED_BODY()
	


public:


	// Inherited via UPState
	virtual void Begin() override;

	virtual void End() override;


	// Inherited via UPState
	virtual void Update() override;

	float TwirlDuration = 6.0f;
	float TwirlTimer = 0.0f;
	bool CooldownRequired = false;


};
