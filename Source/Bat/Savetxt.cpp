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