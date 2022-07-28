#pragma once

#include "PWBaseMessage.h"

class PWBaseRequest : public PWBaseMessage
{
public:
	PWBaseRequest(PWMessageTypes msgType) : PWBaseMessage(msgType) {}

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};
