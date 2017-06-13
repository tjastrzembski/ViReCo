// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Networking.h"


#include "E4WristbandListener.generated.h"

/**
*	ViReCoE4WristbandListener
*
*	Class for communicating with E4Wristbands.
*/

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VIRECO_API UE4WristbandListener : public UActorComponent
{
	GENERATED_BODY()

public:
	/**
	* Constructor
	*/
	UE4WristbandListener();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Server)
	FString serverAdress;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Server)
	int port;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	/**
	* Method for connection
	*
	* @param serverAdress
	* Qparam port
	*/

	bool ConnectToServer(const FString& serverAddress, const uint32& port);


	/*
	* Methods for the ConnectionSocket
	*/
	FString ReadMessage(void);

	bool SendMessageToServer(const FString&);

	bool IsConnected();

private:
	class FSocket* Socket;
	FString LastMessage;
};
