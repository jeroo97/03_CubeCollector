// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubesToCollect.generated.h"

class AScoreSystem;
class UTimeManager;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCubeDelegate);

UCLASS()
class CUBECOLLECTOR_API ACubesToCollect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubesToCollect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UPROPERTY(EditAnywhere, Category = "Setup")
	AScoreSystem* ScoreSystem;
	int32 CubeType;

	int32 GetCubeType();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetParent(AScoreSystem* CubeParent);

private:

	UFUNCTION()
	void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category = "Setup")
	UStaticMeshComponent* CubeMesh = nullptr;

	void SetCubes();

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* BlueMaterial;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* YellowMaterial;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* GreenMaterial;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 MaxSpecificCubes = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* CollectSound = nullptr;
};
