#include "PWServer.h"
#include "PWInventory.h"

#include <iostream>
#include <PWException.h>

PWServer::PWServer(const std::string& invFile,
				  const std::string& outFile)
	: invFile(invFile),outFile(outFile)
{
}

void PWServer::Start()
{
	//Init inventory
	std::unique_ptr<PWInventory> inventory = std::make_unique<PWInventory>();
	inventory->Load(invFile);

	//Update the inventory
	inventory->UpdateQuality();

    // Store the inventory
	inventory->Save(outFile);
}
