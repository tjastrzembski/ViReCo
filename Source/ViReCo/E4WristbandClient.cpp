// Fill out your copyright notice in the Description page of Project Settings.

#include "E4WristbandClient.h"
#include "Runtime/Sockets/Public/SocketSubsystem.h"
#include "Engine.h"
#include "Networking.h"
#include "SocketSubsystem.h"
#include "BufferArchive.h"

#ifdef DEBUG_E4
DEFINE_LOG_CATEGORY(E4WristbandLogs)
#endif


// Sets default values for this component's properties
UE4WristbandClient::UE4WristbandClient()
	:Socket(nullptr),
	data(),
	serverAddress(FString("0.0.0.0")),
	port(0),
	deviceID(FString("")),
	deviceConnected(false),
	currentDeltaTime(.0f),
	maxDeltaTime(.0f),
	enableAcc(false),
	enableBvp(false),
	enableGsr(false),
	enableHr(false),
	enableIbi(false),
	enableTmp(false),
	enableBat(false)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

UE4WristbandClient::~UE4WristbandClient()
{
}

// Called when the game starts
void UE4WristbandClient::BeginPlay()
{
	Super::BeginPlay();

	Connect();
}

void UE4WristbandClient::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	FString str("device_disconnect \r\n");
	SendMessage(str);

	Disconnect();
}

// Called every frame
void UE4WristbandClient::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	currentDeltaTime += DeltaTime;
	if (currentDeltaTime > maxDeltaTime)
		if (deviceConnected)
		{
			UpdateData();
			currentDeltaTime = 0;
		}
		else
		{
			Connect();
		}
}


bool UE4WristbandClient::Connect(void)
{
	if (ConnectToServer())
	{
		deviceConnected = ConnectToDevice();
		return deviceConnected;
	}
	else
	{
		return false;
	}
}

void UE4WristbandClient::Disconnect(void)
{
	DisconnectFromDevice();
	DisconnectFromServer();
}

bool UE4WristbandClient::IsConnected(void) const
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

bool UE4WristbandClient::SendMessage(const FString& message)
{
	if (!IsConnected())
		return false;

	const TCHAR* RawMessage = message.GetCharArray().GetData();

	int32 Size = FCString::Strlen(RawMessage);
	int32 Sent = 0;

#ifdef DEBUG_E4
	UE_LOG(E4WristbandLogs, Log, TEXT("%s"), *message);
#endif
	return Socket->Send((uint8*)TCHAR_TO_UTF8(RawMessage), Size, Sent);
}

bool UE4WristbandClient::ReadMessage(FString& message)
{
	if (!IsConnected())
		return false;

	TArray<uint8> data;
	FBufferArchive archive;
	uint32 size;
	int32 read = 0;

	while (Socket->HasPendingData(size))
	{
		data.Init(FMath::Min(size, 65507u), size);

		Socket->Recv(data.GetData(), data.Num(), read);
		archive.Append(data);
	}

	if (archive.Num() <= 0)
	{
		message = FString("NoData");
#ifdef DEBUG_E4
		UE_LOG(E4WristbandLogs, Warning, TEXT("%s"), *message);
#endif
		return false;
	}

	message = FString::FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(archive.GetData())));

#ifdef DEBUG_E4
	UE_LOG(E4WristbandLogs, Log, TEXT("%s"), *message);
#endif
	return true;
}

bool UE4WristbandClient::UpdateData(void)
{
	FString message;
	if (!ReadMessage(message))
		return false;

	//Get values from socket and replace all ',' with '.' for float converting
	message = message.Replace(TEXT(","), TEXT("."), ESearchCase::CaseSensitive);

	//Split String
	message.ParseIntoArray(data, TEXT("\n"));
	return true;
}

bool UE4WristbandClient::ConnectToServer(void)
{
	if (IsConnected())
		Disconnect();

	Socket = FTcpSocketBuilder("E4WRISTBAND").AsBlocking().AsReusable().Build();

	bool valid = true;
	TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	Addr->SetIp(serverAddress.GetCharArray().GetData(), valid);
	Addr->SetPort(port);

#ifdef DEBUG_E4
	if (Socket->Connect(*Addr))
	{
		UE_LOG(E4WristbandLogs, Log, TEXT("Established Connection to %s:%d"), *serverAddress, port);
		return true;
	}
	UE_LOG(E4WristbandLogs, Error, TEXT("Failed to connect to %s:%d"), *serverAddress, port);
	return false;
#else
	return Socket->Connect(*Addr);
#endif
}

bool UE4WristbandClient::ConnectToDevice(void)
{
	FPlatformProcess::Sleep(0.2f);

	FString message = "device_connect " + deviceID + " \r\n";

#ifdef DEBUG_E4
	if (!SendMessage(message))
	{
		UE_LOG(E4WristbandLogs, Error, TEXT("SendMessage Failed to send :%s"), *message);
		return false;
	}
	UE_LOG(E4WristbandLogs, Log, TEXT("Send: %s"), *message);
#else
	if (!SendMessage(message))
		return false;
#endif

	FPlatformProcess::Sleep(0.3f);
	ReadMessage(message);

#ifdef DEBUG_E4
	UE_LOG(E4WristbandLogs, Log, TEXT("Received: %s"), *message);
	if (!message.Contains("R device_connect OK"))
	{
		UE_LOG(E4WristbandLogs, Error, TEXT("Failed to connect to device"));
		return false;
	}
#else 
	if (!message.Contains("R device_connect OK"))
		return false;
#endif

	if (enableAcc)
		while (!Subscribe("acc"));
	if (enableBvp)
		while (!Subscribe("bvp"));
	if (enableGsr)
		while (!Subscribe("gsr"));
	if (enableHr || enableIbi)
		while (!Subscribe("ibi"));
	if (enableTmp)
		while (!Subscribe("tmp"));
	if (enableBat)
		while (!Subscribe("bat"));

	return true;
}

bool UE4WristbandClient::DisconnectFromDevice(void)
{
	FString message("device_disconnect \r\n");
	SendMessage(message);
	FPlatformProcess::Sleep(0.2f);
	if (!message.Contains("R device_disconnect OK"))
		return false;

	deviceConnected = false;
	return true;
}

bool UE4WristbandClient::DisconnectFromServer(void)
{
	if (IsConnected())
		Socket->Close();

	delete Socket;
	Socket = nullptr;
	return true;
}

bool UE4WristbandClient::Subscribe(const char* val)
{
	FPlatformProcess::Sleep(0.3f);
	FString message = "device_subscribe " + FString(val) + " ON \r\n";
#ifdef DEBUG_E4
	UE_LOG(E4WristbandLogs, Log, TEXT("Received: %s"), *message);
	if (!SendMessage(message))
	{
		UE_LOG(E4WristbandLogs, Warning, TEXT("Failed to send subscription %s"), val);
		return false;
	}
	else
	{
		FPlatformProcess::Sleep(0.3f);
		ReadMessage(message);
		if (message.Contains("ERR"))
		{
			UE_LOG(E4WristbandLogs, Warning, TEXT("Failed to subscribe %s"), val);
			return false;
		}
	}
#else 
	if (!SendMessage(message))
		return false;
	else
	{
		FPlatformProcess::Sleep(0.3f);
		ReadMessage(message);
		if (message.Contains("ERR"))
			return false;
	}
#endif
	return true;
}

void UE4WristbandClient::UpdateAcc(void)
{
	for (FString item : data)
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
	}
}

void UE4WristbandClient::UpdateBvp(void)
{
	for (FString item : data)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));
		if (splitItem[0] == TEXT("E4_Bvp"))
		{
			bvp = FCString::Atof(*splitItem[2]);
		}
	}

}

void UE4WristbandClient::UpdateGsr(void)
{
	for (FString item : data)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));
		if (splitItem[0] == TEXT("E4_Gsr"))
		{
			gsr = FCString::Atof(*splitItem[2]);
		}
	}
}

void UE4WristbandClient::UpdateHr(void)
{
	for (FString item : data)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));
		if (splitItem[0] == TEXT("E4_Hr"))
		{
			hr = FCString::Atof(*splitItem[2]);
		}
	}
}
void UE4WristbandClient::UpdateIbi(void)
{
	for (FString item : data)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));
		if (splitItem[0] == TEXT("E4_Ibi"))
		{
			ibi = FCString::Atof(*splitItem[2]);
		}
	}
}

void UE4WristbandClient::UpdateTmp(void)
{
	for (FString item : data)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));
		if (splitItem[0] == TEXT("E4_Temperature"))
		{
			tmp = FCString::Atof(*splitItem[2]);
		}
	}
}

void UE4WristbandClient::UpdateBat(void)
{
	for (FString item : data)
	{
		//Split item
		TArray<FString>  splitItem;
		item.ParseIntoArray(splitItem, TEXT(" "));
		if (splitItem[0] == TEXT("E4_Battery"))
		{
			bat = FCString::Atof(*splitItem[2]);
		}
	}
}
