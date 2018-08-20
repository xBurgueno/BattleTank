// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "Components/SceneComponent.h"
#include "TankMovementComponent.generated.h"

//Forward Declaration
class UTankTracks;

/**
 * Responsible for driving the Tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_SUB_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void InitializeComponent(UTankTracks * LeftTrackToSet, UTankTracks* RightTrackToSet);
	
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);

	//TODO Check best protection
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	UTankTracks * LeftTrack = nullptr;
	UTankTracks * RightTrack = nullptr;
};
