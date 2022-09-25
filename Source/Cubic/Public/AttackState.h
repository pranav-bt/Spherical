// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterState.h"
#include "AttackState.generated.h"

/**
 * 
 */
UCLASS()
class CUBIC_API UAttackState : public UPState
{
	GENERATED_BODY()
	

// Inherited via UCharacterState
	virtual void Begin() override;

	virtual void End() override;


	// Inherited via UPState
	virtual void Update() override;

};
