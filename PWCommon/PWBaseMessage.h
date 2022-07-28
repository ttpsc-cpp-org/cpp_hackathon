#pragma once

#include "PWMessageTypes.h"

class PWBaseMessage : public PWSerializableMessage
{
protected:

	PWMessageTypes type;

public:

	PWBaseMessage(PWMessageTypes msgType) : type(msgType) {}
	PWMessageTypes GetType() const { return type; }

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};
