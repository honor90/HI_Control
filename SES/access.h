/* -*- mode:c; coding:windows-1251; -*- */
/***************************************************************
	access.h
	�/� ��������������� �������.

	RTL2 - ���������� ������� ���������� ���/����.

	(�) �.������, 2000.
	�� ������ ��� ������.
 ***************************************************************/
/***************************************************************
	������� ���������:
	13.09.2001 ������
	  ��������� ���� LType � msp_DeviceInfo � ��� ������������
	  � �������� � msp_GetDeviceInfo(), msp_FindDevice
	14.01.2002 �������
		��������� ������� mspRR_EXTERNAL_FLOG_ID, msp_CLOCK_��MHz,
		��� ��� � ��������� ���� �������������� ������.
	24.10.2005 ������, ������, ���������
		��������� ��������� ��������������� ����������.
		��������� ��������� ���������� ��������� ������� Ardence RT�
 ***************************************************************/

#ifndef ACCESS_H
#define ACCESS_H

#define RTL2_VERSION 505
// ����� ������ ����������

#include "types.h"
#include "errors.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	msp_Bus_PCI = 1,
	msp_Bus_USB = 2,
	msp_Bus_NULL = 3,
	msp_Bus_VXI = 4
    #define msp_MAX_BUS_TYPE msp_BUS_VXI
} msp_BusType;

typedef enum {
	msp_Driver95 = 1,
	msp_DriverNT,
	msp_DriverRTX,
	msp_DriverNT_USB,
	msp_DriverLinux, 
	msp_DriverLinux_USB, 
	msp_DriverFBSD, 
	msp_DriverFBSD_USB,
	msp_Driver_VXI,
	msp_Driver_USB_FTDI,
	msp_Driver7,
	msp_Driver_NULL
    #define msp_MAX_DRIVER_TYPE msp_Driver_NULL
} msp_DriverType;

typedef struct { 
	msp_SIGNED_WORD VendorId; 
	msp_SIGNED_WORD DeviceId;
	msp_SIGNED_WORD SubsystemVendorId;
	msp_SIGNED_WORD SubsystemId;
	msp_SIGNED_DWORD InstanceId;
	msp_SIGNED_DWORD ProcessId;
	msp_SIGNED_DWORD LType;
	msp_SIGNED_DWORD BusType;
	msp_SIGNED_DWORD DriverType;
	msp_SIGNED_WORD  Busy; /* 0 | 1 */
	msp_WCHAR*	SerialNumber;
} msp_DeviceInfo;

/*
���������� �� ����������
VendorId � ������������� ������������� (�� ����������������� ������������ PCI)
DeviceId � ������������� ���������� (�� ����������������� ������������ PCI)
InstanceId � ����� ���������� � ���������������� ������������ PCI. 
			������ ������������� ������� �������� PCI CONFIG_ADDRESS (��� 31 = 0).
ProcessId � ������������� �������� (��), ������������ ����������, ��� 0, 
			���� ���������� ��������
LType - ��� �������������� ������, mspLT_XXXX
���������� ���������� � 0 �� msp_GetNumberOfDevices()-1.
*/

//��������� ���� �������������� ������
#define mspLT_BU			0x00 // ��� BU-61580, ����������� ������ ��/��/��
#define mspLT_PLM_BU		0x01 // ��� 1879��1� ��� ���, ����������� ������
#define mspLT_TESTER		0x02 // ���������������� ������� (������)
#define mspLT_EXT_TESTER	0x03 // ���������������� ������� + ����������� ������ (UNIVERSAL)
#define mspLT_MULTIPORT		0x04 // 31�� + ����������� ������
#define mspLT_VIRTUALRT		0xFE // ����������� �� � ������� mspLT_MULTIPORT
//�������� �������������. �� ���������������.
#define mspLT_UNIVERSAL		mspLT_EXT_TESTER

//��������� ������ ������ ����������
#define msp_MODE_DEFINED

#ifndef __linux__ 
typedef msp_WORD msp_MODE; //bitmapped:
#endif

#define msp_MODE_NOT_DEFINED 0x0000
#define msp_MODE_BC                     0x0001
#define msp_MODE_RT                     0x0002
#define msp_MODE_MM                     0x0004
#define msp_MODE_WM                     0x0008
#define msp_MODE_IDLE					0x0010
#define msp_MODE_ENHANCED				0x8000
#define msp_MODE_WG						0x0020 // ��� ���

//����� (�������) ��� SelectMode
#define msp_SWITCH_WITHOUT_RESET        0x0100
#define msp_SWITCH_KEEP_RAM             0x0200
// ��� ���
#define msp_WG_FIRST					0
#define msp_WM_FIRST					0x4000
// ��� MRT
#define msp_MODE_MRT					0x0040			

typedef struct { 
	msp_DWORD		BoardTypeId;   /* 4 hex ����� �� ����� ����� */
	char*			BoardTypeName; /* RUS windows-1251 */
	msp_BYTE		Clocks;        /* OR'ed (1 << MSP_CLOCK_XXX) */
	msp_MODE*       Modes;
	msp_DWORD OnChipRamSize;  /*words*/
	msp_DWORD OnBoardRamSize; /*words*/
	msp_DWORD SpecialRamSize; /*words*/
} msp_DeviceTypeInfo;
//���������� � ���� ����������
//BoardTypeId - �������� ������������� ���� ����� (4 hex ����� �� ����� �����)
	#define msp_BOARD_Unknown 0
	#define msp_BOARD_MBXXXX 0
	#define msp_BOARD_MB1101 0x1101
	#define msp_BOARD_MB1104 0x1104
	#define msp_BOARD_MB2604 0x2604
	#define msp_BOARD_MB2603 msp_BOARD_MB2604
	#define msp_BOARD_MB2614 0x2614
	#define msp_BOARD_MB2605 msp_BOARD_MB2614
	#define msp_BOARD_MB2615 msp_BOARD_MB2614
	#define msp_BOARD_MB2616 0x2616
	#define msp_BOARD_MB2617 0x2617
	#define msp_BOARD_MB2619 0x2619
	#define msp_BOARD_MB2620 0x2620
	#define msp_BOARD_MB2630 0x2630
	#define msp_BOARD_MB2634 0x2634
	#define msp_BOARD_MB5601 0x5601
	#define msp_BOARD_NULL	 0xDEAD
	#define msp_BOARD_nonMB  0x7FFE
	#define msp_BOARD_unIDENT 0x7FFF
    //����� ���������� ��������������� �� ���������
	//���������� ����������� ��������� - �� ������� ��� ������ �� ������ � �����������
//BoardTypeName - ������������ ���� �����, ������, RUS windows-1251
//Clocks - �������������� �������� ������� (OR'ed (1 << msp_CLOCK_XXX))
//Modes - ������ �������������� ������� � ���������� �������, ������� ����� - 0
//OnChipRamSize - ������ ����������� ���, � ������
//OnBoardRamSize - ������ �������� ���, � ������
//SpecialRamSize - ������ ��� � ����������� ������ (������, 31��), � ������

typedef struct { 
	msp_SIGNED_WORD  VendorId; 
	msp_SIGNED_WORD  DeviceId;
	msp_SIGNED_WORD  SubsystemVendorId;
	msp_SIGNED_WORD  SubsystemId;
	msp_SIGNED_DWORD InstanceId;
	msp_SIGNED_DWORD ProcessId;
	msp_SIGNED_DWORD LType;
	msp_SIGNED_DWORD BusType;
	msp_SIGNED_DWORD DriverType;
	msp_SIGNED_WORD  Busy;
	msp_WCHAR*		 SerialNumber;
	msp_SIGNED_DWORD BoardTypeId;
	char*			 BoardTypeName;
	msp_SIGNED_BYTE	 Clocks;      
	msp_MODE*        Modes;
	msp_SIGNED_WORD	 ModesMask;  /* OR'ed Modes */
	msp_SIGNED_DWORD OnChipRamSize;
	msp_SIGNED_DWORD OnBoardRamSize;
	msp_SIGNED_DWORD SpecialRamSize;
} msp_DeviceInfoEx;
//����������� ���������� �� ���������� � ��� ����
//ModesMask - ������� ����� �������������� ������� (OR'ed Modes)

typedef	msp_HANDLE msp_DEVHANDLE;

/***************************************************************
    ������� ����������� � �������������� �������
 ***************************************************************/

msp_WORD msp_GetVersion();

// ���������� ����� ������ ���������� (�������� ������� RTL2_VERSION)
// ��� ����������� ������������ ������ ������, ����� ���������� ������������ ��� DLL

msp_ERROR msp_Startup();

// ������������� RTL

msp_ERROR msp_Cleanup();

// ���������� ������ RTL

//
// ������������� RTL �� ��������� ���������
//
msp_ERROR msp_StartupDrv(msp_DriverType drv);
// ������ ������ msp_Startup() ���������� ����� ������� ��������� �������
// msp_StartupDrv() ��� ���������� ���������, � �������� ��� ����� ��������.
// ���� msp_Driver95 � msp_DriverNT � ���� ������� �������� �����������������,
// ��������� ����� ����� ����� ���������� ������������ � ����������� ��
// ���������, ������� ������������� �����������

int msp_GetNumberOfDevices();

//���������� ���������� ���������� ���������.
// -1 � ������ ������

msp_ERROR msp_GetDeviceInfo(int i, msp_DeviceInfo* I);

//���������� ���������� �� ���������� ���������� � ������� �� ������� i � ��������� DeviceInfo:
//���������� ���������� � 0 �� msp_GetNumberOfDevices()-1.

int msp_FindDevice(msp_DeviceInfo* I);

//���������� ���������� ����� ���������� � ��������� ����������, -1 ���� ���������� �� �������. 
//����� ������� ������� ���������� ������ ��������� ��������� I. 
//��� ������������� �������� ��������������� ���� ������ ���� ����������� � �1.
//���������� ���������� � 0 �� msp_GetNumberOfDevics()-1.
//���� SerialNumber �� �����������

#define msp_InitPattern(I) \
	(memset((I), -1, sizeof(*(I))), (I)->SerialNumber = NULL)
//msp_DeviceInfo* I
//�������������� I ��� ������ � �������� "��� �������� �������������"
//������ ������������ ����� ������� � I ������������ ���������

msp_DeviceTypeInfo* msp_GetDeviceTypeInfo(int i);

//���������� ��������� �� ����������� ���������� � ���� ���������� � ���������� ������� i.
//	��� ������ ���������� NULL � ������������� ��� ������
//		( msp_ERROR_UNKNOWN_DEVICE_TYPE, msp_ERROR_INVALID_PARAMETER, msp_ERROR_NOT_INITIALIZED).
//���������� ���������� � 0 �� msp_GetNumberOfDevices()-1.

msp_ERROR msp_GetDeviceInfoEx(int i, msp_DeviceInfoEx* I);
//�-��� ���������� msp_GetDeviceInfo(), �� ���������� ����������� ����������
//���� ���������� �� ���������� �������, � � ���� - ���, ���� ����������
//� ���� ����������� -1, ��������������� ������ msp_ERROR_UNKNOWN_DEVICE_TYPE

#define msp_FIND_FIRST	0
#define msp_FIND_NEXT	1
int msp_FindDeviceEx(msp_DeviceInfoEx* I, int next);
//�-��� ���������� msp_FindDevice(), �� �� ������ ���������� ����������.
//������� ������ ��������������� ����������
//���� BoardTypeName ������������
//���� SerialNumber ������������
//���� Modes, ���� ���������, ������ ���� ����������� � NULL
//���� Clocks � ModesMask ������������ "�� ��������� ��������",
//���� Modes - "�� ��������� �������"
//next - �������� ����������� ������� ��������� msp_FIND_XXXX

#define msp_InitPatternEx(I) \
	(memset((I), -1, sizeof(*(I))), (I)->Modes = NULL, (I)->SerialNumber = NULL)
//msp_DeviceInfoEx* I
//�������������� I ��� ������ � �������� "��� �������� �������������"
//������ ������������ ����� ������� � I ������������ ���������

/***************************************************************
    ������� ������������ ����� � �����������
 ***************************************************************/

msp_DEVHANDLE mspi_OpenAccess(int i);
msp_DEVHANDLE mspi_OpenAccessEx(int i, int flags);

//��������� ������ � ��������� ����������
//� ������ ������������� ������� ���������� 
//������������ �������� msp_NOHANDLE.
//���������� �� msp_Open()/msp_OpenEx()

//flags:
#define msp_of64		(1<<0)
#define msp_ofZEROWAIT	(1<<1)
#define msp_ofBackDoor	(1<<2)
#define msp_ofShrinkRam	(1<<3)

msp_ERROR mspi_CloseAccess(msp_DEVHANDLE device);

//��������� ������ � ��������� ����������
//���������� �� msp_Close

int msp_GetDeviceNo(msp_DEVHANDLE device);
//���������� � ��������� ����������

/***************************************************************
    ������ � ��������� � ��� ����������
 ***************************************************************/

//������ � ������ ��������� ����������. RegNo � ����� ��������.

msp_WORD msp_ReadReg(msp_DEVHANDLE device, msp_BYTE RegNo);
msp_ERROR msp_WriteReg(msp_DEVHANDLE device, msp_BYTE RegNo, msp_WORD Data);


//������ � ������ ���� � ������� ���� �� ��� ����������. Address � ����� � ��� ����������.

msp_WORD  msp_ReadRamW   (msp_DEVHANDLE device, msp_WORD Address);
msp_ERROR msp_WriteRamW  (msp_DEVHANDLE device, msp_WORD Address, msp_WORD Data);
msp_DWORD msp_ReadRamDW  (msp_DEVHANDLE device, msp_WORD Address);
msp_ERROR msp_WriteRamDW (msp_DEVHANDLE device, msp_WORD Address, msp_DWORD Data);

#define msp_ReadRam msp_ReadRamW
#define msp_WriteRam msp_WriteRamW
//��� ������

//��������� ������ ���������� �� ��� ��� � ��� ����� � �������.
//����� �������� � ������

msp_ERROR msp_ReadRamBLK  (msp_DEVHANDLE device, msp_WORD Address, void *Data, msp_WORD Length);
msp_ERROR msp_WriteRamBLK (msp_DEVHANDLE device, msp_WORD Address, void *Data, msp_WORD Length);

//���������� ����� � ��� ��� ����������.
msp_ERROR msp_FillRamBLK (msp_DEVHANDLE device, msp_WORD Address, msp_WORD Data, msp_WORD Length);

//��������� ������ ���������� �� ��� ��� � ��� ����� � �������
//�� ����������� ������� ��������� �������.
//NextAddress �.�. NULL.

msp_ERROR msp_ReadRamCIRC(msp_DEVHANDLE device, msp_WORD Address, void *Data,
						  msp_WORD Length, msp_DWORD Modulo, msp_WORD *NextAddress);
msp_ERROR msp_WriteRamCIRC(msp_DEVHANDLE device, msp_WORD Address, void *Data, 
						   msp_WORD Length, msp_DWORD Modulo, msp_WORD *NextAddress);

//������ � ������ ��������� ����������� PCI. RegNo - ����� ��. �����
//��� ������� �� �������� ������ ������������ RTL � ����� �� ��������������
//� ������ ������� � �� ������ ����������
msp_DWORD msp_LPCI_ReadReg(msp_DEVHANDLE device, msp_BYTE RegNo);
msp_ERROR msp_LPCI_WriteReg(msp_DEVHANDLE device, msp_BYTE  RegNo, msp_DWORD Data);

/*************************************************************************
  �������� ���
  0x00-0x0F �������� ����-���������� (BU-61580)
  0x10-0x1F �������� ����-���������� �� ������������ (BU-61580)
  0x20-0x21	�������� ���: ������� ���� �� ������������
  0x40-???	�������� ��� (�� �����������)
**************************************************************************/

#define		mspRR_INTERRUPT_MASK			0x00
#define		mspRR_CONFIG1					0x01
#define		mspRR_CONFIG2					0x02
#define		mspRR_COMMAND					0x03
#define		mspRR_COMMAND_STACK_POINTER		0x03
#define		mspRR_CONTROL_WORD				0x04
#define		mspRR_TIME_TAG					0x05
#define		mspRR_INTERRUPT_STATUS			0x06
#define		mspRR_CONFIG3					0x07
#define		mspRR_CONFIG4					0x08
#define		mspRR_CONFIG5					0x09
#define		mspRR_DATA_STACK_ADDRESS		0x0A
#define		mspRR_FRAME_TIME_REMAINING		0x0B
#define		mspRR_MESSAGE_TIME_REMAINING	0x0C
#define		mspRR_BC_FRAME_TIME				0x0D
#define		mspRR_RT_LAST_COMMAND			0x0D
#define		mspRR_MT_TRIGGER				0x0D
#define		mspRR_RT_STATUS_WORD			0x0E
#define		mspRR_RT_BIT_WORD				0x0F
#define		mspRR_MRT_ADDRESS				0x10
#define		mspRR_MRT_CONFIG1				0x11
#define		mspRR_MRT_STATUS				0x15
#define		mspRR_MRT_INTERRUPT_STATUS		0x16
//lve new config
#define		mspRR_CONFIG6					0x18
#define		mspRR_MRT_COMMAND_WORD			0x1D
#define		mspRR_MRT_STATUS_WORD			0x1E

//Test mode registers 0x10-0x17 are not defined here
//but still accessible

#define		mspRR_EXTERNAL_CONFIG			0x20
#define		mspRR_EXTERNAL_RT_ADDRESS		0x21
#define		mspRR_EXTERNAL_CDIVIDER			0x22
#define		mspRR_EXTERNAL_FLOG_ID			0x23
// USB
#define		mspRR_EXTERNAL_USB_POWER		0x24
#define		mspRR_EXTERNAL_USB_FIRMWARE_VERSION	0x25
#define		mspRR_EXTERNAL_USB_COMMAND		0x26
//Software only
#define		mspRR_SOFTWARE1					0xFF
#define		mspRR_SOFTWARE2_MRT_ISR			0xFE
//--
#define     mspRR_SOFTWARE_LOW				mspRR_SOFTWARE2_MRT_ISR

// ��� ������ ���
#define		mspRR_WG_DATA_STACK_POINTER			0x03
#define		mspRR_WG_INITIAL_DATA_STACK_POINTER	0x04
		
// �������� �������� �������
#define		msp_CLOCK_12MHz		1
#define		msp_CLOCK_16MHz		0
#define		msp_CLOCK_24MHz		2
#define		msp_CLOCK_48MHz		3

/*************************************************************************
  �������� ����������� PCI 9050
  ��� �������� �� �������� ������ ������������ RTL
  � ����� �� �������������� � ������ ������� � ��
  ������ ����������
**************************************************************************/

#define LPCI_LAS0RR		0x00
#define LPCI_LAS1RR		0x01
#define LPCI_LAS2RR		0x02
#define LPCI_LAS3RR		0x03
#define LPCI_EROMRR		0x04
#define LPCI_LAS0BA		0x05
#define LPCI_LAS1BA		0x06
#define LPCI_LAS2BA		0x07
#define LPCI_LAS3BA		0x08
#define LPCI_EROMBA		0x09
#define LPCI_LAS0BRD	0x0A
#define LPCI_LAS1BRD	0x0B
#define LPCI_LAS2BRD	0x0C
#define LPCI_LAS3BRD	0x0D
#define LPCI_EROMBRD	0x0E
#define LPCI_CS0BASE	0x0F
#define LPCI_CS1BASE	0x10
#define LPCI_CS2BASE	0x11
#define LPCI_CS3BASE	0x12
#define LPCI_INTCSR		0x13
#define LPCI_CNTRL		0x14

/*************************************************************************
  ��������� ����������
**************************************************************************/

typedef void (*msp_ISR)(msp_DEVHANDLE device);

msp_ERROR msp_SetISR (msp_DEVHANDLE device, msp_ISR ISR);
//���������� �/� ��������� ���������� �� ������� ��������� (device).
//������� ������������� ������� ����� ���������� ���,
//��������� ���������� �� ������ ����������� 9050

/************************************************************************
    ��������� ������������� ������ ���
 ************************************************************************/

msp_DEVHANDLE mspi_OpenAccess64(int i);
//���������� msp_OpenAccess(),
//������ � ������� ��� �� ����� ����

/************************************************************************
    ���������������� ������ � ��� ����� "BackDoor"
 ************************************************************************/
msp_DEVHANDLE mspi_OpenBackDoor(int i);
msp_ERROR mspi_SwitchBackDoorBank(msp_DEVHANDLE device, int code);
/************************************************************************
    ��������� ������ ZEROWAIT
 ************************************************************************/

typedef void (*msp_Delay)(msp_DEVHANDLE device, int count);

msp_ERROR msp_RegisterDelay(msp_Delay fndelay, int count);

/***************************************************************
    ������� ������������ ����� � ������������� �����������
 ***************************************************************/

msp_DEVHANDLE mspi_OpenAccess_Multi(msp_DEVHANDLE device,int i);
//��������� ����������� ���������� (��) ����������������� ����������
//device - ���������������� ����������
//i - ����� ��
//� device ������ ���� ������ ����� msp_MODE_MRT ��� ���������� ��� 14 � CONFIG2
//����� ������������ msp_Open_Multi() (config.h)

#define ofs_MRT_REGISTER_OVERRIDE 3 
#define mask_MRT_REGISTER_OVERRIDE ((msp_WORD)(1 << ofs_MRT_REGISTER_OVERRIDE))
#define ofs_MRT_ATOMIC_RW 4
#define mask_MRT_ATOMIC_RW ((msp_WORD)(1 << ofs_MRT_ATOMIC_RW))
//����������� ��� ����������� �������������

/***************************************************************
    ��������� ��������� �� USB
 ***************************************************************/

// ������� ��� USB ����������
#define USB_POWER_EXTERNAL	1
#define USB_POWER_INTERNAL	0
// ������������ ������� USB ����������
// code = USB_POWER_EXTERNAL - ������� �� ��
//      = USB_POWER_INTERNAL - ���������� �� USB
msp_ERROR msp_USB_SwitchPower(msp_DEVHANDLE device, int code);

HANDLE msp_USB_GetHandle(msp_DEVHANDLE device);
//���������� ��������� ���������� ����������,
//������� ����� ������������ � �������� MPApi.h

msp_DWORD mspi_InstanceIdForPci(msp_BYTE bus, msp_BYTE device);
void mspi_PciInstanceIdParse(msp_DWORD instanceId, msp_BYTE* bus, msp_BYTE* device);

msp_DWORD mspi_InstanceIdForVxi(msp_BYTE crate, msp_BYTE slot, msp_BYTE mezonin);
void mspi_VxiInstanceIdParse(msp_DWORD instanceId, msp_BYTE* crate, msp_BYTE* slot, msp_BYTE* mezonin);

#ifdef __cplusplus
}
#endif

#endif
