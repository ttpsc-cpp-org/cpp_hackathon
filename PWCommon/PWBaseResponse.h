#pragma once

#include "PWBaseMessage.h"

class PWBaseResponse : public PWBaseMessage
{
private:
	PWResponseStatus status;

public:
	PWBaseResponse(PWMessageTypes msgType, PWResponseStatus msgStatus) : PWBaseMessage(msgType)
	{
		status = msgStatus;
	}

	PWBaseResponse(PWMessageTypes msgType) : PWBaseResponse(msgType, PWResponseStatus::Success) {}

	PWResponseStatus GetStatus() const { return status; }
	void SetStatus(PWResponseStatus newStatus) { status; }

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};
