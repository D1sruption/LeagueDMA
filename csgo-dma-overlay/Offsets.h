#pragma once
#define TARGET_GAMEVERSION "Version 10.22.339.2173 [PUBLIC]"  // 

#define oRetAddr 0x6E502 // 				// find addr : ret // opcode : C3
#define oDrawCircleRetAddr 0x6E4FF // 		// find addr : add esp, 28 ret // opcode : 83 C4 1C C3
#define oChatClientPtr 0x1C65854 //			8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33 // dword_[offset]

#define oUpdateChargeableSpell 0x512BD0	//E8 ? ? ? ? 8B 43 24 8B 0D ? ? ? ?
#define oGameVersion 0x57C060	//8B 44 24 04 BA ? ? ? ? 2B D0
#define oIsObjectType 0x172450	//51 56 57 8B F9 33 D2 0F B6 47 58
#define oLocalPlayer 0x3518034	//A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56
#define oGameTime 0x3510778	//F3 0F 11 05 ? ? ? ? 8B 49
#define oHudInstance 0x1C7BB54	//8B 0D ? ? ? ? F3 0F 11 04 24 50 8B 49 0C E8 ? ? ? ? 83 C4 0C
#define oRenderer 0x3540C74	//8B 15 ? ? ? ? 83 EC 08 F3
#define oGameInfo 0x35118B0	//A1 ? ? ? ? 83 78 08 02 0F 94 C0
#define oViewMatrix 0x353DF38	//b9 ? ? ? ? e8 ? ? ? ? b9 ? ? ? ? e9 ? ? ? ? cc cc cc cc cc cc cc cc
#define oObjAttackRange 0x12D0	//D8 81 ? ? ? ? 8B 81 ? ? ? ?
#define oNetClient 0x351F884	//8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oUnderMouse 0x323351	//8B 0D ? ? ? ? 89 0D
#define oZoomClass 0x350FF54	//A3 ? ? ? ? 83 FA 10 72 32
#define oObjManager 0x1C67DD8 //			8B 0D ? ? ? ? 89 74 24 14 // dword_[offset]

// FUNCTIONS
#define oCastSpell 0x50B350 // 				xref: ERROR: Client Tried to cast a spell from an invalid slot: %d.\n
#define oDrawCircle 0x4FEF20 //			 	E8 ? ? ? ? 83 C4 1C 80 7F // sub_[offset]
#define oGetBasicAttack 0x166060 // 	 	53 8B D9 B8 ? ? ? ? 8B 93 // fn
#define oGetAttackCastDelay 0x2A0320 // 	83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90 // fn
#define oGetAttackDelay 0x2A0420 // 		E8 ? ? ? ? 8B 44 24 1C 83 C4 0C 8B CE // sub_[offset]
#define oGetPing 0x332C80 // 				E8 ? ? ? ? 8B 4F 2C 85 C9 0F // sub_[offset]
#define oPingInstance 0x350BC58 //			8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B // dword_[offset]
#define oGetSpellState 0x5004F0 // 			E8 ? ? ? ? 8B F8 8B CB 89 // sub_[offset]
#define oIsTargetable 0x1CC620 //			56 8B F1 E8 ? ? ? ? 84 C0 74 2E // fn
#define oIsAlive 0x19BFC0 // 				56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19 // fn
#define oIsBaron 0x172860 //				E8 ? ? ? ? 84 C0 74 0A BB // sub_[offset]
#define oIsTurret 0x1A9F40 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F // sub_[offset]
#define oIsInhib 0x1A9B50 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 38 // sub_[offset]
#define oIsHero 0x1A9CD0 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 2B 57 // sub_[offset]
#define oIsMinion 0x1A9D10 // 				E8 ? ? ? ? 83 C4 04 84 C0 74 16 8B 0F // sub_[offset]
#define oIsDragon 0x170AA0 //  				E8 ? ? ? ? 33 DB 84 C0 0F 95 C3 8D 1C 5D ? ? ? ? E9 // sub_[offset]
#define oIsMissile 0x1A9D30 //		   		E8 ?? ?? ?? ?? 83 C4 04 84 C0 74 60 // sub_[offset]
#define oIsNexus 0x1A9C50 //				E8 ? ? ? ? 83 C4 04 84 C0 0F 95 C0 C3 CC 8A // sub_[offset]
#define oIsNotWall 0x8F0E70 // 				E8 ? ? ? ? 33 C9 83 C4 0C 84 // sub_[offset]
#define oIsTroy 0x1A9BD0  // 				E8 ? ? ? ? 8B E8 83 C4 04 85 ED 0F 84 ? ? ? ? 6A 08 // go to sub_XXX then sub_[offset]
#define oIssueOrder 0x173BD0 // 			81 EC ? ? ? ? 56 57 8B F9 C7 // fn
#define oPrintChat 0x579BF0 //				E8 ? ? ? ? 33 C0 5F C2 // sub_[offset]
#define oSendChat 0x5F4C00 //				A1 ? ? ? ? 56 6A FF // fn // E8 ? ? ? ? 8D 4C 24 04 C6 // sub_[offset]
#define oGetTimerExpiry 0x16C420 // 		E8 ? ? ? ? 51 D9 1C 24 E8 ? ? ? ? 8B // sub_[offset]

//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC //
#define oObjPos 0x1D8 //220
#define oObjVisibility 0x270
#define oObjHealth 0xDC4
#define oObjMana 0x298
#define oObjMaxMana 0x2A8
#define oObjArmor 0x12B0
#define oObjMagicRes 0x12B8
#define oObjBonusMagicRes 0x12BC
#define oObjBaseAtk 0x1288
#define oObjBonusAtk 0x1208
#define oObjMoveSpeed 0x12C8
#define oObjAtkRange 0x12D0
#define oObjBuffMgr 0x2174
#define oObjSpellBook 0x2720
#define oObjChampionName 0x314C
#define oObjLevel 0x36BC
#define oIsAlive 0x218 //TESTING

//buff

#define O_BUFFMGR_BUFFNAME 0x08
#define O_BUFFMGR_STARTTIME 0xC
#define O_BUFFMGR_ENDTIME 0x10
#define O_BUFFMGR_flBUFFCOUNT 0x2C
#define O_BUFFMGR_iBUFFCOUNT 0x70

//
#define objectArray 0x14

#define oBaseAddr 0xFFF

#define oGameTime 0xFFF
#define oPrintChat 0xFFF
#define oGetFirstObject 0xFFF
#define oGetNextObject 0xFFF

#define oHeroList 0x1C79A48        //A1 ? ? ? ? 53 55 56 8B 68 04 8B 40 08 57 33 FF
#define oMinionList 0x28C8100      //A1 ? ? ? ? 8B 50 04 8D 48 04 89 44 24 1C	
#define oTurretList 0x350F720      //8B 0D ? ? ? ? E8 ? ? ? ? 85 C0 74 13 8B 10
#define oInhibitorList 0x35191C0   //8B 15 ? ? ? ? 8B 7A 04 8B 42 08 8D 0C 87 3B F9 73 31 66 90