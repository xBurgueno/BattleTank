// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANK_SUB_API ATank : public APawn
{
	GENERATED_BODY()



private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;

	ATank();
	

public:
	//Called by the engine when a actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator, AActor * DamageCauser) override;

	//Return current as a percentage of starting health, between 0 - 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;
};