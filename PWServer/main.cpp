#include <iostream>
#include <PWException.h>

#include "PWInventory.h"

const std::string INVENTORY_FILE_PATH = ".\\inventory.json";

int main()
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
		return -1;
	}

    return 0;
}
