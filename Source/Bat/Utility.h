// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/Actor.h"
#include "Utility.generated.h"

/**
 * 
 */
UCLASS()
class BAT_API UUtility : public UBlueprintFunctionLibrary
{
	public:
		UFUNCTION(BlueprintCallable, Category = "Custom")
			static void ChangeVal(float *value, float* motify, float* threshold, bool* greater);
		GENERATED_BODY()
};
