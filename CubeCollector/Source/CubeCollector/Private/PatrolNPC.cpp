// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolNPC.h"

// Sets default values
APatrolNPC::APatrolNPC()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Mesh Component"));
}

// Called when the game starts or when spawned
void APatrolNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrolNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APatrolNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
