// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTELTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	virtual void BeginPlay() override;

private:

	// Move the barrel toward the crosshair
	void AimTowardsCrosshair();
	ATank* GetTank() const;
	bool GetSightRayHitLocation(FVector & ) const;
};
