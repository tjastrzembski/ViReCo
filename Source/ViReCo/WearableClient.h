// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WearableClient.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWearableClient : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VIRECO_API IWearableClient
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
protected:
	virtual bool Connect(void) = 0;
	virtual void Disconnect(void) = 0;
	virtual bool IsConnected(void) const = 0;
	virtual bool SendMessage(const FString& message) = 0;
	virtual bool ReadMessage(FString& message) = 0;
	virtual bool UpdateData(void) = 0;
};
