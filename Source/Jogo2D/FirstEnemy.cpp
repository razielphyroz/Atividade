// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstEnemy.h"

AFirstEnemy::AFirstEnemy()
{
	MaxMoveDistance = 200.0f;
	Direction = 0;
	Life = 3;
}

void AFirstEnemy::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

void AFirstEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AFirstEnemy::Move()
{
	if (Direction == 0) {
		SetActorLocation(FVector(GetActorLocation().X + 10, GetActorLocation().Y, GetActorLocation().Z));
		if (GetActorLocation().X >= InitialLocation.X + MaxMoveDistance) {
			Direction = 1;
		}
	} else {
		SetActorLocation(FVector(GetActorLocation().X - 10, GetActorLocation().Y, GetActorLocation().Z));
		if (GetActorLocation().X <= InitialLocation.X - MaxMoveDistance) {
			Direction = 0;
		}
	}
}
