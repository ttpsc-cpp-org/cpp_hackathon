#pragma once

#include "PWBaseResponse.h"

class EchoMessageResponse : public PWBaseResponse
{
private:
	std::string msg;

public:
	EchoMessageResponse() : PWBaseResponse(PWMessageTypes::EchoResponse, PWResponseStatus::Success)
	{
	}

	EchoMessageResponse(std::string responseMsg, PWResponseStatus status) : PWBaseResponse(PWMessageTypes::EchoResponse, status)
	{
		msg = responseMsg;
	}

	std::string GetMsgData() const { return msg; }

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};