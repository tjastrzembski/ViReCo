// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WearableClient.h"
#include "Sockets.h"
#include "IPv4Address.h"

#include "E4WristbandClient.generated.h"

//#define DEBUG_E4 
#ifdef DEBUG_E4
DECLARE_LOG_CATEGORY_EXTERN(E4WristbandLogs, Log, All);
#endif
/**
*	E4WristbandClient
*
*	Class for communicating with E4Wristbands.
*/

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class VIRECO_API UE4WristbandClient : public UActorComponent, public IWearableClient
{
	GENERATED_BODY()

public:
	/**
	* Constructor
	*/
	UE4WristbandClient();
	~UE4WristbandClient();
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Server)
		FString serverAddress;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Server)
		int port;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableAcc;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableBvp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableGsr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableHr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableIbi;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableTmp;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		bool enableBat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = E4Wristband)
		FString deviceID;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		FVector acc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float bvp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float gsr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float hr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float ibi;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float tmp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = E4Wristband)
		float bat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = updateFrequence)
		float maxDeltaTime;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Called when this Component will be removed;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	* Inherited functions of IWearableClient
	*/
	virtual bool Connect(void);
	virtual void Disconnect(void);
	virtual bool IsConnected(void) const;
	virtual bool SendMessage(const FString& message);
	virtual bool ReadMessage(FString& message);
	virtual bool UpdateData(void);

	/**
	* Functions for better understanding
	*/
	bool ConnectToServer(void);
	bool ConnectToDevice(void);
	bool DisconnectFromDevice(void);
	bool DisconnectFromServer(void);
	bool Subscribe(const char* val);

	/**
	* Functions for blueprint usage
	*/
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateAcc();
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateBvp();
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateGsr();
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateHr();
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateIbi();
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateTmp();
	UFUNCTION(BlueprintCallable, Category = E4Wristband)
		void UpdateBat();
private:
	class FSocket* Socket;
	TArray<FString> data;
	bool deviceConnected;
	float currentDeltaTime;
};
