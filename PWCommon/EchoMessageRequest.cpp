#include "EchoMessageRequest.h"
#include <nlohmann/json.hpp>

void EchoMessageRequest::ToJson(nlohmann::json& j) const
{
	PWBaseRequest::ToJson(j);
	j["msg"] = msg;
}

void EchoMessageRequest::FromJson(const nlohmann::json& j)
{
	PWBaseRequest::FromJson(j);
	msg = j["msg"];
}