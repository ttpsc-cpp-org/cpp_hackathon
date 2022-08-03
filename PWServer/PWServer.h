#pragma once

#include <string>

class PWServer
{
private:

	const std::string INVENTORY_FILE_PATH = ".\\inventory.json";

public:
	PWServer() {}
	void Start();
};