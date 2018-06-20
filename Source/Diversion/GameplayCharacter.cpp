// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayCharacter.h"
#include "Engine/Engine.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AGameplayCharacter::AGameplayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);

}

// Called when the game starts or when spawned
void AGameplayCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameplayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGameplayCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Pressed, this, &AGameplayCharacter::Aim);
	PlayerInputComponent->BindAction("Aim", EInputEvent::IE_Released, this, &AGameplayCharacter::AimReleased);
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameplayCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameplayCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

void AGameplayCharacter::MoveForward(float Value)
{
	if (Value != 0)
	{
		IsMoving = true;
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
	else
	{
		IsMoving = false;
	}
}

void AGameplayCharacter::MoveRight(float Value)
{
	if (Value!=0)
	{
		IsMoving = true;
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
	else
	{
		IsMoving = false;
	}
	
}

void AGameplayCharacter::Aim()
{
	IsAiming = true;
	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void AGameplayCharacter::AimReleased()
{
	IsAiming = false;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
}


