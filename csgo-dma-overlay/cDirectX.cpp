#include "hDirectX.h"
#include "Screen.h"
#include <string>
#include <thread>
#include <chrono>
using namespace std;

#define PIPE_NAME "\\\\.\\pipe\\LeagueDMA_IOCommProtocol"

IDirect3D9Ex* p_Object = 0;
IDirect3DDevice9Ex* p_Device = 0;
D3DPRESENT_PARAMETERS p_Params;

ID3DXLine* p_Line;
ID3DXFont* pFontSmall = 0;

int DirectXInit(HWND hWnd)
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(1);

	ZeroMemory(&p_Params, sizeof(p_Params));
	p_Params.Windowed = TRUE;
	p_Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
	p_Params.hDeviceWindow = hWnd;
	p_Params.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	p_Params.BackBufferFormat = D3DFMT_A8R8G8B8;
	p_Params.BackBufferWidth = Width;
	p_Params.BackBufferHeight = Height;
	p_Params.EnableAutoDepthStencil = TRUE;
	p_Params.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(p_Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &p_Params, 0, &p_Device)))
		exit(1);

	if (!p_Line)
		D3DXCreateLine(p_Device, &p_Line);
	//p_Line->SetAntialias(1); *removed cuz crosshair was blurred*

	D3DXCreateFontA(p_Device, 18, 0, 0, 0, false, DEFAULT_CHARSET, OUT_CHARACTER_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Calibri", &pFontSmall);

	return 0;
}

int Render()
{
	using clock = chrono::system_clock;
	using ms = chrono::duration<double, milli>;

	const auto before = clock::now();
	
	//cout << "Calling Renderer.." << endl;
	p_Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
	p_Device->BeginScene();


	if (tWnd == GetForegroundWindow())
	{
		//text with shadow
		//DrawShadowString((char*)"UnKnoWnCheaTs.me - Debug Overlay - by Grab", 5, 0, 240, 240, 250, pFontSmall);

		//text without shadow
		//Vector2 screen_bounds{ Screen::WorldToScreen(g_heroVector[0].GetPos()) };
		//DrawString((char*)"Hero", screen_bounds.X, screen_bounds.Y+20, 255, 0, 0, pFontSmall);
		//cout << screen_bounds.X << " | " << screen_bounds.Y << endl;
		//DrawString((char*)"Test Overlay", Screen::WorldToScreen(g_heroVector[0].GetPos()).X, Screen::WorldToScreen(g_heroVector[0].GetPos()).Y, 255, 0, 0, pFontSmall);


		for (int i = 0; i < g_minionVector.size(); i++)
		{
			Vector2 screen_bounds{ Screen::WorldToScreen(g_minionVector[i].GetPos()) };

			if (screen_bounds.X > 1920 || screen_bounds.Y > 1080 || screen_bounds.X == 0 && screen_bounds.Y == 0)
			{
				continue;
			}
			//DrawString((char*)"Minion", screen_bounds.X, screen_bounds.Y, 255, 0, 0, pFontSmall);

			if (g_minionVector[i].IsKillable(g_heroVector[0]) && g_minionVector[i].IsAlive())
			{
				DrawString((char*)"Killable", screen_bounds.X, screen_bounds.Y, 255, 0, 0, pFontSmall);
			}
		}

		//for (int i = 0; i < g_heroVector.size(); i++)
		//{
		//	Vector2 screen_bounds{ Screen::WorldToScreen(g_heroVector[i].GetPos()) };

		//	if (screen_bounds.X > 1920 || screen_bounds.Y > 1080 || screen_bounds.X == 0 && screen_bounds.Y == 0)
		//	{
		//		continue;
		//	}

		//	
		//	DrawString((char*)"Hero", screen_bounds.X, screen_bounds.Y, 255, 0, 0, pFontSmall);
		//}

		//colored rects
		//FillRGB(30, 40, 10, 10, 255, 0, 0, 155);
		//FillRGB(30, 60, 10, 10, 0, 255, 0, 155);
		//FillRGB(30, 80, 10, 10, 0, 0, 255, 155);

		//crosshair
		//FillRGB(Width / 2 - 22, Height / 2, 44, 1, 240, 240, 250, 255); 
		//FillRGB(Width / 2, Height / 2 - 22, 1, 44, 240, 240, 250, 255);
	}
	//else
	//{
	//	SetForegroundWindow(tWnd);
	//	SetFocus(tWnd);
	//	SetActiveWindow(tWnd);
	//}

	p_Device->EndScene();
	p_Device->PresentEx(0, 0, 0, 0, 0);

	const ms duration = clock::now() - before;

	cout << "Elapsed Time: " << duration.count() << endl;

	
	return 0;
}
