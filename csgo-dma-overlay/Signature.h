#pragma once

#include <Windows.h>
#include <iostream>

namespace Signature
{
	bool GetSignatures(DWORD pid, ModuleDump module, VMMDLL_MAP_MODULEENTRY g_baseModule);
};