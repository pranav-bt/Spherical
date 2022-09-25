// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PState.generated.h"

/**
 * 
 */
UCLASS()
class CUBIC_API UPState : public UObject
{
	GENERATED_BODY()
	

public:
	UPState();
	UPState(class UPlayerStateMachine* SM);

	class ASphereCharacter* PlayerCharacter;

	virtual void Begin() ;
	virtual void Update() ;
	virtual void End() ;


};
