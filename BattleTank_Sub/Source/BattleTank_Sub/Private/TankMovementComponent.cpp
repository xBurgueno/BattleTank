// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTracks.h"



void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!ensure (LeftTrack || !RightTrack) ) { return; }
	LeftTrack->SetThrottle(Throw); //I set these in the Tank_BP and have pointers of them in Hfile
	RightTrack->SetThrottle(Throw); // The SetThrottle lives in TankTacks.h and I can use it here bc *

	//TODO prevent double speed using both throttles
}

void UTankMovementComponent::InitializeComponent(UTankTracks * LeftTrackToSet, UTankTracks* RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure (LeftTrack || !RightTrack) ) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No need to call super, we are changing the functionality
	
	//They are in world Space, TF & AFI
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal(); //Forward Vector is X-Axis
	auto AiForwardIntention = MoveVelocity.GetSafeNormal(); //Unit Vector in direction AiWould like to go

	auto ForwardThrow = FVector::DotProduct(TankForward, AiForwardIntention);
	IntendMoveForward(ForwardThrow);


	auto RightThrow = FVector::CrossProduct(TankForward, AiForwardIntention).Z;
	IntendTurnRight(RightThrow);
	// UE_LOG(LogTemp, Error, TEXT("Tank Name: %s Vectoring to : %s"), *TankName, *MoveVelocityString);

}
