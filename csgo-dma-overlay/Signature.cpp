#pragma once
#include <Windows.h>
#include <iostream>
#include <map>
#include <string>
#include "Utils.h"

namespace Signature
{
	using namespace std;
	// INITIALIZE SIGNATURE LIST
	map<string, string> sig_map = {
		{ "LocalPlayer", "A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56" }, //offset = 1
		{ "ObjectManager", "8B 0D ? ? ? ? 89 74 24 14" },
		{ "HeroList", "A1 ? ? ? ? 53 55 56 8B 68 04 8B 40 08 57 33 FF" },
		{ "MinionList", "A1 ? ? ? ? 8B 50 04 8D 48 04 89 44 24 1C" },
		{ "TurretList", "8B 0D ? ? ? ? E8 ? ? ? ? 85 C0 74 13 8B 10" },
		{ "InhibitorList", "8B 15 ? ? ? ? 8B 7A 04 8B 42 08 8D 0C 87 3B F9 73 31 66 90" },
		{ "ViewMatrix", "//b9 ? ? ? ? e8 ? ? ? ? b9 ? ? ? ? e9 ? ? ? ? cc cc cc cc cc cc cc cc" },
		{ "Renderer", "8B 15 ? ? ? ? 83 EC 08 F3" },
		{ "PrintChat", "E8 ? ? ? ? 33 C0 5F C2" },
	};

	bool GetSignatures(DWORD pid, ModuleDump module, VMMDLL_MAP_MODULEENTRY g_baseModule)
	{
		printf("[+] SIGNATURE LIST[+]\n");
		for (map<string, string>::iterator it = sig_map.begin(); it != sig_map.end(); ++it)
		{
			//cout << it->first << " => " << it->second << '\n';

			const char* sig = it->second.c_str();

			DWORD sig_1 = Utils::FindSignature(pid, module, sig, 0, 0);
			printf("   [*] %s : 0x%X + 0x%X* = 0x%X\n",it->first, g_baseModule.vaBase, sig_1 - g_baseModule.vaBase, sig_1);
			VMMDLL_MemReadEx(pid, sig_1, (PBYTE)&sig_1, sizeof(sig_1), 0, VMMDLL_FLAG_NOCACHE);
			//for (int i = 0; i < 11; i++)
			//{
			//	DWORD sig_1 = Utils::FindSignature(pid, module, sig, i, 0);
			//	printf("ITERATOR: %u", i);
			//	printf("[*] 0x%X + 0x%X* = 0x%X\n", g_baseModule.vaBase, sig_1 - g_baseModule.vaBase, sig_1);
			//	VMMDLL_MemReadEx(pid, sig_1, (PBYTE)&sig_1, sizeof(sig_1), 0, VMMDLL_FLAG_NOCACHE);
			//	printf("\n");
			//}
		}

		printf("\n");
		return false;
	}
}