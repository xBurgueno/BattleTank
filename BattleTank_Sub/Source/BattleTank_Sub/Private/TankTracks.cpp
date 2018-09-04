// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




UTankTracks::UTankTracks()
{
	PrimaryComponentTick.bCanEverTick = false;
	
	
}


void UTankTracks::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}


void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OhterActor, UPrimitiveComponent* OtherComponents, FVector NormalImpulses, const FHitResult& Hit)
{
	//don't use a boolean flag! 
	DriveTrack();
	ApplySidewaysForce();

	//Reset throttle
	CurrentThrottle = 0;

}

void UTankTracks::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

	//Workout the required acceleration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//Calculate and apply sideways force ( F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTracks::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);

}

void UTankTracks::DriveTrack()
{
	//TODO clamp actual throttle value so player can't overdrive

	auto ForceApplied = GetForwardVector() * CurrentThrottle *TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}