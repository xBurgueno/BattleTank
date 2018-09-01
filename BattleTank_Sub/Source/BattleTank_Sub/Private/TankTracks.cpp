// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"




UTankTracks::UTankTracks()
{
	PrimaryComponentTick.bCanEverTick = true;
	
	
}


void UTankTracks::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}


void UTankTracks::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	//Super::TickComponent();

	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());
	
	//Workout the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	
	//Calculate and apply sideways force ( F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>( GetOwner()->GetRootComponent() );

	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);

}

void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OhterActor, UPrimitiveComponent* OtherComponents, FVector NormalImpulses, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Error, TEXT("This is A test!"));

}

void UTankTracks::SetThrottle(float Throttle)
{
	//TODO clamp actual throttle value so player can't overdrive

	auto ForceApplied = GetForwardVector() * Throttle *TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}