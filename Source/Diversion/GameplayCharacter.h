// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BulletRifle.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "GameplayCharacter.generated.h"

UCLASS()
class DIVERSION_API AGameplayCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameplayCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float Value);
	
	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void Aim();

	UFUNCTION()
	void AimReleased();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = PublicVars)
	bool IsAiming = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = PublicVars)
	bool IsMoving = false;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletRifle> ToSpawn;

	UFUNCTION(BlueprintCallable)
	void Spawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector loc;
	
};
