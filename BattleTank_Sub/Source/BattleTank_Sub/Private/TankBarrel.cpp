// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"




void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame

	//Given a max elevation speed, and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	//SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
	SetRelativeRotation(FRotator(Elevation, 0, 0));
	//FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

}
