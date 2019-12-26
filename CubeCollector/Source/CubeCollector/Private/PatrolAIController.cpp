// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolAIController.h"
#include "..\Public\PatrolAIController.h"

APatrolAIController::APatrolAIController() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

void APatrolAIController::BeginPlay()
{
	Super::BeginPlay();

}

void APatrolAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
