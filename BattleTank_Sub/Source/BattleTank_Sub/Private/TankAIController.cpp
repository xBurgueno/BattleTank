// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"


ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("AiController in  Begin Play!"));

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller cant find player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller Found playertank: %s"), *PlayerTank->GetName())
	}

}

///AI Finding Players tank
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//TODO Move Towards Player

		//Aim Towards player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if Ready
	}
}


