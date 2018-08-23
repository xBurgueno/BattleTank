// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankTracks.h"
#include "TankBarrel.h"
#include "BattleTank_Sub.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;	

	
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if ( isReloaded)
	{
		//Spawn Projectile at socket location in barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))

			);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}


void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent) ) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	UE_LOG(LogTemp, Error, TEXT("I;m Being Called here"));
}