/* -*- mode:c; coding:windows-1251; -*- */
/***************************************************************
	config.h
	���������������� ����������;
	������� ��� ������ �� 	MIL-STD-1553, ����� ��� ���� �������.

	RTL2 - ���������� ������� ���������� ���/����.

	(�) �.������, 2000.
	�� ������ ��� ������.
 ***************************************************************/
/***************************************************************
	������� ���������: 
	14.01.2002 �������
	��������� msp_Message  ��������� �������:
		msp_BYTE present; 
		msp_BYTE transmit;
		msp_BYTE check;
		msp_BYTE role;
	������� ������� ��� ���.
	24.10.2005 ������, ������
		��������� ��������� ��������������� ����������.
	11.11.2006 ��������, ������
		���������� ������ � ��������� ������ ��������� ����� mspF_S��,
		mspF_MRT_Sxx.
		��������� ����� � ����� ��� ��������� ����� ��������� �����,
		����� ��� ������������ ��������� ����� ��������������� ����������.
 ***************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

#include "types.h"
#include "errors.h"
#include "access.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************-
    ������� ������������ ����� � �����������
 ***************************************************************/

msp_DEVHANDLE msp_Open(int i);
msp_DEVHANDLE msp_OpenEx(int i, int flags);

//��������� ���������� ��� ������� ����������.
//� ������ ������������� ������� ����������
//������������ �������� msp_NOHANDLE.
//flags: ��. mspi_OpenAccessEx() (access.h)

msp_ERROR msp_Close(msp_DEVHANDLE device);
//��������� ���������� ��� ������� ����������.

/***************************************************************
    ��������� ������������� ������ ���
 ***************************************************************/

msp_DEVHANDLE msp_Open64(int i);
//���������� msp_Open(),
//������ � ����� A ��� �� ����� ����
//����� ������������ msp_OpenEx() !

/***************************************************************-
    ������� ������������ ����� � �������������� �����������
 ***************************************************************/

msp_DEVHANDLE msp_Open_Multi(msp_DEVHANDLE device, int i);
//��������� ����������� ���������� (��) ����������������� ����������
//device - ���������������� ����������
//i - ����� ��
//� device ������ ���� ������ ����� msp_MODE_MRT
//
//���������� ����������� ������������������ � ������ msp_MODE_RT
//� ��������. ������������� ���������� ����� �-�� msp_Switch_Multi()


msp_ERROR msp_Switch_Multi(msp_DEVHANDLE device, msp_BIT mode);
//�������� � ��������� ���������� ��������� ������ ��� ���������
//���������������� ������� ����������� ����������.


/***************************************************************
        Flags / virtual registers data types
 ***************************************************************/

typedef msp_DWORD msp_FLAGID;
typedef msp_DWORD msp_REGID;
typedef struct {
        msp_REGID       reg;
        msp_WORD        value;
} msp_REGVALUE;

/***************************************************************
        Flag functions
 ***************************************************************/

msp_BIT msp_GetFlag(msp_DEVHANDLE device, msp_FLAGID flag);
//������ ��������� �������� �����. ���������� 0 ��� 1 � �����������
//�� ��������� ������ flag ���������� device.

msp_ERROR msp_SetFlag(msp_DEVHANDLE device, msp_FLAGID flag, msp_BIT value);
//��������� ��������� �������� �����. ������������� �������� ������ flag
//���������� device � 0 ���� value=0 � � 1 � ��������� ������.

msp_ERROR msp_SetFlagsIndirect(msp_DEVHANDLE device, MSP_CONST msp_FLAGID* flags, msp_BIT value);
//��������� ���������� ������� ������ � 0 ��� 1 ����������� msp_SetFlag().
//���������:
//device � ����������
//flags � ������ ������� ������� mspF_XXXX; ������ �� ���������; ��������� ����� �������� �������� 0
//value � ��������, � ������� ��������������� ��� ��������� ������.
//������� ��������� ������� �� ������������.

/***************************************************************
        Virtual register functions
 ***************************************************************/

msp_WORD msp_GetVReg(msp_DEVHANDLE device, msp_REGID reg);
//���������� �������� ������������ ��������.
//���������:
//device � ����������
//reg � ����� ��������
//�������: ������� ��������.

msp_ERROR msp_SetVReg(msp_DEVHANDLE device, msp_REGID reg, msp_WORD value);
//������������ �������� ������������ ��������.
//���������:
//device � ����������
//reg � ����� ����������
//value � ������������� ��������

msp_ERROR msp_SetVRegsIndirect(msp_DEVHANDLE device, MSP_CONST msp_REGVALUE* regvalues);
//������������ �������� ���������� ����������� ���������.
//���������:
//device � ����������
//regvalue � ������ ��� �����-��������; ������ �� ���������;
//��������� ����� �������� ����� �������� ������ 0

/***************************************************************
        Flags & virtual regisers definition
 ***************************************************************/

#define MakeFLAGID(RR, BIT) ((RR) << 16 | 1 << (BIT))
#define StarFLAGID(RR, BIT) (MakeFLAGID(RR, BIT) ^ 0x80000000)
#define MakeREGID(RR, MASK) ((RR) << 16 | (MASK))
#define OffsREGID(RR, MASK, offs) ((offs) << 28 | (RR) << 16 | (MASK))
#define MakeALIAS(RR) ((RR) << 16 | 0xFFFF)

//Common flags
#define mspF_CURRENT_AREA						MakeFLAGID(mspRR_CONFIG1, 13)
#define mspF_CURRENT_AREA_B						mspF_CURRENT_AREA
#define mspF_CURRENT_AREA_A						StarFLAGID(mspRR_CONFIG1, 13)
#define mspF_LOWER_CLOCK_SELECT					MakeFLAGID(mspRR_CONFIG5, 15)
#define mspF_DOUBLE_SAMPLE_FREQUENCY			MakeFLAGID(mspRR_CONFIG5, 11)
#define mspF_EXPANDED_ZERO_CROSSING_ENABLED		mspF_DOUBLE_SAMPLE_FREQUENCY
#define mspF_GAP_CHECK_ENABLED					MakeFLAGID(mspRR_CONFIG5, 8)
#define mspF_256WORD_BOUNDARY_DISABLE			MakeFLAGID(mspRR_CONFIG2, 10)
#define mspF_ENHANCED_MODE						MakeFLAGID(mspRR_CONFIG3, 15)
//lve
#define mspF_ENHANCED_CPU_ACCESS				MakeFLAGID(mspRR_CONFIG6, 14)


//BC mode flags
#define mspF_MESSAGE_STOP_ON_ERROR				MakeFLAGID(mspRR_CONFIG1, 12)
#define mspF_FRAME_STOP_ON_ERROR				MakeFLAGID(mspRR_CONFIG1, 11)
#define mspF_STATUS_SET_STOP_ON_MESSSAGE        MakeFLAGID(mspRR_CONFIG1, 10)
#define mspF_STATUS_SET_STOP_ON_FRAME           MakeFLAGID(mspRR_CONFIG1, 9)
#define mspF_FRAME_AUTOREPEAT                   MakeFLAGID(mspRR_CONFIG1, 8)
#define mspF_EXTERNAL_TRIGGER_ENABLED           MakeFLAGID(mspRR_CONFIG1, 7)
#define mspF_INTERNAL_TRIGGER_ENABLED           MakeFLAGID(mspRR_CONFIG1, 6)
#define mspF_MESSAGE_GAP_TIMER_ENABLED          MakeFLAGID(mspRR_CONFIG1, 5)
#define mspF_RETRY_ENABLED                      MakeFLAGID(mspRR_CONFIG1, 4)
#define mspF_DOUBLE_RETRY                       MakeFLAGID(mspRR_CONFIG1, 3)
#define mspF_BC_ENABLED                         MakeFLAGID(mspRR_CONFIG1, 2)
#define mspF_BC_FRAME_IN_PROGRESS               MakeFLAGID(mspRR_CONFIG1, 1)
#define mspF_BC_MESSAGE_IN_PROGRESS             MakeFLAGID(mspRR_CONFIG1, 0)
#define mspF_EXPANDED_BC_CONTROL_WORD           MakeFLAGID(mspRR_CONFIG4, 12)
#define mspF_BROADCAST_MASK_ENABLED             MakeFLAGID(mspRR_CONFIG4, 11)
#define mspF_RETRY_IF_1553A_AND_MESSAGE_ERROR   MakeFLAGID(mspRR_CONFIG4, 10)
#define mspF_RETRY_IF_STATUS_SET                MakeFLAGID(mspRR_CONFIG4, 9)
#define mspF_RETRY1_AT_ALT_BUS                  MakeFLAGID(mspRR_CONFIG4, 8)
#define mspF_RETRY2_AT_ALT_BUS                  MakeFLAGID(mspRR_CONFIG4, 7)
#define mspF_VALID_ERROR_BIT_NO_DATA            MakeFLAGID(mspRR_CONFIG4, 6)
#define mspF_VALID_BUSY_BIT_NO_DATA             MakeFLAGID(mspRR_CONFIG4, 5)

//lve RT, RT/MM, MM flags
#define mspF_INCREMENT_ON_EOM					MakeFLAGID(mspRR_CONFIG6, 13)

//RT mode flags
#define mspF_NOT_ACCEPT_DYNAMIC_BUS_CONTROL     MakeFLAGID(mspRR_CONFIG1, 11)
#define mspF_ACCEPT_DYNAMIC_BUS_CONTROL         StarFLAGID(mspRR_CONFIG1, 11)
#define mspF_NOT_BUSY                           MakeFLAGID(mspRR_CONFIG1, 10)
#define mspF_BUSY                               StarFLAGID(mspRR_CONFIG1, 10)
#define mspF_NOT_SERVICE_REQUEST                MakeFLAGID(mspRR_CONFIG1, 9)
#define mspF_SERVICE_REQUEST                    StarFLAGID(mspRR_CONFIG1, 9)
#define mspF_NOT_SUBSYSTEM_FLAG                 MakeFLAGID(mspRR_CONFIG1, 8)
#define mspF_SUBSYSTEM_FLAG                     StarFLAGID(mspRR_CONFIG1, 8)
#define mspF_NOT_RTFLAG                         MakeFLAGID(mspRR_CONFIG1, 7)
#define mspF_RTFLAG                             StarFLAGID(mspRR_CONFIG1, 7)
#define mspF_RT_MESSAGE_IN_PROGRESS             MakeFLAGID(mspRR_CONFIG1, 0)

#define mspF_S10                                MakeFLAGID(mspRR_CONFIG1, 11)
#define mspF_S09                                MakeFLAGID(mspRR_CONFIG1, 10)
#define mspF_S08                                MakeFLAGID(mspRR_CONFIG1, 9)
#define mspF_S07                                MakeFLAGID(mspRR_CONFIG1, 8)
#define mspF_S06                                MakeFLAGID(mspRR_CONFIG1, 7)
#define mspF_S05                                MakeFLAGID(mspRR_CONFIG1, 6)
#define mspF_S04                                MakeFLAGID(mspRR_CONFIG1, 5)
#define mspF_S03                                MakeFLAGID(mspRR_CONFIG1, 4)
#define mspF_S02                                MakeFLAGID(mspRR_CONFIG1, 3)
#define mspF_S01                                MakeFLAGID(mspRR_CONFIG1, 2)
#define mspF_S00                                MakeFLAGID(mspRR_CONFIG1, 1)
#define mspF_ALTSTATUS_MESSAGE_ERROR            mspF_S10
#define mspF_ALTSTATUS_INSTRUMENTATION			mspF_S09
#define mspF_ALTSTATUS_SERVICE_REQUEST          mspF_S08
#define mspF_ALTSTATUS_RESERVED_12		      mspF_S07
#define mspF_ALTSTATUS_RESERVED_13		      mspF_S06
#define mspF_ALTSTATUS_RESERVED_14		      mspF_S05
#define mspF_ALTSTATUS_BROADCAST_COMMAND_RECEIVED	mspF_S04
#define mspF_ALTSTATUS_BUSY                     mspF_S03
#define mspF_ALTSTATUS_SUBSYSTEM_FLAG           mspF_S02
#define mspF_ALTSTATUS_ACCEPT_DYNAMIC_BUS_CONTROL   mspF_S01
#define mspF_ALTSTATUS_TERMINAL_FLAG            mspF_S00

#define mspF_MULTIRT_ENABLE                     MakeFLAGID(mspRR_CONFIG2, 14)
#define mspF_BUSY_BIT_LOOKUP_TABLE_ENABLE       MakeFLAGID(mspRR_CONFIG2, 13)
#define mspF_DOUBLE_BUFFERING_ENABLE            MakeFLAGID(mspRR_CONFIG2, 12)
#define mspF_OVERWRITE_INVALID_DATA             MakeFLAGID(mspRR_CONFIG2, 11)
#define mspF_CLEAR_TIME_TAG_ON_SYNCHRONIZE      MakeFLAGID(mspRR_CONFIG2, 6)
#define mspF_LOAD_TIME_TAG_ON_SYNCHRONIZE       MakeFLAGID(mspRR_CONFIG2, 5)
#define mspF_CLEAR_SERVICE_REQUEST              MakeFLAGID(mspRR_CONFIG2, 2)
#define mspF_ENHANCED_RT_MEMORY_MANAGEMENT      MakeFLAGID(mspRR_CONFIG2, 1)
#define mspF_SEPARATE_BROADCAST_DATA            MakeFLAGID(mspRR_CONFIG2, 0)
#define mspF_ILLEGALIZATION_DISABLED            MakeFLAGID(mspRR_CONFIG3, 7)
#define mspF_OVERRIDE_MODE_CODE_BIT_ERROR       MakeFLAGID(mspRR_CONFIG3, 6)
#define mspF_ALTERNATE_RT_STATUS_WORD_ENABLED   MakeFLAGID(mspRR_CONFIG3, 5)
#define mspF_ILLEGAL_RECEIVE_TRANSFER_DISABLE   MakeFLAGID(mspRR_CONFIG3, 4)
#define mspF_BUSY_RECEIVE_TRANSFER_DISABLE      MakeFLAGID(mspRR_CONFIG3, 3)
#define mspF_RTF_WRAP_ENABLE                    MakeFLAGID(mspRR_CONFIG3, 2)
#define mspF_1553A_MODE_CODES_ENABLED           MakeFLAGID(mspRR_CONFIG3, 1)
#define mspF_ENHANCED_MODE_CODE_HANDLING        MakeFLAGID(mspRR_CONFIG3, 0)
#define mspF_EXTERNAL_BIT_WORD_ENABLE           MakeFLAGID(mspRR_CONFIG4, 15)
#define mspF_INHIBIT_BIT_WORD_TRANSMIT_IF_BUSY  MakeFLAGID(mspRR_CONFIG4, 14)
#define mspF_MODE_CODE_OVERRIDE_BUSY            MakeFLAGID(mspRR_CONFIG4, 13)
#define mspF_BROADCAST_DISABLED                 MakeFLAGID(mspRR_CONFIG5, 7)

//MT mode flags
#define mspF_MONITOR_TRIGGER_ENABLED			MakeFLAGID(mspRR_CONFIG1, 11)
#define mspF_START_ON_TRIGGER                   MakeFLAGID(mspRR_CONFIG1, 10)
#define mspF_STOP_ON_TRIGGER                    MakeFLAGID(mspRR_CONFIG1, 9)
#define mspF_EXTERNAL_TRIGGER_ENABLED			MakeFLAGID(mspRR_CONFIG1, 7)
#define mspF_MONITOR_ENABLED                    MakeFLAGID(mspRR_CONFIG1, 2)
#define mspF_MONITOR_TRIGGERED                  MakeFLAGID(mspRR_CONFIG1, 1)
#define mspF_MONITOR_ACTIVE                     MakeFLAGID(mspRR_CONFIG1, 0)
#define mspF_1553A_MODE_CODES_ENABLED			MakeFLAGID(mspRR_CONFIG3, 1)
#define mspF_MONITOR_TAG_GAP_OPTION             MakeFLAGID(mspRR_CONFIG4, 4)
#define mspF_BROADCAST_DISABLED                 MakeFLAGID(mspRR_CONFIG5, 7)

//Interrupt control flags
#define mspF_ENHANCED_INTERRUPTS                MakeFLAGID(mspRR_CONFIG2, 15)
#define mspF_INTERRUPT_STATUS_AUTO_CLEAR        MakeFLAGID(mspRR_CONFIG2, 4)
#define mspF_LEVEL_INTERRUPTS                   MakeFLAGID(mspRR_CONFIG2, 3)
#define mspF_PULSE_INTERRUPTS                   StarFLAGID(mspRR_CONFIG2, 3)

//External config flags
#define mspFE_BUS_TRANSPARENT_MODE				MakeFLAGID(mspRR_EXTERNAL_CONFIG, 0)
#define mspFE_BUS_BUFFERED_MODE					StarFLAGID(mspRR_EXTERNAL_CONFIG, 0)
#define mspFE_BUS_BUFFERED_WORD					MakeFLAGID(mspRR_EXTERNAL_CONFIG, 1)
#define mspFE_BUS_BUFFERED_BYTE					StarFLAGID(mspRR_EXTERNAL_CONFIG, 1)
#define mspFE_POLARITY                          MakeFLAGID(mspRR_EXTERNAL_CONFIG, 2)
#define mspFE_NONZEROWAIT                       MakeFLAGID(mspRR_EXTERNAL_CONFIG, 3)
#define mspFE_NOT_ZEROWAIT                      mspFE_NONZEROWAIT
#define mspFE_ZEROWAIT                          StarFLAGID(mspRR_EXTERNAL_CONFIG, 3)
#define mspFE_ADDR_LAT                          MakeFLAGID(mspRR_EXTERNAL_CONFIG, 4)
#define mspFE_TRIGGER_SEL                       MakeFLAGID(mspRR_EXTERNAL_CONFIG, 5)
#define mspFE_EXT_TRIG                          MakeFLAGID(mspRR_EXTERNAL_CONFIG, 7)
#define mspFE_NOT_SSFLAG                        MakeFLAGID(mspRR_EXTERNAL_CONFIG, 7)
#define mspFE_SSFLAG                            StarFLAGID(mspRR_EXTERNAL_CONFIG, 7)
#define mspFE_NOT_INCMD                         MakeFLAGID(mspRR_EXTERNAL_CONFIG, 8)
#define mspFE_INCMD                             StarFLAGID(mspRR_EXTERNAL_CONFIG, 8)

//Software flags
#define mspFS_RT_SET_BUSY_FOR_BUFFER            MakeFLAGID(mspRR_SOFTWARE1, 0)
#define mspFS_RT_ILLEGALIZE_FOR_BUFFER          MakeFLAGID(mspRR_SOFTWARE1, 1)
#define mspFS_RT_SAFE_RETRIEVE					MakeFLAGID(mspRR_SOFTWARE1, 2)
#define mspFS_MRT_REGISTER_OVERRIDE				MakeFLAGID(mspRR_SOFTWARE1, ofs_MRT_REGISTER_OVERRIDE)
#define mspFS_MRT_REGISTER_NOT_OVERRIDE			StarFLAGID(mspRR_SOFTWARE1, ofs_MRT_REGISTER_OVERRIDE)
												//ofs_MRT_REGISTER_OVERRIDE defined in access.h
												//assumed to be 3
												/* bit 4 is reserved for internal use (see access.h) */
#define mspFS_DISPATCH_KEEP_INTERRUPT			MakeFLAGID(mspRR_SOFTWARE1, 5)

//Virtual registers
#define mspR_RT_STATUS_WORD                     MakeALIAS(mspRR_RT_STATUS_WORD)
#define mspR_TIME_TAG_RESOLUTION                MakeREGID(mspRR_CONFIG2, 0x380)
        //��������:
        #define msp_TIME_TAG_RESOLUTION_64us            0x0000
        #define msp_TIME_TAG_RESOLUTION_32us            0x0080
        #define msp_TIME_TAG_RESOLUTION_16us            0x0100
        #define msp_TIME_TAG_RESOLUTION_8us             0x0180
        #define msp_TIME_TAG_RESOLUTION_4us             0x0200
        #define msp_TIME_TAG_RESOLUTION_2us             0x0280
        #define msp_TIME_TAG_RESOLUTION_TEST_MODE       0x0300
        #define msp_TIME_TAG_RESOLUTION_EXT_CLOCK       0x0380
#define mspR_COMMAND_STACK_POINTER              MakeALIAS(mspRR_COMMAND_STACK_POINTER)
#define mspR_CONTROL_WORD                       MakeALIAS(mspRR_CONTROL_WORD)
#define mspR_TIME_TAG                           MakeALIAS(mspRR_TIME_TAG)
#define mspR_COMMAND_STACK_SIZE                 MakeREGID(mspRR_CONFIG3, 0x6000)
//��� ������� ��/��.
        //��������:
        #define msp_STACK_SIZE_64						0x0000
        #define msp_STACK_SIZE_128                      0x2000
        #define msp_STACK_SIZE_256                      0x4000
        #define msp_STACK_SIZE_512                      0x6000
        //(������ � � ����������)
#define mspR_MT_COMMAND_STACK_SIZE              MakeREGID(mspRR_CONFIG3, 0x1800)
//��� ������ ��.
        //��������:
        #define msp_MT_CSTACK_SIZE_64                   0x0000
        #define msp_MT_CSTACK_SIZE_256                  0x0800
        #define msp_MT_CSTACK_SIZE_1024                 0x1000
        #define msp_MT_CSTACK_SIZE_4096                 0x1800
        //(������ � � ����������)
#define mspR_MT_DATA_STACK_SIZE                 MakeREGID(mspRR_CONFIG3, 0x0700)
//��� ������ ��.
        //��������:
        #define msp_MT_DSTACK_SIZE_64K                  0x0000
        #define msp_MT_DSTACK_SIZE_32K                  0x0100
        #define msp_MT_DSTACK_SIZE_16K                  0x0200
        #define msp_MT_DSTACK_SIZE_8K                   0x0300
        #define msp_MT_DSTACK_SIZE_4K                   0x0400
        #define msp_MT_DSTACK_SIZE_2K                   0x0500
        #define msp_MT_DSTACK_SIZE_1K                   0x0600
        #define msp_MT_DSTACK_SIZE_512                  0x0700
        //(������ � � ������)
#define mspR_RESPONSE_TIMEOUT                   MakeREGID(mspRR_CONFIG5, 0x0600)
        //��������:
        #define msp_RESPONSE_TIMEOUT_18us5              0x0000
        #define msp_RESPONSE_TIMEOUT_22us5              0x0200
        #define msp_RESPONSE_TIMEOUT_50us5              0x0400
        #define msp_RESPONSE_TIMEOUT_130us              0x0600
#define mspR_DATA_STACK_ADDRESS                 MakeALIAS(mspRR_DATA_STACK_ADDRESS)
#define mspR_BC_FRAME_TIME_REMAINING			MakeALIAS(mspRR_FRAME_TIME_REMAINING)
#define mspR_BC_MESSAGE_TIME_REMAINING			MakeALIAS(mspRR_MESSAGE_TIME_REMAINING)
#define mspR_BC_FRAME_TIME                      MakeALIAS(mspRR_BC_FRAME_TIME)
#define mspR_RT_LAST_COMMAND                    mspR_BC_FRAME_TIME
#define mspR_MT_TRIGGER                         mspR_BC_FRAME_TIME
#define mspR_RT_STATUS_WORD                     MakeALIAS(mspRR_RT_STATUS_WORD)
#define mspR_RT_BIT_WORD                        MakeALIAS(mspRR_RT_BIT_WORD)
#define mspR_INTERRUPT_MASK                     MakeALIAS(mspRR_INTERRUPT_MASK)
#define mspR_INTERRUPT_STATUS                   MakeALIAS(mspRR_INTERRUPT_STATUS)
        //mspR_INTERRUPT_MASK � mspR_INTERRUPT_STATUS - ���������� ���.
        //��������� ���:
        #define mspM_MASTER_INTERRUPT                   0x8000 /*������ mspR_INTERRUPT_STATUS*/
        #define mspM_RAM_PARITY_ERROR                   0x4000
        #define mspM_TRANSMITTER_TIMEOUT                0x2000
        #define mspM_COMMAND_STACK_ROLLOVER             0x1000
        #define mspM_MT_COMMAND_STACK_ROLLOVER          0x0800
        #define mspM_MT_DATA_STACK_ROLLOVER             0x0400
        #define mspM_HANDSHAKE_FAILURE                  0x0200
        #define mspM_BC_RETRY                           0x0100
        #define mspM_RT_ADDRESS_PARITY_ERROR            0x0080
        #define mspM_TIME_TAG_ROLLOVER                  0x0040
        #define mspM_RT_CIRCULAR_BUFFER_ROLLOVER        0x0020
        #define mspM_BCCW_EOM                           0x0010
        #define mspM_SACW_EOM                           0x0010
        #define mspM_BC_EOF                             0x0008
        #define mspM_FORMAT_ERROR                       0x0004
        #define mspM_BC_STATUS_SET                      0x0002
        #define mspM_RT_MODE_CODE                       0x0002
        #define mspM_MT_PATTERN_TRIGGER                 0x0002
        #define mspM_EOM                                0x0001
#define mspR_RT_ADDRESS                                 OffsREGID(mspRR_CONFIG5, 0x003E, 1) /*RO; autoshift*/
#define mspRE_RT_ADDRESS                                MakeREGID(mspRR_EXTERNAL_RT_ADDRESS, 0x001F)

//Virtual aliases to other physical registers
//NOT recommended for use programmatically,
//BUT usefull for graphic shell trics
#define mspR_CONFIG1                            MakeALIAS(mspRR_CONFIG1)
#define mspR_CONFIG2                            MakeALIAS(mspRR_CONFIG2)
#define mspR_COMMAND                            MakeALIAS(mspRR_COMMAND)
#define mspR_CONFIG3                            MakeALIAS(mspRR_CONFIG3)
#define mspR_CONFIG4                            MakeALIAS(mspRR_CONFIG4)
#define mspR_CONFIG5                            MakeALIAS(mspRR_CONFIG5)
//lve
#define mspR_CONFIG6                            MakeALIAS(mspRR_CONFIG6)
#define mspRE_EXTERNAL_CONFIG					MakeALIAS(mspRR_EXTERNAL_CONFIG)

//MRT mode flags & vregisters
#define mspR_MRT_ADDRESS                        MakeALIAS(mspRR_MRT_ADDRESS)
#define mspR_MRT_CONFIG1                        MakeALIAS(mspRR_MRT_CONFIG1)
	#define mspF_MRT_S10                            MakeFLAGID(mspRR_MRT_CONFIG1, 11)
	#define mspF_MRT_S09                            MakeFLAGID(mspRR_MRT_CONFIG1, 10)
	#define mspF_MRT_S08                            MakeFLAGID(mspRR_MRT_CONFIG1, 9)
	#define mspF_MRT_S07                            MakeFLAGID(mspRR_MRT_CONFIG1, 8)
	#define mspF_MRT_S06                            MakeFLAGID(mspRR_MRT_CONFIG1, 7)
	#define mspF_MRT_S05                            MakeFLAGID(mspRR_MRT_CONFIG1, 6)
	#define mspF_MRT_S04                            MakeFLAGID(mspRR_MRT_CONFIG1, 5)
	#define mspF_MRT_S03                            MakeFLAGID(mspRR_MRT_CONFIG1, 4)
	#define mspF_MRT_S02                            MakeFLAGID(mspRR_MRT_CONFIG1, 3)
	#define mspF_MRT_S01                            MakeFLAGID(mspRR_MRT_CONFIG1, 2)
	#define mspF_MRT_S00                            MakeFLAGID(mspRR_MRT_CONFIG1, 1)
	#define mspF_MRT_ALTSTATUS_MESSAGE_ERROR        mspF_MRT_S10
	#define mspF_MRT_ALTSTATUS_INSTRUMENTATION	mspF_MRT_S09
	#define mspF_MRT_ALTSTATUS_SERVICE_REQUEST      mspF_MRT_S08
	#define mspF_MRT_ALTSTATUS_RESERVED_12		mspF_MRT_S07
	#define mspF_MRT_ALTSTATUS_RESERVED_13	      mspF_MRT_S06
	#define mspF_MRT_ALTSTATUS_RESERVED_14		mspF_MRT_S05
	#define mspF_MRT_ALTSTATUS_BROADCAST_COMMAND_RECEIVED	mspF_MRT_S04
	#define mspF_MRT_ALTSTATUS_BUSY                 mspF_MRT_S03
	#define mspF_MRT_ALTSTATUS_SUBSYSTEM_FLAG       mspF_MRT_S02
	#define mspF_MRT_ALTSTATUS_ACCEPT_DYNAMIC_BUS_CONTROL	mspF_MRT_S01
	#define mspF_MRT_ALTSTATUS_TERMINAL_FLAG        mspF_MRT_S00
	#define mspF_MRT_NOT_ACCEPT_DYNAMIC_BUS_CONTROL MakeFLAGID(mspRR_MRT_CONFIG1, 11)
	#define mspF_MRT_ACCEPT_DYNAMIC_BUS_CONTROL     StarFLAGID(mspRR_MRT_CONFIG1, 11)
	#define mspF_MRT_BUSY                           StarFLAGID(mspRR_MRT_CONFIG1, 10)
	#define mspF_MRT_NOT_SERVICE_REQUEST            MakeFLAGID(mspRR_MRT_CONFIG1, 9)
	#define mspF_MRT_SERVICE_REQUEST                StarFLAGID(mspRR_MRT_CONFIG1, 9)
	#define mspF_MRT_NOT_SUBSYSTEM_FLAG             MakeFLAGID(mspRR_MRT_CONFIG1, 8)
	#define mspF_MRT_SUBSYSTEM_FLAG                 StarFLAGID(mspRR_MRT_CONFIG1, 8)
	#define mspF_MRT_NOT_RTFLAG                     MakeFLAGID(mspRR_MRT_CONFIG1, 7)
	#define mspF_MRT_RTFLAG                         StarFLAGID(mspRR_MRT_CONFIG1, 7)
#define mspR_MRT_STATUS                         MakeALIAS(mspRR_MRT_STATUS)
	#define mspF_MRT_MESSAGE_IN_PROGRESS			MakeFLAGID(mspRR_MRT_STATUS, 15)
	#define mspR_MRT_ISR_FIFO_COUNTER               MakeREGID(mspRR_MRT_STATUS, 0xF)
	#define mspR_MRT_ACTIVE_RT                      OffsREGID(mspRR_MRT_STATUS, 0x1F00, 8)
#define mspR_MRT_INTERRUPT_STATUS               MakeALIAS(mspRR_MRT_INTERRUPT_STATUS)
	#define mspM_MRT_TRANSMITTER_TIMEOUT        0x2000
    #define mspM_MRT_COMMAND_STACK_ROLLOVER     0x1000
    #define mspM_MRT_HANDSHAKE_FAILURE          0x0200
    #define mspM_MRT_TIME_TAG_ROLLOVER          0x0040
    #define mspM_MRT_RT_CIRCULAR_BUFFER_ROLLOVER  0x0020
    #define mspM_MRT_SACW_EOM                   0x0010
    #define mspM_MRT_FORMAT_ERROR               0x0004
    #define mspM_MRT_RT_MODE_CODE               0x0002
    #define mspM_MRT_EOM                        0x0001
#define mspR_MRT_ISR_RT_ADDRESS					MakeREGID(mspRR_MRT_INTERRUPT_STATUS, 0xFF00)
#define mspR_MRT_COMMAND_WORD                   MakeALIAS(mspRR_MRT_COMMAND_WORD)
#define mspR_MRT_STATUS_WORD                    MakeALIAS(mspRR_MRT_STATUS_WORD)
#define mspR_SOFTWARE2_MRT_ISR					MakeALIAS(mspRR_SOFTWARE2_MRT_ISR)

/***************************************************************
        General configuration functions
 ***************************************************************/

#ifndef msp_MODE_DEFINED

//����� ������ ����������
//������ ����������� � access.h
//��������� ��������� ��� ������ "�������������� �-���" (msp_GetDeviceInfoEx())

typedef msp_WORD msp_MODE; //bitmapped:

#define msp_MODE_NOT_DEFINED 0x0000
#define msp_MODE_BC                     0x0001
#define msp_MODE_RT                     0x0002
#define msp_MODE_MM                     0x0004
#define msp_MODE_WM                     0x0008
#define msp_MODE_IDLE					0x0010
#define msp_MODE_ENHANCED				0x8000
// ��� ���
#define msp_MODE_WG						0x0020

//����� (�������) ��� SelectMode
#define msp_SWITCH_WITHOUT_RESET        0x0100
#define msp_SWITCH_KEEP_RAM             0x0200
// ��� ���
#define msp_WG_FIRST					0
#define msp_WM_FIRST					0x4000
// ��� MRT
#define msp_MODE_MRT					0x0040

#endif

msp_ERROR msp_SelectMode(msp_DEVHANDLE device, msp_MODE mode);
//����� ������ ������ ����������.
//���������:
//device � ����������
//mode � ��������� (������� �����) ���������� ������� msp_MODE_XX, msp_SWITCH_XX

msp_ERROR msp_Configure(msp_DEVHANDLE device, msp_MODE mode,
                        MSP_CONST msp_FLAGID* flags, MSP_CONST msp_REGVALUE* regvalues);
//����������� ���������������� ����������.
//������������ ���������� ������� msp_SelectMode(),
//msp_SetFlagsIndirect(), msp_SetVRegsIndirect().
//���������:
//device � ����������
//mode � ��������� (������� �����) ���������� �������
//flags � ������ �������, ��������������� � �1�. �.�. NULL
//regvalues � ������ �������� ���������� � �� ��������, �.�. NULL

/***************************************************************
        Command functions
 ***************************************************************/

msp_ERROR msp_Command(msp_DEVHANDLE device, msp_WORD command);
//������ �������. (������ � ��������� �������)
//���������:
//device � ����������
//command � ��� �������. bitmapped: mspC_XXXX

#define mspC_RESET                      0x0001
#define mspC_START                      0x0002
#define mspC_INTERRUPT_RESET            0x0004
#define mspC_TIME_TAG_RESET             0x0008
#define mspC_TIME_TAG_TEST_CLOCK        0x0010
#define mspC_STOP_ON_FRAME              0x0020
#define mspC_STOP_ON_MESSAGE            0x0040

#define msp_Start(device)               msp_Command(device, mspC_START)
#define msp_Reset(device)               msp_Command(device, mspC_RESET)
#define msp_ResetInterrupt(device)      msp_Command(device, mspC_INTERRUPT_RESET)
#define msp_ResetTimeTag(device)        msp_Command(device, mspC_TIME_TAG_RESET)
#define msp_TimeTagTestClock(device)    msp_Command(device, mspC_TIME_TAG_TEST_CLOCK)
#define msp_StopOnFrame(device)         msp_Command(device, mspC_STOP_ON_FRAME)
#define msp_StopOnMessage(device)       msp_Command(device, mspC_STOP_ON_MESSAGE)

/***************************************************************
 ***************************************************************
        Mode-independent protocol functions & data types
 ***************************************************************
 ***************************************************************/

/***************************************************************
        Common constants & data types
 ***************************************************************/

//����� ������ � ��� ���
#ifndef RAM_H
// gcc forbids redefinitions
typedef msp_HANDLE      msp_RAMHANDLE;
#endif
//������� ������� ���
#define msp_STK_A       0
#define msp_STK_B       1
#define msp_STK_mask	1

//����������� ��������.
#ifndef __linux__ 
typedef msp_BYTE msp_DIR;
#endif

#define msp_DIR_RX      0
#define msp_DIR_TX      1
#define msp_DIR_BCST    2       //������ ��� RT
#define msp_DIR2_mask   1
#define msp_DIR3_mask   3

/***************************************************************
        1553 messages
 ***************************************************************/

//��������� 1553 - ������������� ������������� � ��� �����
//�������������� ���� ������������ ����� ��������� ����������
//����� ���������, �������� ���������� ���������
typedef struct {
        msp_WORD type;     // <=> ������
        msp_WORD dataWordCount; // <-> ������
        msp_WORD bccw;     // <=> � ������ BC
        /*-----*/
        msp_WORD CmdWord1; // <=> ������
        msp_WORD CmdWord2; // <=> RT-to-RT
        msp_WORD Data[32]; // <=> ������
        /*-----*/
        msp_WORD StatusWord1; // => ����� ������� msp_RetrieveMessage(), msp_ReadBCMessage
        msp_WORD StatusWord2; // => -"- + RT-to-RT
        msp_WORD loopback;    // => -"- � ������ BC
        /*-----*/
        msp_WORD bsw; /*Block Status Word*/ // => ����� ������� msp_RetrieveMessage()
        msp_WORD timetag;  // => ����� ������� msp_RetrieveMessage()
		// ��� ���
		msp_BYTE present; //
		msp_BYTE transmit;
		msp_BYTE check;
		msp_BYTE role;
} msp_Message;

//��������������� ������ ��� ��������� ���� type
#define mspM_fRECEIVE 1
#define mspM_fTRANSMIT 2
#define mspM_fMODECODE 4
#define mspM_fBROADCAST 8
// ��� ��������� ��� "������������" ���������
#define mspM_EXTENDED	0x10
// ��� ��������� ��� ������������ �������
#define mspM_EXTENDED_TERM		0x30

//���������� �������� � ���� type
#define mspM_BCtoRT mspM_fRECEIVE
#define mspM_RTtoBC	mspM_fTRANSMIT
#define mspM_RTtoRT	(mspM_fRECEIVE | mspM_fTRANSMIT)
#define mspM_BCtoRT_BROADCAST (mspM_fRECEIVE | mspM_fBROADCAST)
#define mspM_RTtoRT_BROADCAST (mspM_fRECEIVE | mspM_fTRANSMIT | mspM_fBROADCAST)
#define mspM_MODECODE mspM_fMODECODE
#define mspM_MODECODE_DATA_TX (mspM_fMODECODE | mspM_fTRANSMIT)
#define mspM_MODECODE_DATA_RX (mspM_fMODECODE | mspM_fRECEIVE)
#define mspM_MODECODE_BROADCAST (mspM_fMODECODE | mspM_fBROADCAST)
#define mspM_MODECODE_DATA_BROADCAST (mspM_fMODECODE | mspM_fRECEIVE | mspM_fBROADCAST)
//� ������������
#define mspM_UNDEFINED 0

//Mode codes
#define mspMC_DYNAMIC_BUS_CONTROL                       0x00
#define mspMC_SYNCHRONIZE                               0x01
#define mspMC_TRANSMIT_STATUS_WORD                      0x02
#define mspMC_INITIATE_SELF_TEST                        0x03
#define mspMC_TRANSMITTER_SHUTDOWN                      0x04
#define mspMC_OVERRIDE_TRANSMITTER_SHUTDOWN             0x05
#define mspMC_INHIBIT_TFLAG                             0x06
#define mspMC_OVERRIDE_INHIBIT_TFLAG                    0x07
#define mspMC_RESET_REMOTE_TERMINAL                     0x08
#define mspMC_RESET_RT                                  mspMC_RESET_REMOTE_TERMINAL
#define mspMC_TRANSMIT_VECTOR_WORD                      0x10
#define mspMC_SYNCHRONIZE_WITH_DATA                     0x11
#define mspMC_TRANSMIT_LAST_COMMAND                     0x12
#define mspMC_TRANSMIT_BIT_WORD                         0x13
#define mspMC_SELECTED_TRANSMITTER_SHUTDOWN             0x14
#define mspMC_OVERRIDE_SELECTED_TRANSMITTER_SHUTDOWN    0x15

//Status decode
#define msp_STATUS_RTADD_MASK					0xF800
#define msp_STATUS_MESSAGE_ERROR				0x0400
#define msp_STATUS_INSTRUMENTATION				0x0200
#define msp_STATUS_SERVICE_REQUEST				0x0100
#define msp_STATUS_RESERVED_12				0x0080
#define msp_STATUS_RESERVED_13				0x0040
#define msp_STATUS_RESERVED_14				0x0020
#define msp_STATUS_BROADCAST_COMMAND_RECEIVED   0x0010
#define msp_STATUS_BUSY							0x0008
#define msp_STATUS_SUBSYSTEM_FLAG				0x0004
#define msp_STATUS_DYNAMIC_BUS_CONTROL_ACCEPTED 0x0002
#define msp_STATUS_TERMINAL_FLAG				0x0001

/***************************************************************
        Command word encoding & decoding; Status decoding
 ***************************************************************/

#define FormatCommandWord(DIR, RT, SA, WCNT) \
(((DIR)==msp_DIR_TX? 0x0400:0) | ((RT) & 0x1F)<<11 | ((SA) & 0x1F)<<5 | (WCNT) & 0x1F)

#define ParseCommandWord(CMD, TX, RT, SA, WCNT) \
(TX = ((CMD) & 0x0400) != 0, RT = (CMD) >> 11, SA = ((CMD) >> 5) & 0x1F, \
 WCNT = (CMD) & 0x1F)

#define CorrectWCNT(WCNT) (WCNT? WCNT : WCNT = 32)

#define StatusRTADD(S) ((S) >> 11)

/***************************************************************
        Constants & data types for stacks & frames
 ***************************************************************/

//���� ���������
typedef msp_RAMHANDLE   msp_STKHANDLE;
//!!: msp_FRMHANDLE (bc.h) - ������� ������ msp_STKHANDLE

//��������� (���������) ��������
typedef enum {msp_MESSAGE_WAITING, msp_MESSAGE_IN_PROGRESS, msp_MESSAGE_COMPLETED}
msp_MESSAGE_STATUS;

//���� ����� (FW), ����� (SW)
#define msp_FW_BSW      0
#define msp_FW_TIMETAG  1
#define msp_FW_MSGGAP   2
#define msp_FW_MSGADDR  3
#define msp_SW_BSW      0
#define msp_SW_TIMETAG  1
#define msp_SW_DBP      2
#define msp_SW_CMD      3

//����������� "������" � �����
#define msp_LAST_RECEIVED       0xFFFF
#define msp_NEXT_MESSAGE        0xFFFE
#define msp_SAME_MESSAGE        0xFFFD

//Block Status Word bits
#define msp_BSW_EOM                                     (1<<15)
#define msp_BSW_SOM                                     (1<<14)
#define msp_BSW_CHANNEL_B                               (1<<13)
#define msp_BSW_ERROR_FLAG                              (1<<12)
#define msp_BSW_FORMAT_ERROR							(1<<10)
#define msp_BSW_NO_RESPONSE_TIMEOUT                     (1<<9)

#define msp_BSW_BC_EOM                                  (1<<15)
#define msp_BSW_BC_SOM                                  (1<<14)
#define msp_BSW_BC_CHANNEL_B                            (1<<13)
#define msp_BSW_BC_ERROR_FLAG                           (1<<12)
#define msp_BSW_BC_STATUS_SET                           (1<<11)
#define msp_BSW_BC_FORMAT_ERROR                         (1<<10)
#define msp_BSW_BC_NO_RESPONSE_TIMEOUT                  (1<<9)
#define msp_BSW_BC_LOOP_TEST_FAIL                       (1<<8)
#define msp_BSW_BC_MASKED_STATUS_SET                    (1<<7)
#define msp_BSW_BC_DOUBLE_RETRY                         (1<<6)
#define msp_BSW_BC_SINGLE_RETRY                         (1<<5)
#define msp_BSW_BC_GOOD_DATA_BLOCK_TRANSFER             (1<<4)
#define msp_BSW_BC_STATUS_RESPONSE_ERROR                (1<<3)
#define msp_BSW_BC_WORD_COUNT_ERROR                     (1<<2)
#define msp_BSW_BC_INCORRECT_SYNC_TYPE                  (1<<1)
#define msp_BSW_BC_INVALID_WORD                          1

#define msp_BSW_RT_EOM                                  (1<<15)
#define msp_BSW_RT_SOM                                  (1<<14)
#define msp_BSW_RT_CHANNEL_B                            (1<<13)
#define msp_BSW_RT_ERROR_FLAG                           (1<<12)
#define msp_BSW_RT_RT_TO_RT                             (1<<11)
#define msp_BSW_RT_FORMAT_ERROR                         (1<<10)
#define msp_BSW_RT_NO_RESPONSE_TIMEOUT                  (1<<9)
#define msp_BSW_RT_LOOP_TEST_FAIL                       (1<<8)
#define msp_BSW_RT_CIRCULAR_BUFFER_ROLLOVER             (1<<7)
#define msp_BSW_RT_DATA_STACK_ROLLOVER                  msp_BSW_RT_CIRCULAR_BUFFER_ROLLOVER
        //Older invalid identifier - for backward compatibility
#define msp_BSW_RT_ILLEGAL_COMMAND_WORD                 (1<<6)
#define msp_BSW_RT_WORD_COUNT_ERROR                     (1<<5)
#define msp_BSW_RT_INCORRECT_DATA_SYNC                  (1<<4)
#define msp_BSW_RT_INVALID_WORD                         (1<<3)
#define msp_BSW_RT_STATUS_RESPONSE_ERROR                (1<<2)
#define msp_BSW_RT_SECOND_COMMAND_ERROR                 (1<<1)
#define msp_BSW_RT_COMMAND_WORD_ERROR                   1

#define msp_BSW_MM_EOM                                  (1<<15)
#define msp_BSW_MM_SOM                                  (1<<14)
#define msp_BSW_MM_CHANNEL_B                            (1<<13)
#define msp_BSW_MM_ERROR_FLAG                           (1<<12)
#define msp_BSW_MM_RT_TO_RT                             (1<<11)
#define msp_BSW_MM_FORMAT_ERROR                         (1<<10)
#define msp_BSW_MM_NO_RESPONSE_TIMEOUT					(1<<9)
#define msp_BSW_MM_GOOD_DATA_BLOCK_TRANSFER             (1<<8)
#define msp_BSW_MM_DATA_STACK_ROLLOVER                  (1<<7)
                                                      /*Bit 6 is reserved*/
#define msp_BSW_MM_WORD_COUNT_ERROR                     (1<<5)
#define msp_BSW_MM_INCORRECT_DATA_SYNC                  (1<<4)
#define msp_BSW_MM_INVALID_WORD                         (1<<3)
#define msp_BSW_MM_STATUS_RESPONSE_ERROR                (1<<2)
#define msp_BSW_MM_SECOND_COMMAND_ERROR                 (1<<1)
#define msp_BSW_MM_COMMAND_WORD_ERROR                   1

/////////////////////////////// ���������� ��� ��� /////////////////////////////////////////
// ����������� ��������
#define mspR_WG_DATA_STACK_POINTER		(MakeALIAS(mspRR_WG_DATA_STACK_POINTER))
#define mspR_WG_INITIAL_DATA_STACK_POINTER	(MakeALIAS(mspRR_WG_INITIAL_DATA_STACK_POINTER))
// �����
#define mspF_GENERATOR_ACTIVE	(MakeFLAGID(mspRR_CONFIG1,3))


/***************************************************************
    Polymorphic functions for stacks & frames
 ***************************************************************/

msp_ERROR msp_RetrieveMessage(msp_STKHANDLE stack, int entry, msp_Message* buffer);
//���������� ��������� �� ��� ��� � ��� �����, ��������� �� ������� ��������� �� ����������� ��������� � ������ �����/�����
//stack � ����; ����������� RT-����, MT-���� ��� BC-�����
//entry � ����� ����������� ��������� � �����
//                      ��� "������������" ����� ��������� ����������� �������
//                      msp_NEXT_MESSAGE - ��������� ��������� (���������, ���� � ���)
//                                                              ��� �������� ���������� �������� ���������
//                                                              �������� ��������� ������������ ������
//                      msp_SAME_MESSAGE - �� �� ���������, ��� � ��� ���������� ���������
//                      msp_LAST_RECEIVED - ���������, �� ������� ��������� ���������� ���������
//buffer � ����� ��� ���������� ���������. � ������ ����������� �������������� ���� StatusWord1/2, loopback, BSW, timetag.

msp_WORD msp_ReadStackWord(msp_STKHANDLE stack, int entry, msp_BYTE offset);
//���������� ����� �� ��� ���, �� ��������� �����/�����.
//stack � ���� (RT,MT) ��� ���� (BC)
//entry � ����� ����������� ��������� � �����, ��� ����������� ��������
//      msp_NEXT_MESSAGE - ��������� ���������
//                                         ��������� �������� ��������� �� ������������ ������
//      msp_SAME_MESSAGE - �� �� ���������, ��� � ��� ���������� ��������� � msp_RetrieveMessage
//      msp_LAST_RECEIVED - ���������, �� ������� ��������� ���������� ���������
//offset � ����� ����� �����������, ����� ��������� �������� msp_SD_XXXX ��� msp_FD_XXXX
//      msp_SW_BSW � ����� ��������� �����
//      msp_SW_TIMETAG � ��������� �����
//      msp_SW_DBP � ��������� ����� ������
//      msp_SW_CMD � �������� ������� 1553
//      msp_FW_BSW � ����� ��������� ����� (BC)
//      msp_FW_TIMETAG � ��������� ����� (BC)
//      msp_FW_MSGGAP � ��������� �������� �� ���������� ��������� (BC)
//      msp_FW_MSGADDR � ����� ����� ��������� (BC)

msp_MESSAGE_STATUS msp_GetMessageStatus(msp_STKHANDLE stack, int entry);
//������ ��������� ���������.
//stack � ���� (RT,MT) ��� ���� (BC)
//entry � ����� ����������� ��������� � �����, ��� ����������� ��������
//      msp_NEXT_MESSAGE - ��������� ���������
//                                         ��������� �������� ��������� �� ������������ ������
//      msp_SAME_MESSAGE - �� �� ���������, ��� � ��� ���������� ��������� � msp_RetrieveMessage
//      msp_LAST_RECEIVED - ���������, �� ������� ��������� ���������� ���������
//�������: ���� �� ��������:
//msp_MST_WAITING
//msp_MST_IN_PROGRESS
//msp_MST_COMPLETED

msp_WORD msp_GetCurrentEntry(msp_STKHANDLE stack, int option);
//������� ��������� � ����� (�����)
//stack � ����; ����������� RT-����, MT-���� ��� BC-�����
//���� ������ ���� "��������"
//option - ���� �� ��������
//      msp_NEXT_MESSAGE - ��������� ���������
//                                         ��������� �������� ��������� �� ������������ ������
//      msp_SAME_MESSAGE - �� �� ���������, ��� � ��� ���������� ��������� � msp_RetrieveMessage
//      msp_LAST_RECEIVED - ���������, �� ������� ��������� ���������� ���������
//�������: � ���������

msp_ERROR msp_ResetStack(msp_STKHANDLE stack, int msgindex);
//��������� ���������� ������ ��������
//��������� � ������������ ����� ������ RT ��� MT
//���������:
//stack - ����
//msgindex - ��������� ������ ���������
//���� ������ ���� ��������
#define msp_SetStkStart msp_ResetStack
//������ ��������


/***************************************************************
        Ram object functions:. applicable to all.
 ***************************************************************/

msp_WORD msp_AddressOf(msp_RAMHANDLE handle);
msp_WORD msp_SizeOf(msp_RAMHANDLE handle);
msp_RAMHANDLE msp_HandleFrom(msp_DEVHANDLE device, msp_WORD Address); //SLOW!
//����� ������� � ��� ��� � �������

msp_DEVHANDLE msp_DeviceOf(msp_RAMHANDLE handle);
//������ ���������� ����������� ������

#define msp_FillHandle(handle, data) \
        msp_FillRamBLK(msp_DeviceOf(handle), \
                                        msp_AddressOf(handle), \
                                        data, \
                                        msp_SizeOf(handle))
//��������� ������ ����������. ��� ������ ������ ������������

msp_ERROR msp_DestroyHandle(msp_RAMHANDLE handle);
//���� �������� ����� ������� ����� ������ �� ��� ���

/***************************************************************
        Ram control
 ***************************************************************/

msp_DWORD msp_RamTotal(msp_DEVHANDLE device);
msp_DWORD msp_RamFree(msp_DEVHANDLE device); //SLOW!
//���������� � ������������� ���

msp_ERROR msp_EraseRam(msp_DEVHANDLE device);
//���������� ��� ����������
//����� ������: ��� ��������� ���������.
//                              Handle's ���� �������� � ��� - �� �������������
//���� ���������������� ���������� ����� �������� �������
//SelectMode() � Configure() ������������� �������� ��� �������,
//���� �� ������ ����� msp_SWITCH_KEEP_RAM

msp_ERROR msp_FixedRam(msp_DEVHANDLE device, msp_BYTE command, msp_WORD areas);
//���������� ��������������� ������������� ���������� ���
//device - ����������
//command - �������, ���� �� ��������
//      msp_CARE_FRAM - ������������� ������������� ��������� ������������� �������
//                                      (����� msp_Open() ��� ���� �������� ����������� "CARE")
//      msp_DONT_CARE_FRAM - !msp_CARE_FRAM
//      msp_RESERVE_FRAM - ��������������� ��������� ������� ����������
//      msp_FREE_FRAM - ����������  ��������� ������� ����������
//      msp_CHECK_FRAM - ���������� ������������� �������������
//                              � ��������������� ����������� �������;
//                              �������� areas - �� �����������
//areas - �������, � ������� ��������� �������, ���������� �������� msp_FRAM_XXXX

#define msp_CARE_FRAM           1
#define msp_DONT_CARE_FRAM      2
#define msp_RESERVE_FRAM        3
#define msp_FREE_FRAM           4
#define msp_CHECK_FRAM          5

#define msp_FRAM_POINTERS               0x0001
#define msp_FRAM_MM_LOOKUP              0x0002
#define msp_FRAM_LOOKUP_A               0x0004
#define msp_FRAM_LOOKUP_B               0x0008
#define msp_FRAM_MODECODE_INT			0x0010
#define msp_FRAM_MODECODE_DATA			0x0020
#define msp_FRAM_BUSY                   0x0040
#define msp_FRAM_ILLEGALIZATION			0x0080
#define msp_FRAM_DUMMY					0x0100

//Fixed RAM locations (within msp_FRAM_POINTERS)
#define msp_BC_STACK_POINTER_A          0x0100
#define msp_BC_STACK_COUNTER_A          0x0101
#define msp_BC_INITIAL_STACK_POINTER_A	0x0102
#define msp_BC_INITIAL_STACK_COUNTER_A  0x0103
#define msp_RT_STACK_POINTER_A          0x0100
#define msp_MM_STACK_POINTER_A          0x0102
#define msp_MM_DATA_STACK_POINTER_A     0x0103
#define msp_WM_INITIAL_STACK_POINTER_A  0x0100
#define msp_BC_STACK_POINTER_B          0x0104
#define msp_BC_STACK_COUNTER_B          0x0105
#define msp_BC_INITIAL_STACK_POINTER_B  0x0106
#define msp_BC_INITIAL_STACK_COUNTER_B  0x0107
#define msp_RT_STACK_POINTER_B          0x0104
#define msp_MM_STACK_POINTER_B          0x0106
#define msp_MM_DATA_STACK_POINTER_B     0x0107
#define msp_WM_INITIAL_STACK_POINTER_B  0x0104
#define msp_MRT_ACTIVITY_VECTOR_1		0x0102
#define msp_MRT_ACTIVITY_VECTOR_2		0x0103

/***************************************************************
        Common RT/MT configuration parameters
 ***************************************************************/

typedef struct {
        msp_WORD rangeCmdWord0, rangeCmdWord1;
} msp_rangeCmdWords;
//���������� �������� ������, � ������� �����������
//������� msp_SetBusySA[Indirect], msp_MTSelectMessages[Indirect]
//��� msp_SetIllegalCommands[Indirect]
//������������� - ��. �������� ���� �������

#define msp_RANGE_ALL           0xFF
#define msp_RANGE_DIR_TX        msp_DIR_TX
#define msp_RANGE_DIR_RX        msp_DIR_RX
#define msp_RANGE_RT_OWN        0
#define msp_RANGE_RT_BCST       31

//������� ��� �������� �������� msp_rangeCmdWords
//����������� 2 ������������� ��������� � ���� "constant, constant"
//�������������: ��� ��� ������������ ���������������� ��������
//      ������: confBusy [] = { { msp_rangeCmd(DIR, RT, SA0, SA1) },... } 
//��� - ����� �������� - � ������ ���������� �������.
//msp_rangeCmdBUSY() ������������� ��� ������������� � msp_SetBusySA[Indirect],
//msp_rangeCmdILL() - ��������� � msp_SetIllegalCommands[Indirect],
//msp_rangeCmdMT() - ��������� � msp_SelectMessages[Indirect],
//msp_rangeAll() - ���������� ������������ �������� � ����� �������������� � ����� ��������.

#define msp_rangeCmdBUSY(DIR, RT, SA0, SA1) \
  FormatCommandWord((DIR)==msp_RANGE_ALL?msp_DIR_RX:(DIR),  \
                    (RT)==msp_RANGE_ALL?0:(RT), \
                    (SA0), 0), \
  FormatCommandWord((DIR)==msp_RANGE_ALL?msp_DIR_TX:(DIR), \
                    (RT)==msp_RANGE_ALL?31:(RT), \
                    (SA1), 0)

#define msp_rangeCmdILL(DIR, RT, SA0, SA1, WC0, WC1) \
  FormatCommandWord((DIR)==msp_RANGE_ALL?msp_DIR_RX:(DIR),  \
                    (RT)==msp_RANGE_ALL?0:(RT), \
                    (SA0), (WC0)), \
  FormatCommandWord((DIR)==msp_RANGE_ALL?msp_DIR_TX:(DIR), \
                    (RT)==msp_RANGE_ALL?31:(RT), \
                    (SA1), (WC1))

//DIR - ����������� ��������; ���������: msp_RANGE_DIR_TX, 
//              msp_RANGE_DIR_RX, msp_RANGE_ALL
//RT - ������� ������������������/��������� ������,
//              ���������: msp_RANGE_RT_OWN, msp_RANGE_RT_BCST, msp_RANGE_ALL
//SA0, SA1 - ��������� � �������� �� ����������� ���������,
//              ���������: 0-31, ���� ����� ������ 1 ��, ������� ������ ��������
//WC0, WC1 (������ msp_rangeCmdWC())
//              - ��������� � �������� ����� ���� ������ ����������� ���������

#define msp_rangeCmdMT(DIR, RT0, RT1, SA0, SA1) \
  FormatCommandWord((DIR)==msp_RANGE_ALL?msp_DIR_RX:(DIR), (RT0), (SA0), 0), \
  FormatCommandWord((DIR)==msp_RANGE_ALL?msp_DIR_TX:(DIR), (RT1), (SA1), 0)

//DIR - ����������� ��������; ���������: msp_RANGE_DIR_TX, 
//              msp_RANGE_DIR_RX, msp_RANGE_ALL
//RT0, RT1 - ��������� � �������� ����� �� ����������� ���������,
//              ���������: 0-31, ���� ����� ������ 1 ��, ������� ������ ��������
//SA0, SA1 - ��������� � �������� �� ����������� ���������,
//              ���������: 0-31, ���� ����� ������ 1 ��, ������� ������ ��������


#define msp_rangeAll 0x0000, 0xFFFF

#define msp_ENABLE	1
#define msp_DISABLE	0



#ifdef __cplusplus
}
#endif

#endif
