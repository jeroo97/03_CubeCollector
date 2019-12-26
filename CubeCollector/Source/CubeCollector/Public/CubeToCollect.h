// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScoreSystem.h"
#include "CubeToCollect.generated.h"

/**
 * 
 */
UCLASS()
class CUBECOLLECTOR_API ACubeToCollect : public AScoreSystem
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACubeToCollect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UFUNCTION()
	void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Setup")
	UStaticMeshComponent* CubeMesh = nullptr;

	void SetCubes(int32 CubeType);
 };
