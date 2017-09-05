// Fill out your copyright notice in the Description page of Project Settings.

#include "Inimigo.h"
#include "PaperFlipbookComponent.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Personagem.h"
#include "Bullet.h"
#include "PaperSpriteComponent.h"

// Sets default values
AInimigo::AInimigo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
	CollisionComp->bGenerateOverlapEvents = true;
	CollisionComp->SetCollisionProfileName("OverlapAllDynamic");
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AInimigo::OnOverlapBegin);
	CollisionComp->SetupAttachment(RootComponent);

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetCollisionProfileName("NoCollision");
	Sprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AInimigo::BeginPlay()
{
	Super::BeginPlay();
	Dano = 1;
}

// Called every frame
void AInimigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInimigo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != nullptr) {
		if (OtherActor->IsA(APersonagem::StaticClass())) {
			APersonagem* Personagem = Cast<APersonagem>(OtherActor);
			Personagem->SetLife(Personagem->GetLife() - Dano);
		} else if (OtherActor->IsA(ABullet::StaticClass())) {
			UE_LOG(LogTemp, Warning, TEXT("Life %d."), Life);
			Life -= 1;
			if (Life <= 0) {
				Destroy();
			}
		}
	}
}

