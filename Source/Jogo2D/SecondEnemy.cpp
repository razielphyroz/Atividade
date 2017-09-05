// Fill out your copyright notice in the Description page of Project Settings.

#include "SecondEnemy.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Personagem.h"
#include "Bullet.h"

ASecondEnemy::ASecondEnemy()
{
	Life = 5;

	BoxToStartShot = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxStartShot"));
	BoxToStartShot->bGenerateOverlapEvents = true;
	BoxToStartShot->SetCollisionProfileName("OverlapAllDynamic");
	BoxToStartShot->OnComponentBeginOverlap.AddDynamic(this, &ASecondEnemy::OnOverlapBegin2);
	BoxToStartShot->SetupAttachment(RootComponent);

}

void ASecondEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void ASecondEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}


void ASecondEnemy::OnOverlapBegin2(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	UE_LOG(LogTemp, Warning, TEXT("ASASASASASASASAS"));
	if (OtherActor != nullptr && OtherActor->IsA(APersonagem::StaticClass())) {
		APersonagem* Personagem = Cast<APersonagem>(OtherActor);
		UWorld* World = GetWorld();
		if (World != nullptr) {
			FActorSpawnParameters SpawnParam;
			if (Personagem->GetActorLocation().X < GetActorLocation().X) {
				FRotator MyRotator(0.0f, 0.0f, 180.0f);
				ABullet* Bullet = World->SpawnActor<ABullet>(MyBullets, RootComponent->GetComponentLocation(), MyRotator, SpawnParam);
			} else {
				ABullet* Bullet = World->SpawnActor<ABullet>(MyBullets, RootComponent->GetComponentLocation(), FRotator::ZeroRotator, SpawnParam);
			} 
		}
	}
}

