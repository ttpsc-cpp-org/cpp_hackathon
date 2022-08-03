#include "PWServer.h"
#include "PWInventory.h"

#include <iostream>
#include <PWException.h>

const std::string PWServer::INVENTORY_FILE_PATH(".\\inventory.json");

void PWServer::Start()
{
	//Init inventory
	std::unique_ptr<PWInventory> inventory = std::make_unique<PWInventory>();
	inventory->Load(INVENTORY_FILE_PATH);

	//Update the inventory
	inventory->UpdateQuality();	
}
