// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WildHunter.generated.h"

UCLASS()
class BAT_API AWildHunter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWildHunter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
