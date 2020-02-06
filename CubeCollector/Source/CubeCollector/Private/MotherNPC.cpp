// Fill out your copyright notice in the Description page of Project Settings.


#include "MotherNPC.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMotherNPC::AMotherNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
}

// Called when the game starts or when spawned
void AMotherNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMotherNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMotherNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

