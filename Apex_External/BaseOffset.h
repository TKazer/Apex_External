#pragma once
#include <windows.h>

namespace Offset
{
	const DWORD64 ViewRender = 0x7598658;		// 矩阵地址
	const DWORD64 ViewMatrix = 0x11A210;		// 矩阵偏移
	const DWORD64 LocalPlayer = 0x1E24348;		// 本人地址
	const DWORD64 cl_entitylist = 0x1A73F68;	// 数组地址
	const DWORD	  LocalYaw = 0x24E4;			// 本地Yaw
	const DWORD   LocalPitch = 0x24E0;			// 本地Pitch
	struct EntityData_
	{
		const DWORD m_Pos = 0x14C;					// 坐标
		const DWORD Bone = 0xED0;					// 骨骼偏移
		const DWORD m_iTeamNum = 0x448;				// 阵营
		const DWORD m_iSignifierName = 0x580;		// 类名
		const DWORD m_lifeState = 0x798;			// 生命状态
		const DWORD m_bleedoutState = 0x2688;		// 倒地状态
		const DWORD m_iHealth = 0x438;				// 血量
		const DWORD m_vecPunchWeapon_Angle = 0x23F8;// 后坐力Y
		const DWORD timeBase = 0x2050;				// 世界时间
		const DWORD lastVisibleTime = 0x1A44;		// 最后可视时间
	}EntityData;
}