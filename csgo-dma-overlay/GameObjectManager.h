#ifndef __OBJECTMANAGER_H__
#define __OBJECTMANAGER_H__

#include "Offsets.h"
#include "GameObject.h"
#include "Utils.h"

#include <vector>
#include <mutex>
#include <string>
#include <vmmdll.h>

class GameObjectManager {
public:
	DWORD base; //0x0
	int maxObjects; //0x8
	int size; //0xC
	GameObject** objects; //0x14

	GameObjectManager() {
		base = NULL;
		maxObjects = NULL;
		size = NULL;
		objects = nullptr;
	}

	GameObjectManager(DWORD offset) {
		base = offset;
		VMMDLL_MemReadEx(g_pid, offset + 0x8, (PBYTE)&maxObjects, sizeof(maxObjects), 0, VMMDLL_FLAG_NOCACHE);
		VMMDLL_MemReadEx(g_pid, offset + 0xC, (PBYTE)&size, sizeof(size), 0, VMMDLL_FLAG_NOCACHE);
		VMMDLL_MemReadEx(g_pid, offset + 0x14, (PBYTE)&objects, sizeof(maxObjects * 0x4), 0, VMMDLL_FLAG_NOCACHE);
	}
};

extern std::string g_objSerialData;
extern std::mutex g_objSerialDataMutex;

extern GameObject g_localPlayer;
extern GameObjectManager* g_objectManager;

extern std::vector<GameObject> g_heroVector;
extern std::mutex g_heroVectorMutex;
extern std::vector<GameObject> g_minionVector;
extern std::mutex g_minionVectorMutex;
extern std::vector<GameObject> g_turretVector;
extern std::mutex g_turretVectorMutex;
extern std::vector<GameObject> g_inhibitorVector;
extern std::mutex g_inhibitorVectorMutex;

namespace ObjectManager {
	std::vector<GameObject> GetHeroVector(DWORD offset);
	std::vector<GameObject> GetMinionVector(DWORD offset);
	std::vector<GameObject> GetTurretVector(DWORD offset);
	std::vector<GameObject> GetInhibitorVector(DWORD offset);
	bool Init();
	void UpdateLists();
};
#endif