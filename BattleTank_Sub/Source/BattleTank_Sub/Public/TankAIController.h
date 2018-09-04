// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"
#include "AIController.h"
#include "TankAIController.generated.h"
 
UCLASS()
class BATTLETANK_SUB_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime)  override;

	//How close can the AI get to tp

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Setup") //consider EditDefaultsOnly
	float AcceptanceRadius = 12000.0f;

};
