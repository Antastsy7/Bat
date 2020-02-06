// Fill out your copyright notice in the Description page of Project Settings.


#include "Emissive_Tree.h"
#include "ConstructorHelpers.h"

AEmissive_Tree:: AEmissive_Tree()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CylinderAsset(TEXT("/Game/SoulCave/Environment/Meshes/Nature/SM_tree2.SM_tree2"));
	if (CylinderAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(CylinderAsset.Object);
		CubeMesh->SetWorldScale3D(FVector(4, 4, 4));
	}

}