#pragma once
#include <Windows.h>

class CGame
{
public:
	struct Process_
	{
		DWORD64 Exe_Module = 0;
		DWORD Pid = 0;
	}Process;
}*pGame;