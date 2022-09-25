// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyState.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyState : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CUBIC_API IMyState
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Begin() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;
};
