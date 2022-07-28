#pragma once

#include "PWBaseMessage.h"

class PWMessageSerializer
{
public:
	PWMessageSerializer() = delete;

	static std::string Serialize(const PWBaseMessage& request);
	static std::unique_ptr<PWBaseMessage> Deserialize(char * buff);
};
