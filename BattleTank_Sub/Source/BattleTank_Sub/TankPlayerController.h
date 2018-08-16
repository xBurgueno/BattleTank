// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//forward decelerations 
class ATank;

UCLASS()
class BATTLETANK_SUB_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank * GetControlledTank() const;
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HiLocation) const;

	virtual void BeginPlay() override; //Overide Checks if that the method exist in the heirachy
	
	virtual void Tick(float DeltaTime)  override;

	void AimTowardsCrossHair();

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.0f; //10 km in meters 
};

