#include "PWException.h"

#include <cstdarg>
#include <cstdio>

PWException::PWException(const char* fmt, ...) : std::exception()
{
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(msg, sizeof(msg), fmt, ap);
	va_end(ap);
}

char const* PWException::what() const noexcept
{
	return msg;
}