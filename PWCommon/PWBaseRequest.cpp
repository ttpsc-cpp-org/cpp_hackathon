#include "stdafx.h"
#include "PWBaseRequest.h"

void PWBaseRequest::ToJson(nlohmann::json& j) const
{
	PWBaseMessage::ToJson(j);
}

void PWBaseRequest::FromJson(const nlohmann::json& j)
{
	PWBaseMessage::FromJson(j);
}
