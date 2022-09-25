// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PState.h"
#include "DiveState.generated.h"

/**
 * 
 */
UCLASS()
class CUBIC_API UDiveState : public UPState
{
	GENERATED_BODY()
	


public:

	// Inherited via UPState
	virtual void Begin() override;

	virtual void End() override;


	// Inherited via UPState
	virtual void Update() override;
};
