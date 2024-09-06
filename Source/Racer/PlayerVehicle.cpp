// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerVehicle.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Called every frame
APlayerVehicle::APlayerVehicle() {
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArm);

}
void APlayerVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerVehicle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("drive"), this, &APlayerVehicle::Drive);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerVehicle::TurnCar);
}
void APlayerVehicle::Drive(float val) {
	FVector Location = FVector::ZeroVector;
	Location.X = val * speed * ReturnDelta();
	AddActorLocalOffset(Location, true);
}
void APlayerVehicle::TurnCar(float turnVal) {
	FRotator CarRotation = FRotator::ZeroRotator;
	CarRotation.Yaw = turnVal * TurnRate * ReturnDelta();
	AddActorLocalRotation(CarRotation, true);
}
float APlayerVehicle::ReturnDelta() {
	return UGameplayStatics::GetWorldDeltaSeconds(this);
}
