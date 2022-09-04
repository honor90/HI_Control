/***************************************************************
	bc.h
	��������� ������ ��.

	RTL2 - ���������� ������� ���������� ���/����.

	(�) �.������, 2000.
	�� ������ ��� ������.
 ***************************************************************/
/***************************************************************
	Revision history:

 ***************************************************************/

#ifndef BC_H
#define BC_H

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
   ����������� ��������.
 ***************************************************************/

typedef msp_RAMHANDLE	msp_MSGHANDLE;
typedef msp_STKHANDLE	msp_FRMHANDLE;

/***************************************************************
   Working with messaqes: creating, deleting, expecting, 
   editing, etc.
 ***************************************************************/

msp_Message* msp_FormatMessage(
		msp_Message* buffer,
		msp_BYTE type, 
		msp_BYTE RT, 
		msp_BYTE SA, 
		msp_BYTE RTR_MC, 
		msp_WORD SAR_MCD, 
		msp_BYTE dataWordCount,
		msp_WORD *data,
		msp_DWORD bccw);
//�������������� ��������� ��������� 
//� ���������� ��� � ��������� msp_Message.
//���������:
//buffer � ����� ��� ��������� ���������
//type � ��� ��������� (���� �� �������� mspM_XXXX)
//RT � ����� (0-31)
//SA � �������� (0-31)
//RTR_MC, SAR_MCD - ����� �� ���������� ��� mspM_RTtoRT
//                - ��� � ������ ��� mspM_MODECODE_XXXX
//dataWordCount � ����� ���� ������.
//data � ������. ����� ���� NULL, 
//               � ���� ������ ���� buffer->data �� ����������������.
//bccw - ����������� ����� �� (bitmapped). 3 ��. ������� ������������.
//����������: *buffer.

//������� ������������ ��������� � msp_FornatMessage
#define mspi_mcsa(cw) ((cw) & 0x20000?31:0)
#define msp_BCtoRT(B,RT,SA,wcnt,data,cw)	msp_FormatMessage(B, mspM_BCtoRT,					RT, SA,	0, 0, wcnt, data, cw)
#define msp_RTtoBC(B,RT,SA,wcnt,cw)			msp_FormatMessage(B, mspM_RTtoBC,					RT, SA,	0, 0, wcnt, NULL, cw)
#define msp_RTtoRT(B,RT,SA,RTR,SAR,wcnt,cw)	msp_FormatMessage(B, mspM_RTtoRT,					RT, SA,	RTR, SAR, wcnt, NULL, cw)
#define msp_BCtoRT_bcst(B,SA,wcnt,data,cw)	msp_FormatMessage(B, mspM_BCtoRT_BROADCAST,			0,	SA,	0, 0, wcnt, data, cw)
#define msp_RTtoRT_bcst(B,RT,SA,SAR,wcnt,cw) msp_FormatMessage(B, mspM_RTtoRT_BROADCAST,		RT, SA,	0, SAR, wcnt, NULL, cw)
#define msp_Modecode(B,RT,MC,cw)			msp_FormatMessage(B, mspM_MODECODE,					RT, mspi_mcsa(cw),MC, 0, 0, NULL, cw) 
#define msp_Modecode_data_tx(B,RT,MC,cw)	msp_FormatMessage(B, mspM_MODECODE_DATA_TX,			RT, mspi_mcsa(cw),MC, 0, 0, NULL, cw)
#define msp_Modecode_data_rx(B,RT,MC,MCD,cw) msp_FormatMessage(B, mspM_MODECODE_DATA_RX,		RT, mspi_mcsa(cw),MC, MCD, 0, NULL, cw)
#define msp_Modecode_bcst(B,MC,cw)				msp_FormatMessage(B, mspM_MODECODE_BROADCAST,	0,  mspi_mcsa(cw),MC, 0, 0, NULL, cw)
#define msp_Modecode_data_bcst(B,MC,MCD,cw)	msp_FormatMessage(B, mspM_MODECODE_DATA_BROADCAST,	0,  mspi_mcsa(cw),MC, MCD, 0, NULL, cw)
//msp_Message* B  <= buffer
//msp_WORD RT, SA <= address (single or source)
//msp_WORD RTR, SAR <= destination address
//msp_WORD wcnt <= data word cont
//msp_WORD* data <= transfer data 
//msp_WORD MC <= mode code
//msp_WORD MCD <= modecode data
//msp_WORD cw <= BCCW

//��������� ��� BCCW:
//� msp_CreateMessage ���� 0-2 ����������� ������������� �������� buffer->type
//�� ���� �� ��������
//BCCW_EX ������������ ������ � msp_FormatMessage � �� ������������ � msp_Message
#define msp_BCCW_RT_TO_RT_FORMAT		0x0001
#define msp_BCCW_BROADCAST_FORMAT		0x0002
#define msp_BCCW_MODE_CODE_FORMAT		0x0004
#define msp_BCCW_1553A					0x0008
#define msp_BCCW_1553B					0x0000
#define msp_BCCW_EOM_INTR_ENABLE		0x0010
#define msp_BCCW_MASK_BROADCAST			0x0020
#define msp_BCCW_SELFTEST				0x0040
#define msp_BCCW_CHANNEL_A				0x0080
#define msp_BCCW_CHANNEL_B				0x0000
#define msp_BCCW_RETRY_ENABLED			0x0100
#define msp_BCCW_RESERVED_MASK			0x0200
#define msp_BCCW_TERMINAL_FLAG_MASK		0x0400
#define msp_BCCW_SUBSYSTEM_FLAG_MASK	0x0800
#define msp_BCCW_BUSY_MASK				0x1000
#define msp_BCCW_SERVICE_REQUEST_MASK	0x2000
#define msp_BCCW_MESSAGE_ERROR_MASK		0x4000
#define msp_BCCW_EX_BROADCAST_DISABLED 0x10000
#define msp_BCCW_EX_MODECODE_SA_0	   0x00000
#define msp_BCCW_EX_MODECODE_SA_31	   0x20000

void msp_SetDefault_BCCW(msp_DWORD value);
//�������� �������� ����� ��������������� �� OR � ���������� bccw
//��� ������ ��������� � msp_FormatMessage

msp_MSGHANDLE msp_CreateMessage(msp_DEVHANDLE device, msp_Message* buffer);
//�������� ��������� � ��� ���.
//device � ������������� ����������. 
//buffer � ��������� ���������
//����������: ������������� (handle) ���������.

#define msp_DestroyMessage(message) msp_DestroyHandle(message)
//����������� ��������� � ��� ���.

msp_ERROR msp_ReadBCMessage(msp_MSGHANDLE message, msp_Message* buffer);
//�������� (� ��������������� �������) �������� ��������� �� ��� ���
//� ��������� msp_Message, ������� ���� StatusWord1/2, loopback. 
//�������������� ���������� �������� � �������� ������� ���� � 
//���������� �� ���� ��������� (� ���) �� ������������� (� buffer).
//message � ��. (handle) ���������
//buffer � ��������� ���� ����������

msp_BYTE msp_ReadMessageData(msp_MSGHANDLE message, msp_WORD* buffer, msp_BYTE wordcount);
//����������� ���� ������ ��������� �� ��� ���

msp_BYTE msp_WriteMessageData(msp_MSGHANDLE message, msp_WORD* buffer, msp_BYTE wordcount);
//����������� ���� ������ ��������� � ��� ���
//message - ���������
//buffer - 

msp_WORD msp_ReadMessageWord(msp_MSGHANDLE message, msp_BYTE word);
//������ ��������� ���� ��������� �� ��� ���.
//message - ���������
//word - ��������� �����. 
//��������� �������� 0-31 (�������� ����� ������) ��� ��������� msp_MW_XXXX

msp_ERROR msp_WriteMessageWord(msp_MSGHANDLE message, msp_BYTE word, msp_WORD value);
//������ ��������� ���� ��������� � ��� ���.
//message - ���������
//word - ��������� �����. 
//value - ����� ��������
//��������� �������� 0-31 (�������� ����� ������) ��� ��������� msp_MW_XXXX

#define msp_MW_BCCW			32
#define msp_MW_CMD1			33
#define msp_MW_CMD2			34
#define msp_MW_STATUS1		35
#define msp_MW_STATUS2		36
#define msp_MW_LOOPBACK		37
#define msp_MW_WORDCOUNT	38
#define msp_MW_MODECODE		39
//msp_MW_WORDCOUNT, msp_MW_MODECODE - �� �����, 5-������ ���� � CMD1

/***************************************************************
   ������ � �������: ��������, ��������, ���������� �����������,
   ���������, �����������
 ***************************************************************/

msp_FRMHANDLE msp_CreateFrame(msp_DEVHANDLE device, msp_WORD FrameTime, msp_WORD MessageCount);
//������� ���� �� �������� ����� ���������, ������� ������.
//device
//FrameTime � ������������ ����� � �������� �� 100 ���(?).
//MessageCount � ����� ��������� � �����.
//�������: �����. (handle) �����.

#define msp_DestroyFrame(frame) msp_DestroyHandle(frame)
//������� ����

msp_ERROR msp_AddMessage(msp_FRMHANDLE frame, msp_MSGHANDLE message, msp_WORD msggap);
//���������� ��������� � ����
//fram� � ����
//message � ���������
//msggap � �������� ����� ������� ������� � ������� ���������� ���������, ���
//���� � �� �� ��������� ����� ���� ������������ ��������� � ������ ����� ���
//��������� ��� � ���� ����

msp_ERROR msp_AddMessages(msp_FRMHANDLE frame, msp_MSGHANDLE *messages, msp_WORD *msggaps);
//���������� ������������������ ��������� � ����
//fram� � ����
//message - ������ (�������) ���������.
//			��������� ������� ������ ��������� �������� msp_NOHANDLE
//msggaps - ������ ���������� �������. 
//			�.�. NULL, ����� msggap ��������������� � 0

msp_ERROR msp_AddMessagesIndirect(msp_FRMHANDLE frame, msp_MSGHANDLE **messages, msp_WORD *msggaps);
//���������� ������������������ ��������� � ����
//fram� � ����
//messages - ������ ���������� �� (������) ���������
//			��������� ������� ������ ��������� �������� NULL
//msggaps - ������ ���������� �������. 
//			�.�. NULL, ����� msggap ��������������� � 0

msp_ERROR msp_AddMessagesIndirect2(msp_FRMHANDLE frame, msp_WORD *indexes, msp_MSGHANDLE *messages, msp_WORD *msggaps);
//���������� ������������������ ��������� � ����
//fram� � ����
//indexes - ������ �������� ��������� �� ���� messages.
//			��������� ������� ������ ��������� �������� 0xFFFF
//message - ��� (������) ������� ���������, ���������� �� ��������
//msggaps - ������ ���������� �������. 
//			�.�. NULL, ����� msggap ��������������� � 0

msp_BIT msp_VerifyFrameTime(msp_FRMHANDLE frame, msp_BIT adjust);
//�������� � ����������� ������������ �����
//�������: 1 - ��, 0 - ����� ���������� ��������� ������
//					�������� ������������ �����
//adjust !=0 && ������� == 0 - ������������ ���������� �� �����������
//fram� � ����

msp_MSGHANDLE msp_GetFrameMessage(msp_FRMHANDLE frame, int entry);
//���������� ����� ��������� �� ��� ����� � �����
//fram� � ����
//entry - ����� ������� � �����

msp_MSGHANDLE msp_ReplaceFrameMessage(msp_FRMHANDLE frame, int entry, msp_MSGHANDLE newmessage);
//�������� ��������� � �������� ������� ����� ������
//���������� ����� ��������� ������� ���������
//fram� � ����
//entry - ����� ������� � �����
//newmessage - ����� ������ ���������

msp_WORD msp_GetFrameProp(msp_FRMHANDLE frame, msp_BYTE Property);
//������ ������������� �����
//fram� � ����
//Property - ��������� ��������������
//����� ���� ����� �� ��������
//msp_FD_FrameTime
//msp_FD_MessageCount
//msp_FD_MaxMessgeCount

msp_ERROR msp_SetFrameProp(msp_FRMHANDLE frame, msp_BYTE Property, msp_WORD value);
//��������� ������������� �����
//fram� � ����
//Property - ��������� ��������������
//��������� ������ ��������
//msp_FD_FrameTime

#define msp_FD_FrameTime		0
#define msp_FD_MessageCount		1
#define msp_FD_MaxMessgeCount	2

/***************************************************************
   �������� (���������) ������� ����� � ���� ��� ����������.
 ***************************************************************/

msp_ERROR msp_LoadFrame(msp_FRMHANDLE frame, int flags);
//�������� ������� ����� � ��������� ����� � ��� B. 
//frame � ����
//flags � ���������� �������� (msp_STK_A � msp_STK_B �����������)
//msp_STK_A � ��������� � ���� A
//msp_STK_B � ��������� � ���� B
//msp_AUTOREPEAT � ������������� ����������� �������� ���
//��������������� ������� �����
//� ��������������� ������ mspF_FRAME_AUTOREPEAT

//������ ����� �� ���������� ������������� �������� msp_Command()

#define msp_AUTOREPEAT	0x0002

msp_ERROR msp_ResetFrame(msp_FRMHANDLE frame);
//��������� ��������� ��������� � ������ ��� ���������� ������� �����
//frame - ����
//���� �.�. �������

/***************************************************************
   ������� ������� ��������� ��������� �����
 ***************************************************************/

#define msp_ReadFrameWord(frame, entry, offset) msp_ReadStackWord(frame, entry, offset)
//������:
//msp_WORD msp_ReadFrameWord(msp_FRMHANDLE frame, int entry, msp_BYTE offset);
//
//���������� ����� �� ��� ���, �������������� ������� �����.
//frame � ����
//entry � ����� ����������� ��������� � �����
//offset � ����� ����� �����������, ����� ��������� ��������
//msp_FD_BSW � ����� ��������� �����
//msp_FD_TIMETAG � ��������� �����
//msp_FD_MSGGAP � ��������� �������� �� ���������� ���������
//msp_FD_MSGADDR � ����� ����� ���������
//�������: ������������� �����.

msp_ERROR msp_BCRetrieveMessage(msp_FRMHANDLE frame, int entry, msp_Message* buffer);
//���������� ��������� �� ��� ��� � ��� �����, ��������� �� ������� ��������� �� ����������� ��������� � ������ �����.
//frame � ����
//entry � ����� ����������� ��������� � �����
//buffer � ����� ��� ���������� ���������. � ������ ����������� �������������� ���� StatusWord1/2, loopback, BSW, timetag.
//�������: ��� ������ ��� 0.
//������ ������ msp_RetrieveMessage, �� ������ ��� BC

#ifdef __cplusplus
}
#endif

#endif
