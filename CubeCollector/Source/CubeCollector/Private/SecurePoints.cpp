// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurePoints.h"
#include "Components/StaticMeshComponent.h"
#include "..\Public\SecurePoints.h"
#include "ScoreSystem.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ASecurePoints::ASecurePoints()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("MeshComponent"));
	SetRootComponent(MeshComponent);
	MeshComponent->SetNotifyRigidBodyCollision(true);

	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(FName("ParticleSystem"));
	ParticleSystem->SetupAttachment(MeshComponent);
}

// Called when the game starts or when spawned
void ASecurePoints::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ASecurePoints::OnActorBeginOverlap);

	ScoreSystem = Cast<AScoreSystem>(GetAttachParentActor());

	SetSecurePointMaterial(SecurePointType);
}

// Called every frame
void ASecurePoints::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASecurePoints::OnActorBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ScoreSystem->CubeSecured(this);
	UGameplayStatics::PlaySoundAtLocation(this, SecuredSound, this->GetActorLocation());
}

void ASecurePoints::SetSecurePointMaterial(ESecurePointType PointType)
{
	if (PointType == ESecurePointType::Blue)
	{
		ParticleSystem->SetTemplate(BlueParticleSystem);
		MeshComponent->SetMaterial(0, BlueMaterial);
	}

	if (PointType == ESecurePointType::Yellow)
	{
		ParticleSystem->SetTemplate(YellowParticleSystem);
		MeshComponent->SetMaterial(0, YellowMaterial);
	}

	if (PointType == ESecurePointType::Green)
	{
		ParticleSystem->SetTemplate(GreenParticleSystem);
		MeshComponent->SetMaterial(0, GreenMaterial);
	}
}

