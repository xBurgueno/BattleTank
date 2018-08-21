// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


//Enum for Aiming State
UENUM()
enum class EFiringState : uint8
{
	Aiming,
	Reloading,
	Locked
};


//holds barrels properties and elevate method
class UTankBarrel; 
class UTankTurret;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_SUB_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	

	void AimAt(FVector HitLocation, float LauchSpeed);
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FireState = EFiringState::Reloading;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	//void MoveTurretTowards(FVector RotationDirection);

	//Enum Fire Status
	
};
