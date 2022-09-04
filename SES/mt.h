/***************************************************************
	mt.h
	��������� ������ MT.

	RTL2 - ���������� ������� ���������� ���/����.

	(�) �.������, 2000.
	�� ������ ��� ������.
 ***************************************************************/
/***************************************************************
	������� ���������:

 ***************************************************************/

#ifndef MT_H
#define MT_H

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
	��������� ������ WM.
 ***************************************************************/

#define msp_ReadWordTrace(device, index) msp_ReadRamDW(device, index << 1)

#define msp_WM_GAP_TIME_mask	0xFF00
#define msp_WM_WORD_FLAG		0x0080
#define msp_WM_N_THIS_RT		0x0040
#define	msp_WM_N_BROADCAST		0x0020
#define msp_WM_ERROR			0x0010
#define msp_WM_SYNC_TYPE		0x0008  //1 for command, 0 for data
#define msp_WM_CHANNEL			0x0004	//1 for B, 0 for A
#define msp_WM_N_GAP			0x0002
#define msp_WM_N_MODECODE		0x0001

#define msp_WMD_GAP_TIME_mask	(msp_WM_GAP_TIME_mask << 16)
#define msp_WMD_WORD_FLAG		(msp_WM_WORD_FLAG << 16)
#define msp_WMD_N_THIS_RT		(msp_WM_N_THIS_RT << 16)
#define msp_WMD_N_BROADCAST		(msp_WM_N_BROADCAST << 16)
#define msp_WMD_ERROR			(msp_WM_ERROR << 16)
#define msp_WMD_SYNC_TYPE		(msp_WM_SYNC_TYPE << 16)
#define msp_WMD_CHANNEL			(msp_WM_CHANNEL << 16)
#define msp_WMD_N_GAP			(msp_WM_N_GAP << 16)
#define msp_WMD_N_MODECODE		(msp_WM_N_MODECODE << 16)

#define msp_WM_GAP_TIME(W) ((W) >> 8)
#define msp_WMD_GAP_TIME(DW) ((DW) >> 24)

/***************************************************************
	���������������� ������� ������ ���������.
 ***************************************************************/

#define msp_MT_SELECTED		1
#define msp_MT_UNSELECTED	0

msp_ERROR msp_MTSelectMessages(
				msp_DEVHANDLE device, 
				msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, 
				msp_BIT select);
//����� ��������� ��� ����������� (��������� ��� � MT lookup table).
//device � ����������
//rangeCmdWord0,
//rangeCmdWord1 - ������� 1553, ������������ ������� �������� ��������
//		��� ������� ������� ������� sampleCmdWord1 ������ ���������
//		��������, � sampleCmdWord2 - ��������;
//		������������ ������� <RT> (��), <TX> (��������/�����*), <SA> (��������)
//		������������ ������� <WCNT> (����� ���� ������)
//select � ������� ������������ ������ ���������;
//		�������� msp_MT_SELECTED (0x01) ��� msp_MT_UNSELECTED (0x00)

msp_BIT msp_MTIsMessageSelected(msp_DEVHANDLE device, msp_WORD sampleCmdWord);
//���������� �������� ������ ������� ���� ��������� ��� �����������.

msp_ERROR msp_MTSelectMessagesIndirect(
				msp_DEVHANDLE device,
				msp_rangeCmdWords *ranges,
				int count,
				msp_BIT select);
//����� ��������� ��� ����������� �� �������
//device - ����������
//ranges - ������ ��� rangeCmdWord0, rangeCmdWord1
//			������ ���� ���������������� ���������� ����������
//			msp_SelectMessages()
//count	- ���������� ��������� � ������ ranges
//select � ������� ������������ ������ ���������;
//		�������� msp_MT_SELECTED (0x01) ��� msp_MT_UNSELECTED (0x00)

/***************************************************************
	�\� ������ �� ������ ������
 ***************************************************************/

msp_STKHANDLE msp_MTCreateStack(msp_DEVHANDLE device);
//�������� ����� ������ �� (�������������� ������� ���)
//device � ����������

#define msp_MTDestroyStack(stack) msp_DestroyHandle(stack)
//����������� �����.
//stack � ������������� (handle) �����
//�������: ��� ������

msp_ERROR msp_MTLoadStack(msp_STKHANDLE stack, int flags);
//�������� ������� ����� � �������� ����� ������ �� (A ��� B).
//stack � ������������� (handle) �����
//flags � ���� �� ��������
//	msp_STK_A � ��������� � ���� A
//	msp_STK_B � ��������� � ���� B

msp_ERROR msp_MTLoadStackWithOffset(msp_STKHANDLE stack, int start, int flags);
//�������� ������� ����� � �������� ����� ������ ��
//� ������������� ���������� ���������� ������ ���������
//stack � ������������� (handle) �����
//start - ��������� ����� ���������
//flags � ���� �� ��������
//	msp_STK_A � ��������� � ���� A
//	msp_STK_B � ��������� � ���� B

//See also msp_SetStkStart (config.h)

/***************************************************************
	�\� ������ �� ������ ������
 ***************************************************************/

typedef msp_RAMHANDLE msp_DSTKHANDLE;

msp_DSTKHANDLE msp_MTCreateDataStack(msp_DEVHANDLE device);
//�������� ����� ������
//device � ����������

#define msp_MTDestroyDataStack(stack) msp_DestroyHandle(stack)
//����������� ����� ������
//device � ����������

msp_ERROR msp_MTLoadDataStack(msp_DSTKHANDLE stack, int flags);
//�������� ������� ����� � �������� ����� ������
//stack - ���� ������
//flags � ���� �� ��������
//	msp_STK_A � ��������� � ���� A
//	msp_STK_B � ��������� � ���� B

msp_ERROR msp_MTLoadDataStackWithOffset(msp_DSTKHANDLE stack, msp_WORD start, int flags);
//�������� ����� � �������� ����� ������ � ������������� ����������
//���������� ������
//stack - ���� ������
//start - ��������� ����� ������������ ������ ����� (��������)
//flags � ���� �� ��������
//	msp_STK_A � ��������� � ���� A
//	msp_STK_B � ��������� � ���� B

msp_ERROR msp_MTResetDataStack(msp_DSTKHANDLE stack, msp_WORD address);
//��������� ���������� ������ ����� ������
//stack - ���� ������
//adsress - ��������� ����� ������������ ������ ����� (��������)
//���� ������ ���� ��������
#define msp_MTSetDStkStart msp_MTResetDataStack
//������ ��������

/***************************************************************
   ������ ��������� ��������� ���������
 ***************************************************************/

msp_ERROR msp_MTRetrieveMessage(msp_STKHANDLE stack, int index, msp_Message* buffer);
//���������� ��������� �� ��� ��� � ��� �����, ��������� �� ������� ��������� �� ����������� ��������� � ������ �����.
//stack � ����; 
//entry � ����� ����������� ��������� � �����
//buffer � ����� ��� ���������� ���������. � ������ ����������� �������������� ���� StatusWord1/2, loopback, BSW, timetag.
//������ ������ msp_RetrieveMessage, �� ������ ��� MT

#ifdef __cplusplus
}
#endif

#endif
