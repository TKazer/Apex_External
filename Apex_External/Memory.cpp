#include "Memory.h"

void Memory::LightEsp(CEntity* Entity, float WorldTime,bool TeamMate)
{
	RGB Color;
	Driver.Write<int>(Entity->Address + 968, 1);
	if (!TeamMate)
	{
		bool IsVisible = Entity->IsVisible(WorldTime);
		if (Entity->DyingState != 0)
			Color = { 255,0,0 };		// ������ɫ
		else if (IsVisible)				
			Color = { 100,100,0 };		// ������ɫ
		else
			Color = { 0,250,100 };		// ��������ɫ
	}
	else
	{
		if (Entity->DyingState != 0)
			Color = { 255,0,0 };		// ���ѵ�����ɫ
		else
			Color = { 0,150,0 };		// ������ɫ
	}
	Driver.Write<RGB>(Entity->Address + 464, Color);
	for (int Offset = 904; Offset < 948; Offset += 4)
		Driver.Write<float>(Entity->Address + Offset, 999);
	Driver.Write<float>(Entity->Address + 704, 3);
}