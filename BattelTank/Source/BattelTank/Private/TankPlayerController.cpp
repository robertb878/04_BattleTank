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

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetTank()) { return; }

	FVector HitLocation; // Out Parameter

	if (GetSightRayHitLocation(HitLocation)) {

	}
}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

// Get the world location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	FHitResult hitResult;
	HitLocation = FVector(1.0f);

	//FVector StartLocation = 

	return true;
}

