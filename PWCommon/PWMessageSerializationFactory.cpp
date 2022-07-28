#include "stdafx.h"
#include "PWMessageSerializationFactory.h"
#include "EchoMessageRequest.h"
#include "EchoMessageResponse.h"
#include "GetInventoryMessageRequest.h"
#include "GetInventoryMessageResponse.h"

std::unique_ptr<PWBaseMessage> PWMessageSerializationFactory::Create(char * buff)
{
	//parse json
	auto decodeBuff = base64_decode(buff);
	auto json = nlohmann::json::parse(decodeBuff);

	//read type
	int type = json["type"];

	std::unique_ptr<PWBaseMessage> result;
	switch (type)
	{
	case PWMessageTypes::EchoRequest:
		result = std::make_unique<EchoMessageRequest>();
		break;
	case PWMessageTypes::EchoResponse:
		result = std::make_unique<EchoMessageResponse>();
		break;
	case PWMessageTypes::GetInventoryRequest:
		result = std::make_unique<GetInventoryMessageRequest>();
		break;
	case PWMessageTypes::GetInventoryResponse:
		result = std::make_unique<GetInventoryMessageResponse>();
		break;
	
	default:
		throw std::exception("Unknown request or response type");
	}

	result->FromJson(json);

	return result;
}