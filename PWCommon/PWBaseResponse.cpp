// #include "stdafx.h"
#include "PWBaseResponse.h"

void PWBaseResponse::ToJson(nlohmann::json& j) const
{
	PWBaseMessage::ToJson(j);
	j["status"] = status;
}

void PWBaseResponse::FromJson(const nlohmann::json& j)
{
	PWBaseMessage::FromJson(j);
	status = j["status"];
}
