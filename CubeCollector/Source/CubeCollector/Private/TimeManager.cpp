// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"
#include "..\Public\TimeManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTimeManager::UTimeManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called every frame
void UTimeManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	TimeCountDown -= DeltaTime;
	if (TimeCountDown <= 0)
	{
		UGameplayStatics::OpenLevel(this, FName("DefeatScreen"));
	}
	// ...
}

void UTimeManager::ModifyTimeCountDown(float ModificationTime)
{
	TimeCountDown += ModificationTime;
}

float UTimeManager::GetTimeCountDown() const
{
	return TimeCountDown;
}

