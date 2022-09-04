#pragma once
#include <stdio.h>
#include <string.h>
#include "stdafx.h"
#include "windows.h"
#include "MB26_20.h"
#include "Log.h"
#include "CRC16.h"

int count_Devices = 0;
int IndexDevices = 0;
int count_error_crc16 = 0;

Input_Pack IPack;

bool Start_button_q = true;

static unsigned short buf_format_1[6];
static unsigned char addres;
static unsigned char N_Chanel;
static unsigned char count_Valid_pack = 0;
static unsigned char count_bad_pack = 0;
static unsigned char last_number_pack = 0;

static bool push_button_pow_cel_nag = true;
static bool push_button_pow_bat = true;
static bool push_button_launch_aircraft = true;
static bool push_button_aircraft_air = true;

static bool push_button_all = true;

static bool push_button6_1 = true;
static bool push_button6_2 = true;
static bool push_button6_3 = true;
static bool push_button6_4 = true;
static bool push_button6_5 = true;
static bool push_button6_6 = true;
static bool push_button6_7 = true;
static bool push_button6_8 = true;

static bool push_button7_1 = true;
static bool push_button7_2 = true;
static bool push_button7_3 = true;
static bool push_button7_4 = true;
static bool push_button7_5 = true;
static bool push_button7_6 = true;
static bool push_button7_7 = true;
static bool push_button7_8 = true;

static bool push_button8_1 = true;
static bool push_button8_2 = true;
static bool push_button8_3 = true;
static bool push_button8_4 = true;
static bool push_button8_5 = true;
static bool push_button8_6 = true;
static bool push_button8_7 = true;
static bool push_button8_8 = true;

static bool push_button9_1 = true;
static bool push_button9_2 = true;
static bool push_button9_3 = true;
static bool push_button9_4 = true;
static bool push_button9_5 = true;
static bool push_button9_6 = true;
static bool push_button9_7 = true;
static bool push_button9_8 = true;

static bool push_button10_1 = true;
static bool push_button10_2 = true;
static bool push_button10_3 = true;
static bool push_button10_4 = true;
static bool push_button10_5 = true;
static bool push_button10_6 = true;
static bool push_button10_7 = true;
static bool push_button10_8 = true;

unsigned char TP_sec = 0;
unsigned char TP_min = 0;
unsigned char TP_hour = 0;


namespace SES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form_main : public System::Windows::Forms::Form
	{
	public:

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5_1_1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Label^  label_f1;
	private: System::Windows::Forms::Label^  label_f1_text;
	private: System::Windows::Forms::Label^  label_f2;
	private: System::Windows::Forms::Label^  labelf2_text;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel45;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Panel^  panel46;
	private: System::Windows::Forms::Panel^  panel47;
	private: System::Windows::Forms::Button^  button10_2;
	private: System::Windows::Forms::Panel^  panel48;
	private: System::Windows::Forms::Button^  button10_8;
	private: System::Windows::Forms::Panel^  panel49;
	private: System::Windows::Forms::Button^  button10_5;
	private: System::Windows::Forms::Panel^  panel50;
	private: System::Windows::Forms::Button^  button10_1;
	private: System::Windows::Forms::Panel^  panel51;
	private: System::Windows::Forms::Button^  button10_4;
	private: System::Windows::Forms::Panel^  panel52;
	private: System::Windows::Forms::Button^  button10_7;
	private: System::Windows::Forms::Panel^  panel53;
	private: System::Windows::Forms::Panel^  panel54;
	private: System::Windows::Forms::Button^  button10_6;
	private: System::Windows::Forms::Button^  button45;
	private: System::Windows::Forms::Panel^  panel55;
	private: System::Windows::Forms::Button^  button10_3;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::Label^  label47;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::Label^  label49;
	private: System::Windows::Forms::Label^  label50;
	private: System::Windows::Forms::Panel^  panel56;
	private: System::Windows::Forms::Label^  label51;
	private: System::Windows::Forms::Panel^  panel57;
	private: System::Windows::Forms::Panel^  panel58;
	private: System::Windows::Forms::Button^  button9_2;
	private: System::Windows::Forms::Panel^  panel59;
	private: System::Windows::Forms::Button^  button9_8;
	private: System::Windows::Forms::Panel^  panel60;
	private: System::Windows::Forms::Button^  button9_5;
	private: System::Windows::Forms::Panel^  panel61;
	private: System::Windows::Forms::Button^  button9_1;
	private: System::Windows::Forms::Panel^  panel62;
	private: System::Windows::Forms::Button^  button9_4;
	private: System::Windows::Forms::Panel^  panel63;
	private: System::Windows::Forms::Button^  button9_7;
	private: System::Windows::Forms::Panel^  panel64;
	private: System::Windows::Forms::Panel^  panel65;
	private: System::Windows::Forms::Button^  button9_6;
	private: System::Windows::Forms::Button^  button54;
	private: System::Windows::Forms::Panel^  panel66;
	private: System::Windows::Forms::Button^  button9_3;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::Label^  label53;
	private: System::Windows::Forms::Label^  label54;
	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::Label^  label56;
	private: System::Windows::Forms::Label^  label57;
	private: System::Windows::Forms::Label^  label58;
	private: System::Windows::Forms::Label^  label59;
	private: System::Windows::Forms::Label^  label60;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Button^  button7_2;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Button^  button7_8;
	private: System::Windows::Forms::Panel^  panel16;
	private: System::Windows::Forms::Button^  button7_5;
	private: System::Windows::Forms::Panel^  panel17;
	private: System::Windows::Forms::Button^  button7_1;
	private: System::Windows::Forms::Panel^  panel18;
	private: System::Windows::Forms::Button^  button7_4;
	private: System::Windows::Forms::Panel^  panel19;
	private: System::Windows::Forms::Button^  button7_7;
	private: System::Windows::Forms::Panel^  panel20;
	private: System::Windows::Forms::Panel^  panel21;
	private: System::Windows::Forms::Button^  button7_6;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Panel^  panel22;
	private: System::Windows::Forms::Button^  button7_3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  button6_2;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Button^  button6_8;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Button^  button6_5;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button6_1;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  button6_4;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Button^  button6_7;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Button^  button6_6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  button6_3;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label91;
	private: System::Windows::Forms::Label^  label92;
	private: System::Windows::Forms::Label^  label93;
	private: System::Windows::Forms::Label^  label94;
	private: System::Windows::Forms::Label^  label95;
	private: System::Windows::Forms::Label^  label96;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label_U_SH2;
	private: System::Windows::Forms::Panel^  panel127;
	private: System::Windows::Forms::Label^  label142;
	private: System::Windows::Forms::Panel^  panel128;
	private: System::Windows::Forms::Label^  label_1_k8_i;
	private: System::Windows::Forms::Label^  label_1_k7_i;
	private: System::Windows::Forms::Label^  label_1_k6_i;
	private: System::Windows::Forms::Label^  label_1_k5_i;
	private: System::Windows::Forms::Label^  label_1_k4_i;
	private: System::Windows::Forms::Label^  label_1_k2_i;
	private: System::Windows::Forms::Label^  label_1_k1_i;
	private: System::Windows::Forms::Label^  label_1_k3_i;
	private: System::Windows::Forms::Label^  label143;
	private: System::Windows::Forms::Label^  label144;
	private: System::Windows::Forms::Panel^  panel129;
	private: System::Windows::Forms::Label^  label_1_k8_s;
	private: System::Windows::Forms::Label^  label_1_k7_s;
	private: System::Windows::Forms::Label^  label_1_k6_s;
	private: System::Windows::Forms::Label^  label_1_k5_s;
	private: System::Windows::Forms::Label^  label_1_k4_s;
	private: System::Windows::Forms::Label^  label_1_k2_s;
	private: System::Windows::Forms::Label^  label_1_k1_s;
	private: System::Windows::Forms::Label^  label_1_k3_s;
	private: System::Windows::Forms::Label^  label147;
	private: System::Windows::Forms::Label^  label148;
	private: System::Windows::Forms::Label^  label149;
	private: System::Windows::Forms::Label^  label150;
	private: System::Windows::Forms::Label^  label151;
	private: System::Windows::Forms::Label^  label152;
	private: System::Windows::Forms::Label^  label153;
	private: System::Windows::Forms::Label^  label154;
	private: System::Windows::Forms::Label^  label_U_BAT;
	private: System::Windows::Forms::Label^  label_U_SH1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Panel^  panel115;
	private: System::Windows::Forms::Label^  label109;
	private: System::Windows::Forms::Panel^  panel116;
	private: System::Windows::Forms::Label^  label_5_k8_i;
	private: System::Windows::Forms::Label^  label_5_k7_i;
	private: System::Windows::Forms::Label^  label_5_k6_i;
	private: System::Windows::Forms::Label^  label_5_k5_i;
	private: System::Windows::Forms::Label^  label_5_k4_i;
	private: System::Windows::Forms::Label^  label_5_k2_i;
	private: System::Windows::Forms::Label^  label_5_k1_i;
	private: System::Windows::Forms::Label^  label_5_k3_i;
	private: System::Windows::Forms::Label^  label118;
	private: System::Windows::Forms::Label^  label119;
	private: System::Windows::Forms::Panel^  panel117;
	private: System::Windows::Forms::Label^  label_5_k8_s;
	private: System::Windows::Forms::Label^  label_5_k7_s;
	private: System::Windows::Forms::Label^  label_5_k6_s;
	private: System::Windows::Forms::Label^  label_5_k5_s;
	private: System::Windows::Forms::Label^  label_5_k4_s;
	private: System::Windows::Forms::Label^  label_5_k2_s;
	private: System::Windows::Forms::Label^  label_5_k1_s;
	private: System::Windows::Forms::Label^  label_5_k3_s;
	private: System::Windows::Forms::Label^  label128;
	private: System::Windows::Forms::Label^  label129;
	private: System::Windows::Forms::Label^  label130;
	private: System::Windows::Forms::Label^  label131;
	private: System::Windows::Forms::Label^  label132;
	private: System::Windows::Forms::Label^  label133;
	private: System::Windows::Forms::Label^  label134;
	private: System::Windows::Forms::Label^  label135;
	private: System::Windows::Forms::Panel^  panel124;
	private: System::Windows::Forms::Label^  label122;
	private: System::Windows::Forms::Panel^  panel125;
	private: System::Windows::Forms::Label^  label_2_k8_i;
	private: System::Windows::Forms::Label^  label_2_k7_i;
	private: System::Windows::Forms::Label^  label_2_k6_i;
	private: System::Windows::Forms::Label^  label_2_k5_i;
	private: System::Windows::Forms::Label^  label_2_k4_i;
	private: System::Windows::Forms::Label^  label_2_k2_i;
	private: System::Windows::Forms::Label^  label_2_k1_i;
	private: System::Windows::Forms::Label^  label_2_k3_i;
	private: System::Windows::Forms::Label^  label123;
	private: System::Windows::Forms::Label^  label124;
	private: System::Windows::Forms::Panel^  panel126;
	private: System::Windows::Forms::Label^  label_2_k8_s;
	private: System::Windows::Forms::Label^  label_2_k7_s;
	private: System::Windows::Forms::Label^  label_2_k6_s;
	private: System::Windows::Forms::Label^  label_2_k5_s;
	private: System::Windows::Forms::Label^  label_2_k4_s;
	private: System::Windows::Forms::Label^  label_2_k2_s;
	private: System::Windows::Forms::Label^  label_2_k1_s;
	private: System::Windows::Forms::Label^  label_2_k3_s;
	private: System::Windows::Forms::Label^  label125;
	private: System::Windows::Forms::Label^  label126;
	private: System::Windows::Forms::Label^  label127;
	private: System::Windows::Forms::Label^  label137;
	private: System::Windows::Forms::Label^  label138;
	private: System::Windows::Forms::Label^  label139;
	private: System::Windows::Forms::Label^  label140;
	private: System::Windows::Forms::Label^  label141;
	private: System::Windows::Forms::Panel^  panel118;
	private: System::Windows::Forms::Label^  label136;
	private: System::Windows::Forms::Panel^  panel119;
	private: System::Windows::Forms::Label^  label_4_k8_i;
	private: System::Windows::Forms::Label^  label_4_k7_i;
	private: System::Windows::Forms::Label^  label_4_k6_i;
	private: System::Windows::Forms::Label^  label_4_k5_i;
	private: System::Windows::Forms::Label^  label_4_k4_i;
	private: System::Windows::Forms::Label^  label_4_k2_i;
	private: System::Windows::Forms::Label^  label_4_k1_i;
	private: System::Windows::Forms::Label^  label_4_k3_i;
	private: System::Windows::Forms::Label^  label145;
	private: System::Windows::Forms::Label^  label146;
	private: System::Windows::Forms::Panel^  panel120;
	private: System::Windows::Forms::Label^  label_4_k8_s;
	private: System::Windows::Forms::Label^  label_4_k7_s;
	private: System::Windows::Forms::Label^  label_4_k6_s;
	private: System::Windows::Forms::Label^  label_4_k5_s;
	private: System::Windows::Forms::Label^  label_4_k4_s;
	private: System::Windows::Forms::Label^  label_4_k2_s;
	private: System::Windows::Forms::Label^  label_4_k1_s;
	private: System::Windows::Forms::Label^  label_4_k3_s;
	private: System::Windows::Forms::Label^  label155;
	private: System::Windows::Forms::Label^  label156;
	private: System::Windows::Forms::Label^  label157;
	private: System::Windows::Forms::Label^  label158;
	private: System::Windows::Forms::Label^  label159;
	private: System::Windows::Forms::Label^  label160;
	private: System::Windows::Forms::Label^  label161;
	private: System::Windows::Forms::Label^  label162;
	private: System::Windows::Forms::Panel^  panel121;
	private: System::Windows::Forms::Label^  label100;
	private: System::Windows::Forms::Panel^  panel122;
	private: System::Windows::Forms::Label^  label_3_k8_i;
	private: System::Windows::Forms::Label^  label_3_k7_i;
	private: System::Windows::Forms::Label^  label_3_k6_i;
	private: System::Windows::Forms::Label^  label_3_k5_i;
	private: System::Windows::Forms::Label^  label_3_k4_i;
	private: System::Windows::Forms::Label^  label_3_k2_i;
	private: System::Windows::Forms::Label^  label_3_k1_i;
	private: System::Windows::Forms::Label^  label_3_k3_i;
	private: System::Windows::Forms::Label^  label110;
	private: System::Windows::Forms::Label^  label111;
	private: System::Windows::Forms::Panel^  panel123;
	private: System::Windows::Forms::Label^  label_3_k8_s;
	private: System::Windows::Forms::Label^  label_3_k7_s;
	private: System::Windows::Forms::Label^  label_3_k6_s;
	private: System::Windows::Forms::Label^  label_3_k5_s;
	private: System::Windows::Forms::Label^  label_3_k4_s;
	private: System::Windows::Forms::Label^  label_3_k2_s;
	private: System::Windows::Forms::Label^  label_3_k1_s;
	private: System::Windows::Forms::Label^  label_3_k3_s;
	private: System::Windows::Forms::Label^  label112;
	private: System::Windows::Forms::Label^  label113;
	private: System::Windows::Forms::Label^  label114;
	private: System::Windows::Forms::Label^  label115;
	private: System::Windows::Forms::Label^  label116;
	private: System::Windows::Forms::Label^  label117;
	private: System::Windows::Forms::Label^  label120;
	private: System::Windows::Forms::Label^  label121;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel130;
	private: System::Windows::Forms::Label^  label_time_program;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::Label^  label_result_test;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  label_stat_connect;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label_count_bad_pack;
	private: System::Windows::Forms::Label^  label164;
	private: System::Windows::Forms::Panel^  panel142;
	private: System::Windows::Forms::Label^  label169;
	private: System::Windows::Forms::Panel^  panel143;
	private: System::Windows::Forms::Label^  label_gen2_i;
	private: System::Windows::Forms::Label^  label179;
	private: System::Windows::Forms::Panel^  panel139;
	private: System::Windows::Forms::Label^  label167;
	private: System::Windows::Forms::Panel^  panel140;
	private: System::Windows::Forms::Label^  label_gen1_i;
	private: System::Windows::Forms::Label^  label175;
	private: System::Windows::Forms::Panel^  panel136;
	private: System::Windows::Forms::Label^  label166;
	private: System::Windows::Forms::Panel^  panel137;
	private: System::Windows::Forms::Label^  label_bat_i;
	private: System::Windows::Forms::Label^  label168;
	private: System::Windows::Forms::Panel^  panel138;
	private: System::Windows::Forms::Label^  label_bat_s;
	private: System::Windows::Forms::Label^  label170;
	private: System::Windows::Forms::Panel^  panel133;
	private: System::Windows::Forms::Label^  label165;
	private: System::Windows::Forms::Panel^  panel134;
	private: System::Windows::Forms::Label^  label_nip_i;
	private: System::Windows::Forms::Label^  label176;
	private: System::Windows::Forms::Panel^  panel135;
	private: System::Windows::Forms::Label^  label_nip_s;
	private: System::Windows::Forms::Label^  label196;
	private: System::Windows::Forms::Panel^  panel145;
	private: System::Windows::Forms::Label^  label191;
	private: System::Windows::Forms::Panel^  panel131;
	private: System::Windows::Forms::Panel^  panel148;
	private: System::Windows::Forms::Panel^  panel147;
	private: System::Windows::Forms::Panel^  panel132;
	private: System::Windows::Forms::Label^  label180;
	private: System::Windows::Forms::Label^  Напряжение;
	private: System::Windows::Forms::Label^  label178;
	private: System::Windows::Forms::Label^  label500;
	private: System::Windows::Forms::Panel^  panel34;
	private: System::Windows::Forms::Label^  label_cel_nag_i;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Panel^  panel35;
	private: System::Windows::Forms::Label^  label_cel_nag_s;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Panel^  panel39;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Panel^  panel40;
	private: System::Windows::Forms::Panel^  panel41;
	private: System::Windows::Forms::Button^  button_pow_bat;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Panel^  panel36;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Panel^  panel38;
	private: System::Windows::Forms::Panel^  panel37;
	private: System::Windows::Forms::Button^  button_pow_cel_nag;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Panel^  panel67;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Panel^  panel68;
	private: System::Windows::Forms::Panel^  panel69;
	private: System::Windows::Forms::Button^  button_aircraft_air;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Panel^  panel42;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Panel^  panel43;
	private: System::Windows::Forms::Panel^  panel44;
	private: System::Windows::Forms::Button^  button_launch_aircraft;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::Label^  label61;
	private: System::Windows::Forms::Panel^  panel70;
	private: System::Windows::Forms::Label^  label_mrp5_i;
	private: System::Windows::Forms::Label^  label_mrp4_i;
	private: System::Windows::Forms::Label^  label_mrp2_i;
	private: System::Windows::Forms::Label^  label_mrp1_i;
	private: System::Windows::Forms::Label^  label_mrp3_i;
	private: System::Windows::Forms::Label^  label70;
	private: System::Windows::Forms::Label^  label62;
	private: System::Windows::Forms::Label^  label_error_crc16;
	private: System::Windows::Forms::Panel^  panel23;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Panel^  panel24;
	private: System::Windows::Forms::Panel^  panel25;
	private: System::Windows::Forms::Button^  button8_2;
	private: System::Windows::Forms::Panel^  panel26;
	private: System::Windows::Forms::Button^  button8_8;
	private: System::Windows::Forms::Panel^  panel27;
	private: System::Windows::Forms::Button^  button8_5;
	private: System::Windows::Forms::Panel^  panel28;
	private: System::Windows::Forms::Button^  button8_1;
	private: System::Windows::Forms::Panel^  panel29;
	private: System::Windows::Forms::Button^  button8_4;
	private: System::Windows::Forms::Panel^  panel30;
	private: System::Windows::Forms::Button^  button8_7;
	private: System::Windows::Forms::Panel^  panel31;
	private: System::Windows::Forms::Panel^  panel32;
	private: System::Windows::Forms::Button^  button8_6;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::Panel^  panel33;
	private: System::Windows::Forms::Button^  button8_3;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Panel^  panel71;
	private: System::Windows::Forms::Label^  label63;
	private: System::Windows::Forms::Panel^  panel72;
	private: System::Windows::Forms::Panel^  panel73;
	private: System::Windows::Forms::Button^  button_all;
	private: System::Windows::Forms::Label^  label64;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	public:

		Form_main(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
			label1_1_2->Text = " ";
			label1_2_2->Text = " ";

			label_stat_connect->Text = " ";
			label_f1->Text = " ";
			label_f2->Text = " ";

			label_cel_nag_s->Text = " ";
			label_cel_nag_i->Text = " ";
			label_nip_s->Text = " ";
			label_nip_i->Text = " ";
			label_U_SH1->Text = " ";
			label_U_SH2->Text = " ";
			label_U_BAT->Text = " ";
			label_mrp1_i->Text = " ";
			label_mrp2_i->Text = " ";
			label_mrp3_i->Text = " ";
			label_mrp4_i->Text = " ";
			label_mrp5_i->Text = " ";
			label_gen1_i->Text = " ";
			label_gen2_i->Text = " ";
			label_bat_s->Text = " ";
			label_bat_i->Text = " ";
			label_result_test->Text = " ";
			label_count_bad_pack->Text = "0";
			label_error_crc16->Text = "0";
			label_time_program->Text = "00:00:00";

			comboBox2->SelectedIndex = 0;
			comboBox3->SelectedIndex = 1;

			buf_format_1[0] = 0x0000;
			buf_format_1[1] = 0x0000;
			buf_format_1[2] = 0x0000;
			buf_format_1[3] = 0x0000;
			buf_format_1[4] = 0x0000;
			buf_format_1[5] = 0x0000;

			Log_File_Create();

			MB26_20_Startup();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form_main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1_1_2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1_2_2;
	private: System::Windows::Forms::Label^  label1_2_1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1_1_2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1_2_2 = (gcnew System::Windows::Forms::Label());
			this->label1_2_1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label_error_crc16 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label_count_bad_pack = (gcnew System::Windows::Forms::Label());
			this->label164 = (gcnew System::Windows::Forms::Label());
			this->label_stat_connect = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->label_result_test = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_f2 = (gcnew System::Windows::Forms::Label());
			this->labelf2_text = (gcnew System::Windows::Forms::Label());
			this->label_f1 = (gcnew System::Windows::Forms::Label());
			this->label_f1_text = (gcnew System::Windows::Forms::Label());
			this->label5_1_1 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel45 = (gcnew System::Windows::Forms::Panel());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->panel46 = (gcnew System::Windows::Forms::Panel());
			this->panel47 = (gcnew System::Windows::Forms::Panel());
			this->button10_2 = (gcnew System::Windows::Forms::Button());
			this->panel48 = (gcnew System::Windows::Forms::Panel());
			this->button10_8 = (gcnew System::Windows::Forms::Button());
			this->panel49 = (gcnew System::Windows::Forms::Panel());
			this->button10_5 = (gcnew System::Windows::Forms::Button());
			this->panel50 = (gcnew System::Windows::Forms::Panel());
			this->button10_1 = (gcnew System::Windows::Forms::Button());
			this->panel51 = (gcnew System::Windows::Forms::Panel());
			this->button10_4 = (gcnew System::Windows::Forms::Button());
			this->panel52 = (gcnew System::Windows::Forms::Panel());
			this->button10_7 = (gcnew System::Windows::Forms::Button());
			this->panel53 = (gcnew System::Windows::Forms::Panel());
			this->panel54 = (gcnew System::Windows::Forms::Panel());
			this->button10_6 = (gcnew System::Windows::Forms::Button());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->panel55 = (gcnew System::Windows::Forms::Panel());
			this->button10_3 = (gcnew System::Windows::Forms::Button());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->panel56 = (gcnew System::Windows::Forms::Panel());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->panel57 = (gcnew System::Windows::Forms::Panel());
			this->panel58 = (gcnew System::Windows::Forms::Panel());
			this->button9_2 = (gcnew System::Windows::Forms::Button());
			this->panel59 = (gcnew System::Windows::Forms::Panel());
			this->button9_8 = (gcnew System::Windows::Forms::Button());
			this->panel60 = (gcnew System::Windows::Forms::Panel());
			this->button9_5 = (gcnew System::Windows::Forms::Button());
			this->panel61 = (gcnew System::Windows::Forms::Panel());
			this->button9_1 = (gcnew System::Windows::Forms::Button());
			this->panel62 = (gcnew System::Windows::Forms::Panel());
			this->button9_4 = (gcnew System::Windows::Forms::Button());
			this->panel63 = (gcnew System::Windows::Forms::Panel());
			this->button9_7 = (gcnew System::Windows::Forms::Button());
			this->panel64 = (gcnew System::Windows::Forms::Panel());
			this->panel65 = (gcnew System::Windows::Forms::Panel());
			this->button9_6 = (gcnew System::Windows::Forms::Button());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->panel66 = (gcnew System::Windows::Forms::Panel());
			this->button9_3 = (gcnew System::Windows::Forms::Button());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->button7_2 = (gcnew System::Windows::Forms::Button());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->button7_8 = (gcnew System::Windows::Forms::Button());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->button7_5 = (gcnew System::Windows::Forms::Button());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->button7_1 = (gcnew System::Windows::Forms::Button());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->button7_4 = (gcnew System::Windows::Forms::Button());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->button7_7 = (gcnew System::Windows::Forms::Button());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->button7_6 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->button7_3 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button6_2 = (gcnew System::Windows::Forms::Button());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button6_8 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button6_5 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button6_1 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button6_4 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button6_7 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button6_6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button6_3 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->panel71 = (gcnew System::Windows::Forms::Panel());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->panel72 = (gcnew System::Windows::Forms::Panel());
			this->panel73 = (gcnew System::Windows::Forms::Panel());
			this->button_all = (gcnew System::Windows::Forms::Button());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->panel67 = (gcnew System::Windows::Forms::Panel());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->panel68 = (gcnew System::Windows::Forms::Panel());
			this->panel69 = (gcnew System::Windows::Forms::Panel());
			this->button_aircraft_air = (gcnew System::Windows::Forms::Button());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->panel42 = (gcnew System::Windows::Forms::Panel());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->panel43 = (gcnew System::Windows::Forms::Panel());
			this->panel44 = (gcnew System::Windows::Forms::Panel());
			this->button_launch_aircraft = (gcnew System::Windows::Forms::Button());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->panel39 = (gcnew System::Windows::Forms::Panel());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->panel40 = (gcnew System::Windows::Forms::Panel());
			this->panel41 = (gcnew System::Windows::Forms::Panel());
			this->button_pow_bat = (gcnew System::Windows::Forms::Button());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->panel36 = (gcnew System::Windows::Forms::Panel());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->panel38 = (gcnew System::Windows::Forms::Panel());
			this->panel37 = (gcnew System::Windows::Forms::Panel());
			this->button_pow_cel_nag = (gcnew System::Windows::Forms::Button());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->button8_2 = (gcnew System::Windows::Forms::Button());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->button8_8 = (gcnew System::Windows::Forms::Button());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->button8_5 = (gcnew System::Windows::Forms::Button());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->button8_1 = (gcnew System::Windows::Forms::Button());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->button8_4 = (gcnew System::Windows::Forms::Button());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->button8_7 = (gcnew System::Windows::Forms::Button());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->button8_6 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->button8_3 = (gcnew System::Windows::Forms::Button());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->panel131 = (gcnew System::Windows::Forms::Panel());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->panel148 = (gcnew System::Windows::Forms::Panel());
			this->label_U_SH2 = (gcnew System::Windows::Forms::Label());
			this->panel147 = (gcnew System::Windows::Forms::Panel());
			this->label_U_SH1 = (gcnew System::Windows::Forms::Label());
			this->panel132 = (gcnew System::Windows::Forms::Panel());
			this->label_U_BAT = (gcnew System::Windows::Forms::Label());
			this->label180 = (gcnew System::Windows::Forms::Label());
			this->label500 = (gcnew System::Windows::Forms::Label());
			this->label178 = (gcnew System::Windows::Forms::Label());
			this->panel145 = (gcnew System::Windows::Forms::Panel());
			this->panel70 = (gcnew System::Windows::Forms::Panel());
			this->label_mrp5_i = (gcnew System::Windows::Forms::Label());
			this->label_mrp4_i = (gcnew System::Windows::Forms::Label());
			this->label_mrp2_i = (gcnew System::Windows::Forms::Label());
			this->label_mrp1_i = (gcnew System::Windows::Forms::Label());
			this->label_mrp3_i = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label191 = (gcnew System::Windows::Forms::Label());
			this->panel142 = (gcnew System::Windows::Forms::Panel());
			this->label169 = (gcnew System::Windows::Forms::Label());
			this->panel140 = (gcnew System::Windows::Forms::Panel());
			this->label_gen1_i = (gcnew System::Windows::Forms::Label());
			this->panel143 = (gcnew System::Windows::Forms::Panel());
			this->label_gen2_i = (gcnew System::Windows::Forms::Label());
			this->label175 = (gcnew System::Windows::Forms::Label());
			this->label179 = (gcnew System::Windows::Forms::Label());
			this->panel139 = (gcnew System::Windows::Forms::Panel());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->label_cel_nag_i = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->label_cel_nag_s = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label167 = (gcnew System::Windows::Forms::Label());
			this->panel136 = (gcnew System::Windows::Forms::Panel());
			this->label166 = (gcnew System::Windows::Forms::Label());
			this->panel137 = (gcnew System::Windows::Forms::Panel());
			this->label_bat_i = (gcnew System::Windows::Forms::Label());
			this->label168 = (gcnew System::Windows::Forms::Label());
			this->panel138 = (gcnew System::Windows::Forms::Panel());
			this->label_bat_s = (gcnew System::Windows::Forms::Label());
			this->label170 = (gcnew System::Windows::Forms::Label());
			this->panel133 = (gcnew System::Windows::Forms::Panel());
			this->label165 = (gcnew System::Windows::Forms::Label());
			this->panel134 = (gcnew System::Windows::Forms::Panel());
			this->label_nip_i = (gcnew System::Windows::Forms::Label());
			this->label176 = (gcnew System::Windows::Forms::Label());
			this->panel135 = (gcnew System::Windows::Forms::Panel());
			this->label_nip_s = (gcnew System::Windows::Forms::Label());
			this->label196 = (gcnew System::Windows::Forms::Label());
			this->panel127 = (gcnew System::Windows::Forms::Panel());
			this->label142 = (gcnew System::Windows::Forms::Label());
			this->panel128 = (gcnew System::Windows::Forms::Panel());
			this->label_1_k8_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k7_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k6_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k5_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k4_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k2_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k1_i = (gcnew System::Windows::Forms::Label());
			this->label_1_k3_i = (gcnew System::Windows::Forms::Label());
			this->label143 = (gcnew System::Windows::Forms::Label());
			this->label144 = (gcnew System::Windows::Forms::Label());
			this->panel129 = (gcnew System::Windows::Forms::Panel());
			this->label_1_k8_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k7_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k6_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k5_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k4_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k2_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k1_s = (gcnew System::Windows::Forms::Label());
			this->label_1_k3_s = (gcnew System::Windows::Forms::Label());
			this->label147 = (gcnew System::Windows::Forms::Label());
			this->label148 = (gcnew System::Windows::Forms::Label());
			this->label149 = (gcnew System::Windows::Forms::Label());
			this->label150 = (gcnew System::Windows::Forms::Label());
			this->label151 = (gcnew System::Windows::Forms::Label());
			this->label152 = (gcnew System::Windows::Forms::Label());
			this->label153 = (gcnew System::Windows::Forms::Label());
			this->label154 = (gcnew System::Windows::Forms::Label());
			this->panel115 = (gcnew System::Windows::Forms::Panel());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->panel116 = (gcnew System::Windows::Forms::Panel());
			this->label_5_k8_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k7_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k6_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k5_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k4_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k2_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k1_i = (gcnew System::Windows::Forms::Label());
			this->label_5_k3_i = (gcnew System::Windows::Forms::Label());
			this->label118 = (gcnew System::Windows::Forms::Label());
			this->label119 = (gcnew System::Windows::Forms::Label());
			this->panel117 = (gcnew System::Windows::Forms::Panel());
			this->label_5_k8_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k7_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k6_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k5_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k4_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k2_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k1_s = (gcnew System::Windows::Forms::Label());
			this->label_5_k3_s = (gcnew System::Windows::Forms::Label());
			this->label128 = (gcnew System::Windows::Forms::Label());
			this->label129 = (gcnew System::Windows::Forms::Label());
			this->label130 = (gcnew System::Windows::Forms::Label());
			this->label131 = (gcnew System::Windows::Forms::Label());
			this->label132 = (gcnew System::Windows::Forms::Label());
			this->label133 = (gcnew System::Windows::Forms::Label());
			this->label134 = (gcnew System::Windows::Forms::Label());
			this->label135 = (gcnew System::Windows::Forms::Label());
			this->panel124 = (gcnew System::Windows::Forms::Panel());
			this->label122 = (gcnew System::Windows::Forms::Label());
			this->panel125 = (gcnew System::Windows::Forms::Panel());
			this->label_2_k8_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k7_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k6_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k5_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k4_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k2_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k1_i = (gcnew System::Windows::Forms::Label());
			this->label_2_k3_i = (gcnew System::Windows::Forms::Label());
			this->label123 = (gcnew System::Windows::Forms::Label());
			this->label124 = (gcnew System::Windows::Forms::Label());
			this->panel126 = (gcnew System::Windows::Forms::Panel());
			this->label_2_k8_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k7_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k6_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k5_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k4_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k2_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k1_s = (gcnew System::Windows::Forms::Label());
			this->label_2_k3_s = (gcnew System::Windows::Forms::Label());
			this->label125 = (gcnew System::Windows::Forms::Label());
			this->label126 = (gcnew System::Windows::Forms::Label());
			this->label127 = (gcnew System::Windows::Forms::Label());
			this->label137 = (gcnew System::Windows::Forms::Label());
			this->label138 = (gcnew System::Windows::Forms::Label());
			this->label139 = (gcnew System::Windows::Forms::Label());
			this->label140 = (gcnew System::Windows::Forms::Label());
			this->label141 = (gcnew System::Windows::Forms::Label());
			this->panel118 = (gcnew System::Windows::Forms::Panel());
			this->label136 = (gcnew System::Windows::Forms::Label());
			this->panel119 = (gcnew System::Windows::Forms::Panel());
			this->label_4_k8_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k7_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k6_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k5_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k4_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k2_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k1_i = (gcnew System::Windows::Forms::Label());
			this->label_4_k3_i = (gcnew System::Windows::Forms::Label());
			this->label145 = (gcnew System::Windows::Forms::Label());
			this->label146 = (gcnew System::Windows::Forms::Label());
			this->panel120 = (gcnew System::Windows::Forms::Panel());
			this->label_4_k8_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k7_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k6_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k5_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k4_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k2_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k1_s = (gcnew System::Windows::Forms::Label());
			this->label_4_k3_s = (gcnew System::Windows::Forms::Label());
			this->label155 = (gcnew System::Windows::Forms::Label());
			this->label156 = (gcnew System::Windows::Forms::Label());
			this->label157 = (gcnew System::Windows::Forms::Label());
			this->label158 = (gcnew System::Windows::Forms::Label());
			this->label159 = (gcnew System::Windows::Forms::Label());
			this->label160 = (gcnew System::Windows::Forms::Label());
			this->label161 = (gcnew System::Windows::Forms::Label());
			this->label162 = (gcnew System::Windows::Forms::Label());
			this->panel121 = (gcnew System::Windows::Forms::Panel());
			this->label100 = (gcnew System::Windows::Forms::Label());
			this->panel122 = (gcnew System::Windows::Forms::Panel());
			this->label_3_k8_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k7_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k6_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k5_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k4_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k2_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k1_i = (gcnew System::Windows::Forms::Label());
			this->label_3_k3_i = (gcnew System::Windows::Forms::Label());
			this->label110 = (gcnew System::Windows::Forms::Label());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->panel123 = (gcnew System::Windows::Forms::Panel());
			this->label_3_k8_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k7_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k6_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k5_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k4_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k2_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k1_s = (gcnew System::Windows::Forms::Label());
			this->label_3_k3_s = (gcnew System::Windows::Forms::Label());
			this->label112 = (gcnew System::Windows::Forms::Label());
			this->label113 = (gcnew System::Windows::Forms::Label());
			this->label114 = (gcnew System::Windows::Forms::Label());
			this->label115 = (gcnew System::Windows::Forms::Label());
			this->label116 = (gcnew System::Windows::Forms::Label());
			this->label117 = (gcnew System::Windows::Forms::Label());
			this->label120 = (gcnew System::Windows::Forms::Label());
			this->label121 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel130 = (gcnew System::Windows::Forms::Panel());
			this->label_time_program = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->panel45->SuspendLayout();
			this->panel46->SuspendLayout();
			this->panel47->SuspendLayout();
			this->panel48->SuspendLayout();
			this->panel49->SuspendLayout();
			this->panel50->SuspendLayout();
			this->panel51->SuspendLayout();
			this->panel52->SuspendLayout();
			this->panel53->SuspendLayout();
			this->panel54->SuspendLayout();
			this->panel55->SuspendLayout();
			this->panel56->SuspendLayout();
			this->panel57->SuspendLayout();
			this->panel58->SuspendLayout();
			this->panel59->SuspendLayout();
			this->panel60->SuspendLayout();
			this->panel61->SuspendLayout();
			this->panel62->SuspendLayout();
			this->panel63->SuspendLayout();
			this->panel64->SuspendLayout();
			this->panel65->SuspendLayout();
			this->panel66->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->panel71->SuspendLayout();
			this->panel72->SuspendLayout();
			this->panel73->SuspendLayout();
			this->panel67->SuspendLayout();
			this->panel68->SuspendLayout();
			this->panel69->SuspendLayout();
			this->panel42->SuspendLayout();
			this->panel43->SuspendLayout();
			this->panel44->SuspendLayout();
			this->panel39->SuspendLayout();
			this->panel40->SuspendLayout();
			this->panel41->SuspendLayout();
			this->panel36->SuspendLayout();
			this->panel38->SuspendLayout();
			this->panel37->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel27->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel30->SuspendLayout();
			this->panel31->SuspendLayout();
			this->panel32->SuspendLayout();
			this->panel33->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->panel131->SuspendLayout();
			this->panel148->SuspendLayout();
			this->panel147->SuspendLayout();
			this->panel132->SuspendLayout();
			this->panel145->SuspendLayout();
			this->panel70->SuspendLayout();
			this->panel142->SuspendLayout();
			this->panel140->SuspendLayout();
			this->panel143->SuspendLayout();
			this->panel139->SuspendLayout();
			this->panel34->SuspendLayout();
			this->panel35->SuspendLayout();
			this->panel136->SuspendLayout();
			this->panel137->SuspendLayout();
			this->panel138->SuspendLayout();
			this->panel133->SuspendLayout();
			this->panel134->SuspendLayout();
			this->panel135->SuspendLayout();
			this->panel127->SuspendLayout();
			this->panel128->SuspendLayout();
			this->panel129->SuspendLayout();
			this->panel115->SuspendLayout();
			this->panel116->SuspendLayout();
			this->panel117->SuspendLayout();
			this->panel124->SuspendLayout();
			this->panel125->SuspendLayout();
			this->panel126->SuspendLayout();
			this->panel118->SuspendLayout();
			this->panel119->SuspendLayout();
			this->panel120->SuspendLayout();
			this->panel121->SuspendLayout();
			this->panel122->SuspendLayout();
			this->panel123->SuspendLayout();
			this->panel130->SuspendLayout();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 5);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Время работы программы:";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1_1_2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label1_2_2);
			this->groupBox1->Controls->Add(this->label1_2_1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(263, 155);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Управление МВ26.20";
			// 
			// label1_1_2
			// 
			this->label1_1_2->AutoSize = true;
			this->label1_1_2->Location = System::Drawing::Point(237, 38);
			this->label1_1_2->Name = L"label1_1_2";
			this->label1_1_2->Size = System::Drawing::Size(59, 13);
			this->label1_1_2->TabIndex = 11;
			this->label1_1_2->Text = L"label1_1_2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(107, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(133, 13);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Устройств на шине USB:";
			// 
			// comboBox1
			// 
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(110, 81);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(134, 21);
			this->comboBox1->TabIndex = 9;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(6, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(95, 30);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Подключить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form_main::button2_Click);
			// 
			// label1_2_2
			// 
			this->label1_2_2->AutoSize = true;
			this->label1_2_2->Location = System::Drawing::Point(119, 122);
			this->label1_2_2->Name = L"label1_2_2";
			this->label1_2_2->Size = System::Drawing::Size(59, 13);
			this->label1_2_2->TabIndex = 6;
			this->label1_2_2->Text = L"label1_2_2";
			// 
			// label1_2_1
			// 
			this->label1_2_1->AutoSize = true;
			this->label1_2_1->Location = System::Drawing::Point(6, 122);
			this->label1_2_1->Name = L"label1_2_1";
			this->label1_2_1->Size = System::Drawing::Size(107, 13);
			this->label1_2_1->TabIndex = 4;
			this->label1_2_1->Text = L"Статус соединения:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(117, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 31);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Сканировать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form_main::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label_error_crc16);
			this->groupBox2->Controls->Add(this->label62);
			this->groupBox2->Controls->Add(this->label_count_bad_pack);
			this->groupBox2->Controls->Add(this->label164);
			this->groupBox2->Controls->Add(this->label_stat_connect);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->groupBox6);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label_f2);
			this->groupBox2->Controls->Add(this->labelf2_text);
			this->groupBox2->Controls->Add(this->label_f1);
			this->groupBox2->Controls->Add(this->label_f1_text);
			this->groupBox2->Controls->Add(this->label5_1_1);
			this->groupBox2->Controls->Add(this->comboBox3);
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Location = System::Drawing::Point(6, 167);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(263, 396);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"МКИО";
			// 
			// label_error_crc16
			// 
			this->label_error_crc16->AutoSize = true;
			this->label_error_crc16->Location = System::Drawing::Point(167, 253);
			this->label_error_crc16->Name = L"label_error_crc16";
			this->label_error_crc16->Size = System::Drawing::Size(89, 13);
			this->label_error_crc16->TabIndex = 96;
			this->label_error_crc16->Text = L"label_error_crc16";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(6, 253);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(157, 13);
			this->label62->TabIndex = 95;
			this->label62->Text = L"Счетчик бракованных CRC16:";
			// 
			// label_count_bad_pack
			// 
			this->label_count_bad_pack->AutoSize = true;
			this->label_count_bad_pack->Location = System::Drawing::Point(167, 226);
			this->label_count_bad_pack->Name = L"label_count_bad_pack";
			this->label_count_bad_pack->Size = System::Drawing::Size(116, 13);
			this->label_count_bad_pack->TabIndex = 94;
			this->label_count_bad_pack->Text = L"label_count_bad_pack";
			// 
			// label164
			// 
			this->label164->AutoSize = true;
			this->label164->Location = System::Drawing::Point(6, 226);
			this->label164->Name = L"label164";
			this->label164->Size = System::Drawing::Size(164, 13);
			this->label164->TabIndex = 93;
			this->label164->Text = L"Счетчик бракованных пакетов:";
			// 
			// label_stat_connect
			// 
			this->label_stat_connect->AutoSize = true;
			this->label_stat_connect->Location = System::Drawing::Point(167, 145);
			this->label_stat_connect->Name = L"label_stat_connect";
			this->label_stat_connect->Size = System::Drawing::Size(97, 13);
			this->label_stat_connect->TabIndex = 92;
			this->label_stat_connect->Text = L"label_stat_connect";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 145);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(107, 13);
			this->label5->TabIndex = 91;
			this->label5->Text = L"Статус соединения:";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->label_result_test);
			this->groupBox6->Controls->Add(this->button4);
			this->groupBox6->Controls->Add(this->label4);
			this->groupBox6->Location = System::Drawing::Point(6, 284);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(251, 100);
			this->groupBox6->TabIndex = 90;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Режим тестирования ОУ";
			// 
			// label_result_test
			// 
			this->label_result_test->AutoSize = true;
			this->label_result_test->Location = System::Drawing::Point(147, 69);
			this->label_result_test->Name = L"label_result_test";
			this->label_result_test->Size = System::Drawing::Size(83, 13);
			this->label_result_test->TabIndex = 3;
			this->label_result_test->Text = L"label_result_test";
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(16, 26);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(95, 30);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Тест";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form_main::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 69);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Результат тестированя:";
			// 
			// comboBox2
			// 
			this->comboBox2->Enabled = false;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"А", L"Б" });
			this->comboBox2->Location = System::Drawing::Point(203, 38);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(36, 21);
			this->comboBox2->TabIndex = 60;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(125, 41);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(72, 13);
			this->label6->TabIndex = 59;
			this->label6->Text = L"Шина МКИО:";
			// 
			// label_f2
			// 
			this->label_f2->AutoSize = true;
			this->label_f2->Location = System::Drawing::Point(167, 199);
			this->label_f2->Name = L"label_f2";
			this->label_f2->Size = System::Drawing::Size(44, 13);
			this->label_f2->TabIndex = 58;
			this->label_f2->Text = L"label_f2";
			// 
			// labelf2_text
			// 
			this->labelf2_text->AutoSize = true;
			this->labelf2_text->Location = System::Drawing::Point(6, 199);
			this->labelf2_text->Name = L"labelf2_text";
			this->labelf2_text->Size = System::Drawing::Size(148, 13);
			this->labelf2_text->TabIndex = 57;
			this->labelf2_text->Text = L"Счетчик пакетов Формат 2:";
			// 
			// label_f1
			// 
			this->label_f1->AutoSize = true;
			this->label_f1->Location = System::Drawing::Point(167, 172);
			this->label_f1->Name = L"label_f1";
			this->label_f1->Size = System::Drawing::Size(44, 13);
			this->label_f1->TabIndex = 56;
			this->label_f1->Text = L"label_f1";
			// 
			// label_f1_text
			// 
			this->label_f1_text->AutoSize = true;
			this->label_f1_text->Location = System::Drawing::Point(6, 172);
			this->label_f1_text->Name = L"label_f1_text";
			this->label_f1_text->Size = System::Drawing::Size(148, 13);
			this->label_f1_text->TabIndex = 55;
			this->label_f1_text->Text = L"Счетчик пакетов Формат 1:";
			// 
			// label5_1_1
			// 
			this->label5_1_1->AutoSize = true;
			this->label5_1_1->Location = System::Drawing::Point(125, 92);
			this->label5_1_1->Name = L"label5_1_1";
			this->label5_1_1->Size = System::Drawing::Size(41, 13);
			this->label5_1_1->TabIndex = 46;
			this->label5_1_1->Text = L"Адрес:";
			// 
			// comboBox3
			// 
			this->comboBox3->Enabled = false;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26",
					L"27", L"28", L"29", L"30"
			});
			this->comboBox3->Location = System::Drawing::Point(203, 89);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(36, 21);
			this->comboBox3->TabIndex = 45;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Control;
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(6, 32);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 30);
			this->button3->TabIndex = 89;
			this->button3->Text = L"Пуск";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Form_main::button3_Click);
			// 
			// panel45
			// 
			this->panel45->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel45->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel45->Controls->Add(this->label41);
			this->panel45->Controls->Add(this->panel46);
			this->panel45->Controls->Add(this->label42);
			this->panel45->Controls->Add(this->label43);
			this->panel45->Controls->Add(this->label44);
			this->panel45->Controls->Add(this->label45);
			this->panel45->Controls->Add(this->label46);
			this->panel45->Controls->Add(this->label47);
			this->panel45->Controls->Add(this->label48);
			this->panel45->Controls->Add(this->label49);
			this->panel45->Controls->Add(this->label50);
			this->panel45->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel45->Enabled = false;
			this->panel45->Location = System::Drawing::Point(579, 114);
			this->panel45->Name = L"panel45";
			this->panel45->Size = System::Drawing::Size(304, 85);
			this->panel45->TabIndex = 78;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(128, 3);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(58, 13);
			this->label41->TabIndex = 28;
			this->label41->Text = L"Плата №5";
			// 
			// panel46
			// 
			this->panel46->BackColor = System::Drawing::Color::White;
			this->panel46->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel46->Controls->Add(this->panel47);
			this->panel46->Controls->Add(this->panel48);
			this->panel46->Controls->Add(this->panel49);
			this->panel46->Controls->Add(this->panel50);
			this->panel46->Controls->Add(this->panel51);
			this->panel46->Controls->Add(this->panel52);
			this->panel46->Controls->Add(this->panel53);
			this->panel46->Controls->Add(this->panel55);
			this->panel46->Location = System::Drawing::Point(79, 43);
			this->panel46->Name = L"panel46";
			this->panel46->Size = System::Drawing::Size(216, 33);
			this->panel46->TabIndex = 0;
			// 
			// panel47
			// 
			this->panel47->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel47->Controls->Add(this->button10_2);
			this->panel47->Location = System::Drawing::Point(32, 6);
			this->panel47->Name = L"panel47";
			this->panel47->Size = System::Drawing::Size(20, 20);
			this->panel47->TabIndex = 57;
			// 
			// button10_2
			// 
			this->button10_2->BackColor = System::Drawing::SystemColors::Control;
			this->button10_2->Enabled = false;
			this->button10_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_2->Location = System::Drawing::Point(2, 2);
			this->button10_2->Margin = System::Windows::Forms::Padding(1);
			this->button10_2->Name = L"button10_2";
			this->button10_2->Size = System::Drawing::Size(14, 14);
			this->button10_2->TabIndex = 55;
			this->button10_2->UseVisualStyleBackColor = false;
			this->button10_2->Click += gcnew System::EventHandler(this, &Form_main::button10_2_Click);
			// 
			// panel48
			// 
			this->panel48->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel48->Controls->Add(this->button10_8);
			this->panel48->Location = System::Drawing::Point(188, 6);
			this->panel48->Name = L"panel48";
			this->panel48->Size = System::Drawing::Size(20, 20);
			this->panel48->TabIndex = 63;
			// 
			// button10_8
			// 
			this->button10_8->BackColor = System::Drawing::SystemColors::Control;
			this->button10_8->Enabled = false;
			this->button10_8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_8->Location = System::Drawing::Point(2, 2);
			this->button10_8->Margin = System::Windows::Forms::Padding(1);
			this->button10_8->Name = L"button10_8";
			this->button10_8->Size = System::Drawing::Size(14, 14);
			this->button10_8->TabIndex = 55;
			this->button10_8->UseVisualStyleBackColor = false;
			this->button10_8->Click += gcnew System::EventHandler(this, &Form_main::button10_8_Click);
			// 
			// panel49
			// 
			this->panel49->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel49->Controls->Add(this->button10_5);
			this->panel49->Location = System::Drawing::Point(110, 6);
			this->panel49->Name = L"panel49";
			this->panel49->Size = System::Drawing::Size(20, 20);
			this->panel49->TabIndex = 60;
			// 
			// button10_5
			// 
			this->button10_5->BackColor = System::Drawing::SystemColors::Control;
			this->button10_5->Enabled = false;
			this->button10_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_5->Location = System::Drawing::Point(2, 2);
			this->button10_5->Margin = System::Windows::Forms::Padding(1);
			this->button10_5->Name = L"button10_5";
			this->button10_5->Size = System::Drawing::Size(14, 14);
			this->button10_5->TabIndex = 55;
			this->button10_5->UseVisualStyleBackColor = false;
			this->button10_5->Click += gcnew System::EventHandler(this, &Form_main::button10_5_Click);
			// 
			// panel50
			// 
			this->panel50->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel50->Controls->Add(this->button10_1);
			this->panel50->Location = System::Drawing::Point(6, 6);
			this->panel50->Name = L"panel50";
			this->panel50->Size = System::Drawing::Size(20, 20);
			this->panel50->TabIndex = 56;
			// 
			// button10_1
			// 
			this->button10_1->BackColor = System::Drawing::SystemColors::Control;
			this->button10_1->Enabled = false;
			this->button10_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_1->Location = System::Drawing::Point(2, 2);
			this->button10_1->Margin = System::Windows::Forms::Padding(1);
			this->button10_1->Name = L"button10_1";
			this->button10_1->Size = System::Drawing::Size(14, 14);
			this->button10_1->TabIndex = 55;
			this->button10_1->UseVisualStyleBackColor = false;
			this->button10_1->Click += gcnew System::EventHandler(this, &Form_main::button10_1_Click);
			// 
			// panel51
			// 
			this->panel51->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel51->Controls->Add(this->button10_4);
			this->panel51->Location = System::Drawing::Point(84, 6);
			this->panel51->Name = L"panel51";
			this->panel51->Size = System::Drawing::Size(20, 20);
			this->panel51->TabIndex = 59;
			// 
			// button10_4
			// 
			this->button10_4->BackColor = System::Drawing::SystemColors::Control;
			this->button10_4->Enabled = false;
			this->button10_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_4->Location = System::Drawing::Point(2, 2);
			this->button10_4->Margin = System::Windows::Forms::Padding(1);
			this->button10_4->Name = L"button10_4";
			this->button10_4->Size = System::Drawing::Size(14, 14);
			this->button10_4->TabIndex = 55;
			this->button10_4->UseVisualStyleBackColor = false;
			this->button10_4->Click += gcnew System::EventHandler(this, &Form_main::button10_4_Click);
			// 
			// panel52
			// 
			this->panel52->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel52->Controls->Add(this->button10_7);
			this->panel52->Location = System::Drawing::Point(162, 6);
			this->panel52->Name = L"panel52";
			this->panel52->Size = System::Drawing::Size(20, 20);
			this->panel52->TabIndex = 62;
			// 
			// button10_7
			// 
			this->button10_7->BackColor = System::Drawing::SystemColors::Control;
			this->button10_7->Enabled = false;
			this->button10_7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_7->Location = System::Drawing::Point(2, 2);
			this->button10_7->Margin = System::Windows::Forms::Padding(1);
			this->button10_7->Name = L"button10_7";
			this->button10_7->Size = System::Drawing::Size(14, 14);
			this->button10_7->TabIndex = 55;
			this->button10_7->UseVisualStyleBackColor = false;
			this->button10_7->Click += gcnew System::EventHandler(this, &Form_main::button10_7_Click);
			// 
			// panel53
			// 
			this->panel53->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel53->Controls->Add(this->panel54);
			this->panel53->Controls->Add(this->button45);
			this->panel53->Location = System::Drawing::Point(136, 6);
			this->panel53->Name = L"panel53";
			this->panel53->Size = System::Drawing::Size(20, 20);
			this->panel53->TabIndex = 61;
			// 
			// panel54
			// 
			this->panel54->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel54->Controls->Add(this->button10_6);
			this->panel54->Location = System::Drawing::Point(-1, -1);
			this->panel54->Name = L"panel54";
			this->panel54->Size = System::Drawing::Size(20, 20);
			this->panel54->TabIndex = 57;
			// 
			// button10_6
			// 
			this->button10_6->BackColor = System::Drawing::SystemColors::Control;
			this->button10_6->Enabled = false;
			this->button10_6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_6->Location = System::Drawing::Point(2, 2);
			this->button10_6->Margin = System::Windows::Forms::Padding(1);
			this->button10_6->Name = L"button10_6";
			this->button10_6->Size = System::Drawing::Size(14, 14);
			this->button10_6->TabIndex = 55;
			this->button10_6->UseVisualStyleBackColor = false;
			this->button10_6->Click += gcnew System::EventHandler(this, &Form_main::button10_6_Click);
			// 
			// button45
			// 
			this->button45->BackColor = System::Drawing::SystemColors::Control;
			this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button45->Location = System::Drawing::Point(2, 2);
			this->button45->Margin = System::Windows::Forms::Padding(1);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(14, 14);
			this->button45->TabIndex = 55;
			this->button45->UseVisualStyleBackColor = false;
			// 
			// panel55
			// 
			this->panel55->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel55->Controls->Add(this->button10_3);
			this->panel55->Location = System::Drawing::Point(58, 6);
			this->panel55->Name = L"panel55";
			this->panel55->Size = System::Drawing::Size(20, 20);
			this->panel55->TabIndex = 58;
			// 
			// button10_3
			// 
			this->button10_3->BackColor = System::Drawing::SystemColors::Control;
			this->button10_3->Enabled = false;
			this->button10_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button10_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10_3->Location = System::Drawing::Point(2, 2);
			this->button10_3->Margin = System::Windows::Forms::Padding(1);
			this->button10_3->Name = L"button10_3";
			this->button10_3->Size = System::Drawing::Size(14, 14);
			this->button10_3->TabIndex = 55;
			this->button10_3->UseVisualStyleBackColor = false;
			this->button10_3->Click += gcnew System::EventHandler(this, &Form_main::button10_3_Click);
			// 
			// label42
			// 
			this->label42->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label42->Location = System::Drawing::Point(85, 20);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(20, 20);
			this->label42->TabIndex = 10;
			this->label42->Text = L"К1";
			this->label42->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label43
			// 
			this->label43->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label43->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label43->Location = System::Drawing::Point(111, 20);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(20, 20);
			this->label43->TabIndex = 12;
			this->label43->Text = L"К2";
			this->label43->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(2, 53);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(66, 13);
			this->label44->TabIndex = 25;
			this->label44->Text = L"ВКЛ/ВЫКЛ";
			// 
			// label45
			// 
			this->label45->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label45->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label45->Location = System::Drawing::Point(137, 20);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(20, 20);
			this->label45->TabIndex = 14;
			this->label45->Text = L"К3";
			this->label45->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label46
			// 
			this->label46->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label46->Location = System::Drawing::Point(267, 20);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(20, 20);
			this->label46->TabIndex = 24;
			this->label46->Text = L"К8";
			this->label46->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label47
			// 
			this->label47->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label47->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label47->Location = System::Drawing::Point(163, 20);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(20, 20);
			this->label47->TabIndex = 16;
			this->label47->Text = L"К4";
			this->label47->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label48
			// 
			this->label48->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label48->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label48->Location = System::Drawing::Point(241, 20);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(20, 20);
			this->label48->TabIndex = 22;
			this->label48->Text = L"К7";
			this->label48->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label49
			// 
			this->label49->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label49->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label49->Location = System::Drawing::Point(189, 20);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(20, 20);
			this->label49->TabIndex = 18;
			this->label49->Text = L"К5";
			this->label49->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label50
			// 
			this->label50->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label50->Location = System::Drawing::Point(215, 20);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(20, 20);
			this->label50->TabIndex = 20;
			this->label50->Text = L"К6";
			this->label50->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel56
			// 
			this->panel56->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel56->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel56->Controls->Add(this->label51);
			this->panel56->Controls->Add(this->panel57);
			this->panel56->Controls->Add(this->label52);
			this->panel56->Controls->Add(this->label53);
			this->panel56->Controls->Add(this->label54);
			this->panel56->Controls->Add(this->label55);
			this->panel56->Controls->Add(this->label56);
			this->panel56->Controls->Add(this->label57);
			this->panel56->Controls->Add(this->label58);
			this->panel56->Controls->Add(this->label59);
			this->panel56->Controls->Add(this->label60);
			this->panel56->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel56->Enabled = false;
			this->panel56->Location = System::Drawing::Point(579, 23);
			this->panel56->Name = L"panel56";
			this->panel56->Size = System::Drawing::Size(304, 85);
			this->panel56->TabIndex = 77;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(128, 3);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(58, 13);
			this->label51->TabIndex = 28;
			this->label51->Text = L"Плата №4";
			// 
			// panel57
			// 
			this->panel57->BackColor = System::Drawing::Color::White;
			this->panel57->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel57->Controls->Add(this->panel58);
			this->panel57->Controls->Add(this->panel59);
			this->panel57->Controls->Add(this->panel60);
			this->panel57->Controls->Add(this->panel61);
			this->panel57->Controls->Add(this->panel62);
			this->panel57->Controls->Add(this->panel63);
			this->panel57->Controls->Add(this->panel64);
			this->panel57->Controls->Add(this->panel66);
			this->panel57->Location = System::Drawing::Point(79, 43);
			this->panel57->Name = L"panel57";
			this->panel57->Size = System::Drawing::Size(216, 33);
			this->panel57->TabIndex = 0;
			// 
			// panel58
			// 
			this->panel58->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel58->Controls->Add(this->button9_2);
			this->panel58->Location = System::Drawing::Point(32, 6);
			this->panel58->Name = L"panel58";
			this->panel58->Size = System::Drawing::Size(20, 20);
			this->panel58->TabIndex = 57;
			// 
			// button9_2
			// 
			this->button9_2->BackColor = System::Drawing::SystemColors::Control;
			this->button9_2->Enabled = false;
			this->button9_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_2->Location = System::Drawing::Point(2, 2);
			this->button9_2->Margin = System::Windows::Forms::Padding(1);
			this->button9_2->Name = L"button9_2";
			this->button9_2->Size = System::Drawing::Size(14, 14);
			this->button9_2->TabIndex = 55;
			this->button9_2->UseVisualStyleBackColor = false;
			this->button9_2->Click += gcnew System::EventHandler(this, &Form_main::button9_2_Click);
			// 
			// panel59
			// 
			this->panel59->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel59->Controls->Add(this->button9_8);
			this->panel59->Location = System::Drawing::Point(188, 6);
			this->panel59->Name = L"panel59";
			this->panel59->Size = System::Drawing::Size(20, 20);
			this->panel59->TabIndex = 63;
			// 
			// button9_8
			// 
			this->button9_8->BackColor = System::Drawing::SystemColors::Control;
			this->button9_8->Enabled = false;
			this->button9_8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_8->Location = System::Drawing::Point(2, 2);
			this->button9_8->Margin = System::Windows::Forms::Padding(1);
			this->button9_8->Name = L"button9_8";
			this->button9_8->Size = System::Drawing::Size(14, 14);
			this->button9_8->TabIndex = 55;
			this->button9_8->UseVisualStyleBackColor = false;
			this->button9_8->Click += gcnew System::EventHandler(this, &Form_main::button9_8_Click);
			// 
			// panel60
			// 
			this->panel60->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel60->Controls->Add(this->button9_5);
			this->panel60->Location = System::Drawing::Point(110, 6);
			this->panel60->Name = L"panel60";
			this->panel60->Size = System::Drawing::Size(20, 20);
			this->panel60->TabIndex = 60;
			// 
			// button9_5
			// 
			this->button9_5->BackColor = System::Drawing::SystemColors::Control;
			this->button9_5->Enabled = false;
			this->button9_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_5->Location = System::Drawing::Point(2, 2);
			this->button9_5->Margin = System::Windows::Forms::Padding(1);
			this->button9_5->Name = L"button9_5";
			this->button9_5->Size = System::Drawing::Size(14, 14);
			this->button9_5->TabIndex = 55;
			this->button9_5->UseVisualStyleBackColor = false;
			this->button9_5->Click += gcnew System::EventHandler(this, &Form_main::button9_5_Click);
			// 
			// panel61
			// 
			this->panel61->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel61->Controls->Add(this->button9_1);
			this->panel61->Location = System::Drawing::Point(6, 6);
			this->panel61->Name = L"panel61";
			this->panel61->Size = System::Drawing::Size(20, 20);
			this->panel61->TabIndex = 56;
			// 
			// button9_1
			// 
			this->button9_1->BackColor = System::Drawing::SystemColors::Control;
			this->button9_1->Enabled = false;
			this->button9_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_1->Location = System::Drawing::Point(2, 2);
			this->button9_1->Margin = System::Windows::Forms::Padding(1);
			this->button9_1->Name = L"button9_1";
			this->button9_1->Size = System::Drawing::Size(14, 14);
			this->button9_1->TabIndex = 55;
			this->button9_1->UseVisualStyleBackColor = false;
			this->button9_1->Click += gcnew System::EventHandler(this, &Form_main::button9_1_Click);
			// 
			// panel62
			// 
			this->panel62->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel62->Controls->Add(this->button9_4);
			this->panel62->Location = System::Drawing::Point(84, 6);
			this->panel62->Name = L"panel62";
			this->panel62->Size = System::Drawing::Size(20, 20);
			this->panel62->TabIndex = 59;
			// 
			// button9_4
			// 
			this->button9_4->BackColor = System::Drawing::SystemColors::Control;
			this->button9_4->Enabled = false;
			this->button9_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_4->Location = System::Drawing::Point(2, 2);
			this->button9_4->Margin = System::Windows::Forms::Padding(1);
			this->button9_4->Name = L"button9_4";
			this->button9_4->Size = System::Drawing::Size(14, 14);
			this->button9_4->TabIndex = 55;
			this->button9_4->UseVisualStyleBackColor = false;
			this->button9_4->Click += gcnew System::EventHandler(this, &Form_main::button9_4_Click);
			// 
			// panel63
			// 
			this->panel63->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel63->Controls->Add(this->button9_7);
			this->panel63->Location = System::Drawing::Point(162, 6);
			this->panel63->Name = L"panel63";
			this->panel63->Size = System::Drawing::Size(20, 20);
			this->panel63->TabIndex = 62;
			// 
			// button9_7
			// 
			this->button9_7->BackColor = System::Drawing::SystemColors::Control;
			this->button9_7->Enabled = false;
			this->button9_7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_7->Location = System::Drawing::Point(2, 2);
			this->button9_7->Margin = System::Windows::Forms::Padding(1);
			this->button9_7->Name = L"button9_7";
			this->button9_7->Size = System::Drawing::Size(14, 14);
			this->button9_7->TabIndex = 55;
			this->button9_7->UseVisualStyleBackColor = false;
			this->button9_7->Click += gcnew System::EventHandler(this, &Form_main::button9_7_Click);
			// 
			// panel64
			// 
			this->panel64->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel64->Controls->Add(this->panel65);
			this->panel64->Controls->Add(this->button54);
			this->panel64->Location = System::Drawing::Point(136, 6);
			this->panel64->Name = L"panel64";
			this->panel64->Size = System::Drawing::Size(20, 20);
			this->panel64->TabIndex = 61;
			// 
			// panel65
			// 
			this->panel65->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel65->Controls->Add(this->button9_6);
			this->panel65->Location = System::Drawing::Point(-1, -1);
			this->panel65->Name = L"panel65";
			this->panel65->Size = System::Drawing::Size(20, 20);
			this->panel65->TabIndex = 57;
			// 
			// button9_6
			// 
			this->button9_6->BackColor = System::Drawing::SystemColors::Control;
			this->button9_6->Enabled = false;
			this->button9_6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_6->Location = System::Drawing::Point(2, 2);
			this->button9_6->Margin = System::Windows::Forms::Padding(1);
			this->button9_6->Name = L"button9_6";
			this->button9_6->Size = System::Drawing::Size(14, 14);
			this->button9_6->TabIndex = 55;
			this->button9_6->UseVisualStyleBackColor = false;
			this->button9_6->Click += gcnew System::EventHandler(this, &Form_main::button9_6_Click);
			// 
			// button54
			// 
			this->button54->BackColor = System::Drawing::SystemColors::Control;
			this->button54->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button54->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button54->Location = System::Drawing::Point(2, 2);
			this->button54->Margin = System::Windows::Forms::Padding(1);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(14, 14);
			this->button54->TabIndex = 55;
			this->button54->UseVisualStyleBackColor = false;
			// 
			// panel66
			// 
			this->panel66->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel66->Controls->Add(this->button9_3);
			this->panel66->Location = System::Drawing::Point(58, 6);
			this->panel66->Name = L"panel66";
			this->panel66->Size = System::Drawing::Size(20, 20);
			this->panel66->TabIndex = 58;
			// 
			// button9_3
			// 
			this->button9_3->BackColor = System::Drawing::SystemColors::Control;
			this->button9_3->Enabled = false;
			this->button9_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button9_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9_3->Location = System::Drawing::Point(2, 2);
			this->button9_3->Margin = System::Windows::Forms::Padding(1);
			this->button9_3->Name = L"button9_3";
			this->button9_3->Size = System::Drawing::Size(14, 14);
			this->button9_3->TabIndex = 55;
			this->button9_3->UseVisualStyleBackColor = false;
			this->button9_3->Click += gcnew System::EventHandler(this, &Form_main::button9_3_Click);
			// 
			// label52
			// 
			this->label52->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label52->Location = System::Drawing::Point(85, 20);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(20, 20);
			this->label52->TabIndex = 10;
			this->label52->Text = L"К1";
			this->label52->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label53
			// 
			this->label53->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label53->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label53->Location = System::Drawing::Point(111, 20);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(20, 20);
			this->label53->TabIndex = 12;
			this->label53->Text = L"К2";
			this->label53->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(2, 53);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(66, 13);
			this->label54->TabIndex = 25;
			this->label54->Text = L"ВКЛ/ВЫКЛ";
			// 
			// label55
			// 
			this->label55->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label55->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label55->Location = System::Drawing::Point(137, 20);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(20, 20);
			this->label55->TabIndex = 14;
			this->label55->Text = L"К3";
			this->label55->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label56
			// 
			this->label56->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label56->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label56->Location = System::Drawing::Point(267, 20);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(20, 20);
			this->label56->TabIndex = 24;
			this->label56->Text = L"К8";
			this->label56->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label57
			// 
			this->label57->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label57->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label57->Location = System::Drawing::Point(163, 20);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(20, 20);
			this->label57->TabIndex = 16;
			this->label57->Text = L"К4";
			this->label57->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label58
			// 
			this->label58->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label58->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label58->Location = System::Drawing::Point(241, 20);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(20, 20);
			this->label58->TabIndex = 22;
			this->label58->Text = L"К7";
			this->label58->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label59
			// 
			this->label59->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label59->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label59->Location = System::Drawing::Point(189, 20);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(20, 20);
			this->label59->TabIndex = 18;
			this->label59->Text = L"К5";
			this->label59->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label60
			// 
			this->label60->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label60->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label60->Location = System::Drawing::Point(215, 20);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(20, 20);
			this->label60->TabIndex = 20;
			this->label60->Text = L"К6";
			this->label60->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel10->Controls->Add(this->label7);
			this->panel10->Controls->Add(this->panel13);
			this->panel10->Controls->Add(this->label8);
			this->panel10->Controls->Add(this->label9);
			this->panel10->Controls->Add(this->label10);
			this->panel10->Controls->Add(this->label11);
			this->panel10->Controls->Add(this->label12);
			this->panel10->Controls->Add(this->label14);
			this->panel10->Controls->Add(this->label16);
			this->panel10->Controls->Add(this->label18);
			this->panel10->Controls->Add(this->label19);
			this->panel10->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel10->Enabled = false;
			this->panel10->Location = System::Drawing::Point(269, 114);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(304, 85);
			this->panel10->TabIndex = 75;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(128, 3);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(58, 13);
			this->label7->TabIndex = 28;
			this->label7->Text = L"Плата №2";
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::White;
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel13->Controls->Add(this->panel14);
			this->panel13->Controls->Add(this->panel15);
			this->panel13->Controls->Add(this->panel16);
			this->panel13->Controls->Add(this->panel17);
			this->panel13->Controls->Add(this->panel18);
			this->panel13->Controls->Add(this->panel19);
			this->panel13->Controls->Add(this->panel20);
			this->panel13->Controls->Add(this->panel22);
			this->panel13->Location = System::Drawing::Point(79, 43);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(216, 33);
			this->panel13->TabIndex = 0;
			// 
			// panel14
			// 
			this->panel14->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel14->Controls->Add(this->button7_2);
			this->panel14->Location = System::Drawing::Point(32, 6);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(20, 20);
			this->panel14->TabIndex = 57;
			// 
			// button7_2
			// 
			this->button7_2->BackColor = System::Drawing::SystemColors::Control;
			this->button7_2->Enabled = false;
			this->button7_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_2->Location = System::Drawing::Point(2, 2);
			this->button7_2->Margin = System::Windows::Forms::Padding(1);
			this->button7_2->Name = L"button7_2";
			this->button7_2->Size = System::Drawing::Size(14, 14);
			this->button7_2->TabIndex = 55;
			this->button7_2->UseVisualStyleBackColor = false;
			this->button7_2->Click += gcnew System::EventHandler(this, &Form_main::button7_2_Click);
			// 
			// panel15
			// 
			this->panel15->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel15->Controls->Add(this->button7_8);
			this->panel15->Location = System::Drawing::Point(188, 6);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(20, 20);
			this->panel15->TabIndex = 63;
			// 
			// button7_8
			// 
			this->button7_8->BackColor = System::Drawing::SystemColors::Control;
			this->button7_8->Enabled = false;
			this->button7_8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_8->Location = System::Drawing::Point(2, 2);
			this->button7_8->Margin = System::Windows::Forms::Padding(1);
			this->button7_8->Name = L"button7_8";
			this->button7_8->Size = System::Drawing::Size(14, 14);
			this->button7_8->TabIndex = 55;
			this->button7_8->UseVisualStyleBackColor = false;
			this->button7_8->Click += gcnew System::EventHandler(this, &Form_main::button7_8_Click);
			// 
			// panel16
			// 
			this->panel16->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel16->Controls->Add(this->button7_5);
			this->panel16->Location = System::Drawing::Point(110, 6);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(20, 20);
			this->panel16->TabIndex = 60;
			// 
			// button7_5
			// 
			this->button7_5->BackColor = System::Drawing::SystemColors::Control;
			this->button7_5->Enabled = false;
			this->button7_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_5->Location = System::Drawing::Point(2, 2);
			this->button7_5->Margin = System::Windows::Forms::Padding(1);
			this->button7_5->Name = L"button7_5";
			this->button7_5->Size = System::Drawing::Size(14, 14);
			this->button7_5->TabIndex = 55;
			this->button7_5->UseVisualStyleBackColor = false;
			this->button7_5->Click += gcnew System::EventHandler(this, &Form_main::button7_5_Click);
			// 
			// panel17
			// 
			this->panel17->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel17->Controls->Add(this->button7_1);
			this->panel17->Location = System::Drawing::Point(6, 6);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(20, 20);
			this->panel17->TabIndex = 56;
			// 
			// button7_1
			// 
			this->button7_1->BackColor = System::Drawing::SystemColors::Control;
			this->button7_1->Enabled = false;
			this->button7_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_1->Location = System::Drawing::Point(2, 2);
			this->button7_1->Margin = System::Windows::Forms::Padding(1);
			this->button7_1->Name = L"button7_1";
			this->button7_1->Size = System::Drawing::Size(14, 14);
			this->button7_1->TabIndex = 55;
			this->button7_1->UseVisualStyleBackColor = false;
			this->button7_1->Click += gcnew System::EventHandler(this, &Form_main::button7_1_Click);
			// 
			// panel18
			// 
			this->panel18->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel18->Controls->Add(this->button7_4);
			this->panel18->Location = System::Drawing::Point(84, 6);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(20, 20);
			this->panel18->TabIndex = 59;
			// 
			// button7_4
			// 
			this->button7_4->BackColor = System::Drawing::SystemColors::Control;
			this->button7_4->Enabled = false;
			this->button7_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_4->Location = System::Drawing::Point(2, 2);
			this->button7_4->Margin = System::Windows::Forms::Padding(1);
			this->button7_4->Name = L"button7_4";
			this->button7_4->Size = System::Drawing::Size(14, 14);
			this->button7_4->TabIndex = 55;
			this->button7_4->UseVisualStyleBackColor = false;
			this->button7_4->Click += gcnew System::EventHandler(this, &Form_main::button7_4_Click);
			// 
			// panel19
			// 
			this->panel19->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel19->Controls->Add(this->button7_7);
			this->panel19->Location = System::Drawing::Point(162, 6);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(20, 20);
			this->panel19->TabIndex = 62;
			// 
			// button7_7
			// 
			this->button7_7->BackColor = System::Drawing::SystemColors::Control;
			this->button7_7->Enabled = false;
			this->button7_7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_7->Location = System::Drawing::Point(2, 2);
			this->button7_7->Margin = System::Windows::Forms::Padding(1);
			this->button7_7->Name = L"button7_7";
			this->button7_7->Size = System::Drawing::Size(14, 14);
			this->button7_7->TabIndex = 55;
			this->button7_7->UseVisualStyleBackColor = false;
			this->button7_7->Click += gcnew System::EventHandler(this, &Form_main::button7_7_Click);
			// 
			// panel20
			// 
			this->panel20->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel20->Controls->Add(this->panel21);
			this->panel20->Controls->Add(this->button18);
			this->panel20->Location = System::Drawing::Point(136, 6);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(20, 20);
			this->panel20->TabIndex = 61;
			// 
			// panel21
			// 
			this->panel21->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel21->Controls->Add(this->button7_6);
			this->panel21->Location = System::Drawing::Point(-1, -1);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(20, 20);
			this->panel21->TabIndex = 57;
			// 
			// button7_6
			// 
			this->button7_6->BackColor = System::Drawing::SystemColors::Control;
			this->button7_6->Enabled = false;
			this->button7_6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_6->Location = System::Drawing::Point(2, 2);
			this->button7_6->Margin = System::Windows::Forms::Padding(1);
			this->button7_6->Name = L"button7_6";
			this->button7_6->Size = System::Drawing::Size(14, 14);
			this->button7_6->TabIndex = 55;
			this->button7_6->UseVisualStyleBackColor = false;
			this->button7_6->Click += gcnew System::EventHandler(this, &Form_main::button7_6_Click);
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::SystemColors::Control;
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button18->Location = System::Drawing::Point(2, 2);
			this->button18->Margin = System::Windows::Forms::Padding(1);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(14, 14);
			this->button18->TabIndex = 55;
			this->button18->UseVisualStyleBackColor = false;
			// 
			// panel22
			// 
			this->panel22->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel22->Controls->Add(this->button7_3);
			this->panel22->Location = System::Drawing::Point(58, 6);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(20, 20);
			this->panel22->TabIndex = 58;
			// 
			// button7_3
			// 
			this->button7_3->BackColor = System::Drawing::SystemColors::Control;
			this->button7_3->Enabled = false;
			this->button7_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7_3->Location = System::Drawing::Point(2, 2);
			this->button7_3->Margin = System::Windows::Forms::Padding(1);
			this->button7_3->Name = L"button7_3";
			this->button7_3->Size = System::Drawing::Size(14, 14);
			this->button7_3->TabIndex = 55;
			this->button7_3->UseVisualStyleBackColor = false;
			this->button7_3->Click += gcnew System::EventHandler(this, &Form_main::button7_3_Click);
			// 
			// label8
			// 
			this->label8->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(85, 20);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(20, 20);
			this->label8->TabIndex = 10;
			this->label8->Text = L"К1";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(111, 20);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(20, 20);
			this->label9->TabIndex = 12;
			this->label9->Text = L"К2";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(2, 53);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(66, 13);
			this->label10->TabIndex = 25;
			this->label10->Text = L"ВКЛ/ВЫКЛ";
			// 
			// label11
			// 
			this->label11->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(137, 20);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(20, 20);
			this->label11->TabIndex = 14;
			this->label11->Text = L"К3";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(267, 20);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(20, 20);
			this->label12->TabIndex = 24;
			this->label12->Text = L"К8";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(163, 20);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(20, 20);
			this->label14->TabIndex = 16;
			this->label14->Text = L"К4";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label16
			// 
			this->label16->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(241, 20);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(20, 20);
			this->label16->TabIndex = 22;
			this->label16->Text = L"К7";
			this->label16->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label18
			// 
			this->label18->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(189, 20);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(20, 20);
			this->label18->TabIndex = 18;
			this->label18->Text = L"К5";
			this->label18->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label19
			// 
			this->label19->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(215, 20);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(20, 20);
			this->label19->TabIndex = 20;
			this->label19->Text = L"К6";
			this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel11->Controls->Add(this->label27);
			this->panel11->Controls->Add(this->panel12);
			this->panel11->Controls->Add(this->label13);
			this->panel11->Controls->Add(this->label15);
			this->panel11->Controls->Add(this->label17);
			this->panel11->Controls->Add(this->label91);
			this->panel11->Controls->Add(this->label92);
			this->panel11->Controls->Add(this->label93);
			this->panel11->Controls->Add(this->label94);
			this->panel11->Controls->Add(this->label95);
			this->panel11->Controls->Add(this->label96);
			this->panel11->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel11->Enabled = false;
			this->panel11->Location = System::Drawing::Point(269, 23);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(304, 85);
			this->panel11->TabIndex = 74;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(128, 3);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(58, 13);
			this->label27->TabIndex = 28;
			this->label27->Text = L"Плата №1";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::White;
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel12->Controls->Add(this->panel2);
			this->panel12->Controls->Add(this->panel9);
			this->panel12->Controls->Add(this->panel5);
			this->panel12->Controls->Add(this->panel1);
			this->panel12->Controls->Add(this->panel4);
			this->panel12->Controls->Add(this->panel8);
			this->panel12->Controls->Add(this->panel6);
			this->panel12->Controls->Add(this->panel3);
			this->panel12->Location = System::Drawing::Point(79, 43);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(216, 33);
			this->panel12->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button6_2);
			this->panel2->Location = System::Drawing::Point(32, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(20, 20);
			this->panel2->TabIndex = 57;
			// 
			// button6_2
			// 
			this->button6_2->BackColor = System::Drawing::SystemColors::Control;
			this->button6_2->Enabled = false;
			this->button6_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_2->Location = System::Drawing::Point(2, 2);
			this->button6_2->Margin = System::Windows::Forms::Padding(1);
			this->button6_2->Name = L"button6_2";
			this->button6_2->Size = System::Drawing::Size(14, 14);
			this->button6_2->TabIndex = 55;
			this->button6_2->UseVisualStyleBackColor = false;
			this->button6_2->Click += gcnew System::EventHandler(this, &Form_main::button6_2_Click);
			// 
			// panel9
			// 
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->Controls->Add(this->button6_8);
			this->panel9->Location = System::Drawing::Point(188, 6);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(20, 20);
			this->panel9->TabIndex = 63;
			// 
			// button6_8
			// 
			this->button6_8->BackColor = System::Drawing::SystemColors::Control;
			this->button6_8->Enabled = false;
			this->button6_8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_8->Location = System::Drawing::Point(2, 2);
			this->button6_8->Margin = System::Windows::Forms::Padding(1);
			this->button6_8->Name = L"button6_8";
			this->button6_8->Size = System::Drawing::Size(14, 14);
			this->button6_8->TabIndex = 55;
			this->button6_8->UseVisualStyleBackColor = false;
			this->button6_8->Click += gcnew System::EventHandler(this, &Form_main::button6_8_Click);
			// 
			// panel5
			// 
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->button6_5);
			this->panel5->Location = System::Drawing::Point(110, 6);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(20, 20);
			this->panel5->TabIndex = 60;
			// 
			// button6_5
			// 
			this->button6_5->BackColor = System::Drawing::SystemColors::Control;
			this->button6_5->Enabled = false;
			this->button6_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_5->Location = System::Drawing::Point(2, 2);
			this->button6_5->Margin = System::Windows::Forms::Padding(1);
			this->button6_5->Name = L"button6_5";
			this->button6_5->Size = System::Drawing::Size(14, 14);
			this->button6_5->TabIndex = 55;
			this->button6_5->UseVisualStyleBackColor = false;
			this->button6_5->Click += gcnew System::EventHandler(this, &Form_main::button6_5_Click);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button6_1);
			this->panel1->Location = System::Drawing::Point(6, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(20, 20);
			this->panel1->TabIndex = 56;
			// 
			// button6_1
			// 
			this->button6_1->BackColor = System::Drawing::SystemColors::Control;
			this->button6_1->Enabled = false;
			this->button6_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_1->Location = System::Drawing::Point(2, 2);
			this->button6_1->Margin = System::Windows::Forms::Padding(1);
			this->button6_1->Name = L"button6_1";
			this->button6_1->Size = System::Drawing::Size(14, 14);
			this->button6_1->TabIndex = 55;
			this->button6_1->UseVisualStyleBackColor = false;
			this->button6_1->Click += gcnew System::EventHandler(this, &Form_main::button6_1_Click);
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->button6_4);
			this->panel4->Location = System::Drawing::Point(84, 6);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(20, 20);
			this->panel4->TabIndex = 59;
			// 
			// button6_4
			// 
			this->button6_4->BackColor = System::Drawing::SystemColors::Control;
			this->button6_4->Enabled = false;
			this->button6_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_4->Location = System::Drawing::Point(2, 2);
			this->button6_4->Margin = System::Windows::Forms::Padding(1);
			this->button6_4->Name = L"button6_4";
			this->button6_4->Size = System::Drawing::Size(14, 14);
			this->button6_4->TabIndex = 55;
			this->button6_4->UseVisualStyleBackColor = false;
			this->button6_4->Click += gcnew System::EventHandler(this, &Form_main::button6_4_Click);
			// 
			// panel8
			// 
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->Controls->Add(this->button6_7);
			this->panel8->Location = System::Drawing::Point(162, 6);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(20, 20);
			this->panel8->TabIndex = 62;
			// 
			// button6_7
			// 
			this->button6_7->BackColor = System::Drawing::SystemColors::Control;
			this->button6_7->Enabled = false;
			this->button6_7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_7->Location = System::Drawing::Point(2, 2);
			this->button6_7->Margin = System::Windows::Forms::Padding(1);
			this->button6_7->Name = L"button6_7";
			this->button6_7->Size = System::Drawing::Size(14, 14);
			this->button6_7->TabIndex = 55;
			this->button6_7->UseVisualStyleBackColor = false;
			this->button6_7->Click += gcnew System::EventHandler(this, &Form_main::button6_7_Click);
			// 
			// panel6
			// 
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Controls->Add(this->button7);
			this->panel6->Location = System::Drawing::Point(136, 6);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(20, 20);
			this->panel6->TabIndex = 61;
			// 
			// panel7
			// 
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->button6_6);
			this->panel7->Location = System::Drawing::Point(-1, -1);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(20, 20);
			this->panel7->TabIndex = 57;
			// 
			// button6_6
			// 
			this->button6_6->BackColor = System::Drawing::SystemColors::Control;
			this->button6_6->Enabled = false;
			this->button6_6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_6->Location = System::Drawing::Point(2, 2);
			this->button6_6->Margin = System::Windows::Forms::Padding(1);
			this->button6_6->Name = L"button6_6";
			this->button6_6->Size = System::Drawing::Size(14, 14);
			this->button6_6->TabIndex = 55;
			this->button6_6->UseVisualStyleBackColor = false;
			this->button6_6->Click += gcnew System::EventHandler(this, &Form_main::button6_6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::Control;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(2, 2);
			this->button7->Margin = System::Windows::Forms::Padding(1);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(14, 14);
			this->button7->TabIndex = 55;
			this->button7->UseVisualStyleBackColor = false;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->button6_3);
			this->panel3->Location = System::Drawing::Point(58, 6);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(20, 20);
			this->panel3->TabIndex = 58;
			// 
			// button6_3
			// 
			this->button6_3->BackColor = System::Drawing::SystemColors::Control;
			this->button6_3->Enabled = false;
			this->button6_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6_3->Location = System::Drawing::Point(2, 2);
			this->button6_3->Margin = System::Windows::Forms::Padding(1);
			this->button6_3->Name = L"button6_3";
			this->button6_3->Size = System::Drawing::Size(14, 14);
			this->button6_3->TabIndex = 55;
			this->button6_3->UseVisualStyleBackColor = false;
			this->button6_3->Click += gcnew System::EventHandler(this, &Form_main::button6_3_Click);
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(85, 20);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(20, 20);
			this->label13->TabIndex = 10;
			this->label13->Text = L"К1";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label15
			// 
			this->label15->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(111, 20);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(20, 20);
			this->label15->TabIndex = 12;
			this->label15->Text = L"К2";
			this->label15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(2, 53);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(66, 13);
			this->label17->TabIndex = 25;
			this->label17->Text = L"ВКЛ/ВЫКЛ";
			// 
			// label91
			// 
			this->label91->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label91->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label91->Location = System::Drawing::Point(137, 20);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(20, 20);
			this->label91->TabIndex = 14;
			this->label91->Text = L"К3";
			this->label91->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label92
			// 
			this->label92->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label92->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label92->Location = System::Drawing::Point(267, 20);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(20, 20);
			this->label92->TabIndex = 24;
			this->label92->Text = L"К8";
			this->label92->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label93
			// 
			this->label93->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label93->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label93->Location = System::Drawing::Point(163, 20);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(20, 20);
			this->label93->TabIndex = 16;
			this->label93->Text = L"К4";
			this->label93->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label94
			// 
			this->label94->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label94->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label94->Location = System::Drawing::Point(241, 20);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(20, 20);
			this->label94->TabIndex = 22;
			this->label94->Text = L"К7";
			this->label94->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label95
			// 
			this->label95->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label95->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label95->Location = System::Drawing::Point(189, 20);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(20, 20);
			this->label95->TabIndex = 18;
			this->label95->Text = L"К5";
			this->label95->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label96
			// 
			this->label96->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label96->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label96->Location = System::Drawing::Point(215, 20);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(20, 20);
			this->label96->TabIndex = 20;
			this->label96->Text = L"К6";
			this->label96->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->panel71);
			this->groupBox3->Controls->Add(this->panel67);
			this->groupBox3->Controls->Add(this->panel42);
			this->groupBox3->Controls->Add(this->panel39);
			this->groupBox3->Controls->Add(this->panel36);
			this->groupBox3->Controls->Add(this->panel11);
			this->groupBox3->Controls->Add(this->panel10);
			this->groupBox3->Controls->Add(this->panel23);
			this->groupBox3->Controls->Add(this->panel56);
			this->groupBox3->Controls->Add(this->panel45);
			this->groupBox3->Location = System::Drawing::Point(275, 6);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(892, 300);
			this->groupBox3->TabIndex = 83;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Управление";
			// 
			// panel71
			// 
			this->panel71->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel71->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel71->Controls->Add(this->label63);
			this->panel71->Controls->Add(this->panel72);
			this->panel71->Controls->Add(this->label64);
			this->panel71->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel71->Enabled = false;
			this->panel71->Location = System::Drawing::Point(141, 205);
			this->panel71->Name = L"panel71";
			this->panel71->Size = System::Drawing::Size(122, 85);
			this->panel71->TabIndex = 124;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(3, 53);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(66, 13);
			this->label63->TabIndex = 32;
			this->label63->Text = L"ВКЛ/ВЫКЛ";
			// 
			// panel72
			// 
			this->panel72->BackColor = System::Drawing::Color::White;
			this->panel72->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel72->Controls->Add(this->panel73);
			this->panel72->Location = System::Drawing::Point(80, 43);
			this->panel72->Name = L"panel72";
			this->panel72->Size = System::Drawing::Size(32, 32);
			this->panel72->TabIndex = 31;
			// 
			// panel73
			// 
			this->panel73->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel73->Controls->Add(this->button_all);
			this->panel73->Location = System::Drawing::Point(5, 5);
			this->panel73->Name = L"panel73";
			this->panel73->Size = System::Drawing::Size(20, 20);
			this->panel73->TabIndex = 57;
			// 
			// button_all
			// 
			this->button_all->BackColor = System::Drawing::SystemColors::Control;
			this->button_all->Enabled = false;
			this->button_all->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_all->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_all->Location = System::Drawing::Point(2, 2);
			this->button_all->Margin = System::Windows::Forms::Padding(1);
			this->button_all->Name = L"button_all";
			this->button_all->Size = System::Drawing::Size(14, 14);
			this->button_all->TabIndex = 55;
			this->button_all->UseVisualStyleBackColor = false;
			this->button_all->Click += gcnew System::EventHandler(this, &Form_main::button_all_Click);
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(25, 3);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(67, 13);
			this->label64->TabIndex = 28;
			this->label64->Text = L"Все каналы";
			this->label64->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel67
			// 
			this->panel67->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel67->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel67->Controls->Add(this->label39);
			this->panel67->Controls->Add(this->panel68);
			this->panel67->Controls->Add(this->label40);
			this->panel67->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel67->Enabled = false;
			this->panel67->Location = System::Drawing::Point(141, 114);
			this->panel67->Name = L"panel67";
			this->panel67->Size = System::Drawing::Size(122, 85);
			this->panel67->TabIndex = 123;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(3, 45);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(47, 26);
			this->label39->TabIndex = 32;
			this->label39->Text = L"Воздух/\r\nЗемля";
			// 
			// panel68
			// 
			this->panel68->BackColor = System::Drawing::Color::White;
			this->panel68->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel68->Controls->Add(this->panel69);
			this->panel68->Location = System::Drawing::Point(80, 43);
			this->panel68->Name = L"panel68";
			this->panel68->Size = System::Drawing::Size(32, 32);
			this->panel68->TabIndex = 31;
			// 
			// panel69
			// 
			this->panel69->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel69->Controls->Add(this->button_aircraft_air);
			this->panel69->Location = System::Drawing::Point(5, 5);
			this->panel69->Name = L"panel69";
			this->panel69->Size = System::Drawing::Size(20, 20);
			this->panel69->TabIndex = 57;
			// 
			// button_aircraft_air
			// 
			this->button_aircraft_air->BackColor = System::Drawing::SystemColors::Control;
			this->button_aircraft_air->Enabled = false;
			this->button_aircraft_air->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_aircraft_air->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_aircraft_air->Location = System::Drawing::Point(2, 2);
			this->button_aircraft_air->Margin = System::Windows::Forms::Padding(1);
			this->button_aircraft_air->Name = L"button_aircraft_air";
			this->button_aircraft_air->Size = System::Drawing::Size(14, 14);
			this->button_aircraft_air->TabIndex = 55;
			this->button_aircraft_air->UseVisualStyleBackColor = false;
			this->button_aircraft_air->Click += gcnew System::EventHandler(this, &Form_main::button_aircraft_air_Click);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(3, 6);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(115, 26);
			this->label40->TabIndex = 28;
			this->label40->Text = L"Признак нахождения\r\nБПЛА в воздухе";
			this->label40->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel42
			// 
			this->panel42->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel42->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel42->Controls->Add(this->label37);
			this->panel42->Controls->Add(this->panel43);
			this->panel42->Controls->Add(this->label38);
			this->panel42->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel42->Enabled = false;
			this->panel42->Location = System::Drawing::Point(13, 114);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(122, 85);
			this->panel42->TabIndex = 122;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(3, 45);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(68, 26);
			this->label37->TabIndex = 32;
			this->label37->Text = L"Запущен/\r\nОстановлен";
			// 
			// panel43
			// 
			this->panel43->BackColor = System::Drawing::Color::White;
			this->panel43->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel43->Controls->Add(this->panel44);
			this->panel43->Location = System::Drawing::Point(80, 43);
			this->panel43->Name = L"panel43";
			this->panel43->Size = System::Drawing::Size(32, 32);
			this->panel43->TabIndex = 31;
			// 
			// panel44
			// 
			this->panel44->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel44->Controls->Add(this->button_launch_aircraft);
			this->panel44->Location = System::Drawing::Point(5, 5);
			this->panel44->Name = L"panel44";
			this->panel44->Size = System::Drawing::Size(20, 20);
			this->panel44->TabIndex = 57;
			// 
			// button_launch_aircraft
			// 
			this->button_launch_aircraft->BackColor = System::Drawing::SystemColors::Control;
			this->button_launch_aircraft->Enabled = false;
			this->button_launch_aircraft->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_launch_aircraft->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_launch_aircraft->Location = System::Drawing::Point(2, 2);
			this->button_launch_aircraft->Margin = System::Windows::Forms::Padding(1);
			this->button_launch_aircraft->Name = L"button_launch_aircraft";
			this->button_launch_aircraft->Size = System::Drawing::Size(14, 14);
			this->button_launch_aircraft->TabIndex = 55;
			this->button_launch_aircraft->UseVisualStyleBackColor = false;
			this->button_launch_aircraft->Click += gcnew System::EventHandler(this, &Form_main::button_launch_aircraft_Click);
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(10, 6);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(95, 26);
			this->label38->TabIndex = 28;
			this->label38->Text = L"Признак запуска\r\nдвигателя БПЛА";
			this->label38->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel39
			// 
			this->panel39->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel39->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel39->Controls->Add(this->label35);
			this->panel39->Controls->Add(this->panel40);
			this->panel39->Controls->Add(this->label36);
			this->panel39->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel39->Enabled = false;
			this->panel39->Location = System::Drawing::Point(141, 23);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(122, 85);
			this->panel39->TabIndex = 121;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(3, 53);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(66, 13);
			this->label35->TabIndex = 32;
			this->label35->Text = L"ВКЛ/ВЫКЛ";
			// 
			// panel40
			// 
			this->panel40->BackColor = System::Drawing::Color::White;
			this->panel40->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel40->Controls->Add(this->panel41);
			this->panel40->Location = System::Drawing::Point(80, 43);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(32, 32);
			this->panel40->TabIndex = 31;
			// 
			// panel41
			// 
			this->panel41->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel41->Controls->Add(this->button_pow_bat);
			this->panel41->Location = System::Drawing::Point(5, 5);
			this->panel41->Name = L"panel41";
			this->panel41->Size = System::Drawing::Size(20, 20);
			this->panel41->TabIndex = 57;
			// 
			// button_pow_bat
			// 
			this->button_pow_bat->BackColor = System::Drawing::SystemColors::Control;
			this->button_pow_bat->Enabled = false;
			this->button_pow_bat->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_pow_bat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_pow_bat->Location = System::Drawing::Point(2, 2);
			this->button_pow_bat->Margin = System::Windows::Forms::Padding(1);
			this->button_pow_bat->Name = L"button_pow_bat";
			this->button_pow_bat->Size = System::Drawing::Size(14, 14);
			this->button_pow_bat->TabIndex = 55;
			this->button_pow_bat->UseVisualStyleBackColor = false;
			this->button_pow_bat->Click += gcnew System::EventHandler(this, &Form_main::button_pow_bat_Click);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(15, 6);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(89, 26);
			this->label36->TabIndex = 28;
			this->label36->Text = L"Питание канала\r\nАКБ";
			this->label36->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel36
			// 
			this->panel36->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel36->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel36->Controls->Add(this->label31);
			this->panel36->Controls->Add(this->panel38);
			this->panel36->Controls->Add(this->label33);
			this->panel36->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel36->Enabled = false;
			this->panel36->Location = System::Drawing::Point(13, 23);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(122, 85);
			this->panel36->TabIndex = 120;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(3, 53);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(66, 13);
			this->label31->TabIndex = 32;
			this->label31->Text = L"ВКЛ/ВЫКЛ";
			// 
			// panel38
			// 
			this->panel38->BackColor = System::Drawing::Color::White;
			this->panel38->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel38->Controls->Add(this->panel37);
			this->panel38->Location = System::Drawing::Point(80, 43);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(32, 32);
			this->panel38->TabIndex = 31;
			// 
			// panel37
			// 
			this->panel37->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel37->Controls->Add(this->button_pow_cel_nag);
			this->panel37->Location = System::Drawing::Point(5, 5);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(20, 20);
			this->panel37->TabIndex = 57;
			// 
			// button_pow_cel_nag
			// 
			this->button_pow_cel_nag->BackColor = System::Drawing::SystemColors::Control;
			this->button_pow_cel_nag->Enabled = false;
			this->button_pow_cel_nag->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_pow_cel_nag->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->button_pow_cel_nag->Location = System::Drawing::Point(2, 2);
			this->button_pow_cel_nag->Margin = System::Windows::Forms::Padding(1);
			this->button_pow_cel_nag->Name = L"button_pow_cel_nag";
			this->button_pow_cel_nag->Size = System::Drawing::Size(14, 14);
			this->button_pow_cel_nag->TabIndex = 55;
			this->button_pow_cel_nag->UseVisualStyleBackColor = false;
			this->button_pow_cel_nag->Click += gcnew System::EventHandler(this, &Form_main::button_pow_cel_nag_Click);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(8, 6);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(98, 26);
			this->label33->TabIndex = 28;
			this->label33->Text = L"Питание канала\r\nцелевой нагрузки";
			this->label33->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel23->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel23->Controls->Add(this->label20);
			this->panel23->Controls->Add(this->panel24);
			this->panel23->Controls->Add(this->label21);
			this->panel23->Controls->Add(this->label22);
			this->panel23->Controls->Add(this->label23);
			this->panel23->Controls->Add(this->label24);
			this->panel23->Controls->Add(this->label25);
			this->panel23->Controls->Add(this->label26);
			this->panel23->Controls->Add(this->label28);
			this->panel23->Controls->Add(this->label29);
			this->panel23->Controls->Add(this->label30);
			this->panel23->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel23->Enabled = false;
			this->panel23->Location = System::Drawing::Point(269, 205);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(304, 85);
			this->panel23->TabIndex = 76;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(128, 3);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(58, 13);
			this->label20->TabIndex = 28;
			this->label20->Text = L"Плата №3";
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::White;
			this->panel24->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel24->Controls->Add(this->panel25);
			this->panel24->Controls->Add(this->panel26);
			this->panel24->Controls->Add(this->panel27);
			this->panel24->Controls->Add(this->panel28);
			this->panel24->Controls->Add(this->panel29);
			this->panel24->Controls->Add(this->panel30);
			this->panel24->Controls->Add(this->panel31);
			this->panel24->Controls->Add(this->panel33);
			this->panel24->Location = System::Drawing::Point(79, 43);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(216, 33);
			this->panel24->TabIndex = 0;
			// 
			// panel25
			// 
			this->panel25->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel25->Controls->Add(this->button8_2);
			this->panel25->Location = System::Drawing::Point(32, 6);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(20, 20);
			this->panel25->TabIndex = 57;
			// 
			// button8_2
			// 
			this->button8_2->BackColor = System::Drawing::SystemColors::Control;
			this->button8_2->Enabled = false;
			this->button8_2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_2->Location = System::Drawing::Point(2, 2);
			this->button8_2->Margin = System::Windows::Forms::Padding(1);
			this->button8_2->Name = L"button8_2";
			this->button8_2->Size = System::Drawing::Size(14, 14);
			this->button8_2->TabIndex = 55;
			this->button8_2->UseVisualStyleBackColor = false;
			this->button8_2->Click += gcnew System::EventHandler(this, &Form_main::button8_2_Click);
			// 
			// panel26
			// 
			this->panel26->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel26->Controls->Add(this->button8_8);
			this->panel26->Location = System::Drawing::Point(188, 6);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(20, 20);
			this->panel26->TabIndex = 63;
			// 
			// button8_8
			// 
			this->button8_8->BackColor = System::Drawing::SystemColors::Control;
			this->button8_8->Enabled = false;
			this->button8_8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_8->Location = System::Drawing::Point(2, 2);
			this->button8_8->Margin = System::Windows::Forms::Padding(1);
			this->button8_8->Name = L"button8_8";
			this->button8_8->Size = System::Drawing::Size(14, 14);
			this->button8_8->TabIndex = 55;
			this->button8_8->UseVisualStyleBackColor = false;
			this->button8_8->Click += gcnew System::EventHandler(this, &Form_main::button8_8_Click);
			// 
			// panel27
			// 
			this->panel27->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel27->Controls->Add(this->button8_5);
			this->panel27->Location = System::Drawing::Point(110, 6);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(20, 20);
			this->panel27->TabIndex = 60;
			// 
			// button8_5
			// 
			this->button8_5->BackColor = System::Drawing::SystemColors::Control;
			this->button8_5->Enabled = false;
			this->button8_5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_5->Location = System::Drawing::Point(2, 2);
			this->button8_5->Margin = System::Windows::Forms::Padding(1);
			this->button8_5->Name = L"button8_5";
			this->button8_5->Size = System::Drawing::Size(14, 14);
			this->button8_5->TabIndex = 55;
			this->button8_5->UseVisualStyleBackColor = false;
			this->button8_5->Click += gcnew System::EventHandler(this, &Form_main::button8_5_Click);
			// 
			// panel28
			// 
			this->panel28->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel28->Controls->Add(this->button8_1);
			this->panel28->Location = System::Drawing::Point(6, 6);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(20, 20);
			this->panel28->TabIndex = 56;
			// 
			// button8_1
			// 
			this->button8_1->BackColor = System::Drawing::SystemColors::Control;
			this->button8_1->Enabled = false;
			this->button8_1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_1->Location = System::Drawing::Point(2, 2);
			this->button8_1->Margin = System::Windows::Forms::Padding(1);
			this->button8_1->Name = L"button8_1";
			this->button8_1->Size = System::Drawing::Size(14, 14);
			this->button8_1->TabIndex = 55;
			this->button8_1->UseVisualStyleBackColor = false;
			this->button8_1->Click += gcnew System::EventHandler(this, &Form_main::button8_1_Click);
			// 
			// panel29
			// 
			this->panel29->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel29->Controls->Add(this->button8_4);
			this->panel29->Location = System::Drawing::Point(84, 6);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(20, 20);
			this->panel29->TabIndex = 59;
			// 
			// button8_4
			// 
			this->button8_4->BackColor = System::Drawing::SystemColors::Control;
			this->button8_4->Enabled = false;
			this->button8_4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_4->Location = System::Drawing::Point(2, 2);
			this->button8_4->Margin = System::Windows::Forms::Padding(1);
			this->button8_4->Name = L"button8_4";
			this->button8_4->Size = System::Drawing::Size(14, 14);
			this->button8_4->TabIndex = 55;
			this->button8_4->UseVisualStyleBackColor = false;
			this->button8_4->Click += gcnew System::EventHandler(this, &Form_main::button8_4_Click);
			// 
			// panel30
			// 
			this->panel30->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel30->Controls->Add(this->button8_7);
			this->panel30->Location = System::Drawing::Point(162, 6);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(20, 20);
			this->panel30->TabIndex = 62;
			// 
			// button8_7
			// 
			this->button8_7->BackColor = System::Drawing::SystemColors::Control;
			this->button8_7->Enabled = false;
			this->button8_7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_7->Location = System::Drawing::Point(2, 2);
			this->button8_7->Margin = System::Windows::Forms::Padding(1);
			this->button8_7->Name = L"button8_7";
			this->button8_7->Size = System::Drawing::Size(14, 14);
			this->button8_7->TabIndex = 55;
			this->button8_7->UseVisualStyleBackColor = false;
			this->button8_7->Click += gcnew System::EventHandler(this, &Form_main::button8_7_Click);
			// 
			// panel31
			// 
			this->panel31->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel31->Controls->Add(this->panel32);
			this->panel31->Controls->Add(this->button27);
			this->panel31->Location = System::Drawing::Point(136, 6);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(20, 20);
			this->panel31->TabIndex = 61;
			// 
			// panel32
			// 
			this->panel32->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel32->Controls->Add(this->button8_6);
			this->panel32->Location = System::Drawing::Point(-1, -1);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(20, 20);
			this->panel32->TabIndex = 57;
			// 
			// button8_6
			// 
			this->button8_6->BackColor = System::Drawing::SystemColors::Control;
			this->button8_6->Enabled = false;
			this->button8_6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_6->Location = System::Drawing::Point(2, 2);
			this->button8_6->Margin = System::Windows::Forms::Padding(1);
			this->button8_6->Name = L"button8_6";
			this->button8_6->Size = System::Drawing::Size(14, 14);
			this->button8_6->TabIndex = 55;
			this->button8_6->UseVisualStyleBackColor = false;
			this->button8_6->Click += gcnew System::EventHandler(this, &Form_main::button8_6_Click);
			// 
			// button27
			// 
			this->button27->BackColor = System::Drawing::SystemColors::Control;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button27->Location = System::Drawing::Point(2, 2);
			this->button27->Margin = System::Windows::Forms::Padding(1);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(14, 14);
			this->button27->TabIndex = 55;
			this->button27->UseVisualStyleBackColor = false;
			// 
			// panel33
			// 
			this->panel33->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel33->Controls->Add(this->button8_3);
			this->panel33->Location = System::Drawing::Point(58, 6);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(20, 20);
			this->panel33->TabIndex = 58;
			// 
			// button8_3
			// 
			this->button8_3->BackColor = System::Drawing::SystemColors::Control;
			this->button8_3->Enabled = false;
			this->button8_3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button8_3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8_3->Location = System::Drawing::Point(2, 2);
			this->button8_3->Margin = System::Windows::Forms::Padding(1);
			this->button8_3->Name = L"button8_3";
			this->button8_3->Size = System::Drawing::Size(14, 14);
			this->button8_3->TabIndex = 55;
			this->button8_3->UseVisualStyleBackColor = false;
			this->button8_3->Click += gcnew System::EventHandler(this, &Form_main::button8_3_Click);
			// 
			// label21
			// 
			this->label21->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(85, 20);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(20, 20);
			this->label21->TabIndex = 10;
			this->label21->Text = L"К1";
			this->label21->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label22
			// 
			this->label22->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(111, 20);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(20, 20);
			this->label22->TabIndex = 12;
			this->label22->Text = L"К2";
			this->label22->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(2, 53);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(66, 13);
			this->label23->TabIndex = 25;
			this->label23->Text = L"ВКЛ/ВЫКЛ";
			// 
			// label24
			// 
			this->label24->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->Location = System::Drawing::Point(137, 20);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(20, 20);
			this->label24->TabIndex = 14;
			this->label24->Text = L"К3";
			this->label24->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label25
			// 
			this->label25->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->Location = System::Drawing::Point(267, 20);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(20, 20);
			this->label25->TabIndex = 24;
			this->label25->Text = L"К8";
			this->label25->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label26
			// 
			this->label26->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->Location = System::Drawing::Point(163, 20);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(20, 20);
			this->label26->TabIndex = 16;
			this->label26->Text = L"К4";
			this->label26->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label28
			// 
			this->label28->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->Location = System::Drawing::Point(241, 20);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(20, 20);
			this->label28->TabIndex = 22;
			this->label28->Text = L"К7";
			this->label28->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label29
			// 
			this->label29->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label29->Location = System::Drawing::Point(189, 20);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(20, 20);
			this->label29->TabIndex = 18;
			this->label29->Text = L"К5";
			this->label29->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label30
			// 
			this->label30->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label30->Location = System::Drawing::Point(215, 20);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(20, 20);
			this->label30->TabIndex = 20;
			this->label30->Text = L"К6";
			this->label30->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->panel131);
			this->groupBox4->Controls->Add(this->panel145);
			this->groupBox4->Controls->Add(this->panel142);
			this->groupBox4->Controls->Add(this->panel139);
			this->groupBox4->Controls->Add(this->panel136);
			this->groupBox4->Controls->Add(this->panel133);
			this->groupBox4->Controls->Add(this->panel127);
			this->groupBox4->Controls->Add(this->panel115);
			this->groupBox4->Controls->Add(this->panel124);
			this->groupBox4->Controls->Add(this->panel118);
			this->groupBox4->Controls->Add(this->panel121);
			this->groupBox4->Location = System::Drawing::Point(275, 312);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(892, 545);
			this->groupBox4->TabIndex = 84;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Мониторинг";
			// 
			// panel131
			// 
			this->panel131->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel131->Controls->Add(this->label61);
			this->panel131->Controls->Add(this->panel148);
			this->panel131->Controls->Add(this->panel147);
			this->panel131->Controls->Add(this->panel132);
			this->panel131->Controls->Add(this->label180);
			this->panel131->Controls->Add(this->label500);
			this->panel131->Controls->Add(this->label178);
			this->panel131->Enabled = false;
			this->panel131->Location = System::Drawing::Point(13, 411);
			this->panel131->Name = L"panel131";
			this->panel131->Size = System::Drawing::Size(250, 124);
			this->panel131->TabIndex = 122;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(91, 8);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(71, 13);
			this->label61->TabIndex = 125;
			this->label61->Text = L"Напряжение";
			// 
			// panel148
			// 
			this->panel148->BackColor = System::Drawing::Color::White;
			this->panel148->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel148->Controls->Add(this->label_U_SH2);
			this->panel148->Location = System::Drawing::Point(174, 88);
			this->panel148->Name = L"panel148";
			this->panel148->Size = System::Drawing::Size(47, 25);
			this->panel148->TabIndex = 126;
			// 
			// label_U_SH2
			// 
			this->label_U_SH2->AutoSize = true;
			this->label_U_SH2->Location = System::Drawing::Point(4, 5);
			this->label_U_SH2->Name = L"label_U_SH2";
			this->label_U_SH2->Size = System::Drawing::Size(70, 13);
			this->label_U_SH2->TabIndex = 0;
			this->label_U_SH2->Text = L"label_U_SH2";
			// 
			// panel147
			// 
			this->panel147->BackColor = System::Drawing::Color::White;
			this->panel147->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel147->Controls->Add(this->label_U_SH1);
			this->panel147->Location = System::Drawing::Point(174, 56);
			this->panel147->Name = L"panel147";
			this->panel147->Size = System::Drawing::Size(47, 25);
			this->panel147->TabIndex = 125;
			// 
			// label_U_SH1
			// 
			this->label_U_SH1->AutoSize = true;
			this->label_U_SH1->Location = System::Drawing::Point(4, 5);
			this->label_U_SH1->Name = L"label_U_SH1";
			this->label_U_SH1->Size = System::Drawing::Size(70, 13);
			this->label_U_SH1->TabIndex = 0;
			this->label_U_SH1->Text = L"label_U_SH1";
			// 
			// panel132
			// 
			this->panel132->BackColor = System::Drawing::Color::White;
			this->panel132->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel132->Controls->Add(this->label_U_BAT);
			this->panel132->Location = System::Drawing::Point(174, 26);
			this->panel132->Name = L"panel132";
			this->panel132->Size = System::Drawing::Size(47, 25);
			this->panel132->TabIndex = 116;
			// 
			// label_U_BAT
			// 
			this->label_U_BAT->AutoSize = true;
			this->label_U_BAT->Location = System::Drawing::Point(4, 5);
			this->label_U_BAT->Name = L"label_U_BAT";
			this->label_U_BAT->Size = System::Drawing::Size(70, 13);
			this->label_U_BAT->TabIndex = 0;
			this->label_U_BAT->Text = L"label_U_BAT";
			// 
			// label180
			// 
			this->label180->AutoSize = true;
			this->label180->Location = System::Drawing::Point(20, 94);
			this->label180->Name = L"label180";
			this->label180->Size = System::Drawing::Size(110, 13);
			this->label180->TabIndex = 124;
			this->label180->Text = L"Шина правого борта";
			// 
			// label500
			// 
			this->label500->AutoSize = true;
			this->label500->Location = System::Drawing::Point(20, 32);
			this->label500->Name = L"label500";
			this->label500->Size = System::Drawing::Size(91, 13);
			this->label500->TabIndex = 122;
			this->label500->Text = L"Аварийная шина";
			// 
			// label178
			// 
			this->label178->AutoSize = true;
			this->label178->Location = System::Drawing::Point(20, 62);
			this->label178->Name = L"label178";
			this->label178->Size = System::Drawing::Size(104, 13);
			this->label178->TabIndex = 123;
			this->label178->Text = L"Шина левого борта";
			// 
			// panel145
			// 
			this->panel145->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel145->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel145->Controls->Add(this->panel70);
			this->panel145->Controls->Add(this->label70);
			this->panel145->Controls->Add(this->label191);
			this->panel145->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel145->Enabled = false;
			this->panel145->Location = System::Drawing::Point(13, 22);
			this->panel145->Name = L"panel145";
			this->panel145->Size = System::Drawing::Size(250, 124);
			this->panel145->TabIndex = 121;
			// 
			// panel70
			// 
			this->panel70->BackColor = System::Drawing::Color::White;
			this->panel70->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel70->Controls->Add(this->label_mrp5_i);
			this->panel70->Controls->Add(this->label_mrp4_i);
			this->panel70->Controls->Add(this->label_mrp2_i);
			this->panel70->Controls->Add(this->label_mrp1_i);
			this->panel70->Controls->Add(this->label_mrp3_i);
			this->panel70->Location = System::Drawing::Point(36, 52);
			this->panel70->Name = L"panel70";
			this->panel70->Size = System::Drawing::Size(180, 33);
			this->panel70->TabIndex = 26;
			// 
			// label_mrp5_i
			// 
			this->label_mrp5_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_mrp5_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_mrp5_i->Location = System::Drawing::Point(151, 5);
			this->label_mrp5_i->Name = L"label_mrp5_i";
			this->label_mrp5_i->Size = System::Drawing::Size(20, 20);
			this->label_mrp5_i->TabIndex = 17;
			this->label_mrp5_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_mrp4_i
			// 
			this->label_mrp4_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_mrp4_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_mrp4_i->Location = System::Drawing::Point(114, 5);
			this->label_mrp4_i->Name = L"label_mrp4_i";
			this->label_mrp4_i->Size = System::Drawing::Size(20, 20);
			this->label_mrp4_i->TabIndex = 15;
			this->label_mrp4_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_mrp2_i
			// 
			this->label_mrp2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_mrp2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_mrp2_i->Location = System::Drawing::Point(42, 5);
			this->label_mrp2_i->Name = L"label_mrp2_i";
			this->label_mrp2_i->Size = System::Drawing::Size(20, 20);
			this->label_mrp2_i->TabIndex = 11;
			this->label_mrp2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_mrp1_i
			// 
			this->label_mrp1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_mrp1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_mrp1_i->Location = System::Drawing::Point(6, 5);
			this->label_mrp1_i->Name = L"label_mrp1_i";
			this->label_mrp1_i->Size = System::Drawing::Size(20, 20);
			this->label_mrp1_i->TabIndex = 9;
			this->label_mrp1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_mrp3_i
			// 
			this->label_mrp3_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_mrp3_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_mrp3_i->Location = System::Drawing::Point(77, 5);
			this->label_mrp3_i->Name = L"label_mrp3_i";
			this->label_mrp3_i->Size = System::Drawing::Size(20, 20);
			this->label_mrp3_i->TabIndex = 13;
			this->label_mrp3_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label70
			// 
			this->label70->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label70->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label70->Location = System::Drawing::Point(28, 29);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(198, 20);
			this->label70->TabIndex = 27;
			this->label70->Text = L"МРП1  МРП2  МРП3  МРП4  МРП5";
			this->label70->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label191
			// 
			this->label191->AutoSize = true;
			this->label191->Location = System::Drawing::Point(61, 3);
			this->label191->Name = L"label191";
			this->label191->Size = System::Drawing::Size(134, 13);
			this->label191->TabIndex = 25;
			this->label191->Text = L"Исправность РУ-7000НС";
			// 
			// panel142
			// 
			this->panel142->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel142->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel142->Controls->Add(this->label169);
			this->panel142->Controls->Add(this->panel140);
			this->panel142->Controls->Add(this->panel143);
			this->panel142->Controls->Add(this->label175);
			this->panel142->Controls->Add(this->label179);
			this->panel142->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel142->Enabled = false;
			this->panel142->Location = System::Drawing::Point(13, 281);
			this->panel142->Name = L"panel142";
			this->panel142->Size = System::Drawing::Size(122, 124);
			this->panel142->TabIndex = 120;
			// 
			// label169
			// 
			this->label169->AutoSize = true;
			this->label169->Location = System::Drawing::Point(3, 6);
			this->label169->Name = L"label169";
			this->label169->Size = System::Drawing::Size(113, 26);
			this->label169->TabIndex = 28;
			this->label169->Text = L"Исправность канала\r\nгенератора";
			this->label169->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel140
			// 
			this->panel140->BackColor = System::Drawing::Color::White;
			this->panel140->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel140->Controls->Add(this->label_gen1_i);
			this->panel140->Location = System::Drawing::Point(80, 43);
			this->panel140->Name = L"panel140";
			this->panel140->Size = System::Drawing::Size(33, 33);
			this->panel140->TabIndex = 0;
			// 
			// label_gen1_i
			// 
			this->label_gen1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_gen1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_gen1_i->Location = System::Drawing::Point(5, 5);
			this->label_gen1_i->Name = L"label_gen1_i";
			this->label_gen1_i->Size = System::Drawing::Size(20, 20);
			this->label_gen1_i->TabIndex = 9;
			this->label_gen1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel143
			// 
			this->panel143->BackColor = System::Drawing::Color::White;
			this->panel143->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel143->Controls->Add(this->label_gen2_i);
			this->panel143->Location = System::Drawing::Point(80, 81);
			this->panel143->Name = L"panel143";
			this->panel143->Size = System::Drawing::Size(33, 33);
			this->panel143->TabIndex = 0;
			// 
			// label_gen2_i
			// 
			this->label_gen2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_gen2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_gen2_i->Location = System::Drawing::Point(5, 5);
			this->label_gen2_i->Name = L"label_gen2_i";
			this->label_gen2_i->Size = System::Drawing::Size(20, 20);
			this->label_gen2_i->TabIndex = 9;
			this->label_gen2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label175
			// 
			this->label175->AutoSize = true;
			this->label175->Location = System::Drawing::Point(1, 53);
			this->label175->Name = L"label175";
			this->label175->Size = System::Drawing::Size(76, 13);
			this->label175->TabIndex = 25;
			this->label175->Text = L"Левого борта";
			// 
			// label179
			// 
			this->label179->AutoSize = true;
			this->label179->Location = System::Drawing::Point(0, 91);
			this->label179->Name = L"label179";
			this->label179->Size = System::Drawing::Size(82, 13);
			this->label179->TabIndex = 25;
			this->label179->Text = L"Правого борта";
			// 
			// panel139
			// 
			this->panel139->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel139->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel139->Controls->Add(this->panel34);
			this->panel139->Controls->Add(this->label32);
			this->panel139->Controls->Add(this->panel35);
			this->panel139->Controls->Add(this->label34);
			this->panel139->Controls->Add(this->label167);
			this->panel139->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel139->Enabled = false;
			this->panel139->Location = System::Drawing::Point(13, 151);
			this->panel139->Name = L"panel139";
			this->panel139->Size = System::Drawing::Size(122, 124);
			this->panel139->TabIndex = 119;
			// 
			// panel34
			// 
			this->panel34->BackColor = System::Drawing::Color::White;
			this->panel34->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel34->Controls->Add(this->label_cel_nag_i);
			this->panel34->Location = System::Drawing::Point(80, 42);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(33, 33);
			this->panel34->TabIndex = 29;
			// 
			// label_cel_nag_i
			// 
			this->label_cel_nag_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_cel_nag_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_cel_nag_i->Location = System::Drawing::Point(5, 5);
			this->label_cel_nag_i->Name = L"label_cel_nag_i";
			this->label_cel_nag_i->Size = System::Drawing::Size(20, 20);
			this->label_cel_nag_i->TabIndex = 9;
			this->label_cel_nag_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(2, 91);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(61, 13);
			this->label32->TabIndex = 32;
			this->label32->Text = L"Состояние";
			// 
			// panel35
			// 
			this->panel35->BackColor = System::Drawing::Color::White;
			this->panel35->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel35->Controls->Add(this->label_cel_nag_s);
			this->panel35->Location = System::Drawing::Point(79, 81);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(33, 33);
			this->panel35->TabIndex = 31;
			// 
			// label_cel_nag_s
			// 
			this->label_cel_nag_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_cel_nag_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_cel_nag_s->Location = System::Drawing::Point(5, 5);
			this->label_cel_nag_s->Name = L"label_cel_nag_s";
			this->label_cel_nag_s->Size = System::Drawing::Size(20, 20);
			this->label_cel_nag_s->TabIndex = 9;
			this->label_cel_nag_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(3, 52);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(74, 13);
			this->label34->TabIndex = 30;
			this->label34->Text = L"Исправность";
			// 
			// label167
			// 
			this->label167->AutoSize = true;
			this->label167->Location = System::Drawing::Point(10, 6);
			this->label167->Name = L"label167";
			this->label167->Size = System::Drawing::Size(98, 26);
			this->label167->TabIndex = 28;
			this->label167->Text = L"Канал\r\nцелевой нагрузки";
			this->label167->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel136
			// 
			this->panel136->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel136->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel136->Controls->Add(this->label166);
			this->panel136->Controls->Add(this->panel137);
			this->panel136->Controls->Add(this->label168);
			this->panel136->Controls->Add(this->panel138);
			this->panel136->Controls->Add(this->label170);
			this->panel136->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel136->Enabled = false;
			this->panel136->Location = System::Drawing::Point(141, 151);
			this->panel136->Name = L"panel136";
			this->panel136->Size = System::Drawing::Size(122, 124);
			this->panel136->TabIndex = 118;
			// 
			// label166
			// 
			this->label166->AutoSize = true;
			this->label166->Location = System::Drawing::Point(25, 6);
			this->label166->Name = L"label166";
			this->label166->Size = System::Drawing::Size(62, 13);
			this->label166->TabIndex = 28;
			this->label166->Text = L"Канал АКБ";
			// 
			// panel137
			// 
			this->panel137->BackColor = System::Drawing::Color::White;
			this->panel137->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel137->Controls->Add(this->label_bat_i);
			this->panel137->Location = System::Drawing::Point(80, 42);
			this->panel137->Name = L"panel137";
			this->panel137->Size = System::Drawing::Size(33, 33);
			this->panel137->TabIndex = 0;
			// 
			// label_bat_i
			// 
			this->label_bat_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_bat_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_bat_i->Location = System::Drawing::Point(5, 5);
			this->label_bat_i->Name = L"label_bat_i";
			this->label_bat_i->Size = System::Drawing::Size(20, 20);
			this->label_bat_i->TabIndex = 9;
			this->label_bat_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label168
			// 
			this->label168->AutoSize = true;
			this->label168->Location = System::Drawing::Point(3, 91);
			this->label168->Name = L"label168";
			this->label168->Size = System::Drawing::Size(61, 13);
			this->label168->TabIndex = 27;
			this->label168->Text = L"Состояние";
			// 
			// panel138
			// 
			this->panel138->BackColor = System::Drawing::Color::White;
			this->panel138->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel138->Controls->Add(this->label_bat_s);
			this->panel138->Location = System::Drawing::Point(80, 81);
			this->panel138->Name = L"panel138";
			this->panel138->Size = System::Drawing::Size(33, 33);
			this->panel138->TabIndex = 26;
			// 
			// label_bat_s
			// 
			this->label_bat_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_bat_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_bat_s->Location = System::Drawing::Point(5, 5);
			this->label_bat_s->Name = L"label_bat_s";
			this->label_bat_s->Size = System::Drawing::Size(20, 20);
			this->label_bat_s->TabIndex = 9;
			this->label_bat_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label170
			// 
			this->label170->AutoSize = true;
			this->label170->Location = System::Drawing::Point(3, 52);
			this->label170->Name = L"label170";
			this->label170->Size = System::Drawing::Size(74, 13);
			this->label170->TabIndex = 25;
			this->label170->Text = L"Исправность";
			// 
			// panel133
			// 
			this->panel133->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel133->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel133->Controls->Add(this->label165);
			this->panel133->Controls->Add(this->panel134);
			this->panel133->Controls->Add(this->label176);
			this->panel133->Controls->Add(this->panel135);
			this->panel133->Controls->Add(this->label196);
			this->panel133->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel133->Enabled = false;
			this->panel133->Location = System::Drawing::Point(141, 281);
			this->panel133->Name = L"panel133";
			this->panel133->Size = System::Drawing::Size(122, 124);
			this->panel133->TabIndex = 117;
			// 
			// label165
			// 
			this->label165->AutoSize = true;
			this->label165->Location = System::Drawing::Point(25, 6);
			this->label165->Name = L"label165";
			this->label165->Size = System::Drawing::Size(65, 13);
			this->label165->TabIndex = 28;
			this->label165->Text = L"Канал НИП";
			// 
			// panel134
			// 
			this->panel134->BackColor = System::Drawing::Color::White;
			this->panel134->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel134->Controls->Add(this->label_nip_i);
			this->panel134->Location = System::Drawing::Point(80, 42);
			this->panel134->Name = L"panel134";
			this->panel134->Size = System::Drawing::Size(33, 33);
			this->panel134->TabIndex = 0;
			// 
			// label_nip_i
			// 
			this->label_nip_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_nip_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_nip_i->Location = System::Drawing::Point(5, 5);
			this->label_nip_i->Name = L"label_nip_i";
			this->label_nip_i->Size = System::Drawing::Size(20, 20);
			this->label_nip_i->TabIndex = 9;
			this->label_nip_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label176
			// 
			this->label176->AutoSize = true;
			this->label176->Location = System::Drawing::Point(3, 91);
			this->label176->Name = L"label176";
			this->label176->Size = System::Drawing::Size(61, 13);
			this->label176->TabIndex = 27;
			this->label176->Text = L"Состояние";
			// 
			// panel135
			// 
			this->panel135->BackColor = System::Drawing::Color::White;
			this->panel135->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel135->Controls->Add(this->label_nip_s);
			this->panel135->Location = System::Drawing::Point(80, 81);
			this->panel135->Name = L"panel135";
			this->panel135->Size = System::Drawing::Size(33, 33);
			this->panel135->TabIndex = 26;
			// 
			// label_nip_s
			// 
			this->label_nip_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_nip_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_nip_s->Location = System::Drawing::Point(5, 5);
			this->label_nip_s->Name = L"label_nip_s";
			this->label_nip_s->Size = System::Drawing::Size(20, 20);
			this->label_nip_s->TabIndex = 9;
			this->label_nip_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label196
			// 
			this->label196->AutoSize = true;
			this->label196->Location = System::Drawing::Point(3, 52);
			this->label196->Name = L"label196";
			this->label196->Size = System::Drawing::Size(74, 13);
			this->label196->TabIndex = 25;
			this->label196->Text = L"Исправность";
			// 
			// panel127
			// 
			this->panel127->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel127->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel127->Controls->Add(this->label142);
			this->panel127->Controls->Add(this->panel128);
			this->panel127->Controls->Add(this->label143);
			this->panel127->Controls->Add(this->label144);
			this->panel127->Controls->Add(this->panel129);
			this->panel127->Controls->Add(this->label147);
			this->panel127->Controls->Add(this->label148);
			this->panel127->Controls->Add(this->label149);
			this->panel127->Controls->Add(this->label150);
			this->panel127->Controls->Add(this->label151);
			this->panel127->Controls->Add(this->label152);
			this->panel127->Controls->Add(this->label153);
			this->panel127->Controls->Add(this->label154);
			this->panel127->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel127->Enabled = false;
			this->panel127->Location = System::Drawing::Point(269, 22);
			this->panel127->Name = L"panel127";
			this->panel127->Size = System::Drawing::Size(304, 124);
			this->panel127->TabIndex = 94;
			// 
			// label142
			// 
			this->label142->AutoSize = true;
			this->label142->Location = System::Drawing::Point(128, 3);
			this->label142->Name = L"label142";
			this->label142->Size = System::Drawing::Size(58, 13);
			this->label142->TabIndex = 28;
			this->label142->Text = L"Плата №1";
			// 
			// panel128
			// 
			this->panel128->BackColor = System::Drawing::Color::White;
			this->panel128->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel128->Controls->Add(this->label_1_k8_i);
			this->panel128->Controls->Add(this->label_1_k7_i);
			this->panel128->Controls->Add(this->label_1_k6_i);
			this->panel128->Controls->Add(this->label_1_k5_i);
			this->panel128->Controls->Add(this->label_1_k4_i);
			this->panel128->Controls->Add(this->label_1_k2_i);
			this->panel128->Controls->Add(this->label_1_k1_i);
			this->panel128->Controls->Add(this->label_1_k3_i);
			this->panel128->Location = System::Drawing::Point(79, 43);
			this->panel128->Name = L"panel128";
			this->panel128->Size = System::Drawing::Size(216, 33);
			this->panel128->TabIndex = 0;
			// 
			// label_1_k8_i
			// 
			this->label_1_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k8_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k8_i->Location = System::Drawing::Point(187, 5);
			this->label_1_k8_i->Name = L"label_1_k8_i";
			this->label_1_k8_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k8_i->TabIndex = 23;
			this->label_1_k8_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k7_i
			// 
			this->label_1_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k7_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k7_i->Location = System::Drawing::Point(161, 5);
			this->label_1_k7_i->Name = L"label_1_k7_i";
			this->label_1_k7_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k7_i->TabIndex = 21;
			this->label_1_k7_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k6_i
			// 
			this->label_1_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k6_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k6_i->Location = System::Drawing::Point(135, 5);
			this->label_1_k6_i->Name = L"label_1_k6_i";
			this->label_1_k6_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k6_i->TabIndex = 19;
			this->label_1_k6_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k5_i
			// 
			this->label_1_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k5_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k5_i->Location = System::Drawing::Point(109, 5);
			this->label_1_k5_i->Name = L"label_1_k5_i";
			this->label_1_k5_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k5_i->TabIndex = 17;
			this->label_1_k5_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k4_i
			// 
			this->label_1_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k4_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k4_i->Location = System::Drawing::Point(83, 5);
			this->label_1_k4_i->Name = L"label_1_k4_i";
			this->label_1_k4_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k4_i->TabIndex = 15;
			this->label_1_k4_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k2_i
			// 
			this->label_1_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k2_i->Location = System::Drawing::Point(31, 5);
			this->label_1_k2_i->Name = L"label_1_k2_i";
			this->label_1_k2_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k2_i->TabIndex = 11;
			this->label_1_k2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k1_i
			// 
			this->label_1_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k1_i->Location = System::Drawing::Point(5, 5);
			this->label_1_k1_i->Name = L"label_1_k1_i";
			this->label_1_k1_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k1_i->TabIndex = 9;
			this->label_1_k1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k3_i
			// 
			this->label_1_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k3_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k3_i->Location = System::Drawing::Point(57, 5);
			this->label_1_k3_i->Name = L"label_1_k3_i";
			this->label_1_k3_i->Size = System::Drawing::Size(20, 20);
			this->label_1_k3_i->TabIndex = 13;
			this->label_1_k3_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label143
			// 
			this->label143->AutoSize = true;
			this->label143->Location = System::Drawing::Point(2, 92);
			this->label143->Name = L"label143";
			this->label143->Size = System::Drawing::Size(61, 13);
			this->label143->TabIndex = 27;
			this->label143->Text = L"Состояние";
			// 
			// label144
			// 
			this->label144->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label144->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label144->Location = System::Drawing::Point(85, 20);
			this->label144->Name = L"label144";
			this->label144->Size = System::Drawing::Size(20, 20);
			this->label144->TabIndex = 10;
			this->label144->Text = L"К1";
			this->label144->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel129
			// 
			this->panel129->BackColor = System::Drawing::Color::White;
			this->panel129->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel129->Controls->Add(this->label_1_k8_s);
			this->panel129->Controls->Add(this->label_1_k7_s);
			this->panel129->Controls->Add(this->label_1_k6_s);
			this->panel129->Controls->Add(this->label_1_k5_s);
			this->panel129->Controls->Add(this->label_1_k4_s);
			this->panel129->Controls->Add(this->label_1_k2_s);
			this->panel129->Controls->Add(this->label_1_k1_s);
			this->panel129->Controls->Add(this->label_1_k3_s);
			this->panel129->Location = System::Drawing::Point(79, 82);
			this->panel129->Name = L"panel129";
			this->panel129->Size = System::Drawing::Size(216, 33);
			this->panel129->TabIndex = 26;
			// 
			// label_1_k8_s
			// 
			this->label_1_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k8_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k8_s->Location = System::Drawing::Point(187, 5);
			this->label_1_k8_s->Name = L"label_1_k8_s";
			this->label_1_k8_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k8_s->TabIndex = 23;
			this->label_1_k8_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k7_s
			// 
			this->label_1_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k7_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k7_s->Location = System::Drawing::Point(161, 5);
			this->label_1_k7_s->Name = L"label_1_k7_s";
			this->label_1_k7_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k7_s->TabIndex = 21;
			this->label_1_k7_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k6_s
			// 
			this->label_1_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k6_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k6_s->Location = System::Drawing::Point(135, 5);
			this->label_1_k6_s->Name = L"label_1_k6_s";
			this->label_1_k6_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k6_s->TabIndex = 19;
			this->label_1_k6_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k5_s
			// 
			this->label_1_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k5_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k5_s->Location = System::Drawing::Point(109, 5);
			this->label_1_k5_s->Name = L"label_1_k5_s";
			this->label_1_k5_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k5_s->TabIndex = 17;
			this->label_1_k5_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k4_s
			// 
			this->label_1_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k4_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k4_s->Location = System::Drawing::Point(83, 5);
			this->label_1_k4_s->Name = L"label_1_k4_s";
			this->label_1_k4_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k4_s->TabIndex = 15;
			this->label_1_k4_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k2_s
			// 
			this->label_1_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k2_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k2_s->Location = System::Drawing::Point(31, 5);
			this->label_1_k2_s->Name = L"label_1_k2_s";
			this->label_1_k2_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k2_s->TabIndex = 11;
			this->label_1_k2_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k1_s
			// 
			this->label_1_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k1_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k1_s->Location = System::Drawing::Point(5, 5);
			this->label_1_k1_s->Name = L"label_1_k1_s";
			this->label_1_k1_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k1_s->TabIndex = 9;
			this->label_1_k1_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_1_k3_s
			// 
			this->label_1_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_1_k3_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_1_k3_s->Location = System::Drawing::Point(57, 5);
			this->label_1_k3_s->Name = L"label_1_k3_s";
			this->label_1_k3_s->Size = System::Drawing::Size(20, 20);
			this->label_1_k3_s->TabIndex = 13;
			this->label_1_k3_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label147
			// 
			this->label147->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label147->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label147->Location = System::Drawing::Point(111, 20);
			this->label147->Name = L"label147";
			this->label147->Size = System::Drawing::Size(20, 20);
			this->label147->TabIndex = 12;
			this->label147->Text = L"К2";
			this->label147->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label148
			// 
			this->label148->AutoSize = true;
			this->label148->Location = System::Drawing::Point(2, 53);
			this->label148->Name = L"label148";
			this->label148->Size = System::Drawing::Size(74, 13);
			this->label148->TabIndex = 25;
			this->label148->Text = L"Исправность";
			// 
			// label149
			// 
			this->label149->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label149->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label149->Location = System::Drawing::Point(137, 20);
			this->label149->Name = L"label149";
			this->label149->Size = System::Drawing::Size(20, 20);
			this->label149->TabIndex = 14;
			this->label149->Text = L"К3";
			this->label149->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label150
			// 
			this->label150->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label150->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label150->Location = System::Drawing::Point(267, 20);
			this->label150->Name = L"label150";
			this->label150->Size = System::Drawing::Size(20, 20);
			this->label150->TabIndex = 24;
			this->label150->Text = L"К8";
			this->label150->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label151
			// 
			this->label151->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label151->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label151->Location = System::Drawing::Point(163, 20);
			this->label151->Name = L"label151";
			this->label151->Size = System::Drawing::Size(20, 20);
			this->label151->TabIndex = 16;
			this->label151->Text = L"К4";
			this->label151->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label152
			// 
			this->label152->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label152->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label152->Location = System::Drawing::Point(241, 20);
			this->label152->Name = L"label152";
			this->label152->Size = System::Drawing::Size(20, 20);
			this->label152->TabIndex = 22;
			this->label152->Text = L"К7";
			this->label152->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label153
			// 
			this->label153->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label153->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label153->Location = System::Drawing::Point(189, 20);
			this->label153->Name = L"label153";
			this->label153->Size = System::Drawing::Size(20, 20);
			this->label153->TabIndex = 18;
			this->label153->Text = L"К5";
			this->label153->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label154
			// 
			this->label154->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label154->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label154->Location = System::Drawing::Point(215, 20);
			this->label154->Name = L"label154";
			this->label154->Size = System::Drawing::Size(20, 20);
			this->label154->TabIndex = 20;
			this->label154->Text = L"К6";
			this->label154->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel115
			// 
			this->panel115->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel115->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel115->Controls->Add(this->label109);
			this->panel115->Controls->Add(this->panel116);
			this->panel115->Controls->Add(this->label118);
			this->panel115->Controls->Add(this->label119);
			this->panel115->Controls->Add(this->panel117);
			this->panel115->Controls->Add(this->label128);
			this->panel115->Controls->Add(this->label129);
			this->panel115->Controls->Add(this->label130);
			this->panel115->Controls->Add(this->label131);
			this->panel115->Controls->Add(this->label132);
			this->panel115->Controls->Add(this->label133);
			this->panel115->Controls->Add(this->label134);
			this->panel115->Controls->Add(this->label135);
			this->panel115->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel115->Enabled = false;
			this->panel115->Location = System::Drawing::Point(579, 151);
			this->panel115->Name = L"panel115";
			this->panel115->Size = System::Drawing::Size(304, 124);
			this->panel115->TabIndex = 102;
			// 
			// label109
			// 
			this->label109->AutoSize = true;
			this->label109->Location = System::Drawing::Point(128, 3);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(58, 13);
			this->label109->TabIndex = 28;
			this->label109->Text = L"Плата №5";
			// 
			// panel116
			// 
			this->panel116->BackColor = System::Drawing::Color::White;
			this->panel116->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel116->Controls->Add(this->label_5_k8_i);
			this->panel116->Controls->Add(this->label_5_k7_i);
			this->panel116->Controls->Add(this->label_5_k6_i);
			this->panel116->Controls->Add(this->label_5_k5_i);
			this->panel116->Controls->Add(this->label_5_k4_i);
			this->panel116->Controls->Add(this->label_5_k2_i);
			this->panel116->Controls->Add(this->label_5_k1_i);
			this->panel116->Controls->Add(this->label_5_k3_i);
			this->panel116->Location = System::Drawing::Point(79, 43);
			this->panel116->Name = L"panel116";
			this->panel116->Size = System::Drawing::Size(216, 33);
			this->panel116->TabIndex = 0;
			// 
			// label_5_k8_i
			// 
			this->label_5_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k8_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k8_i->Location = System::Drawing::Point(187, 5);
			this->label_5_k8_i->Name = L"label_5_k8_i";
			this->label_5_k8_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k8_i->TabIndex = 23;
			this->label_5_k8_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k7_i
			// 
			this->label_5_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k7_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k7_i->Location = System::Drawing::Point(161, 5);
			this->label_5_k7_i->Name = L"label_5_k7_i";
			this->label_5_k7_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k7_i->TabIndex = 21;
			this->label_5_k7_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k6_i
			// 
			this->label_5_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k6_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k6_i->Location = System::Drawing::Point(135, 5);
			this->label_5_k6_i->Name = L"label_5_k6_i";
			this->label_5_k6_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k6_i->TabIndex = 19;
			this->label_5_k6_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k5_i
			// 
			this->label_5_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k5_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k5_i->Location = System::Drawing::Point(109, 5);
			this->label_5_k5_i->Name = L"label_5_k5_i";
			this->label_5_k5_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k5_i->TabIndex = 17;
			this->label_5_k5_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k4_i
			// 
			this->label_5_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k4_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k4_i->Location = System::Drawing::Point(83, 5);
			this->label_5_k4_i->Name = L"label_5_k4_i";
			this->label_5_k4_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k4_i->TabIndex = 15;
			this->label_5_k4_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k2_i
			// 
			this->label_5_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k2_i->Location = System::Drawing::Point(31, 5);
			this->label_5_k2_i->Name = L"label_5_k2_i";
			this->label_5_k2_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k2_i->TabIndex = 11;
			this->label_5_k2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k1_i
			// 
			this->label_5_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k1_i->Location = System::Drawing::Point(5, 5);
			this->label_5_k1_i->Name = L"label_5_k1_i";
			this->label_5_k1_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k1_i->TabIndex = 9;
			this->label_5_k1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k3_i
			// 
			this->label_5_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k3_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k3_i->Location = System::Drawing::Point(57, 5);
			this->label_5_k3_i->Name = L"label_5_k3_i";
			this->label_5_k3_i->Size = System::Drawing::Size(20, 20);
			this->label_5_k3_i->TabIndex = 13;
			this->label_5_k3_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label118
			// 
			this->label118->AutoSize = true;
			this->label118->Location = System::Drawing::Point(2, 92);
			this->label118->Name = L"label118";
			this->label118->Size = System::Drawing::Size(61, 13);
			this->label118->TabIndex = 27;
			this->label118->Text = L"Состояние";
			// 
			// label119
			// 
			this->label119->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label119->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label119->Location = System::Drawing::Point(85, 20);
			this->label119->Name = L"label119";
			this->label119->Size = System::Drawing::Size(20, 20);
			this->label119->TabIndex = 10;
			this->label119->Text = L"К1";
			this->label119->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel117
			// 
			this->panel117->BackColor = System::Drawing::Color::White;
			this->panel117->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel117->Controls->Add(this->label_5_k8_s);
			this->panel117->Controls->Add(this->label_5_k7_s);
			this->panel117->Controls->Add(this->label_5_k6_s);
			this->panel117->Controls->Add(this->label_5_k5_s);
			this->panel117->Controls->Add(this->label_5_k4_s);
			this->panel117->Controls->Add(this->label_5_k2_s);
			this->panel117->Controls->Add(this->label_5_k1_s);
			this->panel117->Controls->Add(this->label_5_k3_s);
			this->panel117->Location = System::Drawing::Point(79, 82);
			this->panel117->Name = L"panel117";
			this->panel117->Size = System::Drawing::Size(216, 33);
			this->panel117->TabIndex = 26;
			// 
			// label_5_k8_s
			// 
			this->label_5_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k8_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k8_s->Location = System::Drawing::Point(187, 5);
			this->label_5_k8_s->Name = L"label_5_k8_s";
			this->label_5_k8_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k8_s->TabIndex = 23;
			this->label_5_k8_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k7_s
			// 
			this->label_5_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k7_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k7_s->Location = System::Drawing::Point(161, 5);
			this->label_5_k7_s->Name = L"label_5_k7_s";
			this->label_5_k7_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k7_s->TabIndex = 21;
			this->label_5_k7_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k6_s
			// 
			this->label_5_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k6_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k6_s->Location = System::Drawing::Point(135, 5);
			this->label_5_k6_s->Name = L"label_5_k6_s";
			this->label_5_k6_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k6_s->TabIndex = 19;
			this->label_5_k6_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k5_s
			// 
			this->label_5_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k5_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k5_s->Location = System::Drawing::Point(109, 5);
			this->label_5_k5_s->Name = L"label_5_k5_s";
			this->label_5_k5_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k5_s->TabIndex = 17;
			this->label_5_k5_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k4_s
			// 
			this->label_5_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k4_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k4_s->Location = System::Drawing::Point(83, 5);
			this->label_5_k4_s->Name = L"label_5_k4_s";
			this->label_5_k4_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k4_s->TabIndex = 15;
			this->label_5_k4_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k2_s
			// 
			this->label_5_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k2_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k2_s->Location = System::Drawing::Point(31, 5);
			this->label_5_k2_s->Name = L"label_5_k2_s";
			this->label_5_k2_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k2_s->TabIndex = 11;
			this->label_5_k2_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k1_s
			// 
			this->label_5_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k1_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k1_s->Location = System::Drawing::Point(5, 5);
			this->label_5_k1_s->Name = L"label_5_k1_s";
			this->label_5_k1_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k1_s->TabIndex = 9;
			this->label_5_k1_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_5_k3_s
			// 
			this->label_5_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_5_k3_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_5_k3_s->Location = System::Drawing::Point(57, 5);
			this->label_5_k3_s->Name = L"label_5_k3_s";
			this->label_5_k3_s->Size = System::Drawing::Size(20, 20);
			this->label_5_k3_s->TabIndex = 13;
			this->label_5_k3_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label128
			// 
			this->label128->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label128->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label128->Location = System::Drawing::Point(111, 20);
			this->label128->Name = L"label128";
			this->label128->Size = System::Drawing::Size(20, 20);
			this->label128->TabIndex = 12;
			this->label128->Text = L"К2";
			this->label128->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label129
			// 
			this->label129->AutoSize = true;
			this->label129->Location = System::Drawing::Point(2, 53);
			this->label129->Name = L"label129";
			this->label129->Size = System::Drawing::Size(74, 13);
			this->label129->TabIndex = 25;
			this->label129->Text = L"Исправность";
			// 
			// label130
			// 
			this->label130->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label130->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label130->Location = System::Drawing::Point(137, 20);
			this->label130->Name = L"label130";
			this->label130->Size = System::Drawing::Size(20, 20);
			this->label130->TabIndex = 14;
			this->label130->Text = L"К3";
			this->label130->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label131
			// 
			this->label131->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label131->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label131->Location = System::Drawing::Point(267, 20);
			this->label131->Name = L"label131";
			this->label131->Size = System::Drawing::Size(20, 20);
			this->label131->TabIndex = 24;
			this->label131->Text = L"К8";
			this->label131->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label132
			// 
			this->label132->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label132->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label132->Location = System::Drawing::Point(163, 20);
			this->label132->Name = L"label132";
			this->label132->Size = System::Drawing::Size(20, 20);
			this->label132->TabIndex = 16;
			this->label132->Text = L"К4";
			this->label132->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label133
			// 
			this->label133->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label133->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label133->Location = System::Drawing::Point(241, 20);
			this->label133->Name = L"label133";
			this->label133->Size = System::Drawing::Size(20, 20);
			this->label133->TabIndex = 22;
			this->label133->Text = L"К7";
			this->label133->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label134
			// 
			this->label134->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label134->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label134->Location = System::Drawing::Point(189, 20);
			this->label134->Name = L"label134";
			this->label134->Size = System::Drawing::Size(20, 20);
			this->label134->TabIndex = 18;
			this->label134->Text = L"К5";
			this->label134->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label135
			// 
			this->label135->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label135->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label135->Location = System::Drawing::Point(215, 20);
			this->label135->Name = L"label135";
			this->label135->Size = System::Drawing::Size(20, 20);
			this->label135->TabIndex = 20;
			this->label135->Text = L"К6";
			this->label135->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel124
			// 
			this->panel124->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel124->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel124->Controls->Add(this->label122);
			this->panel124->Controls->Add(this->panel125);
			this->panel124->Controls->Add(this->label123);
			this->panel124->Controls->Add(this->label124);
			this->panel124->Controls->Add(this->panel126);
			this->panel124->Controls->Add(this->label125);
			this->panel124->Controls->Add(this->label126);
			this->panel124->Controls->Add(this->label127);
			this->panel124->Controls->Add(this->label137);
			this->panel124->Controls->Add(this->label138);
			this->panel124->Controls->Add(this->label139);
			this->panel124->Controls->Add(this->label140);
			this->panel124->Controls->Add(this->label141);
			this->panel124->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel124->Enabled = false;
			this->panel124->Location = System::Drawing::Point(269, 151);
			this->panel124->Name = L"panel124";
			this->panel124->Size = System::Drawing::Size(304, 124);
			this->panel124->TabIndex = 96;
			// 
			// label122
			// 
			this->label122->AutoSize = true;
			this->label122->Location = System::Drawing::Point(128, 3);
			this->label122->Name = L"label122";
			this->label122->Size = System::Drawing::Size(58, 13);
			this->label122->TabIndex = 28;
			this->label122->Text = L"Плата №2";
			// 
			// panel125
			// 
			this->panel125->BackColor = System::Drawing::Color::White;
			this->panel125->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel125->Controls->Add(this->label_2_k8_i);
			this->panel125->Controls->Add(this->label_2_k7_i);
			this->panel125->Controls->Add(this->label_2_k6_i);
			this->panel125->Controls->Add(this->label_2_k5_i);
			this->panel125->Controls->Add(this->label_2_k4_i);
			this->panel125->Controls->Add(this->label_2_k2_i);
			this->panel125->Controls->Add(this->label_2_k1_i);
			this->panel125->Controls->Add(this->label_2_k3_i);
			this->panel125->Location = System::Drawing::Point(79, 43);
			this->panel125->Name = L"panel125";
			this->panel125->Size = System::Drawing::Size(216, 33);
			this->panel125->TabIndex = 0;
			// 
			// label_2_k8_i
			// 
			this->label_2_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k8_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k8_i->Location = System::Drawing::Point(187, 5);
			this->label_2_k8_i->Name = L"label_2_k8_i";
			this->label_2_k8_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k8_i->TabIndex = 23;
			this->label_2_k8_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k7_i
			// 
			this->label_2_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k7_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k7_i->Location = System::Drawing::Point(161, 5);
			this->label_2_k7_i->Name = L"label_2_k7_i";
			this->label_2_k7_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k7_i->TabIndex = 21;
			this->label_2_k7_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k6_i
			// 
			this->label_2_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k6_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k6_i->Location = System::Drawing::Point(135, 5);
			this->label_2_k6_i->Name = L"label_2_k6_i";
			this->label_2_k6_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k6_i->TabIndex = 19;
			this->label_2_k6_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k5_i
			// 
			this->label_2_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k5_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k5_i->Location = System::Drawing::Point(109, 5);
			this->label_2_k5_i->Name = L"label_2_k5_i";
			this->label_2_k5_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k5_i->TabIndex = 17;
			this->label_2_k5_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k4_i
			// 
			this->label_2_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k4_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k4_i->Location = System::Drawing::Point(83, 5);
			this->label_2_k4_i->Name = L"label_2_k4_i";
			this->label_2_k4_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k4_i->TabIndex = 15;
			this->label_2_k4_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k2_i
			// 
			this->label_2_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k2_i->Location = System::Drawing::Point(31, 5);
			this->label_2_k2_i->Name = L"label_2_k2_i";
			this->label_2_k2_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k2_i->TabIndex = 11;
			this->label_2_k2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k1_i
			// 
			this->label_2_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k1_i->Location = System::Drawing::Point(5, 5);
			this->label_2_k1_i->Name = L"label_2_k1_i";
			this->label_2_k1_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k1_i->TabIndex = 9;
			this->label_2_k1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k3_i
			// 
			this->label_2_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k3_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k3_i->Location = System::Drawing::Point(57, 5);
			this->label_2_k3_i->Name = L"label_2_k3_i";
			this->label_2_k3_i->Size = System::Drawing::Size(20, 20);
			this->label_2_k3_i->TabIndex = 13;
			this->label_2_k3_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label123
			// 
			this->label123->AutoSize = true;
			this->label123->Location = System::Drawing::Point(2, 92);
			this->label123->Name = L"label123";
			this->label123->Size = System::Drawing::Size(61, 13);
			this->label123->TabIndex = 27;
			this->label123->Text = L"Состояние";
			// 
			// label124
			// 
			this->label124->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label124->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label124->Location = System::Drawing::Point(85, 20);
			this->label124->Name = L"label124";
			this->label124->Size = System::Drawing::Size(20, 20);
			this->label124->TabIndex = 10;
			this->label124->Text = L"К1";
			this->label124->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel126
			// 
			this->panel126->BackColor = System::Drawing::Color::White;
			this->panel126->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel126->Controls->Add(this->label_2_k8_s);
			this->panel126->Controls->Add(this->label_2_k7_s);
			this->panel126->Controls->Add(this->label_2_k6_s);
			this->panel126->Controls->Add(this->label_2_k5_s);
			this->panel126->Controls->Add(this->label_2_k4_s);
			this->panel126->Controls->Add(this->label_2_k2_s);
			this->panel126->Controls->Add(this->label_2_k1_s);
			this->panel126->Controls->Add(this->label_2_k3_s);
			this->panel126->Location = System::Drawing::Point(79, 82);
			this->panel126->Name = L"panel126";
			this->panel126->Size = System::Drawing::Size(216, 33);
			this->panel126->TabIndex = 26;
			// 
			// label_2_k8_s
			// 
			this->label_2_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k8_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k8_s->Location = System::Drawing::Point(187, 5);
			this->label_2_k8_s->Name = L"label_2_k8_s";
			this->label_2_k8_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k8_s->TabIndex = 23;
			this->label_2_k8_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k7_s
			// 
			this->label_2_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k7_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k7_s->Location = System::Drawing::Point(161, 5);
			this->label_2_k7_s->Name = L"label_2_k7_s";
			this->label_2_k7_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k7_s->TabIndex = 21;
			this->label_2_k7_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k6_s
			// 
			this->label_2_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k6_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k6_s->Location = System::Drawing::Point(135, 5);
			this->label_2_k6_s->Name = L"label_2_k6_s";
			this->label_2_k6_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k6_s->TabIndex = 19;
			this->label_2_k6_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k5_s
			// 
			this->label_2_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k5_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k5_s->Location = System::Drawing::Point(109, 5);
			this->label_2_k5_s->Name = L"label_2_k5_s";
			this->label_2_k5_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k5_s->TabIndex = 17;
			this->label_2_k5_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k4_s
			// 
			this->label_2_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k4_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k4_s->Location = System::Drawing::Point(83, 5);
			this->label_2_k4_s->Name = L"label_2_k4_s";
			this->label_2_k4_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k4_s->TabIndex = 15;
			this->label_2_k4_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k2_s
			// 
			this->label_2_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k2_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k2_s->Location = System::Drawing::Point(31, 5);
			this->label_2_k2_s->Name = L"label_2_k2_s";
			this->label_2_k2_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k2_s->TabIndex = 11;
			this->label_2_k2_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k1_s
			// 
			this->label_2_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k1_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k1_s->Location = System::Drawing::Point(5, 5);
			this->label_2_k1_s->Name = L"label_2_k1_s";
			this->label_2_k1_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k1_s->TabIndex = 9;
			this->label_2_k1_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_2_k3_s
			// 
			this->label_2_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_2_k3_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_2_k3_s->Location = System::Drawing::Point(57, 5);
			this->label_2_k3_s->Name = L"label_2_k3_s";
			this->label_2_k3_s->Size = System::Drawing::Size(20, 20);
			this->label_2_k3_s->TabIndex = 13;
			this->label_2_k3_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label125
			// 
			this->label125->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label125->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label125->Location = System::Drawing::Point(111, 20);
			this->label125->Name = L"label125";
			this->label125->Size = System::Drawing::Size(20, 20);
			this->label125->TabIndex = 12;
			this->label125->Text = L"К2";
			this->label125->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label126
			// 
			this->label126->AutoSize = true;
			this->label126->Location = System::Drawing::Point(2, 53);
			this->label126->Name = L"label126";
			this->label126->Size = System::Drawing::Size(74, 13);
			this->label126->TabIndex = 25;
			this->label126->Text = L"Исправность";
			// 
			// label127
			// 
			this->label127->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label127->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label127->Location = System::Drawing::Point(137, 20);
			this->label127->Name = L"label127";
			this->label127->Size = System::Drawing::Size(20, 20);
			this->label127->TabIndex = 14;
			this->label127->Text = L"К3";
			this->label127->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label137
			// 
			this->label137->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label137->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label137->Location = System::Drawing::Point(267, 20);
			this->label137->Name = L"label137";
			this->label137->Size = System::Drawing::Size(20, 20);
			this->label137->TabIndex = 24;
			this->label137->Text = L"К8";
			this->label137->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label138
			// 
			this->label138->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label138->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label138->Location = System::Drawing::Point(163, 20);
			this->label138->Name = L"label138";
			this->label138->Size = System::Drawing::Size(20, 20);
			this->label138->TabIndex = 16;
			this->label138->Text = L"К4";
			this->label138->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label139
			// 
			this->label139->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label139->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label139->Location = System::Drawing::Point(241, 20);
			this->label139->Name = L"label139";
			this->label139->Size = System::Drawing::Size(20, 20);
			this->label139->TabIndex = 22;
			this->label139->Text = L"К7";
			this->label139->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label140
			// 
			this->label140->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label140->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label140->Location = System::Drawing::Point(189, 20);
			this->label140->Name = L"label140";
			this->label140->Size = System::Drawing::Size(20, 20);
			this->label140->TabIndex = 18;
			this->label140->Text = L"К5";
			this->label140->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label141
			// 
			this->label141->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label141->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label141->Location = System::Drawing::Point(215, 20);
			this->label141->Name = L"label141";
			this->label141->Size = System::Drawing::Size(20, 20);
			this->label141->TabIndex = 20;
			this->label141->Text = L"К6";
			this->label141->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel118
			// 
			this->panel118->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel118->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel118->Controls->Add(this->label136);
			this->panel118->Controls->Add(this->panel119);
			this->panel118->Controls->Add(this->label145);
			this->panel118->Controls->Add(this->label146);
			this->panel118->Controls->Add(this->panel120);
			this->panel118->Controls->Add(this->label155);
			this->panel118->Controls->Add(this->label156);
			this->panel118->Controls->Add(this->label157);
			this->panel118->Controls->Add(this->label158);
			this->panel118->Controls->Add(this->label159);
			this->panel118->Controls->Add(this->label160);
			this->panel118->Controls->Add(this->label161);
			this->panel118->Controls->Add(this->label162);
			this->panel118->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel118->Enabled = false;
			this->panel118->Location = System::Drawing::Point(579, 22);
			this->panel118->Name = L"panel118";
			this->panel118->Size = System::Drawing::Size(304, 124);
			this->panel118->TabIndex = 100;
			// 
			// label136
			// 
			this->label136->AutoSize = true;
			this->label136->Location = System::Drawing::Point(128, 3);
			this->label136->Name = L"label136";
			this->label136->Size = System::Drawing::Size(58, 13);
			this->label136->TabIndex = 28;
			this->label136->Text = L"Плата №4";
			// 
			// panel119
			// 
			this->panel119->BackColor = System::Drawing::Color::White;
			this->panel119->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel119->Controls->Add(this->label_4_k8_i);
			this->panel119->Controls->Add(this->label_4_k7_i);
			this->panel119->Controls->Add(this->label_4_k6_i);
			this->panel119->Controls->Add(this->label_4_k5_i);
			this->panel119->Controls->Add(this->label_4_k4_i);
			this->panel119->Controls->Add(this->label_4_k2_i);
			this->panel119->Controls->Add(this->label_4_k1_i);
			this->panel119->Controls->Add(this->label_4_k3_i);
			this->panel119->Location = System::Drawing::Point(79, 43);
			this->panel119->Name = L"panel119";
			this->panel119->Size = System::Drawing::Size(216, 33);
			this->panel119->TabIndex = 0;
			// 
			// label_4_k8_i
			// 
			this->label_4_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k8_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k8_i->Location = System::Drawing::Point(187, 5);
			this->label_4_k8_i->Name = L"label_4_k8_i";
			this->label_4_k8_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k8_i->TabIndex = 23;
			this->label_4_k8_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k7_i
			// 
			this->label_4_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k7_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k7_i->Location = System::Drawing::Point(161, 5);
			this->label_4_k7_i->Name = L"label_4_k7_i";
			this->label_4_k7_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k7_i->TabIndex = 21;
			this->label_4_k7_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k6_i
			// 
			this->label_4_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k6_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k6_i->Location = System::Drawing::Point(135, 5);
			this->label_4_k6_i->Name = L"label_4_k6_i";
			this->label_4_k6_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k6_i->TabIndex = 19;
			this->label_4_k6_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k5_i
			// 
			this->label_4_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k5_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k5_i->Location = System::Drawing::Point(109, 5);
			this->label_4_k5_i->Name = L"label_4_k5_i";
			this->label_4_k5_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k5_i->TabIndex = 17;
			this->label_4_k5_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k4_i
			// 
			this->label_4_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k4_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k4_i->Location = System::Drawing::Point(83, 5);
			this->label_4_k4_i->Name = L"label_4_k4_i";
			this->label_4_k4_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k4_i->TabIndex = 15;
			this->label_4_k4_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k2_i
			// 
			this->label_4_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k2_i->Location = System::Drawing::Point(31, 5);
			this->label_4_k2_i->Name = L"label_4_k2_i";
			this->label_4_k2_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k2_i->TabIndex = 11;
			this->label_4_k2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k1_i
			// 
			this->label_4_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k1_i->Location = System::Drawing::Point(5, 5);
			this->label_4_k1_i->Name = L"label_4_k1_i";
			this->label_4_k1_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k1_i->TabIndex = 9;
			this->label_4_k1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k3_i
			// 
			this->label_4_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k3_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k3_i->Location = System::Drawing::Point(57, 5);
			this->label_4_k3_i->Name = L"label_4_k3_i";
			this->label_4_k3_i->Size = System::Drawing::Size(20, 20);
			this->label_4_k3_i->TabIndex = 13;
			this->label_4_k3_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label145
			// 
			this->label145->AutoSize = true;
			this->label145->Location = System::Drawing::Point(2, 92);
			this->label145->Name = L"label145";
			this->label145->Size = System::Drawing::Size(61, 13);
			this->label145->TabIndex = 27;
			this->label145->Text = L"Состояние";
			// 
			// label146
			// 
			this->label146->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label146->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label146->Location = System::Drawing::Point(85, 20);
			this->label146->Name = L"label146";
			this->label146->Size = System::Drawing::Size(20, 20);
			this->label146->TabIndex = 10;
			this->label146->Text = L"К1";
			this->label146->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel120
			// 
			this->panel120->BackColor = System::Drawing::Color::White;
			this->panel120->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel120->Controls->Add(this->label_4_k8_s);
			this->panel120->Controls->Add(this->label_4_k7_s);
			this->panel120->Controls->Add(this->label_4_k6_s);
			this->panel120->Controls->Add(this->label_4_k5_s);
			this->panel120->Controls->Add(this->label_4_k4_s);
			this->panel120->Controls->Add(this->label_4_k2_s);
			this->panel120->Controls->Add(this->label_4_k1_s);
			this->panel120->Controls->Add(this->label_4_k3_s);
			this->panel120->Location = System::Drawing::Point(79, 82);
			this->panel120->Name = L"panel120";
			this->panel120->Size = System::Drawing::Size(216, 33);
			this->panel120->TabIndex = 26;
			// 
			// label_4_k8_s
			// 
			this->label_4_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k8_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k8_s->Location = System::Drawing::Point(187, 5);
			this->label_4_k8_s->Name = L"label_4_k8_s";
			this->label_4_k8_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k8_s->TabIndex = 23;
			this->label_4_k8_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k7_s
			// 
			this->label_4_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k7_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k7_s->Location = System::Drawing::Point(161, 5);
			this->label_4_k7_s->Name = L"label_4_k7_s";
			this->label_4_k7_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k7_s->TabIndex = 21;
			this->label_4_k7_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k6_s
			// 
			this->label_4_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k6_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k6_s->Location = System::Drawing::Point(135, 5);
			this->label_4_k6_s->Name = L"label_4_k6_s";
			this->label_4_k6_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k6_s->TabIndex = 19;
			this->label_4_k6_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k5_s
			// 
			this->label_4_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k5_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k5_s->Location = System::Drawing::Point(109, 5);
			this->label_4_k5_s->Name = L"label_4_k5_s";
			this->label_4_k5_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k5_s->TabIndex = 17;
			this->label_4_k5_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k4_s
			// 
			this->label_4_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k4_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k4_s->Location = System::Drawing::Point(83, 5);
			this->label_4_k4_s->Name = L"label_4_k4_s";
			this->label_4_k4_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k4_s->TabIndex = 15;
			this->label_4_k4_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k2_s
			// 
			this->label_4_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k2_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k2_s->Location = System::Drawing::Point(31, 5);
			this->label_4_k2_s->Name = L"label_4_k2_s";
			this->label_4_k2_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k2_s->TabIndex = 11;
			this->label_4_k2_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k1_s
			// 
			this->label_4_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k1_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k1_s->Location = System::Drawing::Point(5, 5);
			this->label_4_k1_s->Name = L"label_4_k1_s";
			this->label_4_k1_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k1_s->TabIndex = 9;
			this->label_4_k1_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_4_k3_s
			// 
			this->label_4_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_4_k3_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_4_k3_s->Location = System::Drawing::Point(57, 5);
			this->label_4_k3_s->Name = L"label_4_k3_s";
			this->label_4_k3_s->Size = System::Drawing::Size(20, 20);
			this->label_4_k3_s->TabIndex = 13;
			this->label_4_k3_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label155
			// 
			this->label155->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label155->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label155->Location = System::Drawing::Point(111, 20);
			this->label155->Name = L"label155";
			this->label155->Size = System::Drawing::Size(20, 20);
			this->label155->TabIndex = 12;
			this->label155->Text = L"К2";
			this->label155->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label156
			// 
			this->label156->AutoSize = true;
			this->label156->Location = System::Drawing::Point(2, 53);
			this->label156->Name = L"label156";
			this->label156->Size = System::Drawing::Size(74, 13);
			this->label156->TabIndex = 25;
			this->label156->Text = L"Исправность";
			// 
			// label157
			// 
			this->label157->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label157->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label157->Location = System::Drawing::Point(137, 20);
			this->label157->Name = L"label157";
			this->label157->Size = System::Drawing::Size(20, 20);
			this->label157->TabIndex = 14;
			this->label157->Text = L"К3";
			this->label157->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label158
			// 
			this->label158->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label158->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label158->Location = System::Drawing::Point(267, 20);
			this->label158->Name = L"label158";
			this->label158->Size = System::Drawing::Size(20, 20);
			this->label158->TabIndex = 24;
			this->label158->Text = L"К8";
			this->label158->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label159
			// 
			this->label159->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label159->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label159->Location = System::Drawing::Point(163, 20);
			this->label159->Name = L"label159";
			this->label159->Size = System::Drawing::Size(20, 20);
			this->label159->TabIndex = 16;
			this->label159->Text = L"К4";
			this->label159->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label160
			// 
			this->label160->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label160->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label160->Location = System::Drawing::Point(241, 20);
			this->label160->Name = L"label160";
			this->label160->Size = System::Drawing::Size(20, 20);
			this->label160->TabIndex = 22;
			this->label160->Text = L"К7";
			this->label160->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label161
			// 
			this->label161->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label161->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label161->Location = System::Drawing::Point(189, 20);
			this->label161->Name = L"label161";
			this->label161->Size = System::Drawing::Size(20, 20);
			this->label161->TabIndex = 18;
			this->label161->Text = L"К5";
			this->label161->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label162
			// 
			this->label162->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label162->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label162->Location = System::Drawing::Point(215, 20);
			this->label162->Name = L"label162";
			this->label162->Size = System::Drawing::Size(20, 20);
			this->label162->TabIndex = 20;
			this->label162->Text = L"К6";
			this->label162->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel121
			// 
			this->panel121->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel121->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel121->Controls->Add(this->label100);
			this->panel121->Controls->Add(this->panel122);
			this->panel121->Controls->Add(this->label110);
			this->panel121->Controls->Add(this->label111);
			this->panel121->Controls->Add(this->panel123);
			this->panel121->Controls->Add(this->label112);
			this->panel121->Controls->Add(this->label113);
			this->panel121->Controls->Add(this->label114);
			this->panel121->Controls->Add(this->label115);
			this->panel121->Controls->Add(this->label116);
			this->panel121->Controls->Add(this->label117);
			this->panel121->Controls->Add(this->label120);
			this->panel121->Controls->Add(this->label121);
			this->panel121->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel121->Enabled = false;
			this->panel121->Location = System::Drawing::Point(269, 281);
			this->panel121->Name = L"panel121";
			this->panel121->Size = System::Drawing::Size(304, 124);
			this->panel121->TabIndex = 98;
			// 
			// label100
			// 
			this->label100->AutoSize = true;
			this->label100->Location = System::Drawing::Point(128, 3);
			this->label100->Name = L"label100";
			this->label100->Size = System::Drawing::Size(58, 13);
			this->label100->TabIndex = 28;
			this->label100->Text = L"Плата №3";
			// 
			// panel122
			// 
			this->panel122->BackColor = System::Drawing::Color::White;
			this->panel122->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel122->Controls->Add(this->label_3_k8_i);
			this->panel122->Controls->Add(this->label_3_k7_i);
			this->panel122->Controls->Add(this->label_3_k6_i);
			this->panel122->Controls->Add(this->label_3_k5_i);
			this->panel122->Controls->Add(this->label_3_k4_i);
			this->panel122->Controls->Add(this->label_3_k2_i);
			this->panel122->Controls->Add(this->label_3_k1_i);
			this->panel122->Controls->Add(this->label_3_k3_i);
			this->panel122->Location = System::Drawing::Point(79, 43);
			this->panel122->Name = L"panel122";
			this->panel122->Size = System::Drawing::Size(216, 33);
			this->panel122->TabIndex = 0;
			// 
			// label_3_k8_i
			// 
			this->label_3_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k8_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k8_i->Location = System::Drawing::Point(187, 5);
			this->label_3_k8_i->Name = L"label_3_k8_i";
			this->label_3_k8_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k8_i->TabIndex = 23;
			this->label_3_k8_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k7_i
			// 
			this->label_3_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k7_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k7_i->Location = System::Drawing::Point(161, 5);
			this->label_3_k7_i->Name = L"label_3_k7_i";
			this->label_3_k7_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k7_i->TabIndex = 21;
			this->label_3_k7_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k6_i
			// 
			this->label_3_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k6_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k6_i->Location = System::Drawing::Point(135, 5);
			this->label_3_k6_i->Name = L"label_3_k6_i";
			this->label_3_k6_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k6_i->TabIndex = 19;
			this->label_3_k6_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k5_i
			// 
			this->label_3_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k5_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k5_i->Location = System::Drawing::Point(109, 5);
			this->label_3_k5_i->Name = L"label_3_k5_i";
			this->label_3_k5_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k5_i->TabIndex = 17;
			this->label_3_k5_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k4_i
			// 
			this->label_3_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k4_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k4_i->Location = System::Drawing::Point(83, 5);
			this->label_3_k4_i->Name = L"label_3_k4_i";
			this->label_3_k4_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k4_i->TabIndex = 15;
			this->label_3_k4_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k2_i
			// 
			this->label_3_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k2_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k2_i->Location = System::Drawing::Point(31, 5);
			this->label_3_k2_i->Name = L"label_3_k2_i";
			this->label_3_k2_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k2_i->TabIndex = 11;
			this->label_3_k2_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k1_i
			// 
			this->label_3_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k1_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k1_i->Location = System::Drawing::Point(5, 5);
			this->label_3_k1_i->Name = L"label_3_k1_i";
			this->label_3_k1_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k1_i->TabIndex = 9;
			this->label_3_k1_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k3_i
			// 
			this->label_3_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k3_i->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k3_i->Location = System::Drawing::Point(57, 5);
			this->label_3_k3_i->Name = L"label_3_k3_i";
			this->label_3_k3_i->Size = System::Drawing::Size(20, 20);
			this->label_3_k3_i->TabIndex = 13;
			this->label_3_k3_i->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->Location = System::Drawing::Point(2, 92);
			this->label110->Name = L"label110";
			this->label110->Size = System::Drawing::Size(61, 13);
			this->label110->TabIndex = 27;
			this->label110->Text = L"Состояние";
			// 
			// label111
			// 
			this->label111->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label111->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label111->Location = System::Drawing::Point(85, 20);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(20, 20);
			this->label111->TabIndex = 10;
			this->label111->Text = L"К1";
			this->label111->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel123
			// 
			this->panel123->BackColor = System::Drawing::Color::White;
			this->panel123->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel123->Controls->Add(this->label_3_k8_s);
			this->panel123->Controls->Add(this->label_3_k7_s);
			this->panel123->Controls->Add(this->label_3_k6_s);
			this->panel123->Controls->Add(this->label_3_k5_s);
			this->panel123->Controls->Add(this->label_3_k4_s);
			this->panel123->Controls->Add(this->label_3_k2_s);
			this->panel123->Controls->Add(this->label_3_k1_s);
			this->panel123->Controls->Add(this->label_3_k3_s);
			this->panel123->Location = System::Drawing::Point(79, 82);
			this->panel123->Name = L"panel123";
			this->panel123->Size = System::Drawing::Size(216, 33);
			this->panel123->TabIndex = 26;
			// 
			// label_3_k8_s
			// 
			this->label_3_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k8_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k8_s->Location = System::Drawing::Point(187, 5);
			this->label_3_k8_s->Name = L"label_3_k8_s";
			this->label_3_k8_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k8_s->TabIndex = 23;
			this->label_3_k8_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k7_s
			// 
			this->label_3_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k7_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k7_s->Location = System::Drawing::Point(161, 5);
			this->label_3_k7_s->Name = L"label_3_k7_s";
			this->label_3_k7_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k7_s->TabIndex = 21;
			this->label_3_k7_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k6_s
			// 
			this->label_3_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k6_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k6_s->Location = System::Drawing::Point(135, 5);
			this->label_3_k6_s->Name = L"label_3_k6_s";
			this->label_3_k6_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k6_s->TabIndex = 19;
			this->label_3_k6_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k5_s
			// 
			this->label_3_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k5_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k5_s->Location = System::Drawing::Point(109, 5);
			this->label_3_k5_s->Name = L"label_3_k5_s";
			this->label_3_k5_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k5_s->TabIndex = 17;
			this->label_3_k5_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k4_s
			// 
			this->label_3_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k4_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k4_s->Location = System::Drawing::Point(83, 5);
			this->label_3_k4_s->Name = L"label_3_k4_s";
			this->label_3_k4_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k4_s->TabIndex = 15;
			this->label_3_k4_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k2_s
			// 
			this->label_3_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k2_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k2_s->Location = System::Drawing::Point(31, 5);
			this->label_3_k2_s->Name = L"label_3_k2_s";
			this->label_3_k2_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k2_s->TabIndex = 11;
			this->label_3_k2_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k1_s
			// 
			this->label_3_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k1_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k1_s->Location = System::Drawing::Point(5, 5);
			this->label_3_k1_s->Name = L"label_3_k1_s";
			this->label_3_k1_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k1_s->TabIndex = 9;
			this->label_3_k1_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_3_k3_s
			// 
			this->label_3_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
			this->label_3_k3_s->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_3_k3_s->Location = System::Drawing::Point(57, 5);
			this->label_3_k3_s->Name = L"label_3_k3_s";
			this->label_3_k3_s->Size = System::Drawing::Size(20, 20);
			this->label_3_k3_s->TabIndex = 13;
			this->label_3_k3_s->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label112
			// 
			this->label112->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label112->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label112->Location = System::Drawing::Point(111, 20);
			this->label112->Name = L"label112";
			this->label112->Size = System::Drawing::Size(20, 20);
			this->label112->TabIndex = 12;
			this->label112->Text = L"К2";
			this->label112->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label113
			// 
			this->label113->AutoSize = true;
			this->label113->Location = System::Drawing::Point(2, 53);
			this->label113->Name = L"label113";
			this->label113->Size = System::Drawing::Size(74, 13);
			this->label113->TabIndex = 25;
			this->label113->Text = L"Исправность";
			// 
			// label114
			// 
			this->label114->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label114->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label114->Location = System::Drawing::Point(137, 20);
			this->label114->Name = L"label114";
			this->label114->Size = System::Drawing::Size(20, 20);
			this->label114->TabIndex = 14;
			this->label114->Text = L"К3";
			this->label114->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label115
			// 
			this->label115->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label115->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label115->Location = System::Drawing::Point(267, 20);
			this->label115->Name = L"label115";
			this->label115->Size = System::Drawing::Size(20, 20);
			this->label115->TabIndex = 24;
			this->label115->Text = L"К8";
			this->label115->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label116
			// 
			this->label116->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label116->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label116->Location = System::Drawing::Point(163, 20);
			this->label116->Name = L"label116";
			this->label116->Size = System::Drawing::Size(20, 20);
			this->label116->TabIndex = 16;
			this->label116->Text = L"К4";
			this->label116->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label117
			// 
			this->label117->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label117->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label117->Location = System::Drawing::Point(241, 20);
			this->label117->Name = L"label117";
			this->label117->Size = System::Drawing::Size(20, 20);
			this->label117->TabIndex = 22;
			this->label117->Text = L"К7";
			this->label117->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label120
			// 
			this->label120->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label120->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label120->Location = System::Drawing::Point(189, 20);
			this->label120->Name = L"label120";
			this->label120->Size = System::Drawing::Size(20, 20);
			this->label120->TabIndex = 18;
			this->label120->Text = L"К5";
			this->label120->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label121
			// 
			this->label121->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label121->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label121->Location = System::Drawing::Point(215, 20);
			this->label121->Name = L"label121";
			this->label121->Size = System::Drawing::Size(20, 20);
			this->label121->TabIndex = 20;
			this->label121->Text = L"К6";
			this->label121->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form_main::timer1_Tick);
			// 
			// panel130
			// 
			this->panel130->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel130->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel130->Controls->Add(this->label_time_program);
			this->panel130->Controls->Add(this->label3);
			this->panel130->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel130->Location = System::Drawing::Point(0, 865);
			this->panel130->Margin = System::Windows::Forms::Padding(1);
			this->panel130->Name = L"panel130";
			this->panel130->Size = System::Drawing::Size(1175, 28);
			this->panel130->TabIndex = 85;
			// 
			// label_time_program
			// 
			this->label_time_program->AutoSize = true;
			this->label_time_program->Location = System::Drawing::Point(157, 5);
			this->label_time_program->Name = L"label_time_program";
			this->label_time_program->Size = System::Drawing::Size(98, 13);
			this->label_time_program->TabIndex = 3;
			this->label_time_program->Text = L"label_time_program";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &Form_main::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 10;
			this->timer3->Tick += gcnew System::EventHandler(this, &Form_main::timer3_Tick);
			// 
			// Form_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(1175, 893);
			this->Controls->Add(this->panel130);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Location = System::Drawing::Point(50, 50);
			this->MaximizeBox = false;
			this->Name = L"Form_main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"РУ-7000НС";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form_main::Form_main_FormClosing);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->panel45->ResumeLayout(false);
			this->panel45->PerformLayout();
			this->panel46->ResumeLayout(false);
			this->panel47->ResumeLayout(false);
			this->panel48->ResumeLayout(false);
			this->panel49->ResumeLayout(false);
			this->panel50->ResumeLayout(false);
			this->panel51->ResumeLayout(false);
			this->panel52->ResumeLayout(false);
			this->panel53->ResumeLayout(false);
			this->panel54->ResumeLayout(false);
			this->panel55->ResumeLayout(false);
			this->panel56->ResumeLayout(false);
			this->panel56->PerformLayout();
			this->panel57->ResumeLayout(false);
			this->panel58->ResumeLayout(false);
			this->panel59->ResumeLayout(false);
			this->panel60->ResumeLayout(false);
			this->panel61->ResumeLayout(false);
			this->panel62->ResumeLayout(false);
			this->panel63->ResumeLayout(false);
			this->panel64->ResumeLayout(false);
			this->panel65->ResumeLayout(false);
			this->panel66->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel14->ResumeLayout(false);
			this->panel15->ResumeLayout(false);
			this->panel16->ResumeLayout(false);
			this->panel17->ResumeLayout(false);
			this->panel18->ResumeLayout(false);
			this->panel19->ResumeLayout(false);
			this->panel20->ResumeLayout(false);
			this->panel21->ResumeLayout(false);
			this->panel22->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->panel71->ResumeLayout(false);
			this->panel71->PerformLayout();
			this->panel72->ResumeLayout(false);
			this->panel73->ResumeLayout(false);
			this->panel67->ResumeLayout(false);
			this->panel67->PerformLayout();
			this->panel68->ResumeLayout(false);
			this->panel69->ResumeLayout(false);
			this->panel42->ResumeLayout(false);
			this->panel42->PerformLayout();
			this->panel43->ResumeLayout(false);
			this->panel44->ResumeLayout(false);
			this->panel39->ResumeLayout(false);
			this->panel39->PerformLayout();
			this->panel40->ResumeLayout(false);
			this->panel41->ResumeLayout(false);
			this->panel36->ResumeLayout(false);
			this->panel36->PerformLayout();
			this->panel38->ResumeLayout(false);
			this->panel37->ResumeLayout(false);
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->panel24->ResumeLayout(false);
			this->panel25->ResumeLayout(false);
			this->panel26->ResumeLayout(false);
			this->panel27->ResumeLayout(false);
			this->panel28->ResumeLayout(false);
			this->panel29->ResumeLayout(false);
			this->panel30->ResumeLayout(false);
			this->panel31->ResumeLayout(false);
			this->panel32->ResumeLayout(false);
			this->panel33->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->panel131->ResumeLayout(false);
			this->panel131->PerformLayout();
			this->panel148->ResumeLayout(false);
			this->panel148->PerformLayout();
			this->panel147->ResumeLayout(false);
			this->panel147->PerformLayout();
			this->panel132->ResumeLayout(false);
			this->panel132->PerformLayout();
			this->panel145->ResumeLayout(false);
			this->panel145->PerformLayout();
			this->panel70->ResumeLayout(false);
			this->panel142->ResumeLayout(false);
			this->panel142->PerformLayout();
			this->panel140->ResumeLayout(false);
			this->panel143->ResumeLayout(false);
			this->panel139->ResumeLayout(false);
			this->panel139->PerformLayout();
			this->panel34->ResumeLayout(false);
			this->panel35->ResumeLayout(false);
			this->panel136->ResumeLayout(false);
			this->panel136->PerformLayout();
			this->panel137->ResumeLayout(false);
			this->panel138->ResumeLayout(false);
			this->panel133->ResumeLayout(false);
			this->panel133->PerformLayout();
			this->panel134->ResumeLayout(false);
			this->panel135->ResumeLayout(false);
			this->panel127->ResumeLayout(false);
			this->panel127->PerformLayout();
			this->panel128->ResumeLayout(false);
			this->panel129->ResumeLayout(false);
			this->panel115->ResumeLayout(false);
			this->panel115->PerformLayout();
			this->panel116->ResumeLayout(false);
			this->panel117->ResumeLayout(false);
			this->panel124->ResumeLayout(false);
			this->panel124->PerformLayout();
			this->panel125->ResumeLayout(false);
			this->panel126->ResumeLayout(false);
			this->panel118->ResumeLayout(false);
			this->panel118->PerformLayout();
			this->panel119->ResumeLayout(false);
			this->panel120->ResumeLayout(false);
			this->panel121->ResumeLayout(false);
			this->panel121->PerformLayout();
			this->panel122->ResumeLayout(false);
			this->panel123->ResumeLayout(false);
			this->panel130->ResumeLayout(false);
			this->panel130->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		count_Devices = MB26_20_GetNumberOfDevices();

		if (count_Devices >= 0)
		{
			this->label1_1_2->Text = count_Devices.ToString();
			for (int count = 1; count <= count_Devices; count++)
			{
				this->comboBox1->Items->Add("Модуль МВ26.20 №" + count.ToString());
			}
			this->button2->Enabled = true;
			this->comboBox1->Enabled = true;
			this->comboBox1->SelectedIndex = 0;
			Log_File_Write_Count_Dev_MB26_20(count_Devices);
		}
		else
		{
			this->label1_1_2->Text = "0";
			Log_File_Write_Count_Dev_MB26_20(0);
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		IndexDevices = comboBox1->SelectedIndex;

		if (MB26_20_Open(IndexDevices))
		{
			this->label1_2_2->Text = "Установлено";
			Log_File_Write_Text("Связь с модулем МВ26.20 установлена");
			this->button3->Enabled = true;
			this->button4->Enabled = true;

			this->comboBox2->Enabled = true;
			this->comboBox3->Enabled = true;

			Panel_Pin_Enable(true);

			MB26_20_MODE_BC();
		}
		else
		{
			this->label1_2_2->Text = "Не установлено";
			Log_File_Write_Text("Связь с модулем МВ26.20 не установлена");
		}
	}

	private: System::Void button_pow_cel_nag_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button_pow_cel_nag) button_pow_cel_nag->BackColor = SystemColors::WindowText;
		else button_pow_cel_nag->BackColor = SystemColors::Control;

		buf_format_1[1] ^= (1 << 0);
		MKIO_Handler();

		push_button_pow_cel_nag = !push_button_pow_cel_nag;
	}

	private: System::Void button_pow_bat_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button_pow_bat) button_pow_bat->BackColor = SystemColors::WindowText;
		else button_pow_bat->BackColor = SystemColors::Control;

		buf_format_1[1] ^= (1 << 1);
		MKIO_Handler();

		push_button_pow_bat = !push_button_pow_bat;
	}

	private: System::Void button_launch_aircraft_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button_launch_aircraft) button_launch_aircraft->BackColor = SystemColors::WindowText;
		else button_launch_aircraft->BackColor = SystemColors::Control;

		buf_format_1[1] ^= (1 << 2);
		MKIO_Handler();

		push_button_launch_aircraft = !push_button_launch_aircraft;
	}

	private: System::Void button_aircraft_air_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button_aircraft_air) button_aircraft_air->BackColor = SystemColors::WindowText;
		else button_aircraft_air->BackColor = SystemColors::Control;

		buf_format_1[1] ^= (1 << 3);
		MKIO_Handler();

		push_button_aircraft_air = !push_button_aircraft_air;
	}

	private: System::Void button_all_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button_all)
		{
			button_all->BackColor = SystemColors::WindowText;
			buf_format_1[2] = 0xFF;
			buf_format_1[3] = 0xFF;
			buf_format_1[4] = 0x7F;
		}
		else
		{
			button_all->BackColor = SystemColors::Control;
			buf_format_1[2] = 0x00;
			buf_format_1[3] = 0x00;
			buf_format_1[4] = 0x00;
		}

		MKIO_Handler();

		push_button_all = !push_button_all;
	}

	private: System::Void button6_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_1) button6_1->BackColor = SystemColors::WindowText;
		else button6_1->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 0);
		MKIO_Handler();

		push_button6_1 = !push_button6_1;
	}
	private: System::Void button6_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_2) button6_2->BackColor = SystemColors::WindowText;
		else button6_2->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 1);
		MKIO_Handler();

		push_button6_2 = !push_button6_2;
	}
	private: System::Void button6_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_3) button6_3->BackColor = SystemColors::WindowText;
		else button6_3->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 2);
		MKIO_Handler();

		push_button6_3 = !push_button6_3;
	}
	private: System::Void button6_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_4) button6_4->BackColor = SystemColors::WindowText;
		else button6_4->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 3);
		MKIO_Handler();

		push_button6_4 = !push_button6_4;
	}
	private: System::Void button6_5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_5) button6_5->BackColor = SystemColors::WindowText;
		else button6_5->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 4);
		MKIO_Handler();

		push_button6_5 = !push_button6_5;
	}
	private: System::Void button6_6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_6) button6_6->BackColor = SystemColors::WindowText;
		else button6_6->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 5);
		MKIO_Handler();

		push_button6_6 = !push_button6_6;
	}
	private: System::Void button6_7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_7) button6_7->BackColor = SystemColors::WindowText;
		else button6_7->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 6);
		MKIO_Handler();

		push_button6_7 = !push_button6_7;
	}
	private: System::Void button6_8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button6_8) button6_8->BackColor = SystemColors::WindowText;
		else button6_8->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 7);
		MKIO_Handler();

		push_button6_8 = !push_button6_8;
	}
	private: System::Void button7_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_1) button7_1->BackColor = SystemColors::WindowText;
		else button7_1->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 8);
		MKIO_Handler();

		push_button7_1 = !push_button7_1;
	}
	private: System::Void button7_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_2) button7_2->BackColor = SystemColors::WindowText;
		else button7_2->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 9);
		MKIO_Handler();

		push_button7_2 = !push_button7_2;
	}
	private: System::Void button7_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_3) button7_3->BackColor = SystemColors::WindowText;
		else button7_3->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 10);
		MKIO_Handler();

		push_button7_3 = !push_button7_3;
	}
	private: System::Void button7_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_4) button7_4->BackColor = SystemColors::WindowText;
		else button7_4->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 11);
		MKIO_Handler();

		push_button7_4 = !push_button7_4;
	}
	private: System::Void button7_5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_5) button7_5->BackColor = SystemColors::WindowText;
		else button7_5->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 12);
		MKIO_Handler();

		push_button7_5 = !push_button7_5;
	}
	private: System::Void button7_6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_6) button7_6->BackColor = SystemColors::WindowText;
		else button7_6->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 13);
		MKIO_Handler();

		push_button7_6 = !push_button7_6;
	}
	private: System::Void button7_7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_7) button7_7->BackColor = SystemColors::WindowText;
		else button7_7->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 14);
		MKIO_Handler();

		push_button7_7 = !push_button7_7;
	}
	private: System::Void button7_8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button7_8) button7_8->BackColor = SystemColors::WindowText;
		else button7_8->BackColor = SystemColors::Control;

		buf_format_1[2] ^= (1 << 15);
		MKIO_Handler();

		push_button7_8 = !push_button7_8;
	}
	private: System::Void button8_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_1) button8_1->BackColor = SystemColors::WindowText;
		else button8_1->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 0);
		MKIO_Handler();

		push_button8_1 = !push_button8_1;
	}
	private: System::Void button8_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_2) button8_2->BackColor = SystemColors::WindowText;
		else button8_2->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 1);
		MKIO_Handler();

		push_button8_2 = !push_button8_2;
	}
	private: System::Void button8_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_3) button8_3->BackColor = SystemColors::WindowText;
		else button8_3->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 2);
		MKIO_Handler();

		push_button8_3 = !push_button8_3;
	}
	private: System::Void button8_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_4) button8_4->BackColor = SystemColors::WindowText;
		else button8_4->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 3);
		MKIO_Handler();

		push_button8_4 = !push_button8_4;
	}
	private: System::Void button8_5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_5) button8_5->BackColor = SystemColors::WindowText;
		else button8_5->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 4);
		MKIO_Handler();

		push_button8_5 = !push_button8_5;
	}
	private: System::Void button8_6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_6) button8_6->BackColor = SystemColors::WindowText;
		else button8_6->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 5);
		MKIO_Handler();

		push_button8_6 = !push_button8_6;
	}
	private: System::Void button8_7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_7) button8_7->BackColor = SystemColors::WindowText;
		else button8_7->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 6);
		MKIO_Handler();

		push_button8_7 = !push_button8_7;
	}
	private: System::Void button8_8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button8_8) button8_8->BackColor = SystemColors::WindowText;
		else button8_8->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 7);
		MKIO_Handler();

		push_button8_8 = !push_button8_8;
	}
	private: System::Void button9_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_1) button9_1->BackColor = SystemColors::WindowText;
		else button9_1->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 8);
		MKIO_Handler();

		push_button9_1 = !push_button9_1;
	}
	private: System::Void button9_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_2) button9_2->BackColor = SystemColors::WindowText;
		else button9_2->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 9);
		MKIO_Handler();

		push_button9_2 = !push_button9_2;
	}
	private: System::Void button9_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_3) button9_3->BackColor = SystemColors::WindowText;
		else button9_3->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 10);
		MKIO_Handler();

		push_button9_3 = !push_button9_3;
	}
	private: System::Void button9_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_4) button9_4->BackColor = SystemColors::WindowText;
		else button9_4->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 11);
		MKIO_Handler();

		push_button9_4 = !push_button9_4;
	}
	private: System::Void button9_5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_5) button9_5->BackColor = SystemColors::WindowText;
		else button9_5->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 12);
		MKIO_Handler();

		push_button9_5 = !push_button9_5;
	}
	private: System::Void button9_6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_6) button9_6->BackColor = SystemColors::WindowText;
		else button9_6->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 13);
		MKIO_Handler();

		push_button9_6 = !push_button9_6;
	}
	private: System::Void button9_7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_7) button9_7->BackColor = SystemColors::WindowText;
		else button9_7->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 14);
		MKIO_Handler();

		push_button9_7 = !push_button9_7;
	}
	private: System::Void button9_8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button9_8) button9_8->BackColor = SystemColors::WindowText;
		else button9_8->BackColor = SystemColors::Control;

		buf_format_1[3] ^= (1 << 15);
		MKIO_Handler();

		push_button9_8 = !push_button9_8;
	}
	private: System::Void button10_1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_1) button10_1->BackColor = SystemColors::WindowText;
		else button10_1->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 0);
		MKIO_Handler();

		push_button10_1 = !push_button10_1;
	}
	private: System::Void button10_2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_2) button10_2->BackColor = SystemColors::WindowText;
		else button10_2->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 1);
		MKIO_Handler();

		push_button10_2 = !push_button10_2;
	}
	private: System::Void button10_3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_3) button10_3->BackColor = SystemColors::WindowText;
		else button10_3->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 2);
		MKIO_Handler();

		push_button10_3 = !push_button10_3;
	}
	private: System::Void button10_4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_4) button10_4->BackColor = SystemColors::WindowText;
		else button10_4->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 3);
		MKIO_Handler();

		push_button10_4 = !push_button10_4;
	}
	private: System::Void button10_5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_5) button10_5->BackColor = SystemColors::WindowText;
		else button10_5->BackColor = SystemColors::Control;

		buf_format_1[4] |= (1 << 4);
		MKIO_Handler();

		push_button10_5 = !push_button10_5;
	}
	private: System::Void button10_6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_6) button10_6->BackColor = SystemColors::WindowText;
		else button10_6->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 5);
		MKIO_Handler();

		push_button10_6 = !push_button10_6;
	}
	private: System::Void button10_7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_7) button10_7->BackColor = SystemColors::WindowText;
		else button10_7->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 6);
		MKIO_Handler();

		push_button10_7 = !push_button10_7;
	}
	private: System::Void button10_8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (push_button10_8) button10_8->BackColor = SystemColors::WindowText;

		else button10_8->BackColor = SystemColors::Control;

		buf_format_1[4] ^= (1 << 7);
		MKIO_Handler();

		push_button10_8 = !push_button10_8;
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Start_button_q)
		{
			switch (comboBox2->SelectedIndex)
			{
				case 0: N_Chanel = CHANEL_A; break;
				case 1: N_Chanel = CHANEL_B; break;
			}

			addres = comboBox3->SelectedIndex;

			this->button1->Enabled = false;
			this->button2->Enabled = false;
			this->button4->Enabled = false;
			this->comboBox2->Enabled = false;
			this->comboBox3->Enabled = false;

			Log_File_Write_Start(N_Chanel, addres);

			timer1->Enabled = true;
			timer1->Start();

			MB26_20_Send_Format_2(N_Chanel + AUTOREPEAT, addres, 1, 11);

			Log_File_Write_Text("КШ Ф2 ПА: 1");

			button3->Text = "Стоп";

			Start_button_q = false;

			flag_connect = true;
		}
		else
		{
			push_stop = true;
			MB26_20_StopTranslate();

			timer1->Stop();
			timer1->Enabled = false;

			MB26_20_EraseRam();

			Start_button_q = true;
			button3->Text = "Пуск";
			Log_File_Write_Text("Стоп обмена МКИО.");
			this->label_stat_connect->Text = " ";
			this->button1->Enabled = true;
			this->button2->Enabled = true;
			this->button4->Enabled = true;
			this->comboBox2->Enabled = true;
			this->comboBox3->Enabled = true;
			Button_Pin_Enable(false);

			Drop_Button();
			Drop_Label();
		}
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

		button1->Enabled = false;
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;

		switch (comboBox2->SelectedIndex)
		{
		case 0: N_Chanel = CHANEL_A; break;
		case 1: N_Chanel = CHANEL_B; break;
		}

		addres = comboBox3->SelectedIndex;

		buf_format_1[1] = 0xAAAA;
		buf_format_1[2] = 0xBBBB;
		buf_format_1[3] = 0xCCCC;
		buf_format_1[4] = 0xDDDD;
		buf_format_1[5] = 0xEEEE;

		label_f1->Text = buf_format_1[0].ToString();

		timer3->Enabled = true;
		timer3->Start();

		Log_File_Write_Text("Тест ОУ");

		//MB26_20_Send_Format_1(N_Chanel, addres, 30, buf_format_1);

		MB26_20_Test_RT_Send(N_Chanel, addres, buf_format_1);

		Log_File_Write_BC_Test_RT_F1(buf_format_1);

		//MB26_20_StopTranslate();
		//MB26_20_EraseRam();

		//MB26_20_Send_Format_2(N_Chanel, addres, 30, 6);
		//MB26_20_StopTranslate();
		//MB26_20_EraseRam();
		Log_File_Write_Text("КШ Ф2 ПА: 30");
	}


	int _delay = 0;

	private: void MKIO_Handler(void)
	{
		Button_Pin_Enable(false);

		MB26_20_StopTranslate();
		push_stop = true;

		timer1->Stop();
		MB26_20_EraseRam();

		label_f1->Text = buf_format_1[0].ToString();

		buf_format_1[5] = CRC16(buf_format_1, 4);

		MB26_20_Send_Format_1(N_Chanel, addres, 0x01, buf_format_1);

		Log_File_Write_BC_F1(0x01, buf_format_1);

		buf_format_1[0]++;
		if (buf_format_1[0] == 0x100) buf_format_1[0] = 0x0000;


		MB26_20_StopTranslate();
		MB26_20_EraseRam();
		MB26_20_Send_Format_2(N_Chanel + AUTOREPEAT, addres, 1, 11);
		timer1->Start();
		Log_File_Write_Text("КШ Ф2 ПА: 1");

		Button_Pin_Enable(true);

		_delay = 3;
	}

	static bool push_stop = false;
	static bool flag_connect = true;

	static bool flag_disconnect = false;

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		timer1->Stop();

		if (_delay) _delay--;

		if (MB26_20_Receive_Format_2(&IPack))
		{
			if (IPack.dataWordCount)
			{
				Log_File_Write_RT(&IPack);

				if (last_number_pack == IPack.Data[0])
				{
					count_bad_pack++;
					label_count_bad_pack->Text = count_bad_pack.ToString();
					Log_File_Write_Count_Bad_Pack(count_bad_pack);
				}
				else
				{
					last_number_pack = IPack.Data[0];

					if (CRC16(IPack.Data, 9) == IPack.Data[10])
					{
						if (flag_connect)
						{
							flag_connect = false;
							label_stat_connect->Text = "Установлено";
							Log_File_Write_Text("Соединение с ОУ установлено");
							Button_Pin_Enable(true);
							if (flag_disconnect) MKIO_Handler();
							else flag_disconnect = true;
						}
						else if(_delay==0) Print_IPACK();
					}
					else
					{
						count_error_crc16++;
						label_error_crc16->Text = count_error_crc16.ToString();

						Log_File_Error_CRC16(CRC16(IPack.Data, 9));
					}
				}
			}
			else
			{
				flag_connect = true;
				label_stat_connect->Text = "ОУ не отвечает";
				Log_File_Write_Text("ОУ не отвечает");
				
				Button_Pin_Enable(false);
				
				Drop_Label();
			}
		}
		timer1->Start();
	}

	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		TP_sec++;
		if (TP_sec == 60)
		{
			TP_sec = 0;
			TP_min++;
			if (TP_min == 60)
			{
				TP_min = 0;
				TP_hour++;
			}
		}
		this->label_time_program->Text = TP_hour.ToString("D2") + ":" + TP_min.ToString("D2") + ":" + TP_sec.ToString("D2");
	}

	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		timer3->Stop();
		if (MB26_20_Test_RT_Receive(&IPack))
		{
			if (IPack.dataWordCount)
			{
				for (int i = 0; i <= 5; i++) if (buf_format_1[i] == IPack.Data[i]) count_Valid_pack++;

				buf_format_1[0]++;
				if (buf_format_1[0] == 0x100) buf_format_1[0] = 0x0000;

				Log_File_Write_RT(&IPack);

				if (count_Valid_pack == 6)
				{
					label_result_test->Text = "Тест пройден";
					Log_File_Write_Text("ОУ прошел тест");
				}
				else
				{
					label_result_test->Text = "Тест не пройден";
					Log_File_Write_Text("ОУ не прошел тест");
				}

				count_Valid_pack = 0;

				MB26_20_StopTranslate();
				MB26_20_EraseRam();

				button1->Enabled = true;
				button2->Enabled = true;
				button3->Enabled = true;
				button4->Enabled = true;

				timer3->Enabled = false;
			}
		}
		else timer3->Start();
	}


	private: void Drop_Button(void)
	{
		push_button_pow_cel_nag = true;
		push_button_pow_bat = true;
		push_button_launch_aircraft = true;
		push_button_aircraft_air = true;

		push_button_all = true;

		push_button6_1 = true;
		push_button6_2 = true;
		push_button6_3 = true;
		push_button6_4 = true;
		push_button6_5 = true;
		push_button6_6 = true;
		push_button6_7 = true;
		push_button6_8 = true;

		push_button7_1 = true;
		push_button7_2 = true;
		push_button7_3 = true;
		push_button7_4 = true;
		push_button7_5 = true;
		push_button7_6 = true;
		push_button7_7 = true;
		push_button7_8 = true;

		push_button8_1 = true;
		push_button8_2 = true;
		push_button8_3 = true;
		push_button8_4 = true;
		push_button8_5 = true;
		push_button8_6 = true;
		push_button8_7 = true;
		push_button8_8 = true;

		push_button9_1 = true;
		push_button9_2 = true;
		push_button9_3 = true;
		push_button9_4 = true;
		push_button9_5 = true;
		push_button9_6 = true;
		push_button9_7 = true;
		push_button9_8 = true;

		push_button10_1 = true;
		push_button10_2 = true;
		push_button10_3 = true;
		push_button10_4 = true;
		push_button10_5 = true;
		push_button10_6 = true;
		push_button10_7 = true;
		push_button10_8 = true;


		button_pow_cel_nag->BackColor = SystemColors::Control;
		button_pow_bat->BackColor = SystemColors::Control;
		button_launch_aircraft->BackColor = SystemColors::Control;
		button_aircraft_air->BackColor = SystemColors::Control;

		button_all->BackColor = SystemColors::Control;

		button6_1->BackColor = SystemColors::Control;
		button6_2->BackColor = SystemColors::Control;
		button6_3->BackColor = SystemColors::Control;
		button6_4->BackColor = SystemColors::Control;
		button6_5->BackColor = SystemColors::Control;
		button6_6->BackColor = SystemColors::Control;
		button6_7->BackColor = SystemColors::Control;
		button6_8->BackColor = SystemColors::Control;
		button7_1->BackColor = SystemColors::Control;
		button7_2->BackColor = SystemColors::Control;
		button7_3->BackColor = SystemColors::Control;
		button7_4->BackColor = SystemColors::Control;
		button7_5->BackColor = SystemColors::Control;
		button7_6->BackColor = SystemColors::Control;
		button7_7->BackColor = SystemColors::Control;
		button7_8->BackColor = SystemColors::Control;
		button8_1->BackColor = SystemColors::Control;
		button8_2->BackColor = SystemColors::Control;
		button8_3->BackColor = SystemColors::Control;
		button8_4->BackColor = SystemColors::Control;
		button8_5->BackColor = SystemColors::Control;
		button8_6->BackColor = SystemColors::Control;
		button8_7->BackColor = SystemColors::Control;
		button8_8->BackColor = SystemColors::Control;
		button9_1->BackColor = SystemColors::Control;
		button9_2->BackColor = SystemColors::Control;
		button9_3->BackColor = SystemColors::Control;
		button9_4->BackColor = SystemColors::Control;
		button9_5->BackColor = SystemColors::Control;
		button9_6->BackColor = SystemColors::Control;
		button9_7->BackColor = SystemColors::Control;
		button9_8->BackColor = SystemColors::Control;
		button10_1->BackColor = SystemColors::Control;
		button10_2->BackColor = SystemColors::Control;
		button10_3->BackColor = SystemColors::Control;
		button10_4->BackColor = SystemColors::Control;
		button10_5->BackColor = SystemColors::Control;
		button10_6->BackColor = SystemColors::Control;
		button10_7->BackColor = SystemColors::Control;
		button10_8->BackColor = SystemColors::Control;

	}

	private: void Drop_Label(void)
	{
		label_mrp1_i->Text = " ";
		label_mrp2_i->Text = " ";
		label_mrp3_i->Text = " ";
		label_mrp4_i->Text = " ";
		label_mrp5_i->Text = " ";
		label_bat_s->Text = " ";
		label_nip_s->Text = " ";
		label_gen1_i->Text = " ";
		label_gen2_i->Text = " ";
		label_bat_i->Text = " ";
		label_nip_i->Text = " ";
		label_cel_nag_s->Text = " ";
		label_cel_nag_i->Text = " ";

		label_mrp1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_mrp2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_mrp3_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_mrp4_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_mrp5_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_bat_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_nip_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_gen1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_gen2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_bat_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_nip_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_cel_nag_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_cel_nag_i->BackColor = System::Drawing::SystemColors::ControlDark;

		label_1_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;

		label_3_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;

		label_5_k1_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k2_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k3_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k4_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k5_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k6_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k7_i->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k8_i->BackColor = System::Drawing::SystemColors::ControlDark;
		/**************/
		label_1_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_1_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_2_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;

		label_3_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_3_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_4_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;

		label_5_k1_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k2_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k3_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k4_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k5_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k6_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k7_s->BackColor = System::Drawing::SystemColors::ControlDark;
		label_5_k8_s->BackColor = System::Drawing::SystemColors::ControlDark;

		label_U_BAT->Text = " ";
		label_U_SH1->Text = " ";
		label_U_SH2->Text = " ";
	}

	private: void Print_IPACK(void)
	{

		label_f2->Text = IPack.Data[0].ToString();

		if (IPack.Data[1] & (1 << 0))
		{
			label_bat_s->BackColor = System::Drawing::Color::Lime;
			button_pow_bat->BackColor = SystemColors::WindowText;
			push_button_pow_bat = false;
		}
		else
		{
			label_bat_s->BackColor = System::Drawing::Color::Red;
			button_pow_bat->BackColor = SystemColors::Control;
			push_button_pow_bat = true;
		}
		if (IPack.Data[1] & (1 << 1)) label_nip_s->BackColor = System::Drawing::Color::Lime;
		else label_nip_s->BackColor = System::Drawing::Color::Red;
		if (IPack.Data[1] & (1 << 2)) label_cel_nag_s->BackColor = System::Drawing::Color::Lime;
		else label_cel_nag_s->BackColor = System::Drawing::Color::Red;

		if (IPack.Data[1] & (1 << 3)) label_gen1_i->BackColor = System::Drawing::Color::Red;
		else label_gen1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 4)) label_gen2_i->BackColor = System::Drawing::Color::Red;
		else label_gen2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 5)) label_bat_i->BackColor = System::Drawing::Color::Red;
		else label_bat_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 6)) label_nip_i->BackColor = System::Drawing::Color::Red;
		else label_nip_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 7)) label_cel_nag_i->BackColor = System::Drawing::Color::Red;
		else label_cel_nag_i->BackColor = System::Drawing::Color::Lime;

		if (IPack.Data[1] & (1 << 8)) label_mrp1_i->BackColor = System::Drawing::Color::Red;
		else label_mrp1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 9)) label_mrp2_i->BackColor = System::Drawing::Color::Red;
		else label_mrp2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 10)) label_mrp3_i->BackColor = System::Drawing::Color::Red;
		else label_mrp3_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 11)) label_mrp4_i->BackColor = System::Drawing::Color::Red;
		else label_mrp4_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[1] & (1 << 12)) label_mrp5_i->BackColor = System::Drawing::Color::Red;
		else label_mrp5_i->BackColor = System::Drawing::Color::Lime;

		label_U_BAT->Text = (IPack.Data[2] & 0xFF) + "." + ((IPack.Data[2] & 0xFF00) >> 8) + " B";
		label_U_SH1->Text = (IPack.Data[3] & 0xFF) + "." + ((IPack.Data[3] & 0xFF00) >> 8) + " B";
		label_U_SH2->Text = (IPack.Data[4] & 0xFF) + "." + ((IPack.Data[4] & 0xFF00) >> 8) + " B";

		//платы
		if (IPack.Data[5] & (1 << 8)) label_1_k1_i->BackColor = System::Drawing::Color::Red;
		else label_1_k1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 9)) label_1_k2_i->BackColor = System::Drawing::Color::Red;
		else label_1_k2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 10)) label_1_k3_i->BackColor = System::Drawing::Color::Red;
		else label_1_k3_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 11)) label_1_k4_i->BackColor = System::Drawing::Color::Red;
		else label_1_k4_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 12)) label_1_k5_i->BackColor = System::Drawing::Color::Red;
		else label_1_k5_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 13)) label_1_k6_i->BackColor = System::Drawing::Color::Red;
		else label_1_k6_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 14)) label_1_k7_i->BackColor = System::Drawing::Color::Red;
		else label_1_k7_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[5] & (1 << 15)) label_1_k8_i->BackColor = System::Drawing::Color::Red;
		else label_1_k8_i->BackColor = System::Drawing::Color::Lime;

		if (IPack.Data[6] & (1 << 8)) label_2_k1_i->BackColor = System::Drawing::Color::Red;
		else label_2_k1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 9)) label_2_k2_i->BackColor = System::Drawing::Color::Red;
		else label_2_k2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 10)) label_2_k3_i->BackColor = System::Drawing::Color::Red;
		else label_2_k3_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 11)) label_2_k4_i->BackColor = System::Drawing::Color::Red;
		else label_2_k4_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 12)) label_2_k5_i->BackColor = System::Drawing::Color::Red;
		else label_2_k5_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 13)) label_2_k6_i->BackColor = System::Drawing::Color::Red;
		else label_2_k6_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 14)) label_2_k7_i->BackColor = System::Drawing::Color::Red;
		else label_2_k7_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[6] & (1 << 15)) label_2_k8_i->BackColor = System::Drawing::Color::Red;
		else label_2_k8_i->BackColor = System::Drawing::Color::Lime;

		if (IPack.Data[7] & (1 << 8)) label_3_k1_i->BackColor = System::Drawing::Color::Red;
		else label_3_k1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 9)) label_3_k2_i->BackColor = System::Drawing::Color::Red;
		else label_3_k2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 10)) label_3_k3_i->BackColor = System::Drawing::Color::Red;
		else label_3_k3_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 11)) label_3_k4_i->BackColor = System::Drawing::Color::Red;
		else label_3_k4_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 12)) label_3_k5_i->BackColor = System::Drawing::Color::Red;
		else label_3_k5_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 13)) label_3_k6_i->BackColor = System::Drawing::Color::Red;
		else label_3_k6_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 14)) label_3_k7_i->BackColor = System::Drawing::Color::Red;
		else label_3_k7_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[7] & (1 << 15)) label_3_k8_i->BackColor = System::Drawing::Color::Red;
		else label_3_k8_i->BackColor = System::Drawing::Color::Lime;

		if (IPack.Data[8] & (1 << 8)) label_4_k1_i->BackColor = System::Drawing::Color::Red;
		else label_4_k1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 9)) label_4_k2_i->BackColor = System::Drawing::Color::Red;
		else label_4_k2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 10)) label_4_k3_i->BackColor = System::Drawing::Color::Red;
		else label_4_k3_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 11)) label_4_k4_i->BackColor = System::Drawing::Color::Red;
		else label_4_k4_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 12)) label_4_k5_i->BackColor = System::Drawing::Color::Red;
		else label_4_k5_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 13)) label_4_k6_i->BackColor = System::Drawing::Color::Red;
		else label_4_k6_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 14)) label_4_k7_i->BackColor = System::Drawing::Color::Red;
		else label_4_k7_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[8] & (1 << 15)) label_4_k8_i->BackColor = System::Drawing::Color::Red;
		else label_4_k8_i->BackColor = System::Drawing::Color::Lime;

		if (IPack.Data[9] & (1 << 8)) label_5_k1_i->BackColor = System::Drawing::Color::Red;
		else label_5_k1_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 9)) label_5_k2_i->BackColor = System::Drawing::Color::Red;
		else label_5_k2_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 10)) label_5_k3_i->BackColor = System::Drawing::Color::Red;
		else label_5_k3_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 11)) label_5_k4_i->BackColor = System::Drawing::Color::Red;
		else label_5_k4_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 12)) label_5_k5_i->BackColor = System::Drawing::Color::Red;
		else label_5_k5_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 13)) label_5_k6_i->BackColor = System::Drawing::Color::Red;
		else label_5_k6_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 14)) label_5_k7_i->BackColor = System::Drawing::Color::Red;
		else label_5_k7_i->BackColor = System::Drawing::Color::Lime;
		if (IPack.Data[9] & (1 << 15)) label_5_k8_i->BackColor = System::Drawing::Color::Red;
		else label_5_k8_i->BackColor = System::Drawing::Color::Lime;
		/**************/
		if (IPack.Data[5] & (1 << 0))
		{
			label_1_k1_s->BackColor = System::Drawing::Color::Lime;
			button6_1->BackColor = SystemColors::WindowText;
			push_button6_1 = false;
		}
		else
		{
			label_1_k1_s->BackColor = SystemColors::ControlDark;
			button6_1->BackColor = SystemColors::Control;
			push_button6_1 = true;
		}
		if (IPack.Data[5] & (1 << 1))
		{
			label_1_k2_s->BackColor = System::Drawing::Color::Lime;
			button6_2->BackColor = SystemColors::WindowText;
			push_button6_2 = false;
		}
		else
		{
			label_1_k2_s->BackColor = SystemColors::ControlDark;
			button6_2->BackColor = SystemColors::Control;
			push_button6_2 = true;
		}
		if (IPack.Data[5] & (1 << 2))
		{
			label_1_k3_s->BackColor = System::Drawing::Color::Lime;
			button6_3->BackColor = SystemColors::WindowText;
			push_button6_3 = false;
		}
		else
		{
			label_1_k3_s->BackColor = SystemColors::ControlDark;
			button6_3->BackColor = SystemColors::Control;
			push_button6_3 = true;
		}
		if (IPack.Data[5] & (1 << 3))
		{
			label_1_k4_s->BackColor = System::Drawing::Color::Lime;
			button6_4->BackColor = SystemColors::WindowText;
			push_button6_4 = false;
		}
		else
		{
			label_1_k4_s->BackColor = SystemColors::ControlDark;
			button6_4->BackColor = SystemColors::Control;
			push_button6_4 = true;
		}
		if (IPack.Data[5] & (1 << 4))
		{
			label_1_k5_s->BackColor = System::Drawing::Color::Lime;
			button6_5->BackColor = SystemColors::WindowText;
			push_button6_5 = false;
		}
		else
		{
			label_1_k5_s->BackColor = SystemColors::ControlDark;
			button6_5->BackColor = SystemColors::Control;
			push_button6_5 = true;
		}
		if (IPack.Data[5] & (1 << 5))
		{
			label_1_k6_s->BackColor = System::Drawing::Color::Lime;
			button6_6->BackColor = SystemColors::WindowText;
			push_button6_6 = false;
		}
		else
		{
			label_1_k6_s->BackColor = SystemColors::ControlDark;
			button6_6->BackColor = SystemColors::Control;
			push_button6_6 = true;
		}
		if (IPack.Data[5] & (1 << 6))
		{
			label_1_k7_s->BackColor = System::Drawing::Color::Lime;
			button6_7->BackColor = SystemColors::WindowText;
			push_button6_7 = false;
		}
		else
		{
			label_1_k7_s->BackColor = SystemColors::ControlDark;
			button6_7->BackColor = SystemColors::Control;
			push_button6_7 = true;
		}
		if (IPack.Data[5] & (1 << 7))
		{
			label_1_k8_s->BackColor = System::Drawing::Color::Lime;
			button6_8->BackColor = SystemColors::WindowText;
			push_button6_8 = false;
		}
		else
		{
			label_1_k8_s->BackColor = SystemColors::ControlDark;
			button6_8->BackColor = SystemColors::Control;
			push_button6_8 = true;
		}
		if (IPack.Data[6] & (1 << 0))
		{
			label_2_k1_s->BackColor = System::Drawing::Color::Lime;
			button7_1->BackColor = SystemColors::WindowText;
			push_button7_1 = false;
		}
		else
		{
			label_2_k1_s->BackColor = SystemColors::ControlDark;
			button7_1->BackColor = SystemColors::Control;
			push_button7_1 = true;
		}
		if (IPack.Data[6] & (1 << 1))
		{
			label_2_k2_s->BackColor = System::Drawing::Color::Lime;
			button7_2->BackColor = SystemColors::WindowText;
			push_button7_2 = false;
		}
		else
		{
			label_2_k2_s->BackColor = SystemColors::ControlDark;
			button7_2->BackColor = SystemColors::Control;
			push_button7_2 = true;
		}
		if (IPack.Data[6] & (1 << 2))
		{
			label_2_k3_s->BackColor = System::Drawing::Color::Lime;
			button7_3->BackColor = SystemColors::WindowText;
			push_button7_3 = false;
		}
		else
		{
			label_2_k3_s->BackColor = SystemColors::ControlDark;
			button7_3->BackColor = SystemColors::Control;
			push_button7_3 = true;
		}
		if (IPack.Data[6] & (1 << 3))
		{
			label_2_k4_s->BackColor = System::Drawing::Color::Lime;
			button7_4->BackColor = SystemColors::WindowText;
			push_button7_4 = false;
		}
		else
		{
			label_2_k4_s->BackColor = SystemColors::ControlDark;
			button7_4->BackColor = SystemColors::Control;
			push_button7_4 = true;
		}
		if (IPack.Data[6] & (1 << 4))
		{
			label_2_k5_s->BackColor = System::Drawing::Color::Lime;
			button7_5->BackColor = SystemColors::WindowText;
			push_button7_5 = false;
		}
		else
		{
			label_2_k5_s->BackColor = SystemColors::ControlDark;
			button7_5->BackColor = SystemColors::Control;
			push_button7_5 = true;
		}
		if (IPack.Data[6] & (1 << 5))
		{
			label_2_k6_s->BackColor = System::Drawing::Color::Lime;
			button7_6->BackColor = SystemColors::WindowText;
			push_button7_6 = false;
		}
		else
		{
			label_2_k6_s->BackColor = SystemColors::ControlDark;
			button7_6->BackColor = SystemColors::Control;
			push_button7_6 = true;
		}
		if (IPack.Data[6] & (1 << 6))
		{
			label_2_k7_s->BackColor = System::Drawing::Color::Lime;
			button7_7->BackColor = SystemColors::WindowText;
			push_button7_7 = false;
		}
		else
		{
			label_2_k7_s->BackColor = SystemColors::ControlDark;
			button7_7->BackColor = SystemColors::Control;
			push_button7_7 = true;
		}
		if (IPack.Data[6] & (1 << 7))
		{
			label_2_k8_s->BackColor = System::Drawing::Color::Lime;
			button7_8->BackColor = SystemColors::WindowText;
			push_button7_8 = false;
		}
		else
		{
			label_2_k8_s->BackColor = SystemColors::ControlDark;
			button7_8->BackColor = SystemColors::Control;
			push_button7_8 = true;
		}

		if (IPack.Data[7] & (1 << 0))
		{
			label_3_k1_s->BackColor = System::Drawing::Color::Lime;
			button8_1->BackColor = SystemColors::WindowText;
			push_button8_1 = false;
		}
		else
		{
			label_3_k1_s->BackColor = SystemColors::ControlDark;
			button8_1->BackColor = SystemColors::Control;
			push_button8_1 = true;
		}
		if (IPack.Data[7] & (1 << 1))
		{
			label_3_k2_s->BackColor = System::Drawing::Color::Lime;
			button8_2->BackColor = SystemColors::WindowText;
			push_button8_2 = false;
		}
		else
		{
			label_3_k2_s->BackColor = SystemColors::ControlDark;
			button8_2->BackColor = SystemColors::Control;
			push_button8_2 = true;
		}
		if (IPack.Data[7] & (1 << 2))
		{
			label_3_k3_s->BackColor = System::Drawing::Color::Lime;
			button8_3->BackColor = SystemColors::WindowText;
			push_button8_3 = false;
		}
		else
		{
			label_3_k3_s->BackColor = SystemColors::ControlDark;
			button8_3->BackColor = SystemColors::Control;
			push_button8_3 = true;
		}
		if (IPack.Data[7] & (1 << 3))
		{
			label_3_k4_s->BackColor = System::Drawing::Color::Lime;
			button8_4->BackColor = SystemColors::WindowText;
			push_button8_4 = false;
		}
		else
		{
			label_3_k4_s->BackColor = SystemColors::ControlDark;
			button8_4->BackColor = SystemColors::Control;
			push_button8_4 = true;
		}
		if (IPack.Data[7] & (1 << 4))
		{
			label_3_k5_s->BackColor = System::Drawing::Color::Lime;
			button8_5->BackColor = SystemColors::WindowText;
			push_button8_5 = false;
		}
		else
		{
			label_3_k5_s->BackColor = SystemColors::ControlDark;
			button8_5->BackColor = SystemColors::Control;
			push_button8_5 = true;
		}
		if (IPack.Data[7] & (1 << 5))
		{
			label_3_k6_s->BackColor = System::Drawing::Color::Lime;
			button8_6->BackColor = SystemColors::WindowText;
			push_button8_6 = false;
		}
		else
		{
			label_3_k6_s->BackColor = SystemColors::ControlDark;
			button8_6->BackColor = SystemColors::Control;
			push_button8_6 = true;
		}
		if (IPack.Data[7] & (1 << 6))
		{
			label_3_k7_s->BackColor = System::Drawing::Color::Lime;
			button8_7->BackColor = SystemColors::WindowText;
			push_button8_7 = false;
		}
		else
		{
			label_3_k7_s->BackColor = SystemColors::ControlDark;
			button8_7->BackColor = SystemColors::Control;
			push_button8_7 = true;
		}
		if (IPack.Data[7] & (1 << 7))
		{
			label_3_k8_s->BackColor = System::Drawing::Color::Lime;
			button8_8->BackColor = SystemColors::WindowText;
			push_button8_8 = false;
		}
		else
		{
			label_3_k8_s->BackColor = SystemColors::ControlDark;
			button8_8->BackColor = SystemColors::Control;
			push_button8_8 = true;
		}
		if (IPack.Data[8] & (1 << 0))
		{
			label_4_k1_s->BackColor = System::Drawing::Color::Lime;
			button9_1->BackColor = SystemColors::WindowText;
			push_button9_1 = false;
		}
		else
		{
			label_4_k1_s->BackColor = SystemColors::ControlDark;
			button9_1->BackColor = SystemColors::Control;
			push_button9_1 = true;
		}
		if (IPack.Data[8] & (1 << 1))
		{
			label_4_k2_s->BackColor = System::Drawing::Color::Lime;
			button9_2->BackColor = SystemColors::WindowText;
			push_button9_2 = false;
		}
		else
		{
			label_4_k2_s->BackColor = SystemColors::ControlDark;
			button9_2->BackColor = SystemColors::Control;
			push_button9_2 = true;
		}
		if (IPack.Data[8] & (1 << 2))
		{
			label_4_k3_s->BackColor = System::Drawing::Color::Lime;
			button9_3->BackColor = SystemColors::WindowText;
			push_button9_3 = false;
		}
		else
		{
			label_4_k3_s->BackColor = SystemColors::ControlDark;
			button9_3->BackColor = SystemColors::Control;
			push_button9_3 = true;
		}
		if (IPack.Data[8] & (1 << 3))
		{
			label_4_k4_s->BackColor = System::Drawing::Color::Lime;
			button9_4->BackColor = SystemColors::WindowText;
			push_button9_4 = false;
		}
		else
		{
			label_4_k4_s->BackColor = SystemColors::ControlDark;
			button9_4->BackColor = SystemColors::Control;
			push_button9_4 = true;
		}
		if (IPack.Data[8] & (1 << 4))
		{
			label_4_k5_s->BackColor = System::Drawing::Color::Lime;
			button9_5->BackColor = SystemColors::WindowText;
			push_button9_5 = false;
		}
		else
		{
			label_4_k5_s->BackColor = SystemColors::ControlDark;
			button9_5->BackColor = SystemColors::Control;
			push_button9_5 = true;
		}
		if (IPack.Data[8] & (1 << 5))
		{
			label_4_k6_s->BackColor = System::Drawing::Color::Lime;
			button9_6->BackColor = SystemColors::WindowText;
			push_button9_6 = false;
		}
		else
		{
			label_4_k6_s->BackColor = SystemColors::ControlDark;
			button9_6->BackColor = SystemColors::Control;
			push_button9_6 = true;
		}
		if (IPack.Data[8] & (1 << 6))
		{
			label_4_k7_s->BackColor = System::Drawing::Color::Lime;
			button9_7->BackColor = SystemColors::WindowText;
			push_button9_7 = false;
		}
		else
		{
			label_4_k7_s->BackColor = SystemColors::ControlDark;
			button9_7->BackColor = SystemColors::Control;
			push_button9_7 = true;
		}
		if (IPack.Data[8] & (1 << 7))
		{
			label_4_k8_s->BackColor = System::Drawing::Color::Lime;
			button9_8->BackColor = SystemColors::WindowText;
			push_button9_8 = false;
		}
		else
		{
			label_4_k8_s->BackColor = SystemColors::ControlDark;
			button9_8->BackColor = SystemColors::Control;
			push_button9_8 = true;
		}

		if (IPack.Data[9] & (1 << 0))
		{
			label_5_k1_s->BackColor = System::Drawing::Color::Lime;
			button10_1->BackColor = SystemColors::WindowText;
			push_button10_1 = false;
		}
		else
		{
			label_5_k1_s->BackColor = SystemColors::ControlDark;
			button10_1->BackColor = SystemColors::Control;
			push_button10_1 = true;
		}
		if (IPack.Data[9] & (1 << 1))
		{
			label_5_k2_s->BackColor = System::Drawing::Color::Lime;
			button10_2->BackColor = SystemColors::WindowText;
			push_button10_2 = false;
		}
		else
		{
			label_5_k2_s->BackColor = SystemColors::ControlDark;
			button10_2->BackColor = SystemColors::Control;
			push_button10_2 = true;
		}
		if (IPack.Data[9] & (1 << 2))
		{
			label_5_k3_s->BackColor = System::Drawing::Color::Lime;
			button10_3->BackColor = SystemColors::WindowText;
			push_button10_3 = false;
		}
		else
		{
			label_5_k3_s->BackColor = SystemColors::ControlDark;
			button10_3->BackColor = SystemColors::Control;
			push_button10_3 = true;
		}
		if (IPack.Data[9] & (1 << 3))
		{
			label_5_k4_s->BackColor = System::Drawing::Color::Lime;
			button10_4->BackColor = SystemColors::WindowText;
			push_button10_4 = false;
		}
		else
		{
			label_5_k4_s->BackColor = SystemColors::ControlDark;
			button10_4->BackColor = SystemColors::Control;
			push_button10_4 = true;
		}
		if (IPack.Data[9] & (1 << 4))
		{
			label_5_k5_s->BackColor = System::Drawing::Color::Lime;
			button10_5->BackColor = SystemColors::WindowText;
			push_button10_5 = false;
		}
		else
		{
			label_5_k5_s->BackColor = SystemColors::ControlDark;
			button10_5->BackColor = SystemColors::Control;
			push_button10_5 = true;
		}
		if (IPack.Data[9] & (1 << 5))
		{
			label_5_k6_s->BackColor = System::Drawing::Color::Lime;
			button10_6->BackColor = SystemColors::WindowText;
			push_button10_6 = false;
		}
		else
		{
			label_5_k6_s->BackColor = SystemColors::ControlDark;
			button10_6->BackColor = SystemColors::Control;
			push_button10_6 = true;
		}
		if (IPack.Data[9] & (1 << 6))
		{
			label_5_k7_s->BackColor = System::Drawing::Color::Lime;
			button10_7->BackColor = SystemColors::WindowText;
			push_button10_7 = false;
		}
		else
		{
			label_5_k7_s->BackColor = SystemColors::ControlDark;
			button10_7->BackColor = SystemColors::Control;
			push_button10_7 = true;
		}
		if (IPack.Data[9] & (1 << 7))
		{
			label_5_k8_s->BackColor = System::Drawing::Color::Lime;
			button10_8->BackColor = SystemColors::WindowText;
			push_button10_8 = false;
		}
		else
		{
			label_5_k8_s->BackColor = SystemColors::ControlDark;
			button10_8->BackColor = SystemColors::Control;
			push_button10_8 = true;
		}

	}

	private: void Panel_Pin_Enable(bool stat)
	{
		this->panel36->Enabled = stat;
		this->panel39->Enabled = stat;
		this->panel42->Enabled = stat;
		this->panel67->Enabled = stat;

		this->panel71->Enabled = stat;

		this->panel131->Enabled = stat;
		this->panel133->Enabled = stat;
		this->panel136->Enabled = stat;
		this->panel139->Enabled = stat;
		this->panel142->Enabled = stat;
		this->panel145->Enabled = stat;

		this->panel11->Enabled = stat;
		this->panel10->Enabled = stat;
		this->panel23->Enabled = stat;
		this->panel56->Enabled = stat;
		this->panel45->Enabled = stat;

		this->panel127->Enabled = stat;
		this->panel124->Enabled = stat;
		this->panel121->Enabled = stat;
		this->panel118->Enabled = stat;
		this->panel115->Enabled = stat;
	}
	private: void Button_Pin_Enable(bool stat)
	{
		this->button_pow_cel_nag->Enabled = stat;
		this->button_pow_bat->Enabled = stat;
		this->button_launch_aircraft->Enabled = stat;
		this->button_aircraft_air->Enabled = stat;

		this->button_all->Enabled = stat;

		this->button6_1->Enabled = stat;
		this->button6_2->Enabled = stat;
		this->button6_3->Enabled = stat;
		this->button6_4->Enabled = stat;
		this->button6_5->Enabled = stat;
		this->button6_6->Enabled = stat;
		this->button6_7->Enabled = stat;
		this->button6_8->Enabled = stat;

		this->button7_1->Enabled = stat;
		this->button7_2->Enabled = stat;
		this->button7_3->Enabled = stat;
		this->button7_4->Enabled = stat;
		this->button7_5->Enabled = stat;
		this->button7_6->Enabled = stat;
		this->button7_7->Enabled = stat;
		this->button7_8->Enabled = stat;

		this->button8_1->Enabled = stat;
		this->button8_2->Enabled = stat;
		this->button8_3->Enabled = stat;
		this->button8_4->Enabled = stat;
		this->button8_5->Enabled = stat;
		this->button8_6->Enabled = stat;
		this->button8_7->Enabled = stat;
		this->button8_8->Enabled = stat;

		this->button9_1->Enabled = stat;
		this->button9_2->Enabled = stat;
		this->button9_3->Enabled = stat;
		this->button9_4->Enabled = stat;
		this->button9_5->Enabled = stat;
		this->button9_6->Enabled = stat;
		this->button9_7->Enabled = stat;
		this->button9_8->Enabled = stat;

		this->button10_1->Enabled = stat;
		this->button10_2->Enabled = stat;
		this->button10_3->Enabled = stat;
		this->button10_4->Enabled = stat;
		this->button10_5->Enabled = stat;
		this->button10_6->Enabled = stat;
		this->button10_7->Enabled = stat;
		this->button10_8->Enabled = stat;
	}

	private: System::Void Form_main_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		timer1->Stop();
		timer1->Enabled = false;

		timer2->Stop();
		timer2->Enabled = false;

		Log_File_Close();

		MB26_20_Close();
	}
};
}
