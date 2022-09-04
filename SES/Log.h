#pragma once

#include "MB26_20.h"

void Log_File_Create(void);

void Log_File_Write_Count_Dev_MB26_20(int count_dev);

void Log_File_Write_Count_Bad_Pack(int bad_pack);

void Log_File_Write_Connect_MB26_20(void);

void Log_File_Write_Start(unsigned int Number_Chanel, unsigned int addr);

void Log_File_Write_Date(int date);

void Log_File_Write_Text(char *text);

void Log_File_Write_BC_F1(unsigned int subaddress, unsigned short *Data);

void Log_File_Write_RT(Input_Pack *IP);

void Log_File_Write_BC_Test_RT_F1(unsigned short *Data);

void Log_File_Error_CRC16(unsigned short  crc);

void Log_File_Close(void);

