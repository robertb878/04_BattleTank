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

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetTank()) { return; }

	FVector HitLocation; // Out Parameter

	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look direction : %s "), *HitLocation.ToString());
	}
}

ATank* ATankPlayerController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{

}

// Get the world location of linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	HitLocation = FVector(1.0f);
	// Find the pixel position of the crosshair
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector WorldLocation, WorldDirection;
	FHitResult HitResult;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection)) {
		GetLookVectorHitLocation(HitResult, GetPawn()->)
			//UE_LOG(LogTemp, Warning, TEXT("Look direction : %s "), *WorldDirection.ToString());
	}

	return true;
}

