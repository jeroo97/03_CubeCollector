// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreSystem.h"
#include "..\Public\ScoreSystem.h"
#include "Components/BoxComponent.h"
#include "CubesToCollect.h"
#include "Containers/Array.h"
#include "SecurePoints.h"
#include "Components/SceneComponent.h"
#include "Math/Box.h"
#include "Kismet/GameplayStatics.h"
#include "TimeManager.h"

// Sets default values
AScoreSystem::AScoreSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(FName("StaticMeshComponent"));


}

// Called when the game starts or when spawned
void AScoreSystem::BeginPlay()
{
	Super::BeginPlay();	 

	TimeManager = Cast<UTimeManager>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<UTimeManager>());

	MinExt = BoxComponent->GetUnscaledBoxExtent();
	MaxExt = BoxComponent->GetUnscaledBoxExtent() * -1;
	CreationBox = new FBox(MinExt, MaxExt);
	// TODO Spawn the cubes!
}

// Called every frame
void AScoreSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bOnce)
	{
		SpawnTheCubes();
		bOnce = false;
	}
}

TArray <int32> AScoreSystem::GetSpecificCubeCount()
{
	TArray <int32> CubeTypeCount;
	CubeTypeCount.Init(0, 3);

	for (int i : CubesCount)
	{
		if (i == 1)
			CubeTypeCount[0]++;
		else if (i == 2)
			CubeTypeCount[1]++;
		else if (i == 3)
			CubeTypeCount[2]++;
	}

	return CubeTypeCount;
}

void AScoreSystem::CubeCollected(ACubesToCollect * Cube)
{
	int32 CubeType = Cube->GetCubeType();
	switch (CubeType)
	{
	case 1:
		BlueCubes++;
		break;
	case 2:
		YellowCubes++;
		break;
	case 3:
		GreenCubes++;
		break;
	}
}

void AScoreSystem::CubeSecured(ASecurePoints * SecuredCube)
{
	if (SecuredCube->SecurePointType == ESecurePointType::Blue)
	{
		UE_LOG(LogTemp, Warning, TEXT("Blue"));
		BlueCubesSecured += BlueCubes;
		TimeManager->ModifyTimeCountDown(10.f * BlueCubes);
		BlueCubes = 0;
	}
	if (SecuredCube->SecurePointType == ESecurePointType::Yellow)
	{
		UE_LOG(LogTemp, Warning, TEXT("Yellow"));
		YellowCubesSecured += YellowCubes;
		TimeManager->ModifyTimeCountDown(10.f * YellowCubes);
		YellowCubes = 0;
	}
	if (SecuredCube->SecurePointType == ESecurePointType::Green)
	{
		UE_LOG(LogTemp, Warning, TEXT("Green"));
		GreenCubesSecured += GreenCubes;
		TimeManager->ModifyTimeCountDown(10.f * GreenCubes);
		GreenCubes = 0;
	}
	if (BlueCubesSecured + YellowCubesSecured + GreenCubesSecured >= 30)
	{
		UGameplayStatics::OpenLevel(this, FName("WinScreen"));
	}
}

TArray<int32> AScoreSystem::GetSecuredCubes() const
{
	TArray <int32> CubeArray;
	CubeArray = TArray <int32>{ BlueCubesSecured, YellowCubesSecured, GreenCubesSecured };
	return CubeArray;
}

TArray<int32> AScoreSystem::GetCollectedCubes() const
{
	TArray <int32> CubeArray;
	CubeArray = TArray <int32>{ BlueCubes, YellowCubes, GreenCubes };
	return CubeArray;
}

void AScoreSystem::SetCubesCount(ACubesToCollect* CubeToAdd)
{
	CubesCount.Add(CubeToAdd->CubeType);
}

void AScoreSystem::SpawnTheCubes()
{
	for (int32 i = 0; i < HowManyCubsToSpawn; i++)
	{
		BoxPosition = FMath::RandPointInBox(*CreationBox);
		FActorSpawnParameters SpawnParamet;
		SpawnParamet.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		auto CubeSon = GetWorld()->SpawnActor<AActor>(CubeBlueprint, BoxPosition, this->GetActorRotation(), SpawnParamet);
	}
}