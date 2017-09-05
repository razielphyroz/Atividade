// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletInimigo.h"
#include "Inimigo.h"




void ABulletInimigo::OnHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if (!OtherActor->IsA(AInimigo::StaticClass())) {
		Destroy();
	}
}
