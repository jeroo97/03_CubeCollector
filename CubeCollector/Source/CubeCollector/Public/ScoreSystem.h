// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreSystem.generated.h"

class UBoxComponent;
class ACubesToCollect;
class ASecurePoints;
class UTimeManager;

UCLASS()
class CUBECOLLECTOR_API AScoreSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray <int32> GetSpecificCubeCount();

	void CubeCollected(ACubesToCollect* Cube);

	void CubeSecured(ASecurePoints* SecuredCube);

	UFUNCTION(BlueprintCallable, Category = "UI")
	TArray <int32> GetSecuredCubes() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	TArray <int32> GetCollectedCubes() const;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Setup")
	UBoxComponent* BoxComponent = nullptr;

	void SetCubesCount(ACubesToCollect* CubeToAdd);

private:

	void SpawnTheCubes();

	UPROPERTY(EditAnywhere, Category = "Spawn")
	int32 HowManyCubsToSpawn = 30;

	int32 BlueCubes = 0;
	int32 GreenCubes = 0;
	int32 YellowCubes = 0;

	int32 BlueCubesSecured = 0;
	int32 YellowCubesSecured = 0;
	int32 GreenCubesSecured = 0;

	TArray <int32> CubesCount;

	bool bOnce = true;

	FVector MinExt, MaxExt, BoxPosition;
	FBox* CreationBox;

	UTimeManager* TimeManager = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<ACubesToCollect> CubeBlueprint;

};
