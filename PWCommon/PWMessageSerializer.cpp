#include "stdafx.h"
#include "PWMessageSerializer.h"
#include "PWBaseMessage.h"
#include "PWMessageSerializationFactory.h"

std::string PWMessageSerializer::Serialize(const PWBaseMessage& request)
{
	nlohmann::json reqJson;
	request.ToJson(reqJson);
	std::string json = reqJson.dump();
	return base64_encode((BYTE*)&json[0], json.size());
}

std::unique_ptr<PWBaseMessage> PWMessageSerializer::Deserialize(char * buff)
{
	return PWMessageSerializationFactory::Create(buff);
}