#pragma once

#include "PWBaseRequest.h"

class GetInventoryMessageRequest : public PWBaseRequest
{
private:
	std::string msg;

public:
	GetInventoryMessageRequest() : PWBaseRequest(PWMessageTypes::GetInventoryRequest) {}

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};