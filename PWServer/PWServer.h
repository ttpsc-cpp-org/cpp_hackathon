#pragma once

#include <string>

class PWServer
{
private:
	static const std::string INVENTORY_FILE_PATH;

public:
	PWServer() {}
	void Start();
};