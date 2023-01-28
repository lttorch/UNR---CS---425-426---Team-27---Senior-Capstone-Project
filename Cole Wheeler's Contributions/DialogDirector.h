// Fill out your copyright notice in the Description page of Project Settings.

/*
Author:

	Cole Wheeler

Made for:

	CS-426 team 27

Description:

	This class will implement a blueprint exposed function that allow the team to load data from an input file by index.

Notes:

	!-Begin Custom-! and !-End Custom-! are used to indicate where my code blocks begin and end from the pregenerated code.

History:

	1/27/23: Created Class

		Created two test code snippets that test FFileHelper::LoadFileToStringArray and FFileHelper::LoadFileToString from a file stored in the config folder of the Unreal Project.

*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DialogDirector.generated.h"

UCLASS()
class CAMERATESTPROJECT_API ADialogDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADialogDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

// !- Begin Custom - !
private:
	
	// Contain default file path to directory where the files will be contained.
	FString filePath;
	// Name of the file.
	FString fileName;
	// Used to store the output of reading from the file.
	TArray <FString> tempArray;
	// Used to store the individual 
	FString tempString;

// !- End Custom - !
};

