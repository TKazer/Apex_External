#include "Entity.h"
#include "GameData.h"
#include "Function.h"
#include "Memory.h"
#include "AimBot.hpp"
#include "Log.hpp"
#include <thread>

// @Liv QQ:1319923129

void MainLoop()
{
	Vec2 Sight{ (float)pView->WindowWidth / 2,(float)pView->WindowHeight / 2 };
	CEntity* LocalEntity = new CEntity;
	DWORD64  Module = pGame->Process.Exe_Module;

	while (true)
	{
		if (GetAsyncKeyState(VK_END))
		{
			break;
		}
		// 临时实体
		CEntity* Entity = nullptr;

		// 矩阵数据
		DWORD64 ViewRenderAddress = Driver.Read<DWORD64>(Module + Offset::ViewRender);
		DWORD64 MatrixAddress = Driver.Read<DWORD64>(ViewRenderAddress + Offset::ViewMatrix);
		pView->Matrix = Driver.Read<BaseMatrix>(MatrixAddress);

		// 本地数据
		DWORD64 LocalPlayerAddr = Driver.Read<DWORD64>(Module + Offset::LocalPlayer);
		float	WorldTime = Driver.Read<float>(LocalPlayerAddr + Offset::EntityData.timeBase);
		if (!LocalEntity->Update(LocalPlayerAddr))
			continue;

		// 自瞄数据
		CEntity AimEntity;
		float AimMaxDistance = 99999;
		float ToSightDistance = 0;

		for (int i = 0; i < 100; i++, delete Entity)
		{
			DWORD64 Address = Driver.Read<DWORD64>(Module + Offset::cl_entitylist + i * 32);
			Entity = new CEntity;
			if (!Entity->Update(Address))
				continue;
			if (Entity->Team == LocalEntity->Team)
				Memory::LightEsp(Entity, WorldTime, true);
			else
				Memory::LightEsp(Entity, WorldTime, false);

			if (Entity->Team != LocalEntity->Team)
			{
				if (!Entity->IsVisible(WorldTime))
					continue;
				if (Entity->HeadScreenPos <= 0)
					continue;

				ToSightDistance = sqrt(pow(Entity->HeadScreenPos.x - Sight.x, 2) + pow(Entity->HeadScreenPos.y - Sight.y, 2));
				if (ToSightDistance < AimControl::AimRange && ToSightDistance < AimMaxDistance)
				{
					AimMaxDistance = ToSightDistance;
					AimEntity = *Entity;
				}
			}
		}
		
		if (GetAsyncKeyState(VK_CAPITAL))
		{
			AimControl::Aim(LocalEntity, &AimEntity);
		}

	}
	delete LocalEntity;
	return;
}

int main()
{
	pGame = new CGame;
	pGame->Process.Pid = Function::GetProcessID("r5apex.exe");
	HWND hWnd = FindWindowA(NULL, "Apex Legends");

	if (pGame->Process.Pid == 0)
	{
		std::cout << "Get \"r5apex.exe\" process-id failed." << std::endl;
		system("pause");
		return 0;
	}

	if (hWnd == 0)
	{
		std::cout << "Find \"Apex Legends\" window failed." << std::endl;
		system("pause");
		return 0;
	}
	pView = new CView(hWnd);

	if (!Driver.Install(pGame->Process.Pid))
	{
		std::cout << "Driver installed failed." << std::endl;
		system("pause");
		return 0;
	}
	std::cout << "Driver installed succeed." << std::endl;

	pGame->Process.Exe_Module = Driver.GetModuleAddress("r5apex.exe");

	Log("hWnd:%d", hWnd);
	Log("Pid:%d", pGame->Process.Pid);
	Log("Exe:%llX", pGame->Process.Exe_Module);

	std::cout << "Runing..." << std::endl;

	std::thread Thread(MainLoop);
	Thread.join();

	std::cout << "Stopping..." << std::endl;
	delete pGame;
	delete pView;
	Driver.Uninstall();
	std::cout << "Driver uninstalled succeed." << std::endl;
	system("pause");
	return 0;
}