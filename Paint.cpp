#include "Paint.h"

Paint::Paint(HWND hWndIn)
{
	hWnd = hWndIn;
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hdc = BeginPaint(hWnd, &ps);
}

void Paint::SRectRGB(POINT point, RGB rgb)
{
	const int STANDARDLONG = 30;
	RECT rect = {
		point.x - STANDARDLONG,
		point.y,
		point.x,
		point.y - STANDARDLONG
	};
	FillRect(hdc, &rect, CreateSolidBrush(RGB(rgb.R,rgb.G, rgb.B)));
}

void Paint::standardRect(POINT point)
{
	const int STANDARDLONG = 30;
	RECT rect = {
		point.x - STANDARDLONG,
		point.y,
		point.x,
		point.y - STANDARDLONG
	};
	FillRect(hdc, &rect, hBrush);
}