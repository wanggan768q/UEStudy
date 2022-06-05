// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"


namespace HsHttpModel
{
	/**
	 *
	 */
	class HSHTTP_API HsHttpRequest : public IHttpRequest
	{
	public:
		HsHttpRequest();

		static TSharedRef<IHttpRequest> CreateRequest();
	};
}
