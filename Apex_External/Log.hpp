#pragma once
#include <iostream>

template <typename... Args>
void Log(const char* pFormat, Args...args)
{
	int Length = std::snprintf(nullptr, 0, pFormat, args...);
	if (Length <= 0)
		return;
	char* Str = new char[Length + 1];
	std::snprintf(Str, Length + 1, pFormat, args...);
	std::cout << Str << std::endl;
	delete[] Str;
}
