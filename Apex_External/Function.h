#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <atlconv.h>

namespace Function {
	// ��ȡ����ID
	DWORD GetProcessID(const char* ProcessName);
}