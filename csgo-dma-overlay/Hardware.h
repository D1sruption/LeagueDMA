#pragma once

#include <iostream>
#include <vmmdll.h>

namespace Hardware
{
	BOOL sendmouse_rightclick(int x, int y);
	BOOL send_keyboard(UCHAR key, int delay);
	void move_mouse(HWND window, int endX, int endY, int stepCount, int stepDelay);
}