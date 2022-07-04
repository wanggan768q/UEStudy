// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfigTest/ConfigTest.h"

#include "Misc/MemoryReadStream.h"
#include "Misc/CString.h"

// Sets default values
AConfigTest::AConfigTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GConfig->GetFloat(TEXT("/Script/UEStudy.ConfigTest"), TEXT("Fvalue"), this->Fvalue, FString::Printf(TEXT("%s%s"),*FPaths::ProjectConfigDir(),TEXT("DefaultEngine.ini")));
}

// Called when the game starts or when spawned
void AConfigTest::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("保存配置文件"));
	UE_LOG(LogTemp, Log, TEXT("GetDefaultConfigFilename %s"),*this->GetDefaultConfigFilename());
	UE_LOG(LogTemp, Log, TEXT("GetConfigOverridePlatform %s"), this->GetConfigOverridePlatform());
	SaveConfig();

	FString asd(TEXT("123阿萨德看了爱斯达克阿萨@#￥%……&*（）——+"));

	TArray<uint8> Out;
	FString Out2;

	ZipCompress(asd, Out);
	//UE_LOG(LogTemp, Log, TEXT("=%s"),*Out);

	ZipUncompress(Out, Out2);
	UE_LOG(LogTemp, Log, TEXT("Out2=%s"), *Out2);
	UE_LOG(LogTemp, Log, TEXT("保存配置文件"));
}

// Called every frame
void AConfigTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AConfigTest::ZipCompress(const FString& InData, TArray<uint8>& OutData)
{
	if (InData.Len() == 0)
	{
		return true;
	}
	//转成UTF8
	ANSICHAR* SrcTcharBuffer = TCHAR_TO_UTF8(*InData);
	uint32 SrcTcharBufferLen = TCString<ANSICHAR>::Strlen(SrcTcharBuffer);
	uint32 UncompressedSize = SrcTcharBufferLen + 1;
	
	const uint32 UintSize = sizeof(uint32);
	
	//压缩需要的最大字节数
	int CompressBufferLen = FCompression::CompressMemoryBound(NAME_Zlib, UncompressedSize);

	//分配内存大小
	const uint32 MallocSize = CompressBufferLen + UintSize;

	//压缩所需要的内存空间
	uint8* CompressBuffer = static_cast<uint8*>(FMemory::Malloc(MallocSize));

	FMemory::Memcpy(CompressBuffer,&UncompressedSize,UintSize);

	const bool success = FCompression::CompressMemory(NAME_Zlib, CompressBuffer + UintSize, CompressBufferLen, SrcTcharBuffer, UncompressedSize);

	OutData.Append(CompressBuffer,MallocSize);
	
	FMemory::Free(CompressBuffer);
	
	return  success;
}

bool AConfigTest::ZipUncompress(const TArray<uint8>& InData, FString& OutJsonData)
{
	if (InData.Num() == 0 )
	{
		return true;
	}
	const uint32 UintSize = sizeof(uint32);
	
	uint32 UncompressedSize = 0;
	FMemory::Memcpy(&UncompressedSize,InData.GetData(),UintSize);
	
	//解压所需要的内存空间	
	uint8* UncompressBuffer = static_cast<uint8*>(FMemory::Malloc(UncompressedSize));

	const bool success = FCompression::UncompressMemory(NAME_Zlib, UncompressBuffer,UncompressedSize,InData.GetData() + UintSize  , InData.Num() - UintSize);

	OutJsonData = FString(UTF8_TO_TCHAR(reinterpret_cast<ANSICHAR*>(UncompressBuffer)));
	
	FMemory::Free(UncompressBuffer);
	
	return success;
}

