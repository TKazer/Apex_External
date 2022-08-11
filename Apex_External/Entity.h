#pragma once
#include "Struct.h"
#include "BaseOffset.h"
#include "ApDriver.h"
#include "GameView.h"

class CEntity	// 游戏实体类
{
public:
	DWORD64 Address = 0;	// 实体地址
	int Health = 0;			// 血量
	int	Team = -1;			// 阵营
	Vec3 Pos{ 0,0,0 };		// 坐标
	Vec3 HeadPos{ 0,0,0 };	// 头部坐标
	Vec2 HeadScreenPos{ -1,-1 };// 头部屏幕坐标
	std::string Name;		// 类名
	int DyingState = 0;		// 濒死状态

	// 更新数据
	bool Update(DWORD64 ObjAddress);
	// 是否可视
	bool IsVisible(float WorldTime);
private:
	// 是否濒死
	bool GetDyingState();
	// 获取类名
	bool GetName();
	// 获取坐标
	bool GetPos();
	// 获取头部坐标
	bool GetHeadPos();
	// 获取血量
	bool GetHealth();
	// 获取阵营
	bool GetTeam();
	// 获取生命周期
	int GetLifeState();
};