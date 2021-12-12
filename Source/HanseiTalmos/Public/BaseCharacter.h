// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class HANSEITALMOS_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:

	//UFUNCTION(BlueprintImplementableEvent)
	void MoveForward(float AxisValue);

	//UFUNCTION(BlueprintImplementableEvent)
	void MoveRight(float AxisValue);
	//UFUNCTION(BlueprintImplementableEvent)
	void Turn(float AxisValue);
	//UFUNCTION(BlueprintImplementableEvent)
	void LookUp(float AxisValue);


	void TurnRate(float AxisValue);

	void LookUpRate(float AxisValue);


	void Pressed_r_Button();
	void Released_r_Button();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPressed_r_Button();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReleased_r_Button();

	void Pressed_l_Button();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPressed_l_button();
	
	void Pressed_Space();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPressed_Space();

	//UFUNCTION(BlueprintPure, Category = "Utilities|Time", meta = (WorldContext = "WorldContextObject"))
		//static float GetWorldDeltaSeconds(const UObject* WorldContextObject);

public:
	//UPROPERTY(EditAnywhere)
	//bool Zoom = false;
	
	UPROPERTY(EditAnywhere)
	float BaseTurnRate;

	UPROPERTY(EditAnywhere)
	float BaseLookUpRate;
};
