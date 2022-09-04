/***************************************************************
	rt.h
	��������� ������ ��.

	RTL2 - ���������� ������� ���������� ���/����.

	(�) �.������, 2000.
	�� ������ ��� ������.
 ***************************************************************/
/***************************************************************
	������� ���������:

 ***************************************************************/

#ifndef RT_H
#define RT_H

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
	������� ���� ������
 ***************************************************************/

typedef msp_HANDLE  msp_BUFHANDLE;
typedef msp_BYTE    msp_SUBADDRESS;

/***************************************************************
    ��������� � ������� ������������ ���. ����� �� (����)
 ***************************************************************/

//���������� ������
#define msp_SA_NO_BUFFER                            0
#define msp_SA_SINGLE_BUFFER                        8
#define msp_SA_DOUBLE_BUFFER                        16
#define msp_SA_CIRCULAR_BUFFER_128          1
#define msp_SA_CIRCULAR_BUFFER_256          2
#define msp_SA_CIRCULAR_BUFFER_512          3
#define msp_SA_CIRCULAR_BUFFER_1024         4
#define msp_SA_CIRCULAR_BUFFER_2048         5
#define msp_SA_CIRCULAR_BUFFER_4096         6
#define msp_SA_CIRCULAR_BUFFER_8192         7

//������ ������ ��� ��
//8,16,32 - ��������� �� �������� � ������������ �����������
//�������� � ����.
#define msp_SA_ROLLOVER_INT                         8
    //���������� �� �������� � ������ ���������� ������
#define msp_SA_EOM_INT                                      16
    //���������� �� ����� ���������
#define msp_SA_DOUBLE_BUFFERING                     32
    //��������� ������� ����������� ��� ������� ������
    //�����������: � ���� ��������� ������ ���� ������
    //���� � �� ���������� 2 ������� ������, ����������
    //������ ���������������, ���� ��� ������ ����������
    //������ � 1
#define msp_SA_STREAMING                            64
    //��������� ��������� �������� (������ ������ �� RTL)
#define msp_SA_BUSY									128
	//����������� �������� ��������� ��� �� ����� ����������
	//������. �����������, ���� ������ ���������� ����
	//mspFS_SET_BUSY_VIA_BUFFER_HANDLE

#define msp_SA_FLAG_mask                            0xF8

/***************************************************************
    ����������� ������ (�����) ��� �\� ��
 ***************************************************************/

/*reserved mspSTK_B/A*              0x01*/
#define msp_SA_FREE_RAM             0x02
#define msp_SA_ACTIVE_BUFFER        0x04
#define msp_SA_INACTIVE_BUFFER      0x08
#define msp_SA_SAFE_READ            0x10
#define msp_SA_RETURN_IF_BUSY       0x40
#define msp_SA_WAIT_IF_BUSY         0x80
#define msp_SA_SWAP_BUFFER			0x100

/***************************************************************
    �������� ������ ��� ��
 ***************************************************************/

msp_BUFHANDLE msp_CreateBuffer(msp_DEVHANDLE device,
                                                       msp_BYTE BufferSize,
                                                       msp_BYTE BufferFlags);
//�������� ������ ��� ������ ��������� ��.
//device � ����������
//BufferSize � ������ ������ - ���� �� ��������
//                                  msp_SA_SINGLE_BUFFER
//                                  msp_SA_DOUBLE_BUFFER
//                                  msp_SA_CIRCULAR_BUFFER_128 - msp_SA_CIRCULAR_BUFFER_8192
//BufferFlags - ������ ������������ ��� ������������ ����,
//                                  ����� ����� ������������ � ��; ���� �� ��������
//                                  msp_SA_ROLLOVER_INT
//                                  msp_SA_EOM_INT
//                          ������ msp_SA_DOUBLE_BUFFERING, msp_SA_STREAMING ���������������
//                          ������������� � ����������� �� ����������� ������

#define msp_DestroyBuffer(buffer) msp_DestroyHandle(buffer)
//����������� (������������) ������. 

/***************************************************************
	����������� ������ � ��.
 ***************************************************************/

msp_ERROR msp_SetSABuffer(msp_DEVHANDLE device,
                                              msp_SUBADDRESS subaddress,
                                              msp_DIR dir,
                                              msp_BUFHANDLE buffer,
                                              int flags);
//��������� ��� ������ ������ ��� ��.
//device � ����������
//subaddress � ��
//dir - ����������� ��������, ���� �� ��������
//  msp_DIR_TX � ������ ������ ��� ��������
//  msp_DIR_RX � ������ ������ ��� ������
//  msp_DIR_BCST � ������ ������ ��� ������ ������������������ ���������
//buffer � ��. (handle) ������� ��� ���
//flags � �������������� ��������� ��������, ���������� ��������� ��������
//  msp_STK_A � ������ ��������� � lookup table A
//  msp_STK_B � ������ ��������� � lookup table B; ����������� � msp_STK_A;
//          ���� �� ������� �� msp_STK_A, �� msp_STK_B, ��������� msp_STK_A
//  msp_SA_FREE_RAM � ������������� ������������� ������� �����
//  msp_SA_RETURN_IF_BUSY - ��������, �� ������������ �� �� � ������ ������ � �����
//  msp_SA_WAIT_IF_BUSY - ��������, �� ������������ �� �� � ������ ������ �
//                                          �������� ������������ (���� ������)

msp_BUFHANDLE msp_GetSABuffer(msp_DEVHANDLE device, msp_SUBADDRESS subaddress,
                                                      msp_DIR dir, int flags);
//���������� �������������� ������ ��� ������� ��.
//device � ����������
//subaddress � ��
//dir - ����������� ��������, ���� �� ��������
//  msp_DIR_TX � ����� ������ ��� ��������
//  msp_DIR_RX � ����� ������ ��� ������
//  msp_DIR_BCST � ����� ������ ��� ������ ������������������ ���������
//flags � �������������� ��������� ��������, ���������� ��������� ��������
//  msp_STK_A � ������ �� lookup table A
//  msp_STK_B � ������ �� lookup table B; ����������� � msp_STK_A;
//  ���� ��� �� msp_STK_A, �� msp_STK_B, ��������� msp_STK_A
//�������: ������������� (handle) ������� ��� ���.

/***************************************************************
	���� � ������� ��� ����������������� �� � ����� "Indirect" 
 ***************************************************************/

typedef struct {
    msp_BYTE size;
    msp_BYTE flags;
	msp_BYTE lowlen;
	msp_BYTE highlen;
} msp_BufConfig;

typedef struct {
    msp_BufConfig rx;
    msp_BufConfig tx;
    msp_BufConfig bcst;
} msp_SAConfig;

typedef struct {
    msp_BUFHANDLE rxbuffer;
    msp_BUFHANDLE txbuffer;
    msp_BUFHANDLE bcstbuffer;
} msp_SABuffers;

/*
msp_SAConfig* msp_SetSAConfig(msp_SAConfig* config,
    msp_BYTE rxsize,
    msp_BYTE rxflags,
    msp_BYTE txsize,
    msp_BYTE txflags,
    msp_BYTE bcstsize,
    msp_BYTE bcstflags)
*/
#define msp_SetSAConfig(config, rxsize, rxflags, txsize, txflags, bcstsize, bcstflags) \
( \
    (config)->rx.size = (rxsize), \
    (config)->rx.flags = (rxflags), \
    (config)->rx.lowlen = 1, \
    (config)->rx.highlen = 32, \
    (config)->tx.size = (txsize), \
    (config)->tx.flags = (txflags), \
    (config)->tx.lowlen = 1, \
    (config)->tx.highlen = 32, \
    (config)->bcst.size = (bcstsize), \
    (config)->bcst.flags = (bcstflags), \
    (config)->bcst.lowlen = 1, \
    (config)->bcst.highlen = 32, \
    config \
)

/*
msp_SAConfig* msp_SetSAConfigLeg(msp_SAConfig* config,
    msp_BYTE rxsize,
    msp_BYTE rxflags,
	msp_BYTE rxlowlen,
	msp_BYTE rxhighlen,
    msp_BYTE txsize,
    msp_BYTE txflags,
	msp_BYTE txlowlen,
	msp_BYTE txhighlen,
    msp_BYTE bcstsize,
    msp_BYTE bcstflags
	msp_BYTE bcstlowlen,
	msp_BYTE bcsthighlen)
*/
#define msp_SetSAConfigLeg(config, rxsize, rxflags, rxlowlen, rxhighlen, \
								   txsize, txflags, txlowlen, txhighlen, \
								   bcstsize, bcstflags, bcstlowlen, bcsthighlen) \
( \
    (config)->rx.size = (rxsize), \
    (config)->rx.flags = (rxflags), \
    (config)->rx.lowlen = (rxlowlen), \
    (config)->rx.highlen = (rxhighlen), \
    (config)->tx.size = (txsize), \
    (config)->tx.flags = (txflags), \
    (config)->tx.lowlen = (txlowlen), \
    (config)->tx.highlen = (txhighlen), \
    (config)->bcst.size = (bcstsize), \
    (config)->bcst.flags = (bcstflags), \
    (config)->bcst.lowlen = (bcstlowlen), \
    (config)->bcst.highlen = (bcsthighlen), \
    config \
)

/*
msp_SABuffers* msp_SetSABuffers(msp_SABuffers* buffers,
    msp_BUFHANDLE rxbuffer,
    msp_BUFHANDLE txbuffer,
    msp_BUFHANDLE bcstbuffer)
*/
#define msp_SetSABuffers(buffers, rx, tx, bcst) \
( \
    (buffers)->rxbuffer = (rx), \
    (buffers)->txbuffer = (tx), \
    (buffers)->bcstbuffer = (bcst), \
    buffers \
)

/***************************************************************
	���������������� ��.
 ***************************************************************/

msp_ERROR msp_ConfigureSA(
                    msp_DEVHANDLE device,
                    msp_SUBADDRESS subaddress,
                    msp_BUFHANDLE rxbuffer,
                    msp_BUFHANDLE txbuffer,
                    msp_BUFHANDLE bcstbuffer,
                    int flags);
//��������� ���� ������� ��
//device � ����������
//subaddress � ��
//txbuffer,
//rxbuffer,
//bcstbuffer � �������������� (handle) �������
//flags � �������������� ��������� ��������, ���������� ��������� ��������
//          msp_STK_A � ������ ��������� � lookup table A
//          msp_STK_B � ������ ��������� � lookup table B
//          msp_SA_FREE_RAM � ������������� ������������� ������ ������

msp_ERROR msp_ConfigureSAIndirect(
                    msp_DEVHANDLE device,
                    msp_SUBADDRESS subaddress,
                    MSP_CONST msp_SAConfig *config,
                    msp_SABuffers *buffers,
                    int flags);
//device � ����������
//subaddress � ��
//config - ������������ ��
//buffers - ������ ��. �.�. NULL. ���� �� NULL, ������������ ���������
//                  ������; ����������� �� ������������ config. ���� �-���� �����
//                  ���� msp_NOHANDLE, �-� ������� ����� �������������, � ����������
//                  handle � �����. ����. ���� ����� ��� ������� ����������� ��
//                  ����� (msp_SA_NO_BUFFER), �����. ���� ������ ���� NULL.
//flags � �������������� ��������� ��������, ���������� ��������� ��������
//          msp_STK_A � ������ ��������� � lookup table A
//          msp_STK_B � ������ ��������� � lookup table B
//          msp_SA_FREE_RAM � ������������� ������������� ������ ������

msp_ERROR msp_ConfigureAllSAIndirect(
                    msp_DEVHANDLE device,
                    MSP_CONST msp_SAConfig *configs,
                    msp_SABuffers *buffers,
                    int flags);
//����������������� ���� 32 ��
//device � ����������
//config - ������������ �� (������ �� 32 ���������), ������ ������������
//                  ��� � msp_ConfigureSAIndirect
//buffers - ������ 32 ����� ������� ��. ������ ������� ������������ ���
//                  � msp_ConfigureSAIndirect. �.�. NULL.
//flags � �������������� ��������� ��������, ���������� ��������� ��������
//          msp_STK_A � ������ ��������� � lookup table A
//          msp_STK_B � ������ ��������� � lookup table B
//          msp_SA_FREE_RAM � ������������� ������������� ������ ������

/***************************************************************
	�\� ��� ������� � ������� ������
 ***************************************************************/

msp_ERROR msp_SetBufferFlag(msp_BUFHANDLE buffer, msp_BYTE flagid,
                                                    msp_BIT value);
//��������� ������� ������.
//������ ������ ������ �� ����. ���� ����� ��������� (msp_SetSABuffer())
//���� ����������� ����������.
//buffer - �����
//flagid - �����. ������, ���� �� �������� msp_SA_XXXX
//value - ����� ��������, ���� �� �������� 0 ��� 1

msp_BIT msp_GetBufferFlag(msp_BUFHANDLE buffer, msp_BYTE flagid);
//������ ������� ������.
//���� ����� ��������� (msp_SetSABuffer()), ����������� �����������
//�������� �� ����
//buffer - �����
//flagid - �����. ������, ���� �� �������� msp_SA_XXXX
//          ��� ������ msp_SA_DOUBLE_BUFFERING ���������
//          �������� ����� ���������� �� ��������, ���������
//          � msp_SetBufferFlags (��� �� ������ � ��������� �������)

/***************************************************************
	��������� ������ ��\� �����
 ***************************************************************/

msp_WORD msp_ReadSAData(msp_BUFHANDLE sabuffer, msp_WORD* buffer,
                                            msp_WORD offset, msp_WORD wordcount, int flags);
//������ ������ �� ������
//sabuffer � ������������� (handle) ������ � ��� ���
//offset - �������� 1-�� ��������� ����� � sabuffer
//buffer � ������� ��� ����� ��� ����������
//wordcounut � ������� ���� �������
//flags � �������������� ��������� �������� ��� ������ ������� �����������,
//  ���������� ���������  ��������:
//  msp_SA_ACTIVE_BUFFER � �� ��������� ������
//                  (�������� ��������� �� ������ �������� ��������)
//  msp_SA_INACTIVE_BUFFER � �� ����������� ������
//                  (�������� ��������� �� ������ ���������� ��������)
//                  ���� ��� msp_SA_DOUBLE_BUFFER �� ������� ��
//                  msp_SA_ACTIVE_BUFFER, �� msp_SA_INACTIVE_BUFFER,
//                  �������� - �� ������ ���, ��� � ������� ������
//  msp_SA_INACTIVE_BUFFER + msp_SA_SAFE_READ
//                  � �� ����������� ������,
//                    ��������� ��������� ������������ �������
//  msp_SA_RETURN_IF_BUSY - ��������, �� ������������ �� �� � ������ ������ � �����
//  msp_SA_WAIT_IF_BUSY - ��������, �� ������������ �� �� � ������ ������ �
//                                          �������� ������������ (���� ������)
//�������: ����� ���������� ����������� ����; ��� ������ - 0;


msp_WORD msp_WriteSAData(msp_BUFHANDLE sabuffer, msp_WORD* buffer,
                                             msp_WORD offset, msp_WORD wordcount, int flags);
//������ ������ � �����
//sabuffer � ������������� (handle) ������ � ��� ���
//buffer � ������� ��� ����� � �������
//offset - �������� 1-�� ������������� ����� � sabuffer
//wordcounut � ������� ���� ��������
//flags � �������������� ��������� �������� ��� ������ ������� �����������,
//  ���������� ���������  ��������:
//  msp_SA_ACTIVE_BUFFER � � �������� �����
//                  (�������� ��������� �� ������ �������� ��������)
//  msp_SA_INACTIVE_BUFFER � � ���������� �����
//                  (�������� ��������� �� ������ ���������� ��������)
//                  ���� ��� msp_SA_DOUBLE_BUFFER �� ������� ��
//                  msp_SA_ACTIVE_BUFFER, �� msp_SA_INACTIVE_BUFFER,
//                  �������� - �� ������ ���, ��� � ������� ������
//  msp_SA_SWAP_BUFFER - ����� ������ �������� � ���������� ������
//					�������� ������
//  msp_SA_RETURN_IF_BUSY - ��������, �� ������������ �� �� � ������ ������ � �����
//  msp_SA_WAIT_IF_BUSY - ��������, �� ������������ �� �� � ������ ������ �
//�������: ����� ���������� ��������� ����.

/***************************************************************
	��������� ������ ��\� ����� - ��������� �����
 ***************************************************************/

msp_WORD msp_ReadSAStream(msp_BUFHANDLE sabuffer, msp_WORD* buffer, msp_WORD wordcount);
//������ ������ �� ������ � ��������� ������
//sabuffer � ������������� (handle) ������ � ��� ���
//                  (�������������� msp_SA_CIRCULLAR_BUFFER_XXXXXXX)
//buffer � ������� ��� ����� ��� ����������
//wordcounut � ������� ���� �������
//�������: ����� ���������� ����������� ����;
// = 0 ���� � ����� �� ��������� �������������� ������,
//     � ����� ��� ������

msp_WORD msp_WriteSAStream(msp_BUFHANDLE sabuffer, msp_WORD* buffer, msp_WORD wordcount);
//������ ������ � ����� � ��������� ������
//sabuffer � ������������� (handle) ������ � ��� ���
//                  (�������������� msp_SA_CIRCULLAR_BUFFER_XXXXXXX)
//buffer � ������� ��� ����� � �������
//wordcounut � ������� ���� ��������
//�������: ����� ���������� ���������� ����;
// = 0 ���� � ������ ��� ����� ��� ����� ������,
//     � ����� ��� ������

msp_ERROR msp_MarkSAStream(msp_BUFHANDLE sabuffer, int flags);
//Later.
//Flags:
#define msp_STREAM_READ     1
#define msp_STREAM_WRITTEN  2
#define msp_STREAM_EMPTY    3

#define msp_ResetSAStream msp_ResetSABuffer
//���������� ���������. ��. msp_ResetSABuffer

/***************************************************************
	������� � ��������� ��������� ������� ������
 ***************************************************************/

msp_ERROR msp_ResetSABuffer(msp_BUFHANDLE sabuffer, msp_WORD offset);
//��������� ���������� ������� ������� ������ � �������� ��������
//sabuffer - ������������� (handle) ������ � ��� ���
//offset - �������� ������� ������� �� ������ ������
//			��� msp_SA_DOUBLE_BUFFER ��������� �������� 0 � 32
//			��� msp_SA_CIRCULAR_BUFFER_���� - �����, �� ��������� �� ������� ������
//			��� msp_SA_SINGLE_BUFFER - �������� ���������

/***************************************************************
	���� � ��������� ��� ���������������� ����������� ������
 ***************************************************************/

typedef struct {
    msp_WORD CmdWord;
    msp_WORD Data;
} msp_ModeCodeInitData;

#define msp_LEGAL           0
#define msp_ILLEGAL         1
#define msp_BUSY            1
#define msp_NOT_BUSY        0
#define msp_ENABLE          1
#define msp_DISABLE         0

/***************************************************************
	���������������� ������� ������� ������ (illegalizetion)
 ***************************************************************/

msp_ERROR msp_SetIllegalCommands(msp_DEVHANDLE device, msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, msp_BIT illegal);
//����������/����������* ������ ������
//device - ����������
//rangeCmdWord0,
//rangeCmdWord1 - ������� ������ 1553, ������������ ������� �������� ��������
//          ��� ������� ������� ������� sampleCmdWord1 ������ ���������
//          ��������, � sampleCmdWord2 - ��������
//          ������������ �������:
//          <RT> :  = 31 - �������� ��������� � ����������������� ��������,
//                          ����� ������ �������� - �������� ��������� � ��������,
//                          ������������ ������� ��
//          <TX> :  ��������/�����
//          <SA> :  � ��
//          <WC/MC> : ����� ����/��� ������ (mode code)
//illegal - �������� �������� ���������� �������

msp_ERROR msp_SetIllegalCommandsDW(msp_DEVHANDLE device, msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, msp_DWORD illegal);
//��� msp_SetIllegalCommands(), ������ ������� <WC/MC> ������������,
//� illegal �������� ������� ����� ��� ���� 32� ��������� <WC/MC>

msp_BIT msp_IsIllegalCommand(msp_DEVHANDLE device, msp_WORD CmdWord);
//��������� �� ������ �������

#define msp_SetIllegalCommand(device, cmd, illegal) \
	msp_SetIllegalCommands(device, cmd, cmd, illegal)

msp_ERROR msp_SetIllegalCommandsIndirect(
    msp_DEVHANDLE device,
    msp_rangeCmdWords *ranges,
    int count,
    msp_BIT illegal);
//����������/����������* ������ ������
//device - ����������
//ranges - ������ ��� ��������� ������ (������������ ��� � msp_SetIllegalCommands)
//count - ����� ����� �������
//illegal - �������� �������� ���������� �������

msp_ERROR msp_IllegalizeForBuffer(msp_BUFHANDLE buffer, msp_BYTE lowlen, msp_BYTE highlen);
//����������/���������� ������ ������, ��������� � ������ �������
//������� ��������������� ��������� ����� mspFS_RT_ILLEGALIZE_FOR_BUFFER
//��� ������������� ������ ������������ �����������, ��� ��������������� -
//� ������ �����������
//��� �������, � �������� ��������� ����� ���� ������ �����������
//������������, ��������� - ������������
//buffer - ���������� ������
//lowlen - ���. ����� ���� ������
//highlen - ����. ����� ���� ������

/***************************************************************
	���������������� ������� ������������ ��
 ***************************************************************/

msp_ERROR msp_SetBusySA(msp_DEVHANDLE device, msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, msp_BIT busy);
//��������� �������� ��������� ������ ��
//device - ����������
//rangeCmdWord0,
//rangeCmdWord1 - ������� ������, ������������ ������� �������� ��������
//          ��� ������� ������� ������� sampleCmdWord1 ������ ���������
//          ��������, � sampleCmdWord2 - ��������
//          ������������ �������:
//          <RT> :  = 31 - �������� ��������� � ����������������� ��������,
//                          ����� ������ �������� - �������� ��������� � ��������,
//                          ������������ ������� ��
//          <TX> :  ��������/�����
//          <SA> :  � ��
//busy - �������� �������� ��������� ��

msp_BIT msp_GetBusySA(msp_DEVHANDLE device, msp_WORD CmdWord);
//����� �������� ��������� ��

msp_ERROR msp_SetBusySAIndirect(
    msp_DEVHANDLE device,
    msp_rangeCmdWords *ranges,
    int count,
    msp_BIT busy);
//��������� �������� ��������� ������ ��
//device - ����������
//ranges - ������ ��� ��������� ������ (������������ ��� � msp_SetBusySA)
//count - ����� ����� �������
//busy - �������� �������� ��������� ��

/***************************************************************
	���������������� ������ ��� �������������� ���������
	��������� mode code
 ***************************************************************/

msp_ERROR msp_SetModeCodeData(msp_DEVHANDLE device, msp_WORD CmdWord, msp_WORD data);
//��������� ����� ������ ��� ������ mode code
//device - ����������
//CmdWord - �������, ��� ������� ��������������� ������.������������ �������:
//          <RT> :  = 31 - �������� ��������� � ����������������� ��������,
//                          ����� ������ �������� - �������� ��������� � ��������,
//                          ������������ ������� ��
//          <TX> :  ��������/�����
//          <MC> :  ��� ������ (mode code)
//data - �������� ����� ������

msp_WORD  msp_GetModeCodeData(msp_DEVHANDLE device, msp_WORD CmdWord);
//������� ����� ����� ��� ������ mode code
//device - ����������
//CmdWord - �������, ��� ������� ����������� ������.
//                  ������������ ��� � msp_SetModeCodeData
//�������: �������� ����� ������

msp_ERROR msp_SetModeCodeDataIndirect(
    msp_DEVHANDLE device,
    msp_ModeCodeInitData *data);
//��������� ���� ������ ��� ������ ������ mode code
//device - ����������
//data - ������ ��� <�������, ������>. ������ ���� ��������������
//                  ���������� ���������� msp_SetModeCodeData(). ������� �����
//                  ������� - ������� CmdWord

msp_ERROR msp_SetModeCodeInt(msp_DEVHANDLE device, msp_WORD CmdWord, msp_BIT enable);
//���������� ���������� �� ���������� ������� mode code
//device - ����������
//CmdWord - �������, ��� ������� �����������/����������� ����������
//                  ������������ ��� � msp_SetModeCodeData
//enable - �������� �������� ���������� ����������

msp_BIT msp_GetModeCodeInt(msp_DEVHANDLE device, msp_WORD CmdWord);
//��������� �� ���������� �� ���������� ������� mode code
//device - ����������
//CmdWord - �������, ��� ������� �����������/����������� ����������
//                  ������������ ��� � msp_SetModeCodeData

msp_ERROR msp_SetModeCodeIntIndirect(
    msp_DEVHANDLE device,
    msp_WORD *CmdWords,
    msp_BIT enable);
//���������� ���������� ��� ������ ���������� ������ mode code
//device - ����������
//CmdWords - ������ ������, ������ ������������ ��� � msp_SetModeCodeData;
//                          ������� ����� ������� - �������� 0

/***************************************************************
	������ �� ������ ������
 ***************************************************************/

msp_STKHANDLE msp_CreateStack(msp_DEVHANDLE device);
//�������� ����� ������ �� (�������������� ������� ���).
//������ ����� ������������ �������� ����������� ����������.
//��� ����� ������������� �������, ����������� �� �������, ������ �������. ???
//device � ����������
//�������: ������������� (handle) �����.

#define msp_DestroyStack(stack) msp_DestroyHandle(stack)
//����������� �����.
//stack � ������������� (handle) �����

msp_ERROR msp_RTLoadStack(msp_STKHANDLE stack, int flags);
//�������� ������� ����� � �������� ����� A ��� B.
//stack � ������������� (handle) �����
//flags � ���� �� ��������
//  msp_STK_A � ��������� � ���� A
//  msp_STK_B � ��������� � ���� B

msp_ERROR msp_RTLoadStackWithOffset(msp_STKHANDLE stack, int start, int flags);
//�������� ������� ����� � �������� ����� A ��� B.
//� ���������� ���������� ������ ���������
//stack � ������������� (handle) �����
//start - ��������� ����� ���������
//flags � ���� �� ��������
//	msp_STK_A � ��������� � ���� A
//	msp_STK_B � ��������� � ���� B

//See also msp_SetStkStart (config.h)

/***************************************************************
   ������ ��������� ��������� ���������
 ***************************************************************/

msp_ERROR msp_RTRetrieveMessage(msp_STKHANDLE stack, int index, msp_Message* buffer);
//�� ��, ��� msp_RetrieveMessage, �� ������ ��� ����� ������ RT

msp_ERROR msp_RetrieveMCMessage(msp_STKHANDLE stack, int index, msp_WORD* CmdWord, msp_WORD* DataWord);
//������� ��������� �mode code� �� ����� ��.
//stack � ����
//index � ���������� ����� ������� � ����� ��� ����. ��������
//                  msp_NEXT_MESSAGE,
//                  msp_SAME_MESSAGE
//                  msp_LAST_RECEIVED (��. msp_RetrieveMessage())
//CmdWord � ��������� ����� (����� ��� ������)
//DataWord � ����� ������ (����� ��� ������)
//���� ������� ��������� - �� "mode code", ������� � ����� msp_ERROR_NOT_MODECODE,
//������� ������ �� ����� �� ����������.

typedef struct {
    msp_WORD bsw;
    msp_WORD timetag;
    msp_WORD dataAddress;
    msp_WORD cmdword;
    msp_WORD type;
    msp_WORD dataWordCount;
    msp_BUFHANDLE bufhandle;
    msp_WORD dataOffset;
} msp_MessageInfo;

msp_ERROR msp_RetrieveMessageInfo(msp_STKHANDLE stack, int index, msp_MessageInfo* info);
//���������� msp_RTRetrieveMessage, �� ������ ������ ���������
//����������� ������ "� ���" � ���-�� msp_MessageInfo.
// - ��� ����, ����� ����� ���� ������� SAFE_READ �� ������.

#ifdef __cplusplus
}
#endif

#endif
