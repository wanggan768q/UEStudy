// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace HsHttpModel
{
	/**
	 * UE4 HttpModel 需要在游戏线程初始化，多线程处理。高并发。HttpManager
	 */
	class HSHTTP_API HsHttpClient
	{
	public:
		HsHttpClient();
		~HsHttpClient();

		void Post(const FString& Url,const FString& Body);
	};

}
