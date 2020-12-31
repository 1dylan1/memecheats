#include<iostream>
#include<Windows.h>
#include<cmath>
#include"MemMan.h"
#include<math.h>
#include<cstdlib>
#include<d3d9.h>
#include<fcntl.h>
#include<string>
// #include<d3dx9.h>
#include<xmmintrin.h>
#pragma comment(lib, "winmm.lib")

using std::string;
#define KeyDOWN -32768
#define KeyUP 0
#define KEY_C 0x43
#define KEY_Z 0x5A
#define KEY_V 0x56
#define KEY_N 0x4E
#define INSERT 0x2D
#define NUMPAD3 0x63
#define NUMPAD7 0x67
#define KEY_X 0x58
#define PI 3.14159265359
#define M_RADPI 57.295779513082
#define NUMPAD_4 0x64
#define MOUSE1 0x01
#define MOUSE2 0x02
#define MIDDLEMOUSE 0x03
#define KEY_END 0x23
#define KEY_PAGEUP 0x21
#define KEY_PAGEDOWN 0x22
#define KEY_UPARROW 0x26
#define KEY_LEFTARROW 0x25
#define KEY_RIGHTARROW 0x27
#define KEY_DOWNARROW 0x28
#define KEY_DELETE 0x2E
#define KEY_HELP 0x2F

MemMan MemClass;

struct vector
{
	float x, y, z;
};

struct values
{
	DWORD localPlayer;
	DWORD process;
	DWORD gameModule;
	BYTE flag;
	DWORD armorvalue;
	int myteam;
	bool toggletbot = false;
	int tbDelay;
	int distance = 100000;
	int myweaponid;
	DWORD entgrab;
	DWORD dwengine;
	byte sendpackets;
	DWORD clientstate;
	DWORD bestentity;
	int skinid;
	//D3DXVECTOR3 oldaim;
	bool rcstog = false;
	bool aimtog = false;
	int hmhealth = 99;
	bool togglenoflash = false;
	bool silentaim = false;
}val;
//offsets
struct offsets
{
	DWORD localplayer = 0xD882BC;
	DWORD forcejump = 0x5249B34;
	DWORD flags = 0x104;
	DWORD armorvalue = 0xB378;
	DWORD flashduration = 0xA420;
	DWORD entityList = 0x4D9FBD4;
	DWORD dwGlowObjectManager = 0x52E81B0;
	DWORD team = 0xF4;
	DWORD glowIndex = 0xA438;
	DWORD forceattack = 0x31D1134;
	DWORD crosshairid = 0xB3E4;
	DWORD health = 0x100;
	DWORD vecOrigin = 0x138;
	DWORD itemdefindex = 0x2FAA;
	DWORD activeweapon = 0x2EF8;
	DWORD dwbonematrix = 0x26A8;
	DWORD viewmatrix = 0x4D914D4;
	DWORD SpottedByMask = 0x980;
	DWORD dwClientState_ViewAngles = 0x4D90;
	DWORD dwclientstate = 0x58EFE4;
	DWORD m_vecViewOffset = 0x108;
	DWORD isdefusing = 0x3930;
	DWORD bsendpackets = 0xD6E5A;
	DWORD vecvelocity = 0x114;
	DWORD m_bdormant = 0xED;
	DWORD aimpunchangle = 0x302C;
	DWORD m_szCustomName = 0x303C;

}offset;

struct Matrix3x4_t
{
	float Matrix[3][4];
};

DWORD getentbase(int index)
{
	return MemClass.readMem<DWORD>(val.gameModule + offset.entityList + (index * 0x10));
}

float getDistance(DWORD entity)
{
	vector myLocation = MemClass.readMem<vector>(val.localPlayer + offset.vecOrigin);
	vector enemyLocation = MemClass.readMem<vector>(entity + offset.vecOrigin);

	return sqrt(pow(myLocation.x - enemyLocation.x, 2) + pow(myLocation.y - enemyLocation.y, 2) + pow(myLocation.z - enemyLocation.z, 2)) * 0.0254;

}


DWORD GetEntFromIndex(int i)
{
	return MemClass.readMem<DWORD>(val.gameModule + offset.entityList + (i * 0x10));
}

bool isvalid(DWORD player)
{
	bool dormant = MemClass.readMem<bool>(player + offset.m_bdormant);
	int hp = MemClass.readMem<int>(player + offset.health);
	bool alive = false;
	if (hp > 0) alive = true;

	if (!dormant && alive)
	{
		return true;
	}
	else return false;
}

void SendPackets()
{
	MemClass.writeMem<byte>(val.dwengine + offset.bsendpackets, 1);
}

void StopPackets()
{
	MemClass.writeMem<byte>(val.dwengine + offset.bsendpackets, 0);
}

void settbdelay(float distance)
{
	float delay;
	switch (val.myweaponid)
	{
	case 262204: delay = 3; break; //m4a1-s
	case 7: delay = 3.3; break; //ak47
	case 40: delay = 0; break; //scout
	case 9: delay = 0; break; //awp
	case 1: delay = 0.01; break; //deagle (headshots only)
	case 38: delay = 1.5; break; //scar
	case 16: delay = 3; break; //m4a4
	case 11: delay = 2; break; //g3 (T auto sniper)
	default: delay = 0;
	}
	val.tbDelay = delay * distance;
}
void getourweapon()
{
	int weapon = MemClass.readMem<int>(val.localPlayer + offset.activeweapon);
	int weaponentity = MemClass.readMem<int>(val.gameModule + offset.entityList + ((weapon & 0xFFF) - 1) * 0x10);
	if (weaponentity != NULL)
		val.myweaponid = MemClass.readMem<int>(weaponentity + offset.itemdefindex);
}


void shoot()
{
	Sleep(val.tbDelay);
	MemClass.writeMem<int>(val.gameModule + offset.forceattack, 5);
	Sleep(15);
	MemClass.writeMem<int>(val.gameModule + offset.forceattack, 4);
}


bool checkTBot()
{

	int crosshair = MemClass.readMem<int>(val.localPlayer + offset.crosshairid);
	if (crosshair != 0 && crosshair < 64)
	{
		DWORD entity = MemClass.readMem<DWORD>(val.gameModule + offset.entityList + ((crosshair - 1) * 0x10));
		int eteam = MemClass.readMem<int>(entity + offset.team);
		int ehealth = MemClass.readMem<int>(entity + offset.health);
		if (eteam != val.myteam && ehealth > 0)
		{

			float distance = getDistance(entity);
			getourweapon();
			settbdelay(distance);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}


bool canbhop()
{
	vector playervec = MemClass.readMem<vector>(val.localPlayer + offset.vecvelocity);
	int vel = playervec.x + playervec.y + playervec.z; //int instead of float 
	if (vel != 0)
		return true;
	else
		return false;
}


void handleTBot()
{

	if (checkTBot())
		shoot();
}

int main()
{
	std::cout << "loaded\n";
	HWND console = GetConsoleWindow();
	SetWindowText(console, TEXT("MEMECHEATS REDONE 8/15/20"));
	bool togglefakelag = false;
	bool togglesp = false;
	//INITIAL VALUES
	int settings_check = 0;
	std::cout << "\nWould you like to run settings?\n";
	std::cout << "Enter 1 for yes, 0 for no.\n";
	std::cin >> settings_check;
	if (settings_check == 1) {
		system("start C:\\Windows\\memecheatspkg\\settings.exe");
	}
	val.process = MemClass.getProcess("csgo.exe"); //process
	val.gameModule = MemClass.getModule(val.process, "client.dll"); //get module(dll) from process
	val.localPlayer = MemClass.readMem<DWORD>(val.gameModule + offset.localplayer); //get the localplayer by addding offset to the game
	val.armorvalue = MemClass.readMem<DWORD>(val.localPlayer + offset.armorvalue); //get armor by adding armor offset to the local player
	val.dwengine = MemClass.getModule(val.process, "engine.dll");
	val.clientstate = MemClass.readMem<DWORD>(val.dwengine + offset.dwclientstate);
	//wait until localplayer is an entity 
	if (val.localPlayer == NULL)
		while (val.localPlayer == NULL)
			val.localPlayer = MemClass.readMem<DWORD>(val.gameModule + offset.localplayer); //reassign localplayer to be safe
	val.armorvalue = MemClass.readMem<DWORD>(val.localPlayer + offset.armorvalue); //reassign armor value as well 

	//INTRODUCTION
	std::cout << "meme cheat loaded successfully - made by asdjak" << std::endl;
	std::cout << "Do not load meme cheat unless you have already launched CSGO" << std::endl;
	std::cout << "Features: ESP, Noflash, Legit Bunnyhop, Fakelag" << std::endl;
	std::cout << "Controls:" << std::endl;
	std::cout << "Press X to toggle on ESP" << std::endl;
	std::cout << "HOLD C to use triggerbot" << std::endl;
	std::cout << "Hold space for Bhop" << std::endl;
	std::cout << "NUMPAD 1 is a panic button(stops cheat completely)" << std::endl;
	std::cout << "NUMPAD 3 refreshes values(usually if teamcolors for ESP are off, the offsets are off, and youll need to press this) " << std::endl;
	std::cout << "NUMPAD 4 to turn on fakelag" << std::endl;
	std::cout << "HOLD DOWN NUMPAD 5 to turn OFF fakelag" << std::endl;
	std::cout << "NUMPAD 8 TOGGLES NOFLASH ON or OFF" << std::endl;
	//LOOP OF FEATURES
	while (true)
	{
		DWORD glowObject = MemClass.readMem<DWORD>(val.gameModule + offset.dwGlowObjectManager);
		int myTeam = MemClass.readMem<int>(val.localPlayer + offset.team);
		//TOGGLE ESP
		if (GetAsyncKeyState(KEY_X) & 1)
			togglesp = !togglesp;
		if (togglesp)
		{
			{
				for (short int i = 0; i < 64; i++)
				{
					DWORD entity = MemClass.readMem<DWORD>(val.gameModule + offset.entityList + i * 0x10);
					if (entity != NULL)
					{
						int glowIndx = MemClass.readMem<int>(entity + offset.glowIndex);
						int entityTeam = MemClass.readMem<int>(entity + offset.team);
						bool isdefuse = MemClass.readMem<bool>(entity + offset.isdefusing);
						if (isdefuse)
						{
							MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x4), 255);
							MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x8), 255);
							MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0xC), 255);
							MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x10), 1);
						} //maybe this will workie
						else
						{
							if (myTeam == entityTeam)
							{
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x4), 0);
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x8), 0);
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0xC), 2);
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x10), 1);
							}
							else
							{
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x4), 2);
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x8), 0);
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0xC), 0);
								MemClass.writeMem<float>(glowObject + ((glowIndx * 0x38) + 0x10), 1);
							}
						}
						MemClass.writeMem<bool>(glowObject + ((glowIndx * 0x38) + 0x24), true);
						MemClass.writeMem<bool>(glowObject + ((glowIndx * 0x38) + 0x25), false);
					}

				}
			}

		}

		//TRIGGERBOT
		if (GetAsyncKeyState(KEY_C) == KeyDOWN)
		{
			val.myteam = MemClass.readMem<int>(val.localPlayer + offset.team);
			handleTBot();

		}
		//reset aimbot values when letting go of our key.
		//if (GetAsyncKeyState(KEY_Z) == KeyUP)
		//{
			//val.bestentity = 0; //possibly redundant?
			//val.distance = 10000; //redundant?
		//}

		//refresh
		if (GetAsyncKeyState(VK_NUMPAD3) == KeyDOWN)
		{
			val.localPlayer = MemClass.readMem<DWORD>(val.gameModule + offset.localplayer);
			DWORD clientbase = MemClass.readMem<DWORD>(val.dwengine + offset.dwclientstate); //client state?
			vector localangles = MemClass.readMem<vector>(clientbase + offset.dwClientState_ViewAngles); //ACTUALLY GETS THE X AND Y ANGLES YAY
			vector localplayerpos = MemClass.readMem<vector>(val.localPlayer + offset.m_vecViewOffset); //works
			std::cout << "[OFFSETS] refreshed memory addresses" << std::endl;
		}
		//TOGGLE AIMBOT ON AND OFF
		if (GetAsyncKeyState(VK_NUMPAD9) & 1)
		{
			if (val.aimtog == true)
			{
				std::cout << "[AIMBOT] Aimbot turned OFF" << std::endl;
				val.aimtog = false;
			}
			else
			{
				std::cout << "[AIMBOT] Aimbot turned ON" << std::endl;
				val.aimtog = true;
			}
		}
		//CLOSE AND HIDE APPLICATION
		if (GetAsyncKeyState(VK_NUMPAD1) == KeyDOWN)
		{
			std::cout << "closing" << std::endl; //debugger
			HWND console = GetConsoleWindow(); //possibly get the HWND of current window to prevent name changes
			SetWindowText(console, TEXT("closing application")); //set window text just as a check? 9.11.19
			exit(EXIT_SUCCESS);
			Sleep(1000);
			ShowWindow(console, 1);
		}


		/* AIMBOT
		if (GetAsyncKeyState(KEY_Z) == KeyDOWN)
		{
			if (val.aimtog == true)
			{
				GetClosest(10);
				DWORD playr = val.bestentity;
				aimatplayer(playr, 0.5f);
				val.distance = 10000;
				//reset distance before analyzing new entity
			}
			if (val.silentaim == true)
			{
				GetClosest(10);
				DWORD playa = val.bestentity;
				silentaimatplayer(playa, 0.5f);
				val.distance = 10000;
			}
		}
		*/
		//NO FLASH TOGGLE
		int flashDur = 0;
		flashDur = MemClass.readMem<int>(val.localPlayer + offset.flashduration);

		if (GetAsyncKeyState(VK_NUMPAD8) & 1) //NO FLASH CHECK 
		{
			if (val.togglenoflash == true) //actually works in reverse, when boolean returns true, you set to false and turn off
			{ //re-assign entity to struct. 
				std::cout << "[NO FLASH] no flash turned off" << std::endl;
				val.togglenoflash = false;
			}
			else
			{
				std::cout << "[NO FLASH] no flash turned on" << std::endl;
				val.togglenoflash = true;
			}
		}
		if (flashDur > 0 && val.togglenoflash == true)
		{
			MemClass.writeMem<int>(val.localPlayer + offset.flashduration, 0);
		}
		//BUNNY HOP
		val.flag = MemClass.readMem<BYTE>(val.localPlayer + offset.flags); //set flags condition

		if (GetAsyncKeyState(VK_SPACE) && val.flag && canbhop() & (1 << 0)) //check for space bar
			MemClass.writeMem<DWORD>(val.gameModule + offset.forcejump, 6); //force jump
		Sleep(.1); //loop so we dont crash value changed from (1) to (.8) 8.26.19 changed to .1  9.6.19
	}
	return 0;
}
