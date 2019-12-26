// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TimeManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUBECOLLECTOR_API UTimeManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimeManager();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ModifyTimeCountDown(float ModificationTime);

	UFUNCTION(BlueprintCallable, Category = "UI")
	float GetTimeCountDown() const;

private:

	float TimeCountDown = 60.f;
		
};
