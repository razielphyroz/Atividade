// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inimigo.generated.h"

UCLASS()
class JOGO2D_API AInimigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInimigo();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:


	UPROPERTY(EditAnywhere)
		int16 Life;

	UPROPERTY(EditAnywhere)
		int16 Dano;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:

	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* Sprite;
	
	UPROPERTY(EditAnywhere)
		class USphereComponent* CollisionComp;

};	

