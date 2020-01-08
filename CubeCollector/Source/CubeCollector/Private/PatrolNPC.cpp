// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolNPC.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "TimeManager.h"
#include "Math/Vector.h"
#include "Perception/AISense_Hearing.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
APatrolNPC::APatrolNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APatrolNPC::BeginPlay()
{
	Super::BeginPlay();
	
	TimeManager = Cast<UTimeManager>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<UTimeManager>());

	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &APatrolNPC::OnHit);

	LifeLeft = StartingLife;
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

void APatrolNPC::SetCharacter(AActor* Player)
{
	PlayerReference = Player;
}

void APatrolNPC::TakeHealth()
{
	LifeLeft--;
}

float APatrolNPC::GetHealthPercent() const
{
	return (float)LifeLeft / (float)StartingLife;
}

void APatrolNPC::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & hit)
{
	if (OtherActor->GetName() == "FirstPersonCharacter_C_0")
	{
		TimeManager->ModifyTimeCountDown(-30.f);
		// TODO apagar la colicion y no modificar mas el counter una vez se muere.
		Destroy(this);
	}
	if (OtherActor->FindComponentByClass<UProjectileMovementComponent>())
	{
		TakeHealth();
		if (LifeLeft <= 0)
		{
			UAISense_Hearing::ReportNoiseEvent(this, this->GetActorLocation(), 1.f, this, 0.f, TEXT("Noise"));
			this->DetachFromControllerPendingDestroy();
			FTimerHandle TimerSample;
			GetWorld()->GetTimerManager().SetTimer(TimerSample, this, &APatrolNPC::DestroyCharacter, DestroyDelay);
		}
	}
}

float APatrolNPC::GetDistanceToPlayer()
{
	auto Dist = FVector::Dist(this->GetActorLocation(), PlayerReference->GetActorLocation());
	return Dist;
}

void APatrolNPC::DestroyCharacter()
{
	Destroy(this);
}
