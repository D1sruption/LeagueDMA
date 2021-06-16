#include "RenderMain.h"
#include "GameObjectManager.h"
#include "Screen.h"

using namespace std;

int Width = 800;
int Height = 600;

const MARGINS Margin = { 0, 0, Width, Height };

char lWindowName[256] = "Basic Overlay - v0.1 - Credits: Grab";
HWND hWnd;

const char* tWindowName = "League of Legends (TM) Client"; /* tWindowName ? Target Window Name */
HWND tWnd;
RECT tSize;

MSG Message;

float g_posX;
float g_posY;

namespace RenderMain
{
	LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
	{
		switch (Message)
		{
		case WM_PAINT:
			Render();
			break;

		case WM_CREATE:
			DwmExtendFrameIntoClientArea(hWnd, &Margin);
			break;

		case WM_DESTROY:
			PostQuitMessage(1);
			return 0;

		default:
			return DefWindowProc(hWnd, Message, wParam, lParam);
			break;
		}
		return 0;
	}

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hSecInstance, LPSTR nCmdLine, INT nCmdShow)
	{

		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

		WNDCLASSEX wClass;
		wClass.cbClsExtra = NULL;
		wClass.cbSize = sizeof(WNDCLASSEX);
		wClass.cbWndExtra = NULL;
		wClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
		wClass.hCursor = LoadCursor(0, IDC_ARROW);
		wClass.hIcon = LoadIcon(0, IDI_APPLICATION);
		wClass.hIconSm = LoadIcon(0, IDI_APPLICATION);
		wClass.hInstance = hInstance;
		wClass.lpfnWndProc = WinProc;
		wClass.lpszClassName = (LPCSTR)lWindowName;
		wClass.lpszMenuName = (LPCSTR)lWindowName;
		wClass.style = CS_VREDRAW | CS_HREDRAW;

		if (!RegisterClassEx(&wClass))
			exit(1);

		tWnd = FindWindow(0, (LPCSTR)tWindowName);
		if (tWnd)
		{
			GetWindowRect(tWnd, &tSize);
			Width = tSize.right - tSize.left;
			Height = tSize.bottom - tSize.top;
			//hWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_LAYERED, (LPCSTR)lWindowName, (LPCSTR)lWindowName, WS_POPUP, 1, 1, Width, Height, 0, 0, 0, 0);
			hWnd = CreateWindowEx(WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_LAYERED, (LPCSTR)lWindowName, (LPCSTR)lWindowName, WS_POPUP, 1, 1, Width, Height, 0, 0, 0, 0);
			SetLayeredWindowAttributes(hWnd, 0, 1.0f, LWA_ALPHA);
			SetLayeredWindowAttributes(hWnd, 0, RGB(0, 0, 0), LWA_COLORKEY);
			ShowWindow(hWnd, SW_SHOW);
		}

		DirectXInit(hWnd);

		for (;;)
		{
			if (PeekMessage(&Message, hWnd, 0, 0, PM_REMOVE))
			{
				DispatchMessage(&Message);
				TranslateMessage(&Message);
			}
			Sleep(1);
		}
		return 0;
	}

	void SetWindowToTarget()
	{
		while (true)
		{
			tWnd = FindWindowA(0, (LPCSTR)tWindowName);
			if (tWnd)
			{
				GetWindowRect(tWnd, &tSize);
				Width = tSize.right - tSize.left;
				Height = tSize.bottom - tSize.top;
				DWORD dwStyle = GetWindowLong(tWnd, GWL_STYLE);
				if (dwStyle & WS_BORDER)
				{
					tSize.top += 23;
					Height -= 23;
				}
				MoveWindow(hWnd, tSize.left, tSize.top, Width, Height, true);
			}
			else
			{
				char ErrorMsg[125];
				sprintf(ErrorMsg, "Make sure %s is running!", tWindowName);
				MessageBox(0, (LPCSTR)ErrorMsg, "Error - Cannot find the game!", MB_OK | MB_ICONERROR);
				exit(1);
			}
			Sleep(100);
		}
	}
}