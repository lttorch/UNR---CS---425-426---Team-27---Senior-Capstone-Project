// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"

// Required for APlayerController
#include "Kismet/GameplayStatics.h"

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
	// If the initializeCamera constant is set to true, then we will override whatever the default camera is.
	if (intializeCamera)
	{
		// Used to set the camera to the first position at the start of the game.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		OurPlayerController->SetViewTarget(Camera0);
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
		// !-Taken from tutorial-!
		//Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		// !-End of tutorial code-!

		// Reset the cameraUpdate bool to indicate that the change has been handled.
		cameraUpdate = false;
		
		// Compare the Ids against the repsective camera.
		// Once we find the camera, assign it as the current camera.
		if (cameraId == 0)
		{
			OurPlayerController->SetViewTarget(Camera0);
		}
		else if (cameraId == 1)
		{
			OurPlayerController->SetViewTarget(Camera1);
		}
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
// !-End Custom-!