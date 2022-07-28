#pragma once
#include "stdafx.h"
#include "PWBaseResponse.h"

class InventoryItemInfo : PWSerializableMessage
{
private:
	const std::string ITEM_NAME = "name";
	const std::string ITEM_SELLBY = "sellBy";
	const std::string ITEM_VALUE = "value";

public:

	std::string name;
	int sellBy;
	int value;

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
	
	InventoryItemInfo() {}
	InventoryItemInfo(std::string name, int sellBy, int value) :
		name(name), sellBy(sellBy), value(value) {}
	std::string ToString() const;
};

class GetInventoryMessageResponse : public PWBaseResponse
{

private:
	const std::string ITEMS = "Items";

public:
	GetInventoryMessageResponse() : PWBaseResponse(PWMessageTypes::GetInventoryResponse, PWResponseStatus::Success)
	{
	}

	GetInventoryMessageResponse(PWResponseStatus status) : PWBaseResponse(PWMessageTypes::EchoResponse, status)
	{
	}

	std::vector<InventoryItemInfo> Items;

	void ToJson(nlohmann::json& j) const override;
	void FromJson(const nlohmann::json& j) override;
};