/***************************************************************
	cash.h
	Кэширование (программное) для "медленных" шин (USB), и
	оптимизация запросов "быстрых" шин (VXI, PCI и т.д.)

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Чихичин, 2006-2010.
 ***************************************************************/
/***************************************************************
	История изменений:
	25.01.07 - добавлена ф-ция cash_RetrivePreparationLatch
			 - добавлен переключатель cash_GlbErrХХ
	25.03.09 - добавлена ф-ция cash_RefreshReg
			 - добавлена поддержка всех шин
	1.10.10  - удалены ф-ции одновременно действующие на все 
			   кэшируемые устройства.
 ***************************************************************/

#ifndef _CASH_H
#define _CASH_H

#include "access.h"
//#include "sync.h"

#ifdef __cplusplus
extern "C" {
#endif
/*--------------------------------------------------------------*/

typedef enum{
	// управление оптимизацией
	cash_OptimaSwitchOn,
	cash_OptimaSwitchOff,
	cash_GetSwitch,
	// управление отображением в кэше при временном отключении
	cash_SaveExchangeOn, 
	cash_SaveExchangeOff,
	cash_GetSaveExchange,
	// управление отражением ошибки кэша на глобальную ошибку
	cash_GlbErrOn,
	cash_GlbErrOff,
	cash_GetGlbErr,
	// отладочная метка
	cash_DebugMark,
	// режим автоматический обновлений
	cash_UpdateModeAuto,
	cash_UpdateModeSync,
	cash_GetUpdateMode
} cash_TuneParam;


////////////////////////////////
// Активация кэша для устройства
msp_ERROR 
cash_ActivateDeviceCash(msp_DEVHANDLE device);

//////////////////////////////////
// Деактивация кэша для устройства
msp_ERROR 
cash_ReleaseDeviceCash(msp_DEVHANDLE device);

////////////////////////////////////////////////////////////
// Подготовка к чтению данных ОЗУ и всех регистров через кэш 
msp_ERROR 
cash_RefreshRamPreparation(msp_DEVHANDLE device, msp_WORD begin_mem, int size);

////////////////////////////////////////////
// Подготовка к чтению только ОЗУ
msp_ERROR 
cash_RefreshRamPreparationOnly(msp_DEVHANDLE device, msp_WORD begin_mem, int size);

////////////////////////////////////////////////
#define cash_ALL_REGISTERS		0x1F
// Подготовка к чтению регистра(ов) через кэш 
msp_ERROR 
cash_RefreshRegPreparation(msp_DEVHANDLE device, msp_BYTE RegNo);
// возрат - значение ошибки
// device - хендл кэшируемого устройства
// RegNo  - номер читаемого регистра, при значении cash_ALL_REGISTERS
//          происходит обновление кэша по всем регистрам

//////////////////////////////////////////////////
// Подготовка данных для ф-ций msp_RetrieveMessage
msp_ERROR 
cash_RetrievePreparationLatch(void* stack);

//////////////////////////////
// Защелкивание кэша на запись
msp_ERROR 
cash_WriteLatch(msp_DEVHANDLE device);

//////////////////////////////
// Защелкивание кэша на чтение
msp_ERROR 
cash_RefreshLatch(msp_DEVHANDLE device);


/*
	Операции автоматической обработки операций с использование кэша.
	Эффективны для операций записи (например конфигурирование устройства),
	наличие операций чтения - резко снижает скорость обмена.
*/
// Начало автоматического защелкивания кэша
msp_ERROR 
cash_AutoExchangeOn(msp_DEVHANDLE device);

// Конец автоматического защелкивания кэша
msp_ERROR 
cash_AutoExchangeOff(msp_DEVHANDLE device);

// Запрос: кэшируется ли устройство ?
msp_BOOL
cash_IsDevIntoCash(msp_DEVHANDLE device);

// Включение автоматического обновления кэша для МВ26.20v2
msp_ERROR
cash_AutoUpdateOn(msp_DEVHANDLE device);

// Выключение автоматического обновления кэша МВ26.20v2
msp_ERROR
cash_AutoUpdateOff(msp_DEVHANDLE device);

/* 
	Ф-ции управления работой кэша
*/
//////////////////////////////////
// Приостановка кэширования данных
msp_ERROR 
cash_CashInterruption(msp_DEVHANDLE device);

///////////////////////////////////////////////
// Возобновление кэширования после приостановки
msp_ERROR 
cash_CashWorkResumption(msp_DEVHANDLE device);

///////////////////////
// очистка очереди кэша
msp_ERROR 
cash_ForceClear(msp_DEVHANDLE device);

/////////////////
// Настройка кэша.
cash_TuneParam 
cash_Tune(cash_TuneParam parameter);


/*---------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
