#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <atlconv.h>

namespace Function {
	// 获取进程ID
	DWORD GetProcessID(const char* ProcessName);
}