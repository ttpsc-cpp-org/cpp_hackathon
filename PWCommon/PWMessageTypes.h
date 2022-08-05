#pragma once

#include <nlohmann/json.hpp>

enum PWMessageTypes
{
	EchoRequest = 0,
	EchoResponse,
	GetInvRequest,
	GetInventoryRequest,
	GetInventoryResponse,
};

enum PWResponseStatus
{
	Failure = -1,
	Success,
};

class PWSerializableMessage
{
public:

	virtual void ToJson(nlohmann::json& j) const = 0;
	virtual void FromJson(const nlohmann::json& j) = 0;
};
