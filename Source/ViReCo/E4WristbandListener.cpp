// Fill out your copyright notice in the Description page of Project Settings.

#include "E4WristbandListener.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Engine.h"
//#include "Runtime/Networking/Public/Common/TcpSocketBuilder.h"



// Sets default values for this component's properties
UE4WristbandListener::UE4WristbandListener() :Socket(nullptr)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UE4WristbandListener::BeginPlay()
{
	Super::BeginPlay();
	if (ConnectToServer())
		deviceConnected = ConnectToDevice();
	else
		deviceConnected = false;


	// ...


}


// Called every frame
void UE4WristbandListener::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if (Socket->GetConnectionState() == ESocketConnectionState::SCS_Connected)
	if (deviceConnected)
	{
		UpdateData();
	}
	else
	{

	}
	auto answer = ReadMessage();
	//"server_status"
		// ...
}

bool UE4WristbandListener::ConnectToServer(void)
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
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FString("Connection failed!!!") + serverAddress + ":" + FString::FromInt(port));
	return connected;
}

bool UE4WristbandListener::ConnectToDevice(void)
{
	FPlatformProcess::Sleep(0.2f);

	FString str = FString::FString("device_connect ") + deviceID + FString::FString("\r");
	if (!SendMessageToServer(str))
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FString("SendMessage Failed!! ") + str);
	
	FPlatformProcess::Sleep(0.2f);

	str = ReadMessage();
	if (!str.Contains("device_connect OK"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FString("Connection to device failed!!!") + str );
		return false;
	}
	const char* E4Values[] = { "acc","bvp","gsr","hr","ibi","tmp","bat" };

	for (const char* val : E4Values)
	{
		str = FString::FString("device_subscribe ") + FString::FString(val) + FString::FString(" ON");
		SendMessageToServer(str);
	}
	return true;
}

FString UE4WristbandListener::ReadMessage()
{
	if (!IsConnected())
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Not connected");

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

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, message);

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

void UE4WristbandListener::UpdateData(void)
{
	//Get values from socket and replace all ',' with '.' for float converting
	FString data = ReadMessage().Replace(TEXT(","), TEXT("."), ESearchCase::CaseSensitive);

	//Split String
	TArray<FString> dataArr;
	data.ParseIntoArray(dataArr, TEXT("\n"));

	//Test Flag
	for (FString item : dataArr)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));

		if (splitItem[0] == TEXT("E4_Acc"))
		{
			acc[0] = FCString::Atof(*splitItem[2]);
			acc[1] = FCString::Atof(*splitItem[3]);
			acc[2] = FCString::Atof(*splitItem[4]);
		}
		else if (splitItem[0] == TEXT("E4_Bvp"))
		{
			bvp = FCString::Atof(*splitItem[2]);
		}
		else if (splitItem[0] == TEXT("E4_Gsr"))
		{
			gsr = FCString::Atof(*splitItem[2]);
		}
		else if (splitItem[0] == TEXT("E4_Hr"))
		{
			hr = FCString::Atof(*splitItem[2]);
		}
		else if (splitItem[0] == TEXT("E4_Ibi"))
		{
			ibi = FCString::Atof(*splitItem[2]);
		}
		else if (splitItem[0] == TEXT("E4_Temperature"))
		{
			tmp = FCString::Atof(*splitItem[2]);
		}
		else if (splitItem[0] == TEXT("E4_Battery"))
		{
			bat = FCString::Atof(*splitItem[2]);
		}
	}
}


