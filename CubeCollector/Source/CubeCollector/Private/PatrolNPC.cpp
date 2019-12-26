// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolNPC.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "TimeManager.h"

// Sets default values
APatrolNPC::APatrolNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshFace = CreateDefaultSubobject<UStaticMeshComponent>(FName("Static Mesh Face"));

}

// Called when the game starts or when spawned
void APatrolNPC::BeginPlay()
{
	Super::BeginPlay();
	
	TimeManager = Cast<UTimeManager>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<UTimeManager>());

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &APatrolNPC::OnHit);
}

// Called every frame
void APatrolNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APatrolNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APatrolNPC::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & hit)
{
	if (OtherActor->GetName() == "FirstPersonCharacter_C_0")
	{
		TimeManager->ModifyTimeCountDown(-30.f);
		this->DetachFromControllerPendingDestroy();
		// TODO apagar la colicion y no modificar mas el counter una vez se muere.
		//Destroy(this);
	}
}

