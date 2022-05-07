// Fill out your copyright notice in the Description page of Project Settings.



#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"




#include "MyActor.h"
#include "LookAtActorComponent.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LookAtActorComponent = CreateDefaultSubobject<ULookAtActorComponent>(TEXT("Look At Actor Component"));
	LookAtActorComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	//FRotator LookAtRotation(255.0, 255.0, 255.0);
	//GetOwner()->SetActorRotation(LookAtRotation);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	LookAtActorComponent->SetTarget(PlayerCharacter);

}

