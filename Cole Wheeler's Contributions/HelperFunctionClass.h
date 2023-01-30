// Fill out your copyright notice in the Description page of Project Settings.

/*
Author(s):

	Cole Wheeler

Made for:

	CS-426 team 27

Description:

	This class will store a number of blueprint exposed C++ helper functions that the team will use to clean up the blueprint space and make creating conditional logic easier.

Notes:

	!-Begin Custom-! and !-End Custom-! are used to indicate where my code blocks begin and end from the pregenerated code.

History:

	1/29/23: Created Class
		
		Created Blueprint exposed function DAC_Movement_Helper_Function.
			(Needs testing.)

*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelperFunctionClass.generated.h"

UCLASS()
class CAMERATESTPROJECT_API AHelperFunctionClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelperFunctionClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

// !- Begin Custom - !
private:

	// UFUNCTION will allow blueprint components to call the function as well as C++ calls.

	// A helper function for the Demon_AI_Controller Blueprint.
	UFUNCTION(BlueprintCallable, Category = "Custom C++ Helper Function")
		static bool DAC_Movement_Helper_Function(const float actorDistance, const float maxDistanceAllowed, const AActor* targetCube, const AActor* desiredCube);

};
