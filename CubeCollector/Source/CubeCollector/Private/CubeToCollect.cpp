// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeToCollect.h"
#include "Components/StaticMeshComponent.h"
#include "..\Public\CubeToCollect.h"

ACubeToCollect::ACubeToCollect() 
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("CubeMesh"));
	SetRootComponent(CubeMesh);
	CubeMesh->SetNotifyRigidBodyCollision(true);
}

void ACubeToCollect::BeginPlay()
{
	Super::BeginPlay();

	CubeMesh->OnComponentBeginOverlap.AddDynamic(this, &ACubeToCollect::OnActorBeginOverlap);
}

void ACubeToCollect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeToCollect::OnActorBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("%s is being overlaped by %s"), *OverlappedComp->GetOwner()->GetName(), *OtherActor->GetName());

	// Cuando se recolecta el cubo...
	CubeMesh->DestroyComponent();
}
