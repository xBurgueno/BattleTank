// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());


	if (PlayerTank) 
	{
		//TODO Move Towards Player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim Towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		//Fire if Ready
		ControlledTank->Fire(); //TODO dot fire every frame

	}
}


