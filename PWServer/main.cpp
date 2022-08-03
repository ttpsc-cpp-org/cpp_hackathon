#include <iostream>

#include <PWServer.h>
#include <PWException.h>

int main(int argc, char* argv[])
{
	static const std::string DEFAULT_INVENTORY_FILE_PATH(".\\inventory.json");

	try
	{
		std::string invFile;

		if (argc == 1)
		{
			invFile = DEFAULT_INVENTORY_FILE_PATH;
		}
		else if (argc == 2)
		{
			invFile = argv[1];
		}
		else
		{
			throw PWException("Invalid arguments given");
		}

		PWServer server(invFile);
		server.Start();
	}
	catch (const PWException& exp)
	{
		std::cout << exp.what();
		return -1;
	}

    return 0;
}
