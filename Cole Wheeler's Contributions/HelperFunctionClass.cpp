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

	1/29/23: Created Class - Cole Wheeler

		Created Blueprint exposed function DAC_Movement_Helper_Function.
			Will accept:
				Two floats and perform a >= test
					and 
				Two object references and check to see if they are referencing the same object.
			(Needs testing.)

	1/30/23: Integrated with Project - Cole Wheeler

*/

#include "HelperFunctionClass.h"

// Sets default values
AHelperFunctionClass::AHelperFunctionClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHelperFunctionClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHelperFunctionClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// A helper function for the Demon_AI_Controller Blueprint.
bool AHelperFunctionClass::DAC_Movement_Helper_Function(const float actorDistance, const float maxDistanceAllowed, const AActor* targetCube, const AActor* desiredCube)
{	
	// If the NPC's distance (actorDistance) is less then or equal to a specified distance (maxDistanceAllowed) 
	// and 
	// the targeted tile (targetCube) is the desired tile (desiredCube) that the NPC is moving towards.
	
	// If (actorDistance <= maxDistanceAllowed) and (targetCube == desiredCube)
	if ( (actorDistance <= maxDistanceAllowed) && (targetCube == desiredCube) )
	{
		return true;
	}
	else
	{
		return false;
	}

}