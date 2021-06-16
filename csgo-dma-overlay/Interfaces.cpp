#pragma once
#include <Windows.h>
#include <iostream>
#include "vmmdll.h"
#include "Offsets.h"
#include "GameObjectManager.h"
#include "Utils.h"
#include "Signature.h"

LPSTR process_name = (LPSTR)"League of Legends.exe";
DWORD g_pid;

LPWSTR baseModuleName = (LPWSTR)L"League of Legends.exe";
VMMDLL_MAP_MODULEENTRY g_baseModule;

LPWSTR stubModuleName = (LPWSTR)L"stub.dll";
VMMDLL_MAP_MODULEENTRY g_stubModule;

DWORD g_dwLocalPlayer;
DWORD g_dwPlayerName;
DWORD g_dwPlayerHP;
DWORD g_dwPlayerMana;
DWORD g_dwPlayerChampion;
DWORD g_dwTest;
DWORD g_dwRenderer;

char pPlayerName[16];
char pChampName[16];
float pHP;
float pMana;

float pPos_x;
float pPos_y;
float pPos_z;

DWORD g_dwManagerTemplate_AIMinionClient_;
DWORD g_dwFirstobject;
char pObjName[16];

namespace Interfaces
{
	using namespace std;

	bool Init()
	{
		if (!VMMDLL_PidGetFromName(process_name, &g_pid))
			return false;

		printf("[+] Found %s! PID: %d\n", process_name, g_pid);

		printf("[+] Found modules:\n");

		if (!VMMDLL_ProcessMap_GetModuleFromName(g_pid, baseModuleName, &g_baseModule))
			return false;

		wprintf(L"    - %-20s at 0x%X-0x%X\n", baseModuleName, (unsigned int)g_baseModule.vaBase, (unsigned int)g_baseModule.vaBase + g_baseModule.cbImageSize);

		if (!VMMDLL_ProcessMap_GetModuleFromName(g_pid, stubModuleName, &g_stubModule))
			return false;

		wprintf(L"    - %-20s at 0x%X-0x%X\n", stubModuleName, (unsigned int)g_stubModule.vaBase, (unsigned int)g_stubModule.vaBase + g_stubModule.cbImageSize);

		ModuleDump baseModuleDump = Utils::DumpModule(g_pid, g_baseModule);

		printf("\n");

		//START SIG SCAN
		//Signature::GetSignatures(g_pid, baseModuleDump, g_baseModule);

		//READ RENDERER
		VMMDLL_MemRead(g_pid, (ULONG64)g_baseModule.vaBase + oRenderer, (PBYTE)&g_dwRenderer, sizeof(g_dwRenderer));
		//wprintf(L"    Reading Renderer at 0x%X\n", (ULONG64)g_baseModule.vaBase + oRenderer);
	
		printf("\n");

		return true;
	}

}