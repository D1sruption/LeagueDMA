#ifndef HMAIN_H
#define HMAIN_H

#include "hDirectX.h"
#include "GameObjectManager.h"

#include <Windows.h>
#include <iostream>

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

extern int Width;
extern int Height;
extern char lWindowName[256];
extern HWND hWnd;
extern const char* tWindowName;
extern HWND tWnd;
extern RECT tSize;
extern MSG Message;
extern bool Debug_Border;

extern float g_posX;
extern float g_posY;

namespace RenderMain
{
	LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow);
	void SetWindowToTarget();
}


#endif