// Fill out your copyright notice in the Description page of Project Settings.


#include "Client/HsHttpClient.h"

#include "Interfaces/IHttpRequest.h"

namespace HsHttpModel
{
	HsHttpClient::HsHttpClient()
	{
	}

	HsHttpClient::~HsHttpClient()
	{
	}

	void HsHttpClient::Post(const FString& Url, const FString& Body)
	{
		//TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	}

}
