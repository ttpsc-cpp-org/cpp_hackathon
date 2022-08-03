#pragma once

#include <string>

class PWServer
{
private:
	const std::string& invFile;

public:
	PWServer(const std::string& invFile);
	void Start();
};
