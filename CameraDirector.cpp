// Fill out your copyright notice in the Description page of Project Settings.

/*
Author:

	Cole Wheeler

Made for:

	CS-425 team 27

Notes:

	!-Begin Custom-! and !-End Custom-! are used to indicate where my code blocks begin and end from the pregenerated code.

History:

	11/23/22: Created class

		Created Variables:
			- const bool intializeCamera
			- static inline bool cameraUpdate
			- static inline unsigned short cameraId
			- static const unsigned short maxCameraId

		Created Function:
			- static void AdvanceCamera()

		Created Functionalities:
			- A boolean controlled expression that will override the default camera at the start of the game. (In BeginPlay)
			- UPROPERTY components to link to camera actors in the editor.
			- AdvanceCamera will mark to iterate to the next UPROPERTY camera each time it's called. (Will reset to 0 when the last camera is called)

	11/24/22: Intergrated with main project

		Updated:
			- Added Header as I forgot that from the previous update.
			
	12/2/22: Added Functionalities
	
		Updated: 
			- Moved #include "Kismet/GameplayStatics.h" to header file from cpp file.
			
			BeginPlay:
				- Added statement to set Camera0 to the default pawn's default camera. (Default pawn is the one that is spawned from PlayerStart)
				
				- Added statements to insert Camera entity pointers into the array cameraArray.
				
				- Updated SetViewTarget with cameraArray pointer.
				
			Tick:			
				- Updated SetViewTarget with cameraArray pointer.
				
		Added:
			ChangeToCameraId:
				- Will set the camera Id to the set value.
				- Returns true on success and false on failure.
*/

#include "CameraDirector.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	
	// !-Begin Custom-!
	// Will find and map Camera0 to the player pawn that is spawned at the PlayerStart entity when the game begins.
	Camera0 = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	
	// Load the array of cameras.
	cameraArray[0] = Camera0;
	cameraArray[1] = Camera1;
	cameraArray[2] = Camera2;
		
	// If the initializeCamera constant is set to true, then we will override whatever the default camera is.
	if (intializeCamera)
	{
		// Used to set the camera to the first position at the start of the game.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		OurPlayerController->SetViewTarget(cameraArray[0]);
	}
	// !-End Custom-!
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		

	// !-Begin Custom-!
	// If we need to update the camera. (Will prevent needless camera switchs.)
	if (cameraUpdate)
	{
		// Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		
		// Assign it as the current camera from the array of cameras based on the current Id.
		OurPlayerController->SetViewTarget(cameraArray[cameraId]);

		// Reset the cameraUpdate bool to indicate that the change has been handled.
		cameraUpdate = false;
	}

	return;
	// !-End Custom-!
}

// !-Begin Custom-!
// Will increment the cameraId and indicate that a camera update is required.
void ACameraDirector::AdvanceCamera()
{
	// Indicate that a change of camera Id has occured.
	cameraUpdate = true;

	// Increment the Id.
	cameraId++;
	
	// Check to see if the cameraId greater then max.
	if (cameraId > maxCameraId)
	{
		// Reset to 0.
		cameraId = 0;
	}

	return;
}

// Will set the cameraId to the indicated value.
// If successful:	Indicate that a camera update is required and return true.
// Else:			Return false.
// Default Parameter: newCameraId: Will store the new camera Id which will be tested for validity.
bool ACameraDirector::ChangeToCameraId(int32 newCameraId = -1)
{
	// Check if the sent Id is equivilant to the currentId.
	if (newCameraId == cameraId)
	{
		// Return true because the currently active camera is the one being set to active.
		// Return true to indicate success due to, already being set to that Id.
		return true;
	}
	
	// Check to see if:
	// The New Camera Id is greater then the maximum id
	// Or
	// The New Camera Id is less then 0.
	if ( (newCameraId > maxCameraId) || (newCameraId < 0) )
	{
		// If either are true then.
		// Error: Invalid ID sent.
		// Return false to indciate failure.
		return false;
	}

	// Otherwise we have a valid Id and we need to change the Id.
	
	// Indicate that a change of camera Id has occured.
	cameraUpdate = true;
	// Set the Id.
	cameraId = newCameraId;

	// Return true to indicate success.
	return true;
}
// !-End Custom-!