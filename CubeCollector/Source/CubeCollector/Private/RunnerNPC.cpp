// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerNPC.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARunnerNPC::ARunnerNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
}

// Called when the game starts or when spawned
void ARunnerNPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARunnerNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCollisionActivated)
	{
		
	}
}

// Called to bind functionality to input
void ARunnerNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ARunnerNPC::SetCollisionActivated(bool bCollisionToSet)
{
	bCollisionActivated = bCollisionToSet;
}

