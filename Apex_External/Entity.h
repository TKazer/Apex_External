#pragma once
#include "Struct.h"
#include "BaseOffset.h"
#include "ApDriver.h"
#include "GameView.h"

class CEntity	// ��Ϸʵ����
{
public:
	DWORD64 Address = 0;	// ʵ���ַ
	int Health = 0;			// Ѫ��
	int	Team = -1;			// ��Ӫ
	Vec3 Pos{ 0,0,0 };		// ����
	Vec3 HeadPos{ 0,0,0 };	// ͷ������
	Vec2 HeadScreenPos{ -1,-1 };// ͷ����Ļ����
	std::string Name;		// ����
	int DyingState = 0;		// ����״̬

	// ��������
	bool Update(DWORD64 ObjAddress);
	// �Ƿ����
	bool IsVisible(float WorldTime);
private:
	// �Ƿ����
	bool GetDyingState();
	// ��ȡ����
	bool GetName();
	// ��ȡ����
	bool GetPos();
	// ��ȡͷ������
	bool GetHeadPos();
	// ��ȡѪ��
	bool GetHealth();
	// ��ȡ��Ӫ
	bool GetTeam();
	// ��ȡ��������
	int GetLifeState();
};