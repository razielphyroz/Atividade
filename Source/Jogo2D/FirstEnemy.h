// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inimigo.h"
#include "FirstEnemy.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API AFirstEnemy : public AInimigo
{
	GENERATED_BODY()
	
public:
	AFirstEnemy();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	void Move();

	FVector InitialLocation;
	
	UPROPERTY(EditAnywhere)
		float MaxMoveDistance;

	UPROPERTY(EditAnywhere)
		int16 Direction;
};

