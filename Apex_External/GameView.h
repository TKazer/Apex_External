#pragma once
#include <Windows.h>
#include "Struct.h"

class CView // ��Ϸ��ͼ��
{
public:
	CView(){};
	CView(HWND hWnd);
	BaseMatrix Matrix;
	int WindowWidth = 0, WindowHeight = 0;
	bool WorldToScreen(const Vec3& Pos, Vec2& ToPos);
}*pView;