/***************************************************************
	mt.h
	Поддержка режима MT.

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Гурьев, 2000.
	По заказу НТЦ Модуль.
 ***************************************************************/
/***************************************************************
	История изменений:

 ***************************************************************/

#ifndef MT_H
#define MT_H

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
	Поддержка режима WM.
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
	Конфигурирование таблицы выбора сообщений.
 ***************************************************************/

#define msp_MT_SELECTED		1
#define msp_MT_UNSELECTED	0

msp_ERROR msp_MTSelectMessages(
				msp_DEVHANDLE device, 
				msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, 
				msp_BIT select);
//Выбор сообщений для мониторинга (установка бит в MT lookup table).
//device – устройство
//rangeCmdWord0,
//rangeCmdWord1 - команды 1553, определяющие область действия операции
//		для каждого подполя команды sampleCmdWord1 задает начальное
//		значение, а sampleCmdWord2 - конечное;
//		используются подполя <RT> (ОУ), <TX> (передача/прием*), <SA> (подадрес)
//		игнорируется подполе <WCNT> (число слов данных)
//select – признак “избранности” данных сообщений;
//		значения msp_MT_SELECTED (0x01) или msp_MT_UNSELECTED (0x00)

msp_BIT msp_MTIsMessageSelected(msp_DEVHANDLE device, msp_WORD sampleCmdWord);
//Считывание признака выбора данного типа сообщения для мониторинга.

msp_ERROR msp_MTSelectMessagesIndirect(
				msp_DEVHANDLE device,
				msp_rangeCmdWords *ranges,
				int count,
				msp_BIT select);
//Выбор сообщений для мониторинга по массиву
//device - устройство
//ranges - массив пар rangeCmdWord0, rangeCmdWord1
//			каждая пара интерпретируется аналогично параметрам
//			msp_SelectMessages()
//count	- количество элементов в массие ranges
//select – признак “избранности” данных сообщений;
//		значения msp_MT_SELECTED (0x01) или msp_MT_UNSELECTED (0x00)

/***************************************************************
	П\п работы со стеком команд
 ***************************************************************/

msp_STKHANDLE msp_MTCreateStack(msp_DEVHANDLE device);
//Создание стека команд МТ (резервирование области ОЗУ)
//device – устройство

#define msp_MTDestroyStack(stack) msp_DestroyHandle(stack)
//Уничтожение стека.
//stack – идентификатор (handle) стека
//Возврат: код ошибки

msp_ERROR msp_MTLoadStack(msp_STKHANDLE stack, int flags);
//Загрузка данного стека в качестве стека команд МТ (A или B).
//stack – идентификатор (handle) стека
//flags – одно из значений
//	msp_STK_A – загрузить в стэк A
//	msp_STK_B – загрузить в стэк B

msp_ERROR msp_MTLoadStackWithOffset(msp_STKHANDLE stack, int start, int flags);
//Загрузка данного стека в качестве стека команд МТ
//с одновременной установкой начального номера сообщения
//stack – идентификатор (handle) стека
//start - начальный номер сообщения
//flags – одно из значений
//	msp_STK_A – загрузить в стэк A
//	msp_STK_B – загрузить в стэк B

//See also msp_SetStkStart (config.h)

/***************************************************************
	П\п работы со стеком данных
 ***************************************************************/

typedef msp_RAMHANDLE msp_DSTKHANDLE;

msp_DSTKHANDLE msp_MTCreateDataStack(msp_DEVHANDLE device);
//Создание стека данных
//device – устройство

#define msp_MTDestroyDataStack(stack) msp_DestroyHandle(stack)
//Уничтожение стека данных
//device – устройство

msp_ERROR msp_MTLoadDataStack(msp_DSTKHANDLE stack, int flags);
//Загрузка данного стека в качестве стека данных
//stack - стек данных
//flags – одно из значений
//	msp_STK_A – загрузить в стэк A
//	msp_STK_B – загрузить в стэк B

msp_ERROR msp_MTLoadDataStackWithOffset(msp_DSTKHANDLE stack, msp_WORD start, int flags);
//Загрузка стека в качастве стека данных с одновременной установкой
//начального адреса
//stack - стек данных
//start - начальный адрес относительно начала стека (смещение)
//flags – одно из значений
//	msp_STK_A – загрузить в стэк A
//	msp_STK_B – загрузить в стэк B

msp_ERROR msp_MTResetDataStack(msp_DSTKHANDLE stack, msp_WORD address);
//Установка начального адреса стека данных
//stack - стек данных
//adsress - начальный адрес относительно начала стека (смещение)
//Стек должен быть загружен
#define msp_MTSetDStkStart msp_MTResetDataStack
//Старое название

/***************************************************************
   Анализ состояния обработки сообщений
 ***************************************************************/

msp_ERROR msp_MTRetrieveMessage(msp_STKHANDLE stack, int index, msp_Message* buffer);
//Считывание сообщения из ОЗУ МСП в ОЗУ хоста, совместно со словами состояния из дескриптора сообщения в данном стеке.
//stack – стек; 
//entry – номер дескриптора сообщения в кадре
//buffer – буфер для считывания сообщения. В буфере заполняются дополнительные поля StatusWord1/2, loopback, BSW, timetag.
//Полный аналог msp_RetrieveMessage, но только для MT

#ifdef __cplusplus
}
#endif

#endif
