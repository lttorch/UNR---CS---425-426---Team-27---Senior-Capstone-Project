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

	1/27/23: Created Class - Cole Wheeler

		Created two test code snippets that test FFileHelper::LoadFileToStringArray and FFileHelper::LoadFileToString from a file stored in the config folder of the Unreal Project.

	2/1/23: Created Function: DD_Read_At_Line_Index - Cole Wheeler

		Removed depreciated private variables as they are no longer needed.

		Created function call for DD_Read_At_Line_Index and implemented it in DialogDirector.cpp.

		Tested in testbed environment, ready for integration in main project.

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
public:

	// Will open the designated file in the project's Config folder, read in the content of the file, and return it the string at the indicated line index sent.
	UFUNCTION(BlueprintCallable, Category = "Dialog Director")
		static FString DD_Read_At_Line_Index (FString fileName, const int32 lineIndex);

// !- End Custom - !
};

