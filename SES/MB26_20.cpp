#include "stdafx.h"
#include "windows.h"

#include "access.h"
#include "bc.h"
#include "cash.h"
#include "config.h"
#include "errors.h"
#include "gsw.h"
#include "int.h"
#include "mt.h"
#include "nulldev.h"
#include "rt.h"
#include "ruki.h"
#include "types.h"

#include "MB26_20.h"

#pragma comment(lib, "drtl3.lib")

msp_ERROR Error_RTL;

msp_DeviceInfoEx DeviceInfoEx;

msp_DEVHANDLE DEVHANDLE;

msp_FRMHANDLE FRMHANDLE_FORNAT_2;

msp_MSGHANDLE MSGHANDLE_FORMAT_2;

msp_Message M_format2;

static msp_WORD pTT = 0;
static msp_WORD pTT_test = 0;

static msp_FLAGID bcflags[] =
{
	mspF_ENHANCED_MODE,
	mspF_256WORD_BOUNDARY_DISABLE,
	mspF_MESSAGE_GAP_TIMER_ENABLED,
	mspF_INTERNAL_TRIGGER_ENABLED,
	mspF_EXPANDED_BC_CONTROL_WORD,
	0
};

void MB26_20_Startup(void)
{
	Error_RTL = msp_Startup();
}

System::String ^MB26_20_Error_Startup(void)
{
	return Error_RTL.ToString();
}

bool MB26_20_Error_GetDeviceInfoEx(int ID)
{
	if (msp_GetDeviceInfoEx(ID, &DeviceInfoEx) == 0)
	{
		return true;
	}
	else return false;
}

void MB26_20_DeviceInfo(Device_Info *DI)
{
	DI->VendorId = DeviceInfoEx.VendorId;
	DI->DeviceId = DeviceInfoEx.DeviceId;
	DI->SubsystemVendorId = DeviceInfoEx.SubsystemVendorId;
	DI->SubsystemId = DeviceInfoEx.SubsystemId;
	DI->LType = DeviceInfoEx.LType;
	DI->BusType = DeviceInfoEx.BusType;
	DI->DriverType = DeviceInfoEx.DriverType;
	DI->SerialNumber = DeviceInfoEx.SerialNumber;
	DI->BoardTypeId = DeviceInfoEx.BoardTypeId;
	DI->BoardTypeName = DeviceInfoEx.BoardTypeName;
	DI->Clocks = DeviceInfoEx.Clocks;
	DI->ModesMask = DeviceInfoEx.ModesMask;
	DI->OnChipRamSize = DeviceInfoEx.OnChipRamSize;
	DI->OnBoardRamSize = DeviceInfoEx.OnBoardRamSize;
	DI->SpecialRamSize = DeviceInfoEx.SpecialRamSize;
}

System::String ^MB26_20_GetLastError(void)
{
	return msp_GetLastError().ToString();
}

System::String ^MB26_20_GetSubystemError(void)
{
	return msp_GetSubsystemError().ToString();
}

System::String ^MB26_20_GetVersionRTL2(void)
{
	return msp_GetVersion().ToString();
}

int MB26_20_GetNumberOfDevices(void)
{
	return msp_GetNumberOfDevices();
}

void MB26_20_MODE_BC(void)
{
	msp_Configure(DEVHANDLE, msp_MODE_BC + msp_MODE_ENHANCED, bcflags, NULL);
}

bool MB26_20_Open(int ID)
{
	DEVHANDLE = msp_Open(ID);
	if (DEVHANDLE != msp_NOHANDLE) return true;
	else return false;
}

void MB26_20_Send_Format_1(unsigned char num_chanel, unsigned char addr, unsigned char command, unsigned short buffer[6])
{
	msp_FRMHANDLE FRMHANDLE_FORNAT_1;
	msp_MSGHANDLE MSGHANDLE_FORMAT_1;
	msp_Message M_format1;
	msp_WORD Chanel;
	int flag;

	switch (num_chanel&0x0F)
	{
	case CHANEL_A:
		Chanel = msp_BCCW_CHANNEL_A;
		if (num_chanel & AUTOREPEAT) flag = msp_STK_A + msp_AUTOREPEAT;
		else flag = msp_STK_A;
		break;
	case CHANEL_B:
		Chanel = msp_BCCW_CHANNEL_B;
		if (num_chanel & AUTOREPEAT) flag = msp_STK_B + msp_AUTOREPEAT;
		else flag = msp_STK_B;
		break;
	}

	FRMHANDLE_FORNAT_1 = msp_CreateFrame(DEVHANDLE, 1000, 1);
	msp_BCtoRT(&M_format1, addr, command, 6, buffer, Chanel);
	MSGHANDLE_FORMAT_1 = msp_CreateMessage(DEVHANDLE, &M_format1);
	msp_AddMessage(FRMHANDLE_FORNAT_1, MSGHANDLE_FORMAT_1, 10000);
	msp_LoadFrame(FRMHANDLE_FORNAT_1, flag);
	msp_Start(DEVHANDLE);
}

void MB26_20_Send_Format_2(unsigned char num_chanel, unsigned char addr, unsigned char command, unsigned char count_words)
{
	msp_WORD Chanel;
	int flag;
	msp_WORD tim;

	switch (num_chanel&0x0F)
	{
	case CHANEL_A:
		Chanel = msp_BCCW_CHANNEL_A;
		if (num_chanel & AUTOREPEAT)
		{
			flag = msp_STK_A + msp_AUTOREPEAT;
			tim = 100000;
		}
		else
		{
			flag = msp_STK_A;
			tim = 1000;
		}
		break;
	case CHANEL_B:
		Chanel = msp_BCCW_CHANNEL_B;
		if (num_chanel & AUTOREPEAT)
		{
			flag = msp_STK_B + msp_AUTOREPEAT;
			tim = 100000;
		}
		else
		{
			flag = msp_STK_B;
			tim = 1000;
		}
		break;
	}

	FRMHANDLE_FORNAT_2 = msp_CreateFrame(DEVHANDLE, 1000, 1);
	msp_RTtoBC(&M_format2, addr, command, count_words, Chanel);
	MSGHANDLE_FORMAT_2 = msp_CreateMessage(DEVHANDLE, &M_format2);
	msp_AddMessage(FRMHANDLE_FORNAT_2, MSGHANDLE_FORMAT_2, tim);
	msp_LoadFrame(FRMHANDLE_FORNAT_2, /*flag*/ msp_STK_A + msp_AUTOREPEAT);
	msp_Start(DEVHANDLE);
}

msp_FRMHANDLE FRMHANDLE_TEST_RT;
msp_Message M_test_RT;

void MB26_20_Test_RT_Send(unsigned char num_chanel, unsigned char addr, unsigned short buffer[6])
{
	msp_MSGHANDLE MSGHANDLE_TEST_RT;
	
	msp_WORD Chanel;
	int flag;

	switch (num_chanel)
	{
	case CHANEL_A:
		Chanel = msp_BCCW_CHANNEL_A;
		flag = msp_STK_A;
		break;
	case CHANEL_B:
		Chanel = msp_BCCW_CHANNEL_B;
		flag = msp_STK_B;
		break;
	}

	FRMHANDLE_TEST_RT = msp_CreateFrame(DEVHANDLE, 1000, 2);
	msp_BCtoRT(&M_test_RT, addr, 30, 6, buffer, Chanel);
	MSGHANDLE_TEST_RT = msp_CreateMessage(DEVHANDLE, &M_test_RT);
	msp_AddMessage(FRMHANDLE_TEST_RT, MSGHANDLE_TEST_RT, 10000);

	msp_RTtoBC(&M_test_RT, addr, 30, 6, Chanel);
	MSGHANDLE_TEST_RT = msp_CreateMessage(DEVHANDLE, &M_test_RT);
	msp_AddMessage(FRMHANDLE_TEST_RT, MSGHANDLE_TEST_RT, 10000);

	msp_LoadFrame(FRMHANDLE_TEST_RT, flag);
	msp_Start(DEVHANDLE);
}

bool MB26_20_Test_RT_Receive(Input_Pack *IP)
{
	msp_ERROR Error_Pack = 0;

	//Error_Pack = msp_RetrieveMessage(FRMHANDLE_TEST_RT, msp_NEXT_MESSAGE, &M_test_RT);

	//if (Error_Pack == msp_ERROR_NO_NEXT_MESSAGE)
	//{
		//if (pTT != msp_ReadStackWord(FRMHANDLE_TEST_RT, 0, msp_FW_TIMETAG))
			//if (msp_GetMessageStatus(FRMHANDLE_TEST_RT, 0) == msp_MESSAGE_COMPLETED)
			//{
				Error_Pack = msp_RetrieveMessage(FRMHANDLE_TEST_RT, msp_LAST_RECEIVED, &M_test_RT);
				if ((Error_Pack == 0) && (M_test_RT.type == mspM_RTtoBC))
				{
					IP->type = M_test_RT.type;
					IP->dataWordCount = M_test_RT.dataWordCount;
					IP->bccw = M_test_RT.bccw;
					IP->CmdWord1 = M_test_RT.CmdWord1;
					IP->CmdWord2 = M_test_RT.CmdWord2;
					for (char k = 0; k <= 32; k++) IP->Data[k] = M_test_RT.Data[k];
					IP->StatusWord1 = M_test_RT.StatusWord1;
					IP->StatusWord2 = M_test_RT.StatusWord2;
					IP->loopback = M_test_RT.loopback;
					IP->bsw = M_test_RT.bsw;
					IP->timetag = M_test_RT.timetag;

					pTT = M_test_RT.timetag;

					return true;
				}
				else return false;
			//}
	//}
	//else return false;
}

bool MB26_20_Receive_Format_2(Input_Pack *IP)
{
	msp_ERROR Error_Pack = 0;

	Error_Pack = msp_RetrieveMessage(FRMHANDLE_FORNAT_2, msp_NEXT_MESSAGE, &M_format2);

	if (Error_Pack == msp_ERROR_NO_NEXT_MESSAGE)
	{
		if (pTT != msp_ReadStackWord(FRMHANDLE_FORNAT_2, 0, msp_FW_TIMETAG))
			if (msp_GetMessageStatus(FRMHANDLE_FORNAT_2, 0) == msp_MESSAGE_COMPLETED)
			{
				Error_Pack = msp_RetrieveMessage(FRMHANDLE_FORNAT_2, 0, &M_format2);
				if ((Error_Pack == 0) && (M_format2.type == mspM_RTtoBC))
				{
					IP->type = M_format2.type;
					IP->dataWordCount = M_format2.dataWordCount;
					IP->bccw = M_format2.bccw;
					IP->CmdWord1 = M_format2.CmdWord1;
					IP->CmdWord2 = M_format2.CmdWord2;
					for (char k = 0; k <= 32; k++) IP->Data[k] = M_format2.Data[k];
					IP->StatusWord1 = M_format2.StatusWord1;
					IP->StatusWord2 = M_format2.StatusWord2;
					IP->loopback = M_format2.loopback;
					IP->bsw = M_format2.bsw;
					IP->timetag = M_format2.timetag;

					pTT = M_format2.timetag;

					return true;
				}
			}
	}
	else return false;
}

void MB26_20_StopTranslate(void)
{
	msp_StopOnMessage(DEVHANDLE);

	while (msp_GetFlag(DEVHANDLE, mspF_BC_ENABLED) != 0) {}
}

void MB26_20_EraseRam(void)
{
	//while (msp_GetFlag(DEVHANDLE, mspF_BC_ENABLED) != 0) {}

	msp_EraseRam(DEVHANDLE);
	Sleep(20);
}

bool MB26_20_Receive(Input_Pack *IP)
{

	msp_ERROR Error_Pack = 0;

	if (pTT != msp_ReadStackWord(FRMHANDLE_FORNAT_2, 0, msp_FW_TIMETAG))
	{
		Error_Pack = msp_RetrieveMessage(FRMHANDLE_FORNAT_2, msp_LAST_RECEIVED, &M_format2);
		if ((Error_Pack == 0) && (M_format2.type == mspM_RTtoBC))
		{
			IP->type = M_format2.type;
			IP->dataWordCount = M_format2.dataWordCount;
			IP->bccw = M_format2.bccw;
			IP->CmdWord1 = M_format2.CmdWord1;
			IP->CmdWord2 = M_format2.CmdWord2;
			for (char k = 0; k <= 32; k++) IP->Data[k] = M_format2.Data[k];
			IP->StatusWord1 = M_format2.StatusWord1;
			IP->StatusWord2 = M_format2.StatusWord2;
			IP->loopback = M_format2.loopback;
			IP->bsw = M_format2.bsw;
			IP->timetag = M_format2.timetag;

			pTT = M_format2.timetag;

			return true;
		}
		else return false;
	}
}

void MB26_20_Close(void)
{
	MB26_20_StopTranslate();

	msp_Reset(DEVHANDLE);

	msp_Close(DEVHANDLE);

	msp_Cleanup();
}

