// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Emissive_Basic.generated.h"

UCLASS()
class BAT_API AEmissive_Basic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEmissive_Basic();

protected:

	void BeginPlay();

public:	

	UPROPERTY(EditAnyWhere)
		USceneComponent* CubeRoot;

	UPROPERTY(EditAnyWhere)
		UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnyWhere)
		UBoxComponent* Collision;
	
	void Tick(float DeltaTime);

	UFUNCTION()
	void OnSoundWaveRecieve(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnyWhere)
		float decay = 2.0f;

	UPROPERTY(EditAnyWhere)
		float MaxStrength = 2.0f;

	UPROPERTY(EditAnyWhere)
		float Addon = 1.5f;

	UPROPERTY(EditAnyWhere)
		bool Activated = true;

private:
	float strength;

};
