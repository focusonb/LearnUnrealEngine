// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DogdgeballProjectile.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"
#include "MyEnemyCharacter.generated.h"

UCLASS()
class MYPROJECT2_API AMyEnemyCharacter : public ACharacter
{
	GENERATED_BODY()
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
		class ULookAtActorComponent* LookAtActorComponent;

public:
	// Sets default values for this character's properties
	AMyEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ThrowDodgeball();

	bool bCanSeePlayer = false;
	bool bRreviousCanSeePlayer = false;
	FTimerHandle ThrowTimerHandle;
	float ThrowingInterval = 2.0f;
	float ThrowingDelay = 0.5f;


public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Dodgeball)
		TSubclassOf<class ADogdgeballProjectile> DodgeballClass;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
