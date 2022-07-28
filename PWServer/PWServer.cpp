// #include "stdafx.h"
#include "PWServer.h"
#include "PWInventory.h"
#include "PWInventory.h"
#include <PWConnectionHandlerFactory.h>
#include <PWServerSocket.h>
#include <PWException.h>

void PWServer::Start()
{
	try
	{
		//Init inventory
		std::unique_ptr<PWInventory> inventory = std::make_unique<PWInventory>();
		inventory->Load(INVENTORY_FILE_PATH);

		//Update the inventory
		inventory->UpdateQuality();

	}
	catch (const PWException& exp)
	{
		std::cout << exp.what();
	}
	
}
