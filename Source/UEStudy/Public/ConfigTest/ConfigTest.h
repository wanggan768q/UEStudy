// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConfigTest.generated.h"

UCLASS(Config=Game)
class UESTUDY_API AConfigTest : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	float Fvalue;

	UPROPERTY(Config)
	TArray<uint32> FArrayValue;
	
public:	
	// Sets default values for this actor's properties
	AConfigTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool ZipCompress(const FString& InData, TArray<uint8>& OutData);
	bool ZipUncompress(const TArray<uint8>& InData, FString& OutJsonData);

};
