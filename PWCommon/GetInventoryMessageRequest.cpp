#include "stdafx.h"
#include "GetInventoryMessageRequest.h"

void GetInventoryMessageRequest::ToJson(nlohmann::json& j) const
{
	PWBaseRequest::ToJson(j);
}

void GetInventoryMessageRequest::FromJson(const nlohmann::json& j)
{
	PWBaseRequest::FromJson(j);
}