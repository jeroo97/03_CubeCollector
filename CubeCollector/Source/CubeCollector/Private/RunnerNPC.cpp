// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerNPC.h"

void ARunnerNPC::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & hit)
{
	UE_LOG(LogTemp, Warning, TEXT("I'm beeing overlapped"));
}
