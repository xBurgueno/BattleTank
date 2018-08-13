// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play!"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PLayerController possesing: %s"), *ControlledTank->GetName())
	}
}

void ATankPlayerController::Tick(float  DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrossHair();
	
}
	


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //OUT Parameter
	if (GetSightRayHitLocation(HitLocation)) //has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Error, TEXT("HitLocation: %s"), *HitLocation.ToString());

		//TODO tell controlled tank to aim this point
		

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return true;


}
