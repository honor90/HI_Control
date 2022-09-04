/* -*- mode:c; coding:windows-1251; -*- */
/***************************************************************
	access.h
	П/п низкоуровневого доступа.

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Гурьев, 2000.
	По заказу НТЦ Модуль.
 ***************************************************************/
/***************************************************************
	История изменений:
	13.09.2001 Гурьев
	  Добавлено поле LType в msp_DeviceInfo и его формирование
	  и проверка в msp_GetDeviceInfo(), msp_FindDevice
	14.01.2002 Чихичин
		Добавлены макросы mspRR_EXTERNAL_FLOG_ID, msp_CLOCK_ХХMHz,
		для ГСП и кодировки типа функциональной логики.
	24.10.2005 Гурьев, Мешков, Козаченко
		Добавлена поддержка многооконечного устройства.
		Добавлена поддержка расширения реального времени Ardence RTХ
 ***************************************************************/

#ifndef ACCESS_H
#define ACCESS_H

#define RTL2_VERSION 505
// Номер версии библиотеки

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
Инофомация об устройстве
VendorId – идентификатор производителя (из конфигурационного пространства PCI)
DeviceId – идентификатор устройства (из конфигурационного пространства PCI)
InstanceId – адрес устройства в конфигурационном пространстве PCI. 
			Формат соответствует формату регистра PCI CONFIG_ADDRESS (бит 31 = 0).
ProcessId – идентификатор процесса (ВМ), захватившего устройство, или 0, 
			если устройство свободно
LType - тип функциональной логики, mspLT_XXXX
Устройства нумеруются с 0 до msp_GetNumberOfDevices()-1.
*/

//Кодировка типа функциональной логики
#define mspLT_BU			0x00 // БИС BU-61580, стандартные режимы КШ/ОУ/МТ
#define mspLT_PLM_BU		0x01 // БИС 1879ВА1Т или ПЛМ, стандартные режимы
#define mspLT_TESTER		0x02 // функциональность тестера (только)
#define mspLT_EXT_TESTER	0x03 // функциональность тестера + стандартные режимы (UNIVERSAL)
#define mspLT_MULTIPORT		0x04 // 31ОУ + стандартные режимы
#define mspLT_VIRTUALRT		0xFE // виртуальное ОУ в составе mspLT_MULTIPORT
//Обратная совместимость. Не документировать.
#define mspLT_UNIVERSAL		mspLT_EXT_TESTER

//Кодировка режима работы устройства
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
#define msp_MODE_WG						0x0020 // Для ГСП

//опции (команды) для SelectMode
#define msp_SWITCH_WITHOUT_RESET        0x0100
#define msp_SWITCH_KEEP_RAM             0x0200
// Для ГСП
#define msp_WG_FIRST					0
#define msp_WM_FIRST					0x4000
// Для MRT
#define msp_MODE_MRT					0x0040			

typedef struct { 
	msp_DWORD		BoardTypeId;   /* 4 hex цифры от имени платы */
	char*			BoardTypeName; /* RUS windows-1251 */
	msp_BYTE		Clocks;        /* OR'ed (1 << MSP_CLOCK_XXX) */
	msp_MODE*       Modes;
	msp_DWORD OnChipRamSize;  /*words*/
	msp_DWORD OnBoardRamSize; /*words*/
	msp_DWORD SpecialRamSize; /*words*/
} msp_DeviceTypeInfo;
//Информация о типе устройства
//BoardTypeId - числовой идентификатор типа платы (4 hex цифры от имени платы)
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
    //Схема назначения идентификаторов не изменится
	//Отсутствие определения константы - не причина для отказа от работы с устройством
//BoardTypeName - наименование типа платы, строка, RUS windows-1251
//Clocks - поддерживаемые тактовые частоты (OR'ed (1 << msp_CLOCK_XXX))
//Modes - список поддерживаемых режимов и комбинаций режимов, признак конца - 0
//OnChipRamSize - размер внутреннего ОЗУ, в словах
//OnBoardRamSize - размер внешнего ОЗУ, в словах
//SpecialRamSize - размер ОЗУ в специальном режиме (тестер, 31ОУ), в словах

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
//Объединение информации об устройстве и его типе
//ModesMask - битовая маска поддерживаемых режимов (OR'ed Modes)

typedef	msp_HANDLE msp_DEVHANDLE;

/***************************************************************
    Функции иниализации и информационные функции
 ***************************************************************/

msp_WORD msp_GetVersion();

// Возвращает номер версии библиотеки (значение макроса RTL2_VERSION)
// Для определения фактического номера версии, когда библиотека используется как DLL

msp_ERROR msp_Startup();

// Инициализация RTL

msp_ERROR msp_Cleanup();

// Завершение работы RTL

//
// Инициализация RTL по отдельным драйверам
//
msp_ERROR msp_StartupDrv(msp_DriverType drv);
// Вместо вызова msp_Startup() приложение может сделать несколько вызовов
// msp_StartupDrv() для конкретный драйверов, с которыми оно хочет работать.
// Коды msp_Driver95 и msp_DriverNT в этой функции являются взаимозаменяемыми,
// поскольку выбор между этими драйверами производится в зависимости от
// платформы, которая детектируется динамически

int msp_GetNumberOfDevices();

//Возвращает количество опознанных устройств.
// -1 в случае ошибки

msp_ERROR msp_GetDeviceInfo(int i, msp_DeviceInfo* I);

//Возвращает информацию об опознанном устройстве с номером по порядку i в структуру DeviceInfo:
//Устройства нумеруются с 0 до msp_GetNumberOfDevices()-1.

int msp_FindDevice(msp_DeviceInfo* I);

//Возвращает порядковый номер устройства с заданными признаками, -1 если устройство не найдено. 
//Перед вызовом функции приложение должно заполнить структуру I. 
//Для игнорирование признака соответствующее поле должно быть установлено в –1.
//Устройства нумеруются с 0 до msp_GetNumberOfDevics()-1.
//Поле SerialNumber не учитывается

#define msp_InitPattern(I) \
	(memset((I), -1, sizeof(*(I))), (I)->SerialNumber = NULL)
//msp_DeviceInfo* I
//Инициализирует I для поиска с условием "все признаки несущественны"
//Удобно использовать перед записью в I существенных признаков

msp_DeviceTypeInfo* msp_GetDeviceTypeInfo(int i);

//Возвращает указатель на расширенную информацию о типе устройства с порядковым номером i.
//	При ошибке возвращает NULL и устанавливает код ошибки
//		( msp_ERROR_UNKNOWN_DEVICE_TYPE, msp_ERROR_INVALID_PARAMETER, msp_ERROR_NOT_INITIALIZED).
//Устройства нумеруются с 0 до msp_GetNumberOfDevices()-1.

msp_ERROR msp_GetDeviceInfoEx(int i, msp_DeviceInfoEx* I);
//Ф-ция аналогична msp_GetDeviceInfo(), но возвращает расширенную информацию
//Если информация об устройстве найдена, а о типе - нет, поля информации
//о типе заполняются -1, устанавливается ошибка msp_ERROR_UNKNOWN_DEVICE_TYPE

#define msp_FIND_FIRST	0
#define msp_FIND_NEXT	1
int msp_FindDeviceEx(msp_DeviceInfoEx* I, int next);
//Ф-ция аналогична msp_FindDevice(), но на основе раширенной информации.
//находит первое соответствующее устройство
//Поле BoardTypeName игнорируется
//Поле SerialNumber игнорируется
//Поле Modes, если незначимо, должно быть установлено в NULL
//Поля Clocks и ModesMask сравниваются "по включению множеств",
//Поле Modes - "по включению списков"
//next - параметр управлябщий поиском макросами msp_FIND_XXXX

#define msp_InitPatternEx(I) \
	(memset((I), -1, sizeof(*(I))), (I)->Modes = NULL, (I)->SerialNumber = NULL)
//msp_DeviceInfoEx* I
//Инициализирует I для поиска с условием "все признаки несущественны"
//Удобно использовать перед записью в I существенных признаков

/***************************************************************
    Функции установления связи с устройством
 ***************************************************************/

msp_DEVHANDLE mspi_OpenAccess(int i);
msp_DEVHANDLE mspi_OpenAccessEx(int i, int flags);

//Открывает доступ к регистрам устройства
//В случае невозможности открыть устройство 
//возвращается значение msp_NOHANDLE.
//Вызывается из msp_Open()/msp_OpenEx()

//flags:
#define msp_of64		(1<<0)
#define msp_ofZEROWAIT	(1<<1)
#define msp_ofBackDoor	(1<<2)
#define msp_ofShrinkRam	(1<<3)

msp_ERROR mspi_CloseAccess(msp_DEVHANDLE device);

//Закрывает доступ к регистрам устройства
//Вызывается из msp_Close

int msp_GetDeviceNo(msp_DEVHANDLE device);
//Возвращает № открытого устройства

/***************************************************************
    Доступ к регистрам и ОЗУ устройства
 ***************************************************************/

//Чтение и запись регистров устройства. RegNo – номер регистра.

msp_WORD msp_ReadReg(msp_DEVHANDLE device, msp_BYTE RegNo);
msp_ERROR msp_WriteReg(msp_DEVHANDLE device, msp_BYTE RegNo, msp_WORD Data);


//Чтение и запись слов и двойных слов из ОЗУ устройства. Address – адрес в ОЗУ устройства.

msp_WORD  msp_ReadRamW   (msp_DEVHANDLE device, msp_WORD Address);
msp_ERROR msp_WriteRamW  (msp_DEVHANDLE device, msp_WORD Address, msp_WORD Data);
msp_DWORD msp_ReadRamDW  (msp_DEVHANDLE device, msp_WORD Address);
msp_ERROR msp_WriteRamDW (msp_DEVHANDLE device, msp_WORD Address, msp_DWORD Data);

#define msp_ReadRam msp_ReadRamW
#define msp_WriteRam msp_WriteRamW
//Так короче

//Пересылка блоков информации из ОЗУ МСП в ОЗУ хоста и обратно.
//Длина задается в словах

msp_ERROR msp_ReadRamBLK  (msp_DEVHANDLE device, msp_WORD Address, void *Data, msp_WORD Length);
msp_ERROR msp_WriteRamBLK (msp_DEVHANDLE device, msp_WORD Address, void *Data, msp_WORD Length);

//Заполнение блока в ОЗУ МСП константой.
msp_ERROR msp_FillRamBLK (msp_DEVHANDLE device, msp_WORD Address, msp_WORD Data, msp_WORD Length);

//Пересылка блоков информации из ОЗУ МСП в ОЗУ хоста и обратно
//из циклической области заданного размера.
//NextAddress м.б. NULL.

msp_ERROR msp_ReadRamCIRC(msp_DEVHANDLE device, msp_WORD Address, void *Data,
						  msp_WORD Length, msp_DWORD Modulo, msp_WORD *NextAddress);
msp_ERROR msp_WriteRamCIRC(msp_DEVHANDLE device, msp_WORD Address, void *Data, 
						   msp_WORD Length, msp_DWORD Modulo, msp_WORD *NextAddress);

//Чтение и запись регистров контроллера PCI. RegNo - номер дв. слова
//Эти функции не являются частью спецификации RTL и могут не поддерживаться
//в других версиях и на других платформах
msp_DWORD msp_LPCI_ReadReg(msp_DEVHANDLE device, msp_BYTE RegNo);
msp_ERROR msp_LPCI_WriteReg(msp_DEVHANDLE device, msp_BYTE  RegNo, msp_DWORD Data);

/*************************************************************************
  Регистры МКО
  0x00-0x0F регистры хост-интерфейса (BU-61580)
  0x10-0x1F регистры хост-интерфейса не используемые (BU-61580)
  0x20-0x21	регистры БКР: старший байт не используется
  0x40-???	регистры КПИ (не реализовано)
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

// Для режима ГСП
#define		mspRR_WG_DATA_STACK_POINTER			0x03
#define		mspRR_WG_INITIAL_DATA_STACK_POINTER	0x04
		
// Делитель тактовой частоты
#define		msp_CLOCK_12MHz		1
#define		msp_CLOCK_16MHz		0
#define		msp_CLOCK_24MHz		2
#define		msp_CLOCK_48MHz		3

/*************************************************************************
  Регистры конрроллера PCI 9050
  Эти значения не являются частью спецификации RTL
  и могут не поддерживаться в других версиях и на
  других платформах
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
  Обработка прерываний
**************************************************************************/

typedef void (*msp_ISR)(msp_DEVHANDLE device);

msp_ERROR msp_SetISR (msp_DEVHANDLE device, msp_ISR ISR);
//Установить п/п обработки прерываний от данного устройсва (device).
//Функция конфигурирует регистр маски прерываний МСП,
//Разрешает прерывания на уровне контроллера 9050

/************************************************************************
    Поддержка дополнительых банков ОЗУ
 ************************************************************************/

msp_DEVHANDLE mspi_OpenAccess64(int i);
//Аналогично msp_OpenAccess(),
//доступ к внешней ОЗУ на плате ПМКО

/************************************************************************
    Непосредственный доступ к ОЗУ через "BackDoor"
 ************************************************************************/
msp_DEVHANDLE mspi_OpenBackDoor(int i);
msp_ERROR mspi_SwitchBackDoorBank(msp_DEVHANDLE device, int code);
/************************************************************************
    Поддержка режима ZEROWAIT
 ************************************************************************/

typedef void (*msp_Delay)(msp_DEVHANDLE device, int count);

msp_ERROR msp_RegisterDelay(msp_Delay fndelay, int count);

/***************************************************************
    Функции установления связи с многоокнечным устройством
 ***************************************************************/

msp_DEVHANDLE mspi_OpenAccess_Multi(msp_DEVHANDLE device,int i);
//Открывает виртуальное устройство (ОУ) многоабонентского устройства
//device - многоабонентское устройство
//i - номер ОУ
//в device должен быть выбран режим msp_MODE_MRT или установлен бит 14 в CONFIG2
//лучше использовать msp_Open_Multi() (config.h)

#define ofs_MRT_REGISTER_OVERRIDE 3 
#define mask_MRT_REGISTER_OVERRIDE ((msp_WORD)(1 << ofs_MRT_REGISTER_OVERRIDE))
#define ofs_MRT_ATOMIC_RW 4
#define mask_MRT_ATOMIC_RW ((msp_WORD)(1 << ofs_MRT_ATOMIC_RW))
//Определения для внутреннего использования

/***************************************************************
    Поддержка устройств на USB
 ***************************************************************/

// Питание для USB устройства
#define USB_POWER_EXTERNAL	1
#define USB_POWER_INTERNAL	0
// Переключение питания USB устройства
// code = USB_POWER_EXTERNAL - внешнее от ИП
//      = USB_POWER_INTERNAL - внутреннее от USB
msp_ERROR msp_USB_SwitchPower(msp_DEVHANDLE device, int code);

HANDLE msp_USB_GetHandle(msp_DEVHANDLE device);
//Возвращает системный дескриптор устройства,
//который можно использовать в функциях MPApi.h

msp_DWORD mspi_InstanceIdForPci(msp_BYTE bus, msp_BYTE device);
void mspi_PciInstanceIdParse(msp_DWORD instanceId, msp_BYTE* bus, msp_BYTE* device);

msp_DWORD mspi_InstanceIdForVxi(msp_BYTE crate, msp_BYTE slot, msp_BYTE mezonin);
void mspi_VxiInstanceIdParse(msp_DWORD instanceId, msp_BYTE* crate, msp_BYTE* slot, msp_BYTE* mezonin);

#ifdef __cplusplus
}
#endif

#endif
