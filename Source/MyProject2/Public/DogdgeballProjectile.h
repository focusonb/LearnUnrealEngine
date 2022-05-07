// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DogdgeballProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
UCLASS()
class MYPROJECT2_API ADogdgeballProjectile : public AActor
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dodgeball, meta = (AllowPrivateAccess = "true"))
		USphereComponent* SphereComponent;
	
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dodgeball, meta = (AllowPrivateAccess = "true"))
	//	UStaticMesh* StaticMesh;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp
			, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Dodgeball, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;
public:	
	// Sets default values for this actor's properties
	ADogdgeballProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = Damage)
		float Damage = 34.0f;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* BounceSound;
	UPROPERTY(EditDefaultsOnly, Category = Sound)
		class USoundAttenuation* BounceSoundAttenuation;
	UPROPERTY(EditAnywhere, Category = Particles)
		class UParticleSystem* HitParticles;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovementComponent() const
	{
		return ProjectileMovement;
	}

};
