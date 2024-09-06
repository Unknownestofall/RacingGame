// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseClass.h"
#include "PlayerVehicle.generated.h"

/**
 * 
 */
UCLASS()
class RACER_API APlayerVehicle : public ABaseClass
{
	GENERATED_BODY()
public:
	APlayerVehicle();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(EditAnywhere) class USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere) class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere) float speed;
	UPROPERTY(EditAnywhere) float TurnRate;

	void Drive(float val);
	void TurnCar(float TurnVal);

	float ReturnDelta();
protected:
};
