#include "stdafx.h"
#include "EchoMessageResponse.h"

void EchoMessageResponse::ToJson(nlohmann::json& j) const
{
	PWBaseResponse::ToJson(j);
	j["msg"] = msg;
}

void EchoMessageResponse::FromJson(const nlohmann::json& j)
{
	PWBaseResponse::FromJson(j);
	msg = j["msg"];
}