#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <fstream>
#include "vmmdll.h"
#include "GameObjectManager.h"
#include "Interfaces.h"
#include "Screen.h"
#include "json/json.h"

#include "RenderMain.h"

#define PIPE_NAME "\\\\.\\pipe\\LeagueDMA_IOCommProtocol"

using namespace std;
using namespace Json;

// init lists
list<LPCSTR> minion_list;

// Function Pre-Definitions
void send_pipe_message(string json);
int setup_vmmdll();
int Shutdown();

void test();
string encode_hero_object(GameObject obj);
string JsonAsString(const Value& json);


int main()
{
    HINSTANCE hInstance;
    HINSTANCE hSecInstance;
    LPSTR nCmdLine;
    INT nCmdShow;

    setup_vmmdll();

    thread t1(RenderMain::WinMain, hInstance, hSecInstance, nCmdLine, nCmdShow);
    thread t2(ObjectManager::UpdateLists);
    t1.join();
    

    return Shutdown();
    t2.join();
}

int Shutdown()
{
    // Close vmm.dll
    if (!VMMDLL_Close())
    {
        cout << "[-] Failed to close vmm.dll" << endl;
        return 0;
    }
    cout << "[+] vmm.dll closed!" << endl;

    cout << "[*] Exiting..." << endl;
    return 0;
}

int setup_vmmdll()
{
    // Open vmm.dll with FPGA device
    LPSTR args[] = { (LPSTR)"", (LPSTR)"-device", (LPSTR)"FPGA" };
    if (!VMMDLL_Initialize(3, args))
    {
        cout << "[-] Failed to initialize vmm.dll" << endl;
        return -1;
    }
    cout << "[+] vmm.dll initialized!" << endl;


    if (!Interfaces::Init())
        return Shutdown();

    ObjectManager::Init();

    return 0;
}

void send_pipe_message(string json)
{
    HANDLE pipe = CreateFile(TEXT(PIPE_NAME), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    ConnectNamedPipe(pipe, NULL);
    string message = json;
    DWORD numWritten;
    WriteFile(pipe, message.c_str(), message.length(), &numWritten, NULL);

    cout << "Sent following via pipe..." << endl;
    cout << message << "\n\n" << endl;
}

string JsonAsString(const Value& json)
{
    std::string result;
    Json::StreamWriterBuilder wbuilder;

    wbuilder["indentation"] = "";       // Optional
    result = Json::writeString(wbuilder, json);

    ofstream file;
    file.open("GameObject_String.json");
    file << result;
    file.close();

    return result;
}

string encode_hero_object(GameObject obj)
{
    //printf("Encoding GameObject:\n\n");
    Json::Value root;

    root["GameObject"]["team"] = obj.team;
    root["GameObject"]["team"] = root["GameObject"]["team"].asString();
    root["GameObject"]["name"] = obj.name;
    root["GameObject"]["name"] = root["GameObject"]["name"].asString();
    root["GameObject"]["pos_x"] = obj.GetPos().X;
    root["GameObject"]["pos_x"] = root["GameObject"]["pos_x"].asString();
    root["GameObject"]["pos_y"] = obj.GetPos().Y;
    root["GameObject"]["pos_y"] = root["GameObject"]["pos_y"].asString();
    root["GameObject"]["pos_z"] = obj.GetPos().Z;
    root["GameObject"]["pos_z"] = root["GameObject"]["pos_z"].asString();
    root["GameObject"]["w2s_x"] = Screen::WorldToScreen(obj.position).X;
    root["GameObject"]["w2s_x"] = root["GameObject"]["w2s_x"].asString();
    root["GameObject"]["w2s_y"] = Screen::WorldToScreen(obj.position).Y;
    root["GameObject"]["w2s_y"] = root["GameObject"]["w2s_y"].asString();
    root["GameObject"]["visible"] = obj.visible;
    root["GameObject"]["visible"] = root["GameObject"]["visible"].asString();
    root["GameObject"]["mana"] = obj.GetMana();
    root["GameObject"]["mana"] = root["GameObject"]["mana"].asString();
    //root["GameObject"]["ammo"] = obj.ammo;
    //root["GameObject"]["ammo"] = root["GameObject"]["ammo"].asString();
    root["GameObject"]["recallstate"] = obj.recallstate;
    root["GameObject"]["recallstate"] = root["GameObject"]["recallstate"].asString();
    root["GameObject"]["health"] = obj.GetHealth();
    root["GameObject"]["health"] = root["GameObject"]["health"].asString();
    root["GameObject"]["bonusatk"] = obj.GetBonusAD();
    root["GameObject"]["bonusatk"] = root["GameObject"]["bonusatk"].asString();
    //root["GameObject"]["bonusap"] = obj.bonusap;
    //root["GameObject"]["bonusap"] = root["GameObject"]["bonusap"].asString();
    root["GameObject"]["baseatk"] = obj.GetBaseAD();
    root["GameObject"]["baseatk"] = root["GameObject"]["baseatk"].asString();
    root["GameObject"]["totalatk"] = obj.GetTotalAD();
    root["GameObject"]["totalatk"] = root["GameObject"]["totalatk"].asString();
    //root["GameObject"]["critrate"] = obj.critrate;
    //root["GameObject"]["critrate"] = root["GameObject"]["critrate"].asString();
    root["GameObject"]["armor"] = obj.GetArmor();
    root["GameObject"]["armor"] = root["GameObject"]["armor"].asString();
    //root["GameObject"]["bonusarmor"] = obj.bonusarmor;
    //root["GameObject"]["bonusarmor"] = root["GameObject"]["bonusarmor"].asString();
    //root["GameObject"]["mr"] = obj.mr;
    //root["GameObject"]["mr"] = root["GameObject"]["mr"].asString();
    //root["GameObject"]["bonusmr"] = obj.bonusmr;
    //root["GameObject"]["bonusmr"] = root["GameObject"]["bonusmr"].asString();
    root["GameObject"]["movespeed"] = obj.GetMovementSpeed();
    root["GameObject"]["movespeed"] = root["GameObject"]["movespeed"].asString();
    root["GameObject"]["atkrange"] = obj.GetAttackRange();
    root["GameObject"]["atkrange"] = root["GameObject"]["atkrange"].asString();
    root["GameObject"]["effectivehp"] = obj.GetEffectiveHP();
    root["GameObject"]["effectivehp"] = root["GameObject"]["effectivehp"].asString();
    root["GameObject"]["currentgold"] = obj.currentgold;
    root["GameObject"]["currentgold"] = root["GameObject"]["currentgold"].asString();
    //root["GameObject"]["totalgold"] = obj.totalgold;
    //root["GameObject"]["totalgold"] = root["GameObject"]["totalgold"].asString();
    //root["GameObject"]["dir_x"] = obj.direction.X;
    //root["GameObject"]["dir_x"] = root["GameObject"]["dir_x"].asString();
    //root["GameObject"]["dir_y"] = obj.direction.Y;
    //root["GameObject"]["dir_y"] = root["GameObject"]["dir_y"].asString();
    //root["GameObject"]["dir_z"] = obj.direction.Z;
    //root["GameObject"]["dir_z"] = root["GameObject"]["dir_z"].asString();
    root["GameObject"]["boundingradius"] = obj.boundingradius;
    root["GameObject"]["boundingradius"] = root["GameObject"]["boundingradius"].asString();
    root["GameObject"]["championname"] = obj.championname;
    root["GameObject"]["championname"] = root["GameObject"]["championname"].asString();
    //root["GameObject"]["skillpoints"] = obj.skillpoints;
    //root["GameObject"]["skillpoints"] = root["GameObject"]["skillpoints"].asString();
    root["GameObject"]["level"] = obj.GetLevel();
    root["GameObject"]["level"] = root["GameObject"]["level"].asString();

    //ofstream file;
    //file.open("GameObject.json");
    //file << root;
    //file.close();

    //cout << root << endl;

    string json = JsonAsString(root);

    return json;
    
}