// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

namespace HsHttpModel
{
	/**
	 * UE4 HttpModel ��Ҫ����Ϸ�̳߳�ʼ�������̴߳����߲�����HttpManager
	 */
	class HSHTTP_API HsHttpClient
	{
	public:
		HsHttpClient();
		~HsHttpClient();

		void Post(const FString& Url,const FString& Body);
	};

}
