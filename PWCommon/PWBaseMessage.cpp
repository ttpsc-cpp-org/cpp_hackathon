#include "stdafx.h"
#include "PWBaseMessage.h"

void PWBaseMessage::ToJson(nlohmann::json& j) const
{
	j["type"] = type;
}

void PWBaseMessage::FromJson(const nlohmann::json& j)
{
	type = j["type"];
}
