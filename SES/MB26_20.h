#pragma once

#include "types.h"

#define CHANEL_A 0x01
#define CHANEL_B 0x02

#define AUTOREPEAT 0x10

struct Device_Info
{
	msp_SIGNED_WORD VendorId;
	msp_SIGNED_WORD DeviceId;
	msp_SIGNED_WORD SubsystemVendorId;
	msp_SIGNED_WORD SubsystemId;
	msp_SIGNED_WORD LType;
	msp_SIGNED_WORD BusType;
	msp_SIGNED_WORD DriverType;
	msp_WCHAR*		 SerialNumber;
	msp_SIGNED_DWORD BoardTypeId;
	char*			 BoardTypeName;
	msp_SIGNED_BYTE Clocks;
	msp_SIGNED_WORD ModesMask;
	msp_SIGNED_DWORD OnChipRamSize;
	msp_SIGNED_DWORD OnBoardRamSize;
	msp_SIGNED_DWORD SpecialRamSize;
};

struct Input_Pack
{
	msp_WORD type;
	msp_WORD dataWordCount;
	msp_WORD bccw;
	msp_WORD CmdWord1;
	msp_WORD CmdWord2;
	msp_WORD Data[32];
	msp_WORD StatusWord1;
	msp_WORD StatusWord2;
	msp_WORD loopback;
	msp_WORD bsw;
	msp_WORD timetag;
};

void MB26_20_Startup(void);

System::String ^MB26_20_Error_Startup(void);

bool MB26_20_Error_GetDeviceInfoEx(int ID);

void MB26_20_DeviceInfo(Device_Info *DF);

System::String ^MB26_20_GetLastError(void);

System::String ^MB26_20_GetSubystemError(void);

System::String ^MB26_20_GetVersionRTL2(void);

int MB26_20_GetNumberOfDevices(void);

void MB26_20_MODE_BC(void);

bool MB26_20_Open(int ID);

void MB26_20_Send_Format_1(unsigned char num_chanel, unsigned char addr, unsigned char command, unsigned short buffer[6]);

void MB26_20_Send_Format_2(unsigned char num_chanel, unsigned char addr, unsigned char command, unsigned char count_words);

void MB26_20_Test_RT_Send(unsigned char num_chanel, unsigned char addr, unsigned short buffer[6]);

bool MB26_20_Test_RT_Receive(Input_Pack *IP);

void MB26_20_StopTranslate(void);

void MB26_20_EraseRam(void);

bool MB26_20_Receive_Format_2(Input_Pack *IP);

bool MB26_20_Receive(Input_Pack *IP);

void MB26_20_Close(void);


