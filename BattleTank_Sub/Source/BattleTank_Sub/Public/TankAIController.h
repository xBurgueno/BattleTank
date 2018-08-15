// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_SUB_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	ATank * GetAIControlledTank() const;
	
	virtual void BeginPlay() override;

	ATank* GetPlayerTank() const;

	virtual void Tick(float DeltaTime)  override;

	
};
