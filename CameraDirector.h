// Fill out your copyright notice in the Description page of Project Settings.

/*
Author: 

	Cole Wheeler

Made for: 
	
	CS-425 team 27

Notes: 

	!-Begin Custom-! and !-End Custom-! are used to indicate where my code blocks begin and end from the pregenerated code.

How to use class:

	You will need to derive a Blueprint Actor from the class CameraDirector.
	Then place an instance of said CameraDirector in the world.

	You will then need to select camera actors as components.
	By default there are only two actors.

	You can add more by adding UPROPERTY AActors at the bottom of the Header file.
	You will also need to increase the maxCameraId by the sane amount: (<Number of AActors> - 1) Counts from zero.

	C++ Specific:

		Include "CameraDirector.h" in the cpp file you want to call the function from.
		Use "ACameraDirector::AdvanceCamera();" to call the function that will advance the player's view to the next camera.

	Blueprint Specific:

		Under the catagory "Camera" you can find the AdvanceCamera and ChangeToCameraId.
		You should be able to place the component and call both functions from Blueprint.

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
			- Class designation changed:
				from:	class CAMERATESTPROJECT_API ACameraDirector : public AActor
				to:		class BLUEPRINTTEST_API ACameraDirector : public AActor
				(Need the prefix to the "<project_name>_API")
				
	12/2/22: Added functionalities
	
		Updated:
			- Moved #include "Kismet/GameplayStatics.h" to header file from cpp file.
				
		Added:
			- cameraArray that will hold all camera pointers indexed by their corresponding ids
			- Additional AActor* Camera pointers.
			
			- Function: ChangeToCameraId
*/

#pragma once

// Required for APlayerController
#include "Kismet/GameplayStatics.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"

UCLASS()
class BLUEPRINTTEST_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


// !-Begin Custom-!
private:
	// Used to control whether the camera director will override the default camera at the start of the game.
	const bool intializeCamera = true;

	// Used to check if we need to update the camera's position.
	static inline bool cameraUpdate = false;
	
	// Used to change the cameras position.
	static inline unsigned short cameraId = 0;
	// Used to reset the Id if it increments past the maximum.
	static const unsigned short maxCameraId = 2;

	// Will store all camera ids for quick access.
	AActor* cameraArray [maxCameraId + 1];

public:
	// Called to increment cameraId.
	// UFUNCTION will allow blueprint components to call the function as well as C++ calls.

	// Will increment the variable cameraId and change the active camera to the next ided camera.
	UFUNCTION(BlueprintCallable, Category = "Camera")
	static void AdvanceCamera();

	// Will set the variable cameraId and change the active camera to the corresponding ided camera.
	UFUNCTION(BlueprintCallable, Category = "Camera")
	static bool ChangeToCameraId(int32 newCameraId);


	// Blueprint Camera components
	// Will be mapped to the default player pawn that is spawned when the game/level is run.
	AActor* Camera0;
	
	// All UPROPERTY Cameras will be mapped to existing entities such as enemies.
	UPROPERTY(EditAnywhere) AActor* Camera1;
	UPROPERTY(EditAnywhere) AActor* Camera2;
};
// !-End Custom-!