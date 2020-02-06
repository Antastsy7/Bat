// Fill out your copyright notice in the Description page of Project Settings.


#include "Emissive_Basic.h"
#include "Engine/Engine.h"
#include "ConstructorHelpers.h"
#include "SoundWaveBasic.h"

// Sets default values
AEmissive_Basic::AEmissive_Basic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeRoot = CreateAbstractDefaultSubobject<USceneComponent>(TEXT("CubeRoot"));
	RootComponent = CubeRoot;
	
	CubeMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	CubeMesh->AttachToComponent(CubeRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	Collision = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetGenerateOverlapEvents(true);
	Collision->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AEmissive_Basic::OnSoundWaveRecieve);
	Collision->AttachToComponent(CubeRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	strength = 1.0f;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/Geometry/Emssive.Emssive"));
	if (CylinderAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(CylinderAsset.Object);
	}

	


}

// Called when the game starts or when spawned
void AEmissive_Basic::BeginPlay()
{
	Super::BeginPlay();
	strength = 0;
	CubeMesh->SetScalarParameterValueOnMaterials("Strength", strength);
	
}

// Called every frame
void AEmissive_Basic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	strength = strength - DeltaTime * strength_decay;
	if (strength < 0) {
		strength = 0;
	}
	if (Faded){
		if (brightness >= 0) {
			brightness -= DeltaTime * brightness;
		}
	}

	CubeMesh->SetScalarParameterValueOnMaterials("Strength", strength);
	CubeMesh->SetScalarParameterValueOnMaterials("Brightness", brightness);
}

void AEmissive_Basic::OnSoundWaveRecieve(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(ActorTag) || OtherComp->ComponentHasTag(ComponentTag)) {
		ASoundWaveBasic *b = Cast<ASoundWaveBasic>(OtherActor);
		if (b != nullptr) {
			Addon = b->Addon;
		}
		if (Activated) {
			strength += Addon;
			if (strength > MaxStrength) {
				strength = MaxStrength;
			}
		}
	}
	
}

