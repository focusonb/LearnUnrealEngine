// Fill out your copyright notice in the Description page of Project Settings.

#include "../MyProject2Character.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

#include "../Public/HealthComponent.h"
#include "DogdgeballProjectile.h"

// Sets default values
ADogdgeballProjectile::ADogdgeballProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereComponent->SetSphereRadius(35.0f);
	SphereComponent->SetCollisionProfileName(FName("Dodgeball"));
	SphereComponent->SetSimulatePhysics(true);
	SphereComponent->SetNotifyRigidBodyCollision(true);
	(SphereComponent->OnComponentHit).AddDynamic(this, &ADogdgeballProjectile::OnHit);
	RootComponent = SphereComponent;
	//SetupAttachment(RootComponent);

	//StaticMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("StaticMesh"));
	//StaticMesh->SetupAttachment()

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Pro jectile Movement"));
	//ProjectileMovement->InitialSpeed = 1500.f;
}

// Called when the game starts or when spawned
void ADogdgeballProjectile::BeginPlay()
{
	Super::BeginPlay();
	//SetLifeSpan(5.0f);
}

// Called every frame
void ADogdgeballProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ADogdgeballProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp
	, FVector NormalImpulse, const FHitResult& Hit) {

	AMyProject2Character* Player = Cast<AMyProject2Character>(OtherActor);
	if (Player != nullptr){
		UHealthComponent* HealthComponent = Player->FindComponentByClass<UHealthComponent>();
		if (HealthComponent != nullptr) {
			HealthComponent->LoseHealth(Damage);
		}

		if (BounceSound != nullptr && NormalImpulse.Size() > 600.0f) {
			UGameplayStatics::PlaySoundAtLocation(this, BounceSound, GetActorLocation(), 1.0f,
				FMath::RandRange(0.7f, 1.3f));
		}
		Destroy();
	}
}
