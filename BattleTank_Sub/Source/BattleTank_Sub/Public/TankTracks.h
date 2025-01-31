// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * Tank Track is used to set maximum driving force, and apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_SUB_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:

	UTankTracks();

	//Sets a throttle between -1 + 1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	void DriveTrack();
	
	//Max Force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.0f; //Assume 40 tonne tank, 1g acceleration

private:
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OhterActor,
		UPrimitiveComponent* OtherComponents, FVector NormalImpulses, const FHitResult& Hit);
	
	void ApplySidewaysForce();

	float CurrentThrottle = 0;

protected:

	virtual void BeginPlay() override;
};
