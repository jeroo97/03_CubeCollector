// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunnerNPC.generated.h"

class USphereComponent;

UCLASS()
class CUBECOLLECTOR_API ARunnerNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunnerNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetCollisionActivated(bool bCollisionToSet);



private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	UStaticMeshComponent* StaticMesh = nullptr;

	bool bCollisionActivated = false;

};
