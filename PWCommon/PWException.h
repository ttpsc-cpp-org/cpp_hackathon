#pragma once

#pragma comment(lib, "PWCommon.lib")

#include <exception>

#define EXP_MESSAGE_MAX_LENGTH 1000
class PWException : public std::exception
{
private:
	char msg[EXP_MESSAGE_MAX_LENGTH];

public:
	PWException(const char* fmt, ...);
	virtual char const* what() const;
};