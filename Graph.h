#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include "Global.h"
#include "Paint.h"
#pragma   warning(disable:4996)
int fuckInt(char in);
struct Frame
{
	int x = 30;
	int y = 20;
	int pic[30][20];
	/*
	Frame(int xlen, int ylen)
	{
		x = xlen;
		y = ylen;
		pic = new int*[x];
		for (int i = 0; i < y; i++)
		{
			pic[i] = new int[y];
		}
	}
	*/
	Frame()
	{
		FILE* file = fopen("a.txt", "r");
		if (file == nullptr)
		{

			perror("fail to read");
			exit(1);
		}
		char m = NULL;
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0;j < 20; j++)
			{
				m = ((char)fgetc(file));
				pic[i][j] = fuckInt(m);
			}
		}
		fclose(file);
	}
};
class Graph
{
private:
	Paint* paint;
public:
	Graph(HWND hWnd);
	~Graph()
	{
		delete paint;
	}
	void paintGraph(Frame *in)
	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				switch (in->pic[i][j])
				{
				case 1:
				{
					POINT point =
					{
						30 * (i + 1),
						30 * (j + 1)
					};
					paint->standardRect(point);
				}break;
				case 0:
				{
					POINT point =
					{
						30 * (i + 1),
						30 * (j + 1)
					};
					RGB r = {
						255,255,255
					};
					paint->SRectRGB(point, r);
				}
				default:
					break;
				}
			}
		}
	}
};

