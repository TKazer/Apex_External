#pragma once
#include <windows.h>
#include <string>

class ApDriver
{
public:
	DWORD Pid = 0;
	bool Install(DWORD Pid)
	{
		this->Pid = Pid;
		return true;
	}
	bool Uninstall()
	{
		return true;
	}
	DWORD64 GetModuleAddress(std::string ModuleName)
	{
		return 0;
	}
	bool ReadBytes(DWORD64 Address, DWORD Size, byte*)
	{
		return true;
	}
	template <typename Type>
	Type Read(DWORD64 Address)
	{
		return Type{};
	}
	template <typename Type>
	bool Write(DWORD64 Address, Type Value)
	{
		return true;
	}
}Driver;