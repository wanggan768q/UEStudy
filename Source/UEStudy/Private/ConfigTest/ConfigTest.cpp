// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfigTest/ConfigTest.h"

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
}

// Called every frame
void AConfigTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

