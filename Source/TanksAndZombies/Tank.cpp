// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TanksAndZombies.h"


void FTankInput::Sanitize() {
	MovementInput = RawMovementInput.ClampAxes(-1.0f, 1.0f);
	MovementInput = MovementInput.GetSafeNormal();
	RawMovementInput.Set(0.0f, 0.0f);
}

void FTankInput::MoveX(float AxisValue) {
	RawMovementInput.X += AxisValue;
}

void FTankInput::MoveY(float AxisValue) {
	RawMovementInput.Y += AxisValue;
}

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("TankBase"));
	}

	TankDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("TankDirection"));
	TankDirection->SetupAttachment(RootComponent);

	TankSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("TankSprite"));
	TankSprite->SetupAttachment(TankDirection);

	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->TargetArmLength = 500.0f;
	SpringArm->CameraLagSpeed = 2.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = false;
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));
	SpringArm->SetupAttachment(TankDirection);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->bUsePawnControlRotation = false;
	CameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	CameraComponent->OrthoWidth = 1024.0f;
	CameraComponent->AspectRatio = 3.0f / 4.0f;
	CameraComponent->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));
	// Attach to end of spring arm
	CameraComponent->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	ChildTurret = CreateDefaultSubobject<UChildActorComponent>(TEXT("Turret"));
	ChildTurret->SetupAttachment(TankDirection);
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	TankInput.Sanitize();

	//  Move the tank
	{
		FVector DesiredMovementDirection = FVector(TankInput.MovementInput.X, TankInput.MovementInput.Y, 0.0f);
		if (!DesiredMovementDirection.IsNearlyZero()) {
			//  Rotate the tank.  Rotate the TankDirection component, not the RootComponent.
			FRotator MovementAngle = DesiredMovementDirection.Rotation();
			float DeltaYaw = UTankStatics::FindDeltaAngleDegrees(TankDirection->GetComponentRotation().Yaw, MovementAngle.Yaw);
			bool bReverse = false;
			if (DeltaYaw != 0.0f) {
				float AdjustedYaw = DeltaYaw;

				if (AdjustedYaw < -90.0f) {
					AdjustedYaw += 180.0f;
					bReverse = true;
				} else if (AdjustedYaw > 90.0f) {
					AdjustedYaw -= 180.0f;
					bReverse = true;
				}

				//  Turn toward the desired angle.  Stop if we can get there in one frame
				float MaxYawThisFrame = YawSpeed * DeltaTime;
				if (MaxYawThisFrame >= FMath::Abs(AdjustedYaw)) {
					if (bReverse) {
						//  Move backward
						FRotator FacingAngle = MovementAngle;
						FacingAngle.Yaw = MovementAngle.Yaw + 180.0f;
						TankDirection->SetWorldRotation(FacingAngle);
					} else {
						TankDirection->SetWorldRotation(MovementAngle);
					}
				} else {
					//  Can't reach our desired angle this frame, rotate part way.
					TankDirection->AddLocalRotation(FRotator(0.0f,FMath::Sign(AdjustedYaw) * MaxYawThisFrame, 0.0f));
				}
			}
			// Move the tank 
			{
				FVector MovementDirection = TankDirection->GetForwardVector() * (bReverse ? -1.0f : 1.0f);
				FVector Pos = GetActorLocation();
				Pos.X += MovementDirection.X * MoveSpeed * DeltaTime;
				Pos.Y += MovementDirection.Y * MoveSpeed * DeltaTime;
				SetActorLocation(Pos);
			}
		}
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &ATank::MoveX);
	PlayerInputComponent->BindAxis("MoveY", this, &ATank::MoveY);
}

void ATank::MoveX(float AxisValue) {
	TankInput.MoveX(AxisValue);
}

void ATank::MoveY(float AxisValue) {
	TankInput.MoveY(AxisValue);
}