// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseClass.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABaseClass::ABaseClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CarCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CarCollider;

	CarBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Car Body"));
	CarBody->SetupAttachment(CarCollider);

	CarWheels = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Car Wheels"));
	CarWheels->SetupAttachment(CarBody);

	CarDoors = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Car Doors"));
	CarDoors->SetupAttachment(CarBody);

	CarWindshield = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Windshield"));
	CarWindshield->SetupAttachment(CarBody);
}

// Called when the game starts or when spawned
void ABaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

