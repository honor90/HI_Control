#include "Log.h"

#include <stdio.h>
#include "stdafx.h"
#include <direct.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

#include "MB26_20.h"


using namespace std;

char Name_log_file[80];
char Path[200];
char time_prog[80];

ofstream log_file;


void Log_File_Create(void)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "Log_%d_%m_%Y_(%H_%M_%S)";
	strftime(Name_log_file, 80, format, timeinfo);
	strftime(time_prog, 80, format, timeinfo);

	strcat(Name_log_file, ".txt");

	mkdir("Log");

	getcwd(Path, 200);

	strcat(Path, "\\Log\\");

	strcat(Path, Name_log_file);

	log_file.open(Path);

	format = "%d.%m.%Y %H:%M:%S";
	strftime(time_prog, 80, format, timeinfo);

	log_file << "����� ������ ������ ���������: ";
	log_file << time_prog;
	log_file << "\n";
	log_file << "\n";
}

void Log_File_Write_Count_Dev_MB26_20(int count_dev)
{
	log_file << "���������� ��������� �� ����: " << count_dev << "\n";
}

void Log_File_Write_Count_Bad_Pack(int bad_pack)
{
	log_file << "���������� ����������� �������: " << bad_pack << "\n";
}

void Log_File_Write_Start(unsigned int Number_Chanel, unsigned int addr)
{
	switch (Number_Chanel)
	{
		case 0x01: log_file << "����� ������ ����. " << "����� ������: � " << "����� ��: " << addr << "\n";
			break;
		case 0x02: log_file << "����� ������ ����. " << "����� ������: � " << "����� ��: " << addr << "\n";
			break;
	}
}

void Log_File_Write_Date(int date)
{
	log_file << date << "\n";
}

void Log_File_Write_Text(char *text)
{
	log_file << text << "\n";
}

void Log_File_Write_BC_F1(unsigned int subaddress, unsigned short *Data)
{
	log_file << "�� �1 ��: " << subaddress << " ��: ";
	for (int j = 0; j <= 5; j++)
	{
		log_file << hex << setfill('0') << setw(4) << Data[j] << " ";
	}
	log_file << "\n";
}

void Log_File_Write_RT(Input_Pack *IP)
{
	log_file << "��: " << hex << setfill('0') << setw(4) << IP->StatusWord1 << " ��: ";
	
	for (int j = 0; j <= (IP->dataWordCount -1); j++)
	{
		log_file << hex << setfill('0') << setw(4) << IP->Data[j] << " ";
	}
	log_file << "\n";
}

void Log_File_Write_BC_Test_RT_F1(unsigned short *Data)
{
	log_file << "�� �1 ��: 30 ��:";
	for (int j = 0; j <= 5; j++)
	{
		log_file << hex << setfill('0') << setw(4) << Data[j] << " ";
	}
	log_file << "\n";
}

void Log_File_Error_CRC16(unsigned short  crc)
{
	log_file << "������ CRC16. ������������ CRC16: " << hex << setfill('0') << setw(4) << crc;
	log_file << "\n";
}

void Log_File_Close(void)
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%d.%m.%Y %H:%M:%S";
	strftime(time_prog, 80, format, timeinfo);

	log_file << "\n";
	log_file << "����� ���������� ������ ���������: ";
	log_file << time_prog;

	log_file.close();
}

