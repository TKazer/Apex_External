#pragma once
#include <windows.h>

namespace Offset
{
	const DWORD64 ViewRender = 0x7598658;		// �����ַ
	const DWORD64 ViewMatrix = 0x11A210;		// ����ƫ��
	const DWORD64 LocalPlayer = 0x1E24348;		// ���˵�ַ
	const DWORD64 cl_entitylist = 0x1A73F68;	// �����ַ
	const DWORD	  LocalYaw = 0x24E4;			// ����Yaw
	const DWORD   LocalPitch = 0x24E0;			// ����Pitch
	struct EntityData_
	{
		const DWORD m_Pos = 0x14C;					// ����
		const DWORD Bone = 0xED0;					// ����ƫ��
		const DWORD m_iTeamNum = 0x448;				// ��Ӫ
		const DWORD m_iSignifierName = 0x580;		// ����
		const DWORD m_lifeState = 0x798;			// ����״̬
		const DWORD m_bleedoutState = 0x2688;		// ����״̬
		const DWORD m_iHealth = 0x438;				// Ѫ��
		const DWORD m_vecPunchWeapon_Angle = 0x23F8;// ������Y
		const DWORD timeBase = 0x2050;				// ����ʱ��
		const DWORD lastVisibleTime = 0x1A44;		// ������ʱ��
	}EntityData;
}