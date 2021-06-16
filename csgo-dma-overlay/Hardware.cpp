#include "includes.h"

namespace Hardware
{
	BOOL sendmouse_rightclick(int x, int y)
	{
		printf("\nSending RIGHT_CLICK at coordinate: %lu, %lu", x, y);

		INPUT input = { 0 };

		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		::SendInput(1, &input, sizeof(INPUT));

		::ZeroMemory(&input, sizeof(INPUT));
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		::SendInput(1, &input, sizeof(INPUT));

		return true;
	}

	BOOL send_keyboard(UCHAR key, int delay)
	{
		Sleep(delay);
		printf("Sending 0x%x Keyboard command...", key);

		// Set up a generic keyboard event.
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC); // hardware scan code for key
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		// Press the "..." key
		ip.ki.wVk = key; // virtual-key code for the "a" key
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		return true;
	}

	void move_mouse(HWND window, int endX, int endY, int stepCount, int stepDelay)
	{
		POINT point;
		BOOL result = GetCursorPos(&point);
		UCHAR keycode = 0x58; // 'x' key - bound in game to 'Player attack move click'

		int x, y;

		if (result)
		{
			printf("\nReceived current cursor coordinates: %lu, %lu\n", point.x, point.y);

			for (int step = 0; step < stepCount; step++)
			{
				int current_x = point.x + (endX - point.x) * step / stepCount;
				int current_y = point.y + (endY - point.y) * step / stepCount;
				x = current_x;
				y = current_y;

				printf("Setting cursor coordinates: %lu, %lu\n", current_x, current_y);
				SetCursorPos(current_x, current_y);

				Sleep(stepDelay);
			}

			//send_keyboard(keycode, 500);
		}
	}
}