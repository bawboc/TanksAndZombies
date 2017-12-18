// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Core.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//  Struct for managing inputs
//  What inputs can do varies by tank
USTRUCT(BlueprintType)
struct FTankInput {
	GENERATED_BODY()

public:
	// Sanitized movement input, ready to be used by games logic.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
		FVector2D MovementInput;

	// Fire 1 - Boolean
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
		uint32 bFire1 : 1;

	// Fire 2 - Boolean
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank Input")
		uint32 bFire2 : 1;

	void Sanitize();
	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void Fire1(bool bPressed);
	void Fire2(bool bPressed);

private:
	// Private because it's internal, raw data.  Game code should never see this
	FVector2D RawMovementInput;
};

UCLASS()
class TANKSANDZOMBIES_API ATank : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category="Tank Input")
		const FORCEINLINE FTankInput& GetCurrentInput() { return TankInput; }

protected:

	void MoveX(float AxisValue);
	void MoveY(float AxisValue);
	void Fire1Pressed();
	void Fire1Released();
	void Fire2Pressed();
	void Fire2Released();

	//  Input structure
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		FTankInput TankInput;

	//  Maximum turn speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
		float YawSpeed;

	//  Maximum movement speed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tank", meta = (ClampMin = "0.0"))
		float MoveSpeed;

private:

	// Which direction is the tank facing
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* TankDirection;

	// Body sprite for the tank.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* TankSprite;

	//  Actor used as turret.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		UChildActorComponent* ChildTurret;

	//  Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tank", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComponent;

};
