// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//forward decelerations 
class UTankAimingComponent;

/**
 * Responsible for helping the player aim?
 */

UCLASS()
class BATTLETANK_SUB_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent * AimingCompRef);

	UFUNCTION()
	void OnPossesedTankDeath();

private:

	
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HiLocation) const;

	void SetPawn(APawn* InPawn);
	
	virtual void BeginPlay() override; //Override Checks if that the method exist in the heirachy
	
	virtual void Tick(float DeltaTime)  override;

	void AimTowardsCrossHair();

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0f; //10 km in meters 
};

