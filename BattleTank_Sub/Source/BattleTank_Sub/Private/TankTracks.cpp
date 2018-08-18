// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




void UTankTracks::SetThrottle(float Throttle)
{
	
	auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle Speed: %f"), *name , Throttle);

	//TODO clamp actual throttle value so player can't overdrive

	auto ForceApplied = GetForwardVector() * Throttle *TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
