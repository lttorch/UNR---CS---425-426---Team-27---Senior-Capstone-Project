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

	1/27/23: Created Class - Cole Wheeler

		Created two test code snippets that test FFileHelper::LoadFileToStringArray and FFileHelper::LoadFileToString from a file stored in the config folder of the Unreal Project.

	2/1/23: Created Function: DD_Read_At_Line_Index - Cole Wheeler
		
		Removed Code snippets from BeginPlay as they are no long needed.

		Created and tested DD_Read_At_Line_Index.
			Tested in testbed environment, ready for integration in main project.

		Has 1 successful return and 3 error returns.
			Will return all these as strings to save on memory.
				(Might be better to have a bool be passed by reference)
				- Success: Read file, Found line at specified index, returns specified line as string.
				- Error: Invalid Index: Index is less then 0.
				- Error: Invalid Index: Index is greater then the largest indes from the array of file contents.
				- Error: Failed to read specified file in the project's config folder.
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
		

}

// Called every frame
void ADialogDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// !- Begin Custom - !

// Will open the designated file in the project's Config folder, read in the content of the file, and return it the string at the indicated line index sent.
// Input:			File Name as String (w/ extention) and an int to indiacte what line we want read from the file.
// If successful:	The desired string from the file.
//		- Success: Returns desired line as string.
// Else:			An error message as a string that will contain information of what went wrong.
//		- Error: Invalid Index : Index is less then 0.
//		- Error: Invalid Index : Index is greater then the largest indes from the array of file contents.
//		- Error: Failed to read specified file in the project's config folder.
FString ADialogDirector::DD_Read_At_Line_Index(FString fileName, const int32 lineIndex)
{
	// First check if the int value sent is valid (Cannot less then zero.)
	if (lineIndex < 0)
	{
		// Return a string containing the error message.
		// Indicate that the index is invalid and must be >= 0.
		return ("DD Error: Invalid Index, Index must be >= 0, Sent index: " + (FString::FromInt(lineIndex) ) );
	}

	// Create an empty array to store the results of the read.
	TArray <FString> fileArray;

	// Prefix the file name with the file path to the project's config folder.
	fileName = FPaths::ProjectConfigDir() + fileName;

	// Attempt to read the file and store the result in an array.
	if (FFileHelper::LoadFileToStringArray(fileArray, *fileName))
	{
		// We were able to successfully read the file.
		
		// Check to see if the requested index is in range of the array.
		// If the requested index is less then the largest element value of the file array.
		if (lineIndex < fileArray.Num())
		{
			// We will have the requested element, return the requested line.
			return fileArray[lineIndex];
		}
		// Otherwise the index requested is invalid.
		else
		{
			// Return an error message indicating that the index is invalid.
			// Will indicate the largest index value from the array: (Size of the array) - 1
			return "DD Error: Invalid Index, Max Index found in file: " + (FString::FromInt(fileArray.Num() - 1) );
		}
	}
	// Otherwise we could not read the file.
	else
	{
		// Return the string as an error.
		return ("DD Error: Cannot read file: " + (fileName) );
	}
	
}
// !- End Custom - !