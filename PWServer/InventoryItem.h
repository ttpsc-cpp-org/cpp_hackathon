#pragma once


class InventoryItem
{
public:
	InventoryItem() = default;
	std::string name;
	int sellBy;
	int value;
	InventoryItem(std::string name, int sellBy, int value) :
		name(name), sellBy(sellBy), value(value) {}
};