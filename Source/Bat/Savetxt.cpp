// Fill out your copyright notice in the Description page of Project Settings.


#include "Savetxt.h"


bool USavetxt::LoadTxt(FString FileNameA, FString& SaveTextA, FString DirA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(DirA + FileNameA));
}

bool USavetxt::SaveTxt(FString SaveTextB, FString FileNameB)
{
	FString gameDir = FPaths::GameDir();
	return FFileHelper::SaveStringToFile(SaveTextB, *(gameDir + FileNameB));

}