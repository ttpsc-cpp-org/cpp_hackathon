#pragma once

#include "PWBaseMessage.h"

class PWMessageSerializationFactory
{
public:
	PWMessageSerializationFactory() = delete ;

	static std::unique_ptr<PWBaseMessage> Create(char * buff);
};
