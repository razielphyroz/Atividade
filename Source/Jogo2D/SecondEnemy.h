// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inimigo.h"
#include "SecondEnemy.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API ASecondEnemy : public AInimigo
{
	GENERATED_BODY()
	
	ASecondEnemy();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
private:

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABullet> MyBullets;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxToStartShot;
	
	UFUNCTION()
		void OnOverlapBegin2(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
