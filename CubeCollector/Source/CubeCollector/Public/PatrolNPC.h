// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolNPC.generated.h"

class UTimeManager;

UCLASS()
class CUBECOLLECTOR_API APatrolNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APatrolNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetCharacter(AActor* Player);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void TakeHealth(int32 HealthToTake);

	UFUNCTION(BlueprintPure, Category = "UI")
	float GetHealthPercent() const;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& hit);

	float GetDistanceToPlayer();

	void DestroyCharacter();

	UTimeManager* TimeManager = nullptr;

	AActor* PlayerReference = nullptr;

	float DestroyDelay = 1.3f;

	int32 LifeLeft = 0;

	bool bActivateDeath = false;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int32 StartingLife = 3; // Asigned on begin play.

};
