// Fill out your copyright notice in the Description page of Project Settings.

/*
Author: 

	Cole Wheeler

Made for: 
	
	CS-425 team 27

Description:

	This class will implement a series of functions that allow the team to setup a series of cameras and set them to the active camera for the player.

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

		Under the catagory "Camera" you can find the AdvanceCamera.
		You should be able to place the component and call AdvanceCamera from Blueprint. (Untested)

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

	12/6/22: Added functionalities

		Updated:
			- Changed maxCameraId to non-constant so it can be used across multiple levels.
			- Reorganized UPROPERTIES for better readability.
				Added indentation if multi-line command.

			- Changed the category of the UFUNCTIONs to "Camera Director" from "Camera" for easier searches in Unreal Editor.

			- Changed intializeCamera to a non-constant blueprint exposed variable

		Added:
			- MaxPossibleCameraId as a static constant.
				Used for error checking and static array creation

			- UPROPERTY BP_maxCameraId to store the number of cameras linked in the editor.
				Used so that a non-static variable will be storing each value for the active camera director on the given level.

			- More Camera# AActor variables to store up the maximum number of camera actors.
				Note: Will need to be expanded if we require more cameras in a given level.

			- Comments for each UPROPERTY so they can be read in the Unreal Editor with concise detail.

			- BF_defaultId will control the default camera that will be set to active on the start of the game if intializeCamera is set to true.
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
	
	// Used to store the maxCameraId value that can be accessed in static functions.
	static inline unsigned short maxCameraId;

	// Used to initialize the camera array and error check for invalid camera number selection during BeginPlay.
	static const unsigned short MaxPossibleCameraId = 9;

	// Will store all camera ids for quick access.
	AActor* cameraArray[MaxPossibleCameraId + 1];
		

	// Used to check if we need to update the camera's position.
	static inline bool cameraUpdate = false;
	
	// Used to change the cameras position.
	static inline unsigned short cameraId = 0;

public:
	// Called to increment cameraId.
	// UFUNCTION will allow blueprint components to call the function as well as C++ calls.

	// Will increment the variable cameraId and change the active camera to the next ided camera.
	UFUNCTION(BlueprintCallable, Category = "Camera Director")
		static void AdvanceCamera();

	// Will set the variable cameraId and change the active camera to the corresponding ided camera.
	UFUNCTION(BlueprintCallable, Category = "Camera Director")
		static bool ChangeToCameraId(int32 newCameraId);

	// Blueprint Variable
	// Used to reset the Id if it increments past the maximum.
	// Used to indicate the number of custom mapped cameras.

	// Used to control whether the camera director will override the default camera at the start of the game.
	// True => Set default active camera to the defaultId camera.
	// False => Do not override the default camera upon BeginPlay.
	UPROPERTY(EditAnywhere)
		bool intializeCamera = true;

	// Set this value equal to the camera you want to be active at the start of play.
	// Value Range: [0,9] (Inclusive set).
	UPROPERTY(EditAnywhere)
		int BP_defaultId = 0;

	// Set this value equal to last camera's id value.
	// Camera3 => BP Max Camera Id = 3
	UPROPERTY(EditAnywhere)
		int BP_maxCameraId = 0;

	// Blueprint Camera components
	// Will be mapped to the default player pawn that is spawned when the game/level is run.
	AActor* Camera0;
	
	// All UPROPERTY Cameras will be mapped to existing entities such as enemies.
	// Note: These repeated comments are meant for readability in blueprint.

	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera1;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera2;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera3;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera4;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera5;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera6;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera7;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera8;
	// Map to an actor/character that has a default camera component.
	UPROPERTY(EditAnywhere) 
		AActor* Camera9;
};
// !-End Custom-!
