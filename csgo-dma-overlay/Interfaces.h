#pragma once
#include "Utils.h"

extern DWORD g_pid;

extern VMMDLL_MAP_MODULEENTRY g_baseModule;
extern VMMDLL_MAP_MODULEENTRY g_stubModule;
extern DWORD g_dwRenderer;

namespace Interfaces
{
	// Used to initalise interfaces
	bool Init();
};