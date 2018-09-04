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
class AProjectile;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_SUB_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initializer(UTankBarrel* BarreltoSet, UTankTurret* TUrretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	EFiringState GetFiringState() const;
	
protected:

	//Enum Fire Status
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FireState = EFiringState::Reloading;
	
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	//********************************
	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing") //Can only be edited in blueprints
	float ReloadTimeInSeconds = 3.0f;

	double LastFireTime = 0.0;

	FVector AimDirection;

	//**********************************************************
	void MoveBarrelTowards(FVector AimDirection);

	// Sets default values for this component's properties
	UTankAimingComponent();

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000.0f;
	//void MoveTurretTowards(FVector RotationDirection);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction *ThisTickFunction) override;
	
	bool IsBarrelMoving();

	virtual void BeginPlay() override;
};
