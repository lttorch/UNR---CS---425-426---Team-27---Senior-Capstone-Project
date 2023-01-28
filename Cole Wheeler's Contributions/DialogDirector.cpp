// Fill out your copyright notice in the Description page of Project Settings.

/*
Author:

	Cole Wheeler

Made for:

	CS-426 team 27

Description:

	Implementation file for the DialogDirector.h class.

Notes:

	!-Begin Custom-! and !-End Custom-! are used to indicate where my code blocks begin and end from the pregenerated code.

History:

	1/27/23: Created Class

		Created two test code snippets that test FFileHelper::LoadFileToStringArray and FFileHelper::LoadFileToString from a file stored in the config folder of the Unreal Project.

*/

#include "DialogDirector.h"

// Sets default values
ADialogDirector::ADialogDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADialogDirector::BeginPlay()
{
	Super::BeginPlay();

	// !- Begin Custom - !

	/*
	
	int arraySize = 0;
	int index = 0;

	Loads all lines from the input file Text.txt in the config folder of the Unreal Project.
	Delimited by '\n'

	// Set the file path.
	filePath = FPaths::ProjectConfigDir();
	fileName = filePath + (TEXT("Test.txt"));

	// Load the content of the file into the TArray <FString> tempArray.
	if (FFileHelper::LoadFileToStringArray(tempArray, *fileName))
	{
		// Get the number of elements in tempArray.
		arraySize = tempArray.Num();

		// While there are still elements to write to the log.
		while (index < arraySize)
		{
			// Write out the element to the log.
			UE_LOG(LogTemp, Warning, (TEXT("Input: %s")), *tempArray[index]);
			// Increment the index.
			index++;
		}

		// Clear the array.
		tempArray.Empty();

	}
	else
	{
		// Indicate that the file could not be read.
		UE_LOG(LogTemp, Warning, (TEXT("Could not read file.")));
	}

	*/

	/*
	
	Tested reading from a file into a single string.

	// Set the file path.
	filePath = FPaths::ProjectConfigDir();
	fileName = filePath + (TEXT("Test.txt") );
	
	// Load the content of the file into the FString tempString.
	if (FFileHelper::LoadFileToString(tempString, *fileName))
	{
		// Display the output as an error log.
		UE_LOG(LogTemp, Warning, (TEXT("Input from File: %s")), *tempString);
	}
	else
	{
		// Indicate that the file could not be read.
		UE_LOG(LogTemp, Warning, (TEXT("Could not read file.")) );
	}

	*/

	// !- End Custom - !

}

// Called every frame
void ADialogDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

