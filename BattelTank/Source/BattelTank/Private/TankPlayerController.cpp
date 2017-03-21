// Fill out your copyright notice in the Description page of Project Settings.

#include "BattelTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto tank = GetTank();
	if (tank) {
		UE_LOG(LogTemp, Warning, TEXT("%s Got tank"), *tank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Player Controller Not Found"));
	}

}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

