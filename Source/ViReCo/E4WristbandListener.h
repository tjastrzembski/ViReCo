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
		FString serverAddress;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Server)
		int port;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		FString deviceID;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		FVector acc;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float bvp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float gsr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float hr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float ibi;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float tmp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float bat;

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

	bool ConnectToServer(void);
	bool ConnectToDevice(void);


	/*
	* Methods for the ConnectionSocket
	*/
	FString ReadMessage(void);

	bool SendMessageToServer(const FString&);

	bool IsConnected();

	void UpdateData(void);

private:
	class FSocket* Socket;
	FString LastMessage;
	bool deviceConnected;
};
