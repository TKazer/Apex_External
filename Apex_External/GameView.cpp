#include "GameView.h"

CView::CView(HWND hWnd)
{
	if (hWnd == NULL)
		return;
	RECT WindowRect;
	if (GetClientRect(hWnd, &WindowRect))
	{
		this->WindowWidth = WindowRect.right;
		this->WindowHeight = WindowRect.bottom;
	}
}

bool CView::WorldToScreen(const Vec3& Pos, Vec2& ToPos)
{
	if (this->WindowHeight == 0 || this->WindowWidth == 0)
		return false;
	float View, SightX = this->WindowWidth / 2, SightY = this->WindowHeight / 2;
	View = Matrix.at[3][0] * Pos.x + Matrix.at[3][1] * Pos.y + Matrix.at[3][2] * Pos.z + Matrix.at[3][3];
	if (View <= 0.01)
		return false;
	ToPos.x = SightX + (Matrix.at[0][0] * Pos.x + Matrix.at[0][1] * Pos.y + Matrix.at[0][2] * Pos.z + Matrix.at[0][3]) / View * SightX;
	ToPos.y = SightY - (Matrix.at[1][0] * Pos.x + Matrix.at[1][1] * Pos.y + Matrix.at[1][2] * Pos.z + Matrix.at[1][3]) / View * SightY;
	return true;
}