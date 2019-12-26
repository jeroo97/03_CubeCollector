// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PatrolAIController.generated.h"

/**
 * 
 */
UCLASS()
class CUBECOLLECTOR_API APatrolAIController : public AAIController
{
	GENERATED_BODY()

public:
	APatrolAIController();

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};
