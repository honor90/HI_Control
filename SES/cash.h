/***************************************************************
	cash.h
	����������� (�����������) ��� "���������" ��� (USB), �
	����������� �������� "�������" ��� (VXI, PCI � �.�.)

	RTL2 - ���������� ������� ���������� ���/����.

	(�) �.�������, 2006-2010.
 ***************************************************************/
/***************************************************************
	������� ���������:
	25.01.07 - ��������� �-��� cash_RetrivePreparationLatch
			 - �������� ������������� cash_GlbErr��
	25.03.09 - ��������� �-��� cash_RefreshReg
			 - ��������� ��������� ���� ���
	1.10.10  - ������� �-��� ������������ ����������� �� ��� 
			   ���������� ����������.
 ***************************************************************/

#ifndef _CASH_H
#define _CASH_H

#include "access.h"
//#include "sync.h"

#ifdef __cplusplus
extern "C" {
#endif
/*--------------------------------------------------------------*/

typedef enum{
	// ���������� ������������
	cash_OptimaSwitchOn,
	cash_OptimaSwitchOff,
	cash_GetSwitch,
	// ���������� ������������ � ���� ��� ��������� ����������
	cash_SaveExchangeOn, 
	cash_SaveExchangeOff,
	cash_GetSaveExchange,
	// ���������� ���������� ������ ���� �� ���������� ������
	cash_GlbErrOn,
	cash_GlbErrOff,
	cash_GetGlbErr,
	// ���������� �����
	cash_DebugMark,
	// ����� �������������� ����������
	cash_UpdateModeAuto,
	cash_UpdateModeSync,
	cash_GetUpdateMode
} cash_TuneParam;


////////////////////////////////
// ��������� ���� ��� ����������
msp_ERROR 
cash_ActivateDeviceCash(msp_DEVHANDLE device);

//////////////////////////////////
// ����������� ���� ��� ����������
msp_ERROR 
cash_ReleaseDeviceCash(msp_DEVHANDLE device);

////////////////////////////////////////////////////////////
// ���������� � ������ ������ ��� � ���� ��������� ����� ��� 
msp_ERROR 
cash_RefreshRamPreparation(msp_DEVHANDLE device, msp_WORD begin_mem, int size);

////////////////////////////////////////////
// ���������� � ������ ������ ���
msp_ERROR 
cash_RefreshRamPreparationOnly(msp_DEVHANDLE device, msp_WORD begin_mem, int size);

////////////////////////////////////////////////
#define cash_ALL_REGISTERS		0x1F
// ���������� � ������ ��������(��) ����� ��� 
msp_ERROR 
cash_RefreshRegPreparation(msp_DEVHANDLE device, msp_BYTE RegNo);
// ������ - �������� ������
// device - ����� ����������� ����������
// RegNo  - ����� ��������� ��������, ��� �������� cash_ALL_REGISTERS
//          ���������� ���������� ���� �� ���� ���������

//////////////////////////////////////////////////
// ���������� ������ ��� �-��� msp_RetrieveMessage
msp_ERROR 
cash_RetrievePreparationLatch(void* stack);

//////////////////////////////
// ������������ ���� �� ������
msp_ERROR 
cash_WriteLatch(msp_DEVHANDLE device);

//////////////////////////////
// ������������ ���� �� ������
msp_ERROR 
cash_RefreshLatch(msp_DEVHANDLE device);


/*
	�������� �������������� ��������� �������� � ������������� ����.
	���������� ��� �������� ������ (�������� ���������������� ����������),
	������� �������� ������ - ����� ������� �������� ������.
*/
// ������ ��������������� ������������ ����
msp_ERROR 
cash_AutoExchangeOn(msp_DEVHANDLE device);

// ����� ��������������� ������������ ����
msp_ERROR 
cash_AutoExchangeOff(msp_DEVHANDLE device);

// ������: ���������� �� ���������� ?
msp_BOOL
cash_IsDevIntoCash(msp_DEVHANDLE device);

// ��������� ��������������� ���������� ���� ��� ��26.20v2
msp_ERROR
cash_AutoUpdateOn(msp_DEVHANDLE device);

// ���������� ��������������� ���������� ���� ��26.20v2
msp_ERROR
cash_AutoUpdateOff(msp_DEVHANDLE device);

/* 
	�-��� ���������� ������� ����
*/
//////////////////////////////////
// ������������ ����������� ������
msp_ERROR 
cash_CashInterruption(msp_DEVHANDLE device);

///////////////////////////////////////////////
// ������������� ����������� ����� ������������
msp_ERROR 
cash_CashWorkResumption(msp_DEVHANDLE device);

///////////////////////
// ������� ������� ����
msp_ERROR 
cash_ForceClear(msp_DEVHANDLE device);

/////////////////
// ��������� ����.
cash_TuneParam 
cash_Tune(cash_TuneParam parameter);


/*---------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
