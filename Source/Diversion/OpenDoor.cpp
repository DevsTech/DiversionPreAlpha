// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDaDoor()
{
	AActor* DoorActor = GetOwner();
	FRotator Rotated = FRotator(0.f, 90.f, 0.f);
	DoorActor->SetActorRotation(Rotated);
}

void UOpenDoor::CloseDaDoor()
{
	AActor* DoorActor = GetOwner();
	FRotator Rotated = FRotator(0.f, 00.f, 0.f);
	DoorActor->SetActorRotation(Rotated);
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	OpenActor = GetWorld()->GetFirstPlayerController()->GetPawn();

}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(OpenActor))
	{
		OpenDaDoor();
		TimeOpen = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds() > TimeOpen + OpenDuration)
	{
		CloseDaDoor();
	}
	
}

