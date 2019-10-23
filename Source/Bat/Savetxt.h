// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/Actor.h"
#include "Savetxt.generated.h"

/**
 * 
 */
UCLASS()
class BAT_API USavetxt : public UBlueprintFunctionLibrary
{
public:
	UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadTxt"))
		static bool LoadTxt(FString FileNameA, FString& SaveTextA, FString DirA);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveTxt"))

		static void SaveTxt(FString SaveTextB, FString FileNameB);
	GENERATED_BODY()
	
};
