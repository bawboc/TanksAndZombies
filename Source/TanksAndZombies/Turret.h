// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TanksAndZombies.h"
#include "GameFramework/Actor.h"
#include "Turret.generated.h"

UCLASS()
class TANKSANDZOMBIES_API ATurret : public AActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATurret();

protected:
	//  Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//  The missile
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Turret")
		TSubclassOf<AActor> Projectile;

	// The name of the socket at the muzzle
	static const FName MuzzleSocketName;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE UArrowComponent* GetTurretDirection() { return TurretDirection; }

private:

	// Which direction is the tank facing
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* TurretDirection;

	// Body sprite for the tank.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* TurretSprite;

	// Time to delay between Fire1 commands.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		float Fire1Cooldown;

	// If this value is greater than the current game time, Fire1 is ignored because it has been fired too recently.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		float Fire1ReadyTime;

	//  How fast does the turret turn
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		float YawSpeed;

	//  The tank
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Turret", meta = (AllowPrivateAccess = "true"))
		class ATank* Tank;

};
