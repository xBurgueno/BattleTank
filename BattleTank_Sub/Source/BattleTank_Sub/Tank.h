// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Declaration
class UTankBarrel; 
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
class UTankMovementComponent;


UCLASS()
class BATTLETANK_SUB_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	

protected:
	
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();
	
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 5000.0f; 

	UPROPERTY(EditDefaultsOnly, Category = Firing) //Can only be edited in blueprints
	float ReloadTimeInSeconds = 3.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	//Local Reference is spawning projectile
	UTankBarrel * Barrel = nullptr;
	
	
	double LastFireTime = 0.0;
};
