// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
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
		//UE_LOG(LogTemp, Error, TEXT("Hit Location: %s"), *HitLocation.ToString());

		GetControlledTank()->AimAt(HitLocation);
		

	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	
	// Find the crosshair in pixle coordinates
	int32 ViewPortSizeX, ViewPortSizeY;

	GetViewportSize(ViewPortSizeX, ViewPortSizeY); //Out Paramaters
	auto ScreenLocation = FVector2D((ViewPortSizeX * CrosshairXLocation),
		(ViewPortSizeY * CrosshairYLocation));


	//"De-Projection" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line-trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);

	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // For discarding
	
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation, 
		LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
	)
	{
		HitLocation = HitResult.Location;
		return true;		
	}
	
	HitLocation = FVector(0);
		return false; //Line Trace didnt hit anything
}