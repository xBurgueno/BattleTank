// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"




void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();


	if (!ensure(PlayerTank) && !ensure(ControlledTank)) { return; }
	
	//TODO Move Towards Player
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim Towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(AimingComponent)) { return; } //protect aim and fire
	
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
	//Fire if Ready
	AimingComponent->Fire(); //TODO dot fire every frame
	
}


