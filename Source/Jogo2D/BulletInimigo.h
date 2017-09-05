// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bullet.h"
#include "BulletInimigo.generated.h"

/**
 * 
 */
UCLASS()
class JOGO2D_API ABulletInimigo : public ABullet
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
		virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	
};
