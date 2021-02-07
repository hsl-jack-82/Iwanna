#include "Graph.h"
#define _CRT_SECURE_NO_WARNINGS
Graph::Graph(HWND hWnd)
{
	paint = new Paint(hWnd);
}

int fuckInt(char in)
{
	{
		switch (in)
		{
		case '0':
			return 0;
			break;
		case '1':
			return 1;
			break;
		case '2':
			return 2;
			break;
		case '3':
			return 3;
			break;
		case '4':
			return 4;
			break;
		case '5':
			return 5;
			break;
		case '6':
			return 6;
			break;
		case '7':
			return 7;
			break;
		case '/n':
			return 8;
			break;
		default:
		{
			
			return -1;
			break;
		}
		}
	}
}
