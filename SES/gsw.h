/***************************************************************
	gsw.h

	Generator of the sequences of the words

	��������� ������ � ������ ������� ���
	RTL2 (���������� ������� ���������� ���/����)

	(�) �.�������, 2001-2008.
	��� "������".
****************************************************************/
/***************************************************************
	������� ���������: 
	
 ***************************************************************/

#ifndef GSW_H
#define GSW_H

#include "types.h"
#include "access.h"
#include "errors.h"
#include "bc.h"
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef msp_HANDLE  msp_WG_MSGHANDLE;
typedef msp_HANDLE  msp_WG_FRMHANDLE;


#define msp_WGReadRam   msp_WGReadRamW
#define msp_WGWriteRam  msp_WGWriteRamW



// ������� ��������� �� ����� ��������� 
// �������� ������������� msp_MW_XXX �� ����� bc.h
#define msp_MW_DATA	             0x00
#define	msp_MW_ABS               0x40
#define msp_MW_NO_MORE	         0xFF
#define msp_MW_FREE_DATA_BEGIN   0x60

// ����� ����� ������������� ����������
#define msp_WGCW_LOOP        0x20 
#define msp_WGCW_ERROR       0x10
#define msp_WGCW_COMMAND     0x08
#define msp_WGCW_CHANNEL_B   0x04
// ����� ��� ����������� ���
#define msp_WGCW_CONTIGUOUS  0x02
#define msp_WGCW_SET         0x40
#define msp_WGCW_INVERT      0x80
#define msp_WGCW_EXIT_WM     0x01
#define msp_WGCW_INFIN_WM    0x100

// ������� ���� �������� ������
#define msp_INJ_NONE               0xC000
#define msp_INJ_ERROR_INVERT_LEFT  0x00
#define msp_INJ_ERROR_INVERT_RIGHT 0x01
#define msp_INJ_ERROR_SKIP         0x02
#define msp_INJ_ERROR_WORDLEN      0x03

// ������� ����� ��� msp_Message
#define msp_MSG_CMD1         0x01 
#define msp_MSG_CMD2         0x02
#define msp_MSG_STATUS1      0x04
#define msp_MSG_DATA         0x08
#define msp_MSG_STATUS2      0x10

// 
#define msp_NO_STATUS_WORD   0xFFFF
#define msp_NO_WORD          0xFFFF

// ����� ����������� ���� � ������ ��������
#define msp_WGM_CHANNEL_A    0
#define msp_WGM_CHANNEL_B    0x80
#define msp_ROLE_BC          0x40
#define msp_ROLE_RT          0x20
#define msp_ROLE_RT2         0x10

// ������� ���������� ������� ���� (��������/���������/�������������)
#define msp_WG_CHECK_NONE    0x00
#define msp_WG_ABSENT        0x00
#define msp_WG_TRANSMIT      0x01
#define msp_WG_CHECK_PRESENT 0x02
#define msp_WG_CHECK_VALUE   0x03

// ������� ���������� ���������
#define msp_WG_CHK_OK              0x00
#define msp_WG_CHK_NOT_MATCH       0x01
#define msp_WG_CHK_ERROR           0x02
#define msp_WG_CHK_ERROR_GAP       0x03
#define msp_WG_CHK_ANOTHER_CHANNEL 0x04
#define msp_WG_CHK_MISSING         0x05
#define msp_WG_CHK_NONE            0xFF
#define msp_WG_CHK_BUSY            0x06 // < ������ ��� ��������� �����!

// ������ �������� � �����. ������� � ������ �� ��������� �������
#define msp_EXIT_FROM_WM           0x80

// ����� �������������� ���������� ���������
#define mspF_WG_MESS_CLEAR         0x0000
#define mspF_WG_MESS_IMPOSE        0x0001


/**************************/
/* �-��� ������ � ��� ��� */
/**************************/

msp_WORD	msp_WGReadRamW (msp_DEVHANDLE device, msp_DWORD Address);
msp_ERROR	msp_WGWriteRamW  (msp_DEVHANDLE device, msp_DWORD Address, msp_WORD Data);
msp_DWORD	msp_WGReadRamDW  (msp_DEVHANDLE device, msp_DWORD Address);
msp_ERROR	msp_WGWriteRamDW (msp_DEVHANDLE device, msp_DWORD Address, msp_DWORD Data);

msp_ERROR	msp_WGReadRamBLK  (msp_DEVHANDLE device, msp_DWORD Address, void *Data, msp_DWORD Length);
msp_ERROR	msp_WGWriteRamBLK (msp_DEVHANDLE device, msp_DWORD Address, void *Data, msp_DWORD Length);
msp_ERROR	msp_WGFillRamBLK (msp_DEVHANDLE device, msp_DWORD Address, msp_WORD Data, msp_DWORD Length);


/****************************/
/* �������������� ��������� */
/****************************/

///////////////////////////////////
// �������������� ������� ���������
msp_Message* msp_WG_FormatMessage(
				msp_Message*	buffer,
				msp_BYTE		type,
				msp_BYTE		RT,
				msp_BYTE		SA,
				msp_BYTE		RTR_MC,
				msp_WORD		SAR_MCD,
				msp_BYTE		dataWordCount,
				msp_WORD		*data,
				msp_WORD		ST1,
				msp_WORD		ST2,
				msp_BYTE		wgmcw,
				msp_BYTE		checkalso);

//////////////////////////////////////
// �������������� ������������ ���������
msp_Message* msp_WG_ExtendMessage(
				msp_Message*	buffer,
				msp_WORD		*data,
				msp_WORD		ST1,
				msp_WORD		ST2,
				msp_BYTE		wgmcw,
				msp_BYTE		checkalso);


/*******************/
/* ������ � ������ */
/*******************/

/////////////////
// �������� �����
msp_WG_FRMHANDLE	
msp_WGCreateFrame(msp_DEVHANDLE device);

/////////////////////////
// ����� �������� � �����
msp_DWORD	
msp_WGGetMessageCount(msp_WG_FRMHANDLE frame);

/////////////////
// �������� �����
msp_ERROR	
msp_WGDestroyFrame(msp_WG_FRMHANDLE frame);

////////////////////////////////////////////////////////////////////////////////
// �������� ����� � ��������� ��������� � ������� (NRP - No Response Protection)
msp_WG_FRMHANDLE 
msp_WG_LoadFrameWithNRP(msp_WG_FRMHANDLE frame, msp_WORD time);
// time - ����� �������� ��������� � �������� (�� ����� ������������ ���������� ��������� + 12 ���)
// � ��� (������������� ����� 700 ���), ��� �������� 0,
// ����������� ������� "�������" �������� � ��������, �� ������� �����
// �� ������.

// ��������� ���������� "�����" � 700 ���
#define msp_WG_LoadFrame700ms(frm) msp_WG_LoadFrameWithNRP(frm, 700)


/*************************/
/* ������ � �����������  */
/*************************/

/////////////////////
// �������� ���������
msp_WG_MSGHANDLE	
msp_WG_CreateMessage(msp_DEVHANDLE device, msp_Message* buffer);

////////////////////////////
// ��������� ������ ��������
msp_ERROR 
msp_WG_SetTransmit(msp_WG_MSGHANDLE message, msp_BYTE set, msp_BYTE reset);
// set � reset ��������� ������� ������ msp_MSG_xxx

////////////////////////////
// ��������� ������ ��������
msp_ERROR 
msp_WG_SetCheck(msp_WG_MSGHANDLE message, msp_BYTE set, msp_BYTE reset);
// set � reset ��������� ������� ������ msp_MSG_xxx

/////////////////////
// �������� ���������
msp_ERROR 
msp_WG_DestroyMessage(msp_WG_MSGHANDLE message);

///////////////////////////// 
// �������� ������� ���������
msp_WG_MSGHANDLE 
msp_WG_CreateEmptyMessageEx(msp_DEVHANDLE device, msp_BYTE role);

///////////////////////////////////
// �������� ������������ ���������
msp_WG_MSGHANDLE	
msp_WG_CreateFreeMessage(
						 msp_DEVHANDLE device,
						 unsigned int num_triads,
						 int flags,
						 int gap_time,
						 msp_BOOL transmit
						 );
// num_triads - ���-�� ������������/����������� ���� 
// flags : ����� - msp_WGM_CHANNEL_X 
// gap_time - ����� ��������
// transmit = msp_TRUE - ��������, msp_FALSE - ����

/**********************************************/
/* ��������� �������� � ����������� ��������� */
/**********************************************/

////////////////////////////////////////////
// ������ ������������ ����� �������� ������
#define FormatErrorWord(error_type, error_pos, error_dur)\
					((unsigned short)((error_type<<14) | (error_pos) | (error_dur<<6)))

/////////////////////////////////////////////////////////////////////
// ��������� �������� ���� �������������� ��������� � ������
typedef struct{
	msp_BYTE wordref;
	msp_WORD gap;
	msp_WORD flags;
	msp_WORD error;
	} msp_Diversion; // ���������� ��� � ���

////////////////////////////////////////////////////////////////////
// ������� ��� �������� ������ � ���� error ��������� msp_Diversion
////////////////////////////////////////////////////////////////////

// ������ ��������� �� ����������� ������� clock
#define msp_DEV_CLOCK  41.66   

// ������� ��� �������� ������ � ������������ �� ���������� ����������
#define msp_INJERR_SYNCHRO_111100		FormatErrorWord(1, 3, 12)
#define msp_INJERR_SYNCHRO_110000		FormatErrorWord(1, 2, 12)
#define msp_INJERR_SYNCHRO_111001		FormatErrorWord(1, 5, 12)
#define msp_INJERR_SYNCHRO_011000		FormatErrorWord(1, 0, 12)
#define msp_INJERR_SYNCHRO_000011		msp_INJERR_SYNCHRO_111100
#define msp_INJERR_SYNCHRO_001111		msp_INJERR_SYNCHRO_110000
#define msp_INJERR_SYNCHRO_000110		msp_INJERR_SYNCHRO_111001
#define msp_INJERR_SYNCHRO_100111		msp_INJERR_SYNCHRO_011000



// ������� ��� �������� ������ �������� �������� ��������� ����
// x - �������� ��� �� 1 �� 16
#define msp_INJERR_SKIP_BIT(x) 	FormatErrorWord(2, 6 + 2*x, 24)


// ������� ��� ������ ����������� ���� �������������� ����� � ������, 
// �� y ����������
#define msp_INJERR_SYNCHRO_SHIFT_LEFT(y)	FormatErrorWord(0, 2, (int)(12 - (y/msp_DEV_CLOCK)))
#define msp_INJERR_SYNCHRO_SHIFT_RIGHT(y)	FormatErrorWord(1, 3, (int)(y/msp_DEV_CLOCK))

// ������� ��� ������ ����������� ���� ��������� ���� � ����� � ������, 
// �� y ���������� (���� ���������� �� 1)
#define msp_INJERR_SIGN_LEFT(x, y)	FormatErrorWord(0, 4 + x*2, (int)(12 - (y/msp_DEV_CLOCK)))
#define msp_INJERR_SIGN_RIGHT(x, y) FormatErrorWord(1, 5 + x*2, (int)(y/msp_DEV_CLOCK))
#define msp_INJERR_SIGN_INVERT(x)	FormatErrorWord(1, 4 + x*2, 24)

// ������� ��� �������� ������ ����������� ���� ���������� (������� ��� ������) �������
// x - �������� ��� �� 1 �� 16
#define msp_INJERR_RECTIFY(x, lr)		(lr == 0) ? msp_INJERR_SIGN_LEFT(x, 12) : msp_INJERR_SIGN_RIGHT(x, 12)

// ������� ��� ������ ����������� ���� ���� �������� ����� � ������, 
// �� y ���������� (���� ���������� �� 1)
#define msp_INJERR_PARITY_LEFT(y)	msp_INJERR_SIGN_LEFT(17, y)
#define msp_INJERR_PARITY_RIGHT(y)	msp_INJERR_SIGN_RIGHT(17, y)
#define msp_INJERR_PARITY_INVERT	msp_INJERR_SIGN_INVERT(17)

// ������� ����������/���������� ����� �� 1-3 ���
#define msp_INJERR_SHORTING_1_BIT		FormatErrorWord(3, 3, 0)
#define msp_INJERR_SHORTING_2_BIT		FormatErrorWord(3, 2, 0)
#define msp_INJERR_SHORTING_3_BIT		FormatErrorWord(3, 1, 0)
#define msp_INJERR_LENGTHENING_1_BIT	FormatErrorWord(3, 4, 0)
#define msp_INJERR_LENGTHENING_2_BIT	FormatErrorWord(3, 5, 0)
#define msp_INJERR_LENGTHENING_3_BIT	FormatErrorWord(3, 6, 0)

/////////////////////////////
// �������� ����� � ���������
msp_ERROR 
msp_WG_InsertWord(msp_WG_MSGHANDLE message, msp_BYTE wordref,
							msp_BYTE status, msp_WORD data);

/////////////////////////////
// ������� ����� �� ���������
msp_ERROR 
msp_WG_RemoveWord(msp_WG_MSGHANDLE message, msp_BYTE wordref);

/////////////////////////////
// �������� �����
msp_ERROR 
msp_WG_ChangeWord(msp_WG_MSGHANDLE message, msp_BYTE wordref, msp_WORD data);
// wordref - msp_MW_xxx

/////////////////////////////
// �������� ����� �� ���������
msp_WORD 
msp_WG_GetWord(msp_WG_MSGHANDLE message, msp_BYTE wordref);
// wordref - msp_MW_xxx


//////////////////////////////
// �������� ������ � ���������
msp_WG_MSGHANDLE	
msp_WG_DivertWord(
				msp_WG_MSGHANDLE message,
				msp_BYTE	wordref,
				msp_WORD	gap,
				msp_BYTE	flags,
				msp_WORD	error
				);

///////////////////////////////////////////////////////////////////////////////
// �������� ������ � ����� ��������� ��� ������ ������� ��������� msp_Diversion
msp_WG_MSGHANDLE	
msp_WG_DivertWordIndirect(
				msp_WG_MSGHANDLE message,
				msp_Diversion *diversion);

//////////////////////////////////////////////////////////////////////////////////////
// �������� ������ �� ��� ��������� ��� ������ �������� ������� �������� msp_Diversion
msp_WG_MSGHANDLE	
msp_WG_DivertMessageIndirect(
				msp_WG_MSGHANDLE message,
				msp_Diversion *diversions);

///////////////////////////////////////////////////////////////////////////////////////
// �������� �������������� ���������� ���������.
// � ��������� ������ ��������� ������ ����������/�������� ���������.
// �������� ���������, ��� ��������� � ����������, ��� �������� ����� (msp_WG_LoadFrame)
// ��������� �������� �� ���������, � ���� ��� ���������� ���� � �����.
msp_ERROR	
msp_WG_MessageParams(
				msp_WG_MSGHANDLE message, // "���������������" ���������
				int type_param, // ��� ���������
				float param  // ���. ��������
				);
// ��� ���������: 
//         mspF_WG_MESS_CLEAR
//         mspF_WG_MESS_IMPOSE
// ���������:
//         ��� mspF_WG_MESS_IMPOSE - ����� �������� ��������� � ���


/**********************************/
/* �������� ����������� ��������� */
/**********************************/

/////////////////////////////////////////////////
// ������� �������� ������������ ���������
#define msp_WG_TERM_WM          0x0001
#define msp_WG_TERM_LOOP        0x0020
#define msp_WG_TERM_STOP        0xFFC0
#define msp_WG_TERM_PAUSE       0x0003
#define msp_WG_TERM_EXIT_WM     0x0007

msp_WG_MSGHANDLE	
msp_WG_CreateTerminalMessage(
						msp_DEVHANDLE	device,
						int code,
						msp_WORD time);

// ������� - ����� ���������
// code - ���� �� �������� msp_WG_TERM_XXX
// time - ����� (���� ���������)



/*******************************/
/* ���������� ��������� � ���� */
/*******************************/

////////////////////////////////////////
// ���������� ��������� ��������� � ����
msp_ERROR	
msp_WG_AddMessage(
					msp_WG_FRMHANDLE frame,
					msp_WG_MSGHANDLE message);

///////////////////////////////////////////////
// ������ ���������� ��������� ��������� � ����
msp_ERROR	
msp_WG_AddMessageIndirect(
				msp_WG_FRMHANDLE frame,
				msp_Message *message,
				msp_Diversion *diversions);

////////////////////////////////////////
// ���������� ��������� ��������� � ����
msp_ERROR	
msp_WG_AddMessagesIndirect(
				msp_WG_FRMHANDLE frame,
				int count,
				msp_Message *messages,
				msp_Diversion *diversions);


///////////////////////////////////////////////////
// ��������� ������ ��������� �� ��� ������ � �����
msp_WG_MSGHANDLE	
msp_WG_GetFrameMessage(
							msp_WG_FRMHANDLE frame,
							int entry);


/*******************************/
/* ��������� ��������� � ����� */
/*******************************/

/////////////////////////////////////
// ��������� ��������� �� ����������
msp_ERROR
msp_WG_MessageImpose(
					msp_WG_FRMHANDLE frame, 
					int entry,
					float time
					);
// frame - ���� ���������
// entry - ����� ��������� � �����, �������, ����� "�������������" �� 
//         ����������
// time - ����� �������� (� ���) � ��������� �� 0.25 ���


/********************************************/
/* �������� ������� ������������ ���������� */
/********************************************/

////////////////////////////////////////////////////////////
// ���������� ����������� ���������� ������������� ���������
// ���������� � gaptime �������� ��� = 0,5 ���.
msp_WORD	
msp_WG_GetGap(
						msp_WG_FRMHANDLE frame,
						int entry,
						msp_BYTE wordref);

// ��������� ����-�� ���������� � ���
#define msp_WG_GetGapMks(frm, entr, wref) (msp_WG_GetGap(frm, entr, wref) / 2)


/////////////////////////////////
// ��������� ����������� �������� 
msp_ERROR	
msp_WG_GetProcessedMessage(
						msp_WG_FRMHANDLE frame,
						int entry,
						msp_Message *response);
// ���������� msp_WG_CheckMessage, �� ����������� ����, ��� � 
// response ���������� ��������� ������������������ �� ��������


///////////////////////////////////////////////////////
// ��������� ��������� � ��������� (����������� ������)
msp_ERROR	
msp_WG_CheckMessageEx(
						msp_WG_FRMHANDLE frame,
						int entry,
						msp_Message *details,
						msp_Message *response,
						msp_Message *etalon,
						msp_BOOL ignore_status_set);
// ������� - msp_NOERROR ��� ��� ������
// frame - ����� �����
// entry - ������� ��������� � ����� (������� � 0)
// details - ��������� msp_Message c ����������� ���������� �-��� msp_WG_CheckMessage
//			 (�������� �������� NULL)
// response - ��������� msp_Message c ����������� ���������� �-��� msp_WG_GetProcessedMessage
//			 (�������� �������� NULL)
// etalon - ��������� msp_Message ������� ��������� � �����
//			 (�������� �������� NULL)
// ignore_status_set -	msp_TRUE - ������������ ����� ��������� ����� ��� ���������
//						msp_FALSE - ��������� ����� ��������� ����� ��� ��������� (�� ���������
//						�� ��� BUSY - ������� �����)


///////////////////////////////////////////////////////////////////
// ��������� ���� ��������� ����� � ���������� (����������� ������)
msp_ERROR	
msp_WG_CheckMessagesEx( 
						msp_WG_FRMHANDLE frame,
						msp_Message *details,
						msp_Message *response,
						msp_Message *etalon,
						msp_BOOL ignore_status_set);
// ������� - msp_NOERROR ��� ��� ������
// frame - ����� �����
// details - ��������� �� ������ �������� msp_Message c ����������� ���������� �-��� msp_WG_CheckMessage
//			 (�������� �������� NULL)
// response - ��������� �� ������ �������� msp_Message c ����������� ���������� �-��� msp_WG_GetProcessedMessage
//			 (�������� �������� NULL)
// etalon - ��������� �� ������ �������� msp_Message ������� ��������� � �����
//			 (�������� �������� NULL)
//			������ �������� details, response, etalon �.�. �� ����� ����� ��������� � �����
// ignore_status_set -	msp_TRUE - ������������ ����� ��������� ����� ��� ���������
//						msp_FALSE - ��������� ����� ��������� ����� ��� ��������� (�� ���������
//						�� ��� BUSY - ������� �����)



/***********************************************/
/* �������� ���������� ���������� (������) ��� */
/***********************************************/
/////////////////////////////////////////////////
msp_ERROR 
msp_WG_WaitEndOfWork(msp_DEVHANDLE device);
// ������� - msp_NOERROR ��� ��� ������

/***********************************************/
/* ������� ���������������� ����������		   */
/***********************************************/
/////////////////////////////////////////////////
msp_ERROR 
msp_WG_QuickConfig(msp_DEVHANDLE device, msp_MODE mode, msp_BOOL clear_mem);


/*************************************************************************/
/* ������� ������ ���������� (legacy) �-��� (��� �������� �������������) */
/*************************************************************************/
// ��������� ��������� � ���������
#define msp_WG_CheckMessage(frm, entr, det) \
								msp_WG_CheckMessageEx(frm, entr, det, NULL, NULL, msp_FALSE)
// ��������� ���� ��������� ����� � ����������
#define msp_WG_CheckMessages(frm, det) \
								msp_WG_CheckMessagesEx(frm, det, NULL, NULL, msp_FALSE)
// �������� ����� � ����������
#define msp_WGLoadFrame(frm) \
				msp_WG_LoadFrame700ms(frm)
// �������� ����� � ���������� c "������" ���������
#define msp_WGLoadFrameInfin(frm) \
				msp_WG_LoadFrameWithNRP(frm, 0)
// �������� ������� ���������
#define msp_WG_CreateEmptyMessage(device) \
				msp_WG_CreateEmptyMessageEx(device, msp_ROLE_BC)

				
// �������� ���������� ���������� (������) ���
#define gsw_WaitEndOfWork(hd) msp_WG_WaitEndOfWork(hd)
// ������ ���
#define gsw_Start(hd) msp_Start(hd)
// ����� ���
#define gsw_Reset(hd) msp_Reset(hd)
// ���������������� ��� 
// select_mode : msp_WG_FIRST ��� msp_WM_FIRST
#define gsw_Config(hd, mode) msp_WG_QuickConfig(hd, mode, msp_TRUE)
// ��������� ��������� ����� ���
#define gsw_SetStackPointer(hd, stack) msp_WriteReg(hd, mspRR_WG_INITIAL_DATA_STACK_POINTER, stack)




#ifdef __cplusplus
	}
#endif

#endif
