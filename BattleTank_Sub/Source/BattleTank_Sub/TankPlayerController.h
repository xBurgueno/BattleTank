// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_SUB_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank * GetControlledTank() const;
	
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
public:
	
	virtual void BeginPlay() override; //Overide Checks if that the method exist in the heirachy
	
	virtual void Tick(float DeltaTime)  override;

	//Start tank moving the barrel so the that shot would hit
	//wjere the 

	void AimTowardsCrossHair();

	 //return OutHitLocation as parameter
};

