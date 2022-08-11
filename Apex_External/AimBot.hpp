#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "BaseOffset.h"
#include "Entity.h"

namespace AimControl
{
	static float AimRange = 150;		// 自瞄范围
	static float AimRate = 0.04;		// 自瞄速率
	static float Recoil = 1.02;			// 后坐力参数

	Vec2 SmoothCalc(Vec2 CurrentAngle, Vec2 AimAngle, float AimRate)
	{
		Vec2 Result;
		if (CurrentAngle.x != AimAngle.x)
		{
			if (CurrentAngle.x > AimAngle.x)
				Result.x = CurrentAngle.x - AimAngle.x;
			else
				Result.x = AimAngle.x - CurrentAngle.x;
			Result.x = Result.x * AimRate;
			if (CurrentAngle.x < AimAngle.x)
				Result.x = CurrentAngle.x + Result.x;
			if (CurrentAngle.x > AimAngle.x)
				Result.x = CurrentAngle.x - Result.x;
		}
		else
			Result.x = AimAngle.x;

		if (CurrentAngle.y != AimAngle.y)
		{
			if (CurrentAngle.y > AimAngle.y)
				Result.y = CurrentAngle.y - AimAngle.y;
			else
				Result.y = AimAngle.y - CurrentAngle.y;
			Result.y = Result.y * AimRate;
			if (CurrentAngle.y < AimAngle.y)
				Result.y = CurrentAngle.y + Result.y;
			if (CurrentAngle.y > AimAngle.y)
				Result.y = CurrentAngle.y - Result.y;
		}
		else
			Result.y = AimAngle.y;

		if (abs(Result.x - CurrentAngle.x) > 30)
			return AimAngle;
		return Result;
	}

	void Aim(CEntity* LocalEntity, CEntity* AimEntity)
	{
		if (AimEntity->Address == 0)
			return;

		Vec3 OppPos;
		OppPos.x = AimEntity->HeadPos.x - LocalEntity->HeadPos.x;
		OppPos.y = AimEntity->HeadPos.y - LocalEntity->HeadPos.y;
		OppPos.z = AimEntity->HeadPos.z - LocalEntity->HeadPos.z;

		Vec2 CurrentAngle;
		CurrentAngle.x = Driver.Read<float>(LocalEntity->Address + Offset::LocalYaw);
		CurrentAngle.y = Driver.Read<float>(LocalEntity->Address + Offset::LocalPitch);

		Vec2 PunchWeaponAngle;
		PunchWeaponAngle.x = Driver.Read<float>(LocalEntity->Address + Offset::EntityData.m_vecPunchWeapon_Angle + 4);
		PunchWeaponAngle.y = Driver.Read<float>(LocalEntity->Address + Offset::EntityData.m_vecPunchWeapon_Angle);

		Vec2 AimAngle;
		AimAngle.x = atan2f(OppPos.y, OppPos.x) * 180 / M_PI;
		AimAngle.y = -atan2f(OppPos.z, (sqrt(pow(OppPos.x, 2) + pow(OppPos.y, 2)))) * 180 / M_PI;
		AimAngle.x -= PunchWeaponAngle.x * Recoil;
		AimAngle.y -= PunchWeaponAngle.y * Recoil;

		Vec2 SmoothAngle;
		SmoothAngle = SmoothCalc(CurrentAngle, AimAngle, AimRate);

		Driver.Write<float>(LocalEntity->Address + Offset::LocalYaw, SmoothAngle.x);
		Driver.Write<float>(LocalEntity->Address + Offset::LocalPitch, SmoothAngle.y);
	}
}