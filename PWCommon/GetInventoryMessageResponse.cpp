#include "stdafx.h"
#include "stdafx.h"
#include "GetInventoryMessageResponse.h"

void InventoryItemInfo::ToJson(nlohmann::json& j) const
{
	j[ITEM_NAME] = name;
	j[ITEM_SELLBY] = sellBy;
	j[ITEM_VALUE] = value;
}

void InventoryItemInfo::FromJson(const nlohmann::json& j)
{
	name   = j[ITEM_NAME];
	sellBy = j[ITEM_SELLBY];
	value  = j[ITEM_VALUE];
}

std::string InventoryItemInfo::ToString() const
{
	std::stringstream itemStr;
	itemStr << "Name: \"" << name << "\", sellby: " << sellBy << ", value: " << value;
	return itemStr.str();
}

void GetInventoryMessageResponse::ToJson(nlohmann::json& j) const
{
	PWBaseResponse::ToJson(j);

	nlohmann::json inventoryJson;
	for (const auto& i : Items)
	{
		nlohmann::json itemJson;
		i.ToJson(itemJson);
		inventoryJson.push_back(itemJson);
	}

	j[ITEMS] = inventoryJson;
}

void GetInventoryMessageResponse::FromJson(const nlohmann::json& j)
{
	PWBaseResponse::FromJson(j);

	auto inventoryJson = j[ITEMS];
	for (const auto& itemJson : inventoryJson)
	{
		InventoryItemInfo inventoryItem;
		inventoryItem.FromJson(itemJson);
		Items.push_back(inventoryItem);
	}
}