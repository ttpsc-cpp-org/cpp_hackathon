#include <iostream>

#include <PWServer.h>
#include <PWException.h>

int main()
{
	try
	{
		PWServer server;
		return server.Start();
	}
	catch (const PWException& exp)
	{
		std::cout << exp.what();
		return -1;
	}

    return 0;
}
