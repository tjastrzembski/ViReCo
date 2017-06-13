// Fill out your copyright notice in the Description page of Project Settings.

#include "E4WristbandListener.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
//#include "Runtime/Networking/Public/Common/TcpSocketBuilder.h"



// Sets default values for this component's properties
UE4WristbandListener::UE4WristbandListener() :Socket(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	ConnectToServer(TEXT("127.0.0.1"), 28000);
}


// Called when the game starts
void UE4WristbandListener::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UE4WristbandListener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected)
	{
		//SendMessageToServer(command);
	}
	else {
		ConnectToServer(TEXT("127.0.0.1"), 28000);
		//SendMessageToServer(command);	
	}
	auto answer = ReadMessage();
	//"server_status"
		// ...
}

bool UE4WristbandListener::ConnectToServer(const FString &serverAddress, const uint32 &port)
{
	FString serialized = serverAddress;
	TCHAR * serializedChar = serialized.GetCharArray().GetData();
	bool valid = true;

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("default"), false);
	class TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(serializedChar, valid);
	addr->SetPort(port);

	bool connected = Socket->Connect(*addr);

	if (connected)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FString("Connection successful!!!"));

	return connected;
}

FString UE4WristbandListener::ReadMessage()
{

	TArray<uint8> Data;

	uint32 Size;

	while (Socket->HasPendingData(Size))
	{
		Data.Init(FMath::Min(Size, 65507u), Size);

		int32 Read = 0;
		Socket->Recv(Data.GetData(), Data.Num(), Read);
	}

	if (Data.Num() <= 0)
	{
		return "NoData";
	}

	FString message(ANSI_TO_TCHAR(reinterpret_cast<const char*>(Data.GetData())));

	return message;
}

bool UE4WristbandListener::SendMessageToServer(const FString &message)
{
	FString serialized = message;
	TCHAR * serializedChar = serialized.GetCharArray().GetData();

	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, message);

	bool successful = Socket->Send((uint8*)TCHAR_TO_UTF8(serializedChar), size, sent);

	return successful;
}

bool UE4WristbandListener::IsConnected()
{
	if (Socket == nullptr)
	{
		return false;
	}
	else
	{
		return (Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected);
	}

}


