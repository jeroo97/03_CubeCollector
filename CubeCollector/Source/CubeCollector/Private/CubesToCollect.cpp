// Fill out your copyright notice in the Description page of Project Settings.


#include "CubesToCollect.h"
#include "Components/StaticMeshComponent.h"
#include "..\Public\CubesToCollect.h"
#include "Math/UnrealMathUtility.h"
#include "ScoreSystem.h"
#include "Kismet/GameplayStatics.h"
#include "TimeManager.h"

// Sets default values
ACubesToCollect::ACubesToCollect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("CubeMesh"));
	SetRootComponent(CubeMesh);
	CubeMesh->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void ACubesToCollect::BeginPlay()
{
	Super::BeginPlay();	

	this->AttachToActor(ScoreSystem, FAttachmentTransformRules::KeepRelativeTransform);

	CubeMesh->OnComponentBeginOverlap.AddDynamic(this, &ACubesToCollect::OnActorBeginOverlap);

	SetCubes();
}

// Called every frame
void ACubesToCollect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// <SimpleConstructors>
int32 ACubesToCollect::GetCubeType()
{
	return CubeType;
}
// </SimpleConstructors>

void ACubesToCollect::SetParent(AScoreSystem * CubeParent)
{
	ScoreSystem = CubeParent;
}

void ACubesToCollect::OnActorBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!ensure(ScoreSystem))
		return;

	if (OtherActor->GetName() == "FirstPersonCharacter_C_0")
	{
		ScoreSystem->CubeCollected(this);

		CubeMesh->DestroyComponent();
	}
}

void ACubesToCollect::SetCubes()
{
	if (ScoreSystem->GetSpecificCubeCount()[0] < MaxSpecificCubes && ScoreSystem->GetSpecificCubeCount()[1] < MaxSpecificCubes && ScoreSystem->GetSpecificCubeCount()[2] < MaxSpecificCubes)
	{
		CubeType = 1;
	}
	if (ScoreSystem->GetSpecificCubeCount()[0] >= MaxSpecificCubes && ScoreSystem->GetSpecificCubeCount()[1] < MaxSpecificCubes && ScoreSystem->GetSpecificCubeCount()[2] < MaxSpecificCubes)
	{
		CubeType = 2;
	}
	if (ScoreSystem->GetSpecificCubeCount()[0] >= MaxSpecificCubes && ScoreSystem->GetSpecificCubeCount()[1] >= MaxSpecificCubes && ScoreSystem->GetSpecificCubeCount()[2] < MaxSpecificCubes)
	{
		CubeType = 3;
	}

	ScoreSystem->SetCubesCount(this);

	switch (CubeType)
	{
	case 1:
		// Cubo color azul
		CubeMesh->SetMaterial(0, BlueMaterial);
		break;
	case 2:
		// Cubo color amarillo
		CubeMesh->SetMaterial(0, YellowMaterial);
		break;
	case 3:
		// Cubo color verde
		CubeMesh->SetMaterial(0, GreenMaterial);
		break;
	}
}





