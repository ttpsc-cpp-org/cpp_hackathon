#pragma once

#include <string>

class PWServer
{
private:
	const std::string& invFile;
	const std::string& outFile;

public:
	PWServer(const std::string& invFile,const std::string& outFile);
	void Start();
};
