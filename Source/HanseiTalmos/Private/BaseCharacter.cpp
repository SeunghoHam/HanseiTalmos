// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BaseTurnRate = 45.0f;
	BaseLookUpRate = 45.0f;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABaseCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABaseCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("TurnUpRate"), this, &ABaseCharacter::TurnRate);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &ABaseCharacter::LookUpRate);

	PlayerInputComponent->BindAction(TEXT("MouseRButton"), EInputEvent::IE_Pressed, this, &ABaseCharacter::Pressed_r_Button);
	PlayerInputComponent->BindAction(TEXT("MouseRButton"), EInputEvent::IE_Released, this, &ABaseCharacter::Released_r_Button);

	PlayerInputComponent->BindAction(TEXT("MouseLButton"), EInputEvent::IE_Pressed, this, &ABaseCharacter::Pressed_l_Button);
}

#pragma region CharacterMovement

void ABaseCharacter::MoveForward(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector WorldDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(WorldDirection, AxisValue);
	
}

void ABaseCharacter::MoveRight(float AxisValue)
{
	FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector WorldDirection = FRotationMatrix(ControlRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(WorldDirection, AxisValue);
}

void ABaseCharacter::Turn(float AxisValue)
{
	// Origin
	//AddControllerYawInput(AxisValue);

	AddControllerYawInput(AxisValue);
}

void ABaseCharacter::LookUp(float AxisValue)
{
	//AddControllerPitchInput(AxisValue);

	AddControllerPitchInput(AxisValue);
}

void ABaseCharacter::TurnRate(float AxisValue)
{
	//UObject* WorldContextObject;
	//UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,EGetWorldErrorMode::LogAndReturnNull);

	//UWorld World = GEngine->
	//float nyaong = (AxisValue * BaseTurnRate* GetWorld()->GetDeltaSeconds());
	AddControllerYawInput(AxisValue * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ABaseCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

/*float UGameplayStatics::GetWorldDeltaSeconds(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	return World ? World->GetDeltaSeconds() : 0.f;
}*/
#pragma endregion

#pragma region MouseAction



void ABaseCharacter::Pressed_r_Button()
{
	OnPressed_r_Button();
}
void ABaseCharacter::Released_r_Button()
{
	OnReleased_r_Button();
}

void ABaseCharacter::Pressed_l_Button()
{
	OnPressed_l_button();
}

void ABaseCharacter::Pressed_Space()
{
	OnPressed_Space();
}

#pragma endregion



