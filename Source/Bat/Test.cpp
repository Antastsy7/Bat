// Fill out your copyright notice in the Description page of Project Settings.


#include "Test.h"
#include "Engine.h"



// Sets default values
ATest::ATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATest::BeginPlay()
{
	//super::beginplay();
	//fstring savedirectory = fpaths::enginedir();
	//gengine->addonscreendebugmessage(savedirectory);
	//fstring filename = fstring("myfilename.sav");
	//fstring texttosave = fstring("lorem ipsum");
	//bool allowoverwriting = false;

	//iplatformfile& platformfile = fplatformfilemanager::get().getplatformfile();

	//// createdirectorytree returns true if the destination
	//// directory existed prior to call or has been created
	//// during the call.
	//fstring absolutefilepath = savedirectory + "/" + filename;
	//ffilehelper::savestringtofile(texttosave, *absolutefilepath);

}

// Called every frame
void ATest::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

}


