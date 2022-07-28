#pragma once
#include <string>
#include "PWBaseRequest.h"

class EchoMessageRequest : public PWBaseRequest
{
private:
	std::string msg;

public:
	EchoMessageRequest() : PWBaseRequest(PWMessageTypes::EchoRequest) {}
	EchoMessageRequest(std::string requestMsg) : EchoMessageRequest()
	{
		msg = requestMsg;
	}

	std::string GetMsgData() const { return msg; }

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};