#pragma once
#include "Global.h"
#define _CRT_SECURE_NO_WARNINGS
struct RGB
{
	int R;
	int G;
	int B;
};
class Paint
{
private:
	HWND hWnd;
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hBrush;
public:
	Paint(HWND hWnd);
	~Paint()
	{
		DeleteObject(hBrush);
		EndPaint(hWnd, &ps);
	}
	void standardRect(POINT point);
	void SRectRGB(POINT point, RGB rgb);
};

