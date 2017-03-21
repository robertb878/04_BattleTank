// Fill out your copyright notice in the Description page of Project Settings.

#include "BattelTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto aiTank = GetPlayerController();
	if (!aiTank) {
		UE_LOG(LogTemp,Error,TEXT("AI Pawn Not Founs"));
	}
	else {
		UE_LOG(LogTemp,Warning,TEXT("Got playerController %s"),*aiTank->GetName());
	}
}

ATank* ATankAIController::GetAITankController() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerController() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
