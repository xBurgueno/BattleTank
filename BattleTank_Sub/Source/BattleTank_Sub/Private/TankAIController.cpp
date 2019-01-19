// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "TankAimingComponent.h"




void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATank>(InPawn);
		if (!ensure(PossesedTank)) { return; }

		//subscribe local method to the tanks death event
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedTankDeath);
	}
}

void ATankAIController::OnPossesedTankDeath()
{
	//UE_LOG(LogTemp, Warning, TEXT("Received"));
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy(); 

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	auto ControlledTank = GetPawn();

	//if (!ensure(PlayerState && GetPawn())) { return; }


	if (!ensure(PlayerTank) && !ensure(ControlledTank)) { return; }
	
	//TODO Move Towards Player

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerTank && GetPawn())) { return; }

	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim Towards player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(AimingComponent)) { return; } //protect aim and fire
	
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
		
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire(); //TODO limit fire rate
	}
}


