// Fill out your copyright notice in the Description page of Project Settings.


#include "Savetxt.h"
#include <Engine.h>


bool USavetxt::LoadTxt(FString FileNameA, FString& SaveTextA, FString DirA)
{
	return FFileHelper::LoadFileToString(SaveTextA, *(DirA + FileNameA));
}

void USavetxt::SaveTxt(FString SaveTextB, FString FileNameB)
{
	FString SaveDirectory = FString("C:/Path/To/My/Save/Directory");
	FString FileName = FString("MyFileName.sav");
	bool AllowOverwriting = false;

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// CreateDirectoryTree returns true if the destination
	// directory existed prior to call or has been created
	// during the call.
	if (PlatformFile.CreateDirectoryTree(*SaveDirectory))
	{
		// Get absolute file path
		FString AbsoluteFilePath = SaveDirectory + "/" + FileName;

		// Allow overwriting or file doesn't already exist
		FFileHelper::SaveStringToFile(SaveTextB, *AbsoluteFilePath);
	}
}

float USavetxt::ChangeVal(float value, float addon, float threshold, bool greater)
{
	if (greater) {
		return value + addon > threshold ? threshold : value + addon;
	}
	else {
		return value - addon < threshold ? threshold : value - addon;
	}
}



//void USavetxt::ChangeVal(float& value, float& const addon, float& const threshold, bool& const greater) {
//	value = value + addon;
//}