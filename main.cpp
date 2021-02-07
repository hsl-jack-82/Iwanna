#include "Global.h"
#include "Paint.h"
#include "Graph.h"
#define _CRT_SECURE_NO_WARNINGS
LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	static TCHAR szWindowClass[] = ("DesktopApp");
	static TCHAR szTitle[] = ("Windows Desktop Guided Tour Application");
	WNDCLASSEX MainWindow = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		NULL,
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		szWindowClass,
		NULL,
	};
	if (!RegisterClassEx(&MainWindow))
	{
		MessageBox(NULL,
			("Call to RegisterClassEx failed!"),
			("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		900, 600,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
	{
		MessageBox(NULL,
			("Call to CreateWindow failed!"),
			("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}
	// The parameters to ShowWindow explained:
// hWnd: the value returned from CreateWindow
// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	switch (message)
	{
	case WM_PAINT:
	{
		Graph* g = new Graph(hWnd);
		Frame* f = new Frame;
		g->paintGraph(f);
		delete f;
		delete g;
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}