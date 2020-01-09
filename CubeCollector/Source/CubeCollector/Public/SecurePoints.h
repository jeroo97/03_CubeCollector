// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SecurePoints.generated.h"

UENUM()
enum class ESecurePointType : uint8
{
	Blue,
	Yellow,
	Green
};

class AScoreSystem;

UCLASS()
class CUBECOLLECTOR_API ASecurePoints : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASecurePoints();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AScoreSystem* ScoreSystem;

	UPROPERTY(EditAnywhere, Category = "Setup")
	ESecurePointType SecurePointType;

private:
	
	UFUNCTION()
	void OnActorBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	void SetSecurePointMaterial(ESecurePointType PointType);

	UPROPERTY(EditAnywhere, Category = "Setup")
	UStaticMeshComponent* MeshComponent = nullptr;

	// <Particle systems>
	UPROPERTY(EditAnywhere, Category = "Setup")
	UParticleSystem* BlueParticleSystem = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UParticleSystem* YellowParticleSystem = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UParticleSystem* GreenParticleSystem = nullptr;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UParticleSystemComponent* ParticleSystem = nullptr;
	// </Particle systems>

	// <Materials>
	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* BlueMaterial;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* YellowMaterial;

	UPROPERTY(EditAnywhere, Category = "Setup")
	UMaterialInterface* GreenMaterial;
	// </Materials>

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundBase* SecuredSound = nullptr;
};
