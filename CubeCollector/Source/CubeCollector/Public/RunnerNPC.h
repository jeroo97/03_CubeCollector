// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotherNPC.h"
#include "RunnerNPC.generated.h"

/**
 * 
 */
UCLASS()
class CUBECOLLECTOR_API ARunnerNPC : public AMotherNPC
{
	GENERATED_BODY()
	

private:

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& hit);
};
