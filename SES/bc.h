/***************************************************************
	bc.h
	Поддержка режима КШ.

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Гурьев, 2000.
	По заказу НТЦ Модуль.
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
   Дескрипторы объектов.
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
//Форматирование заготовки сообщения 
//и размещение его в структуре msp_Message.
//Параметры:
//buffer – буфер для заготовки сообщения
//type – тип сообщения (одна из констант mspM_XXXX)
//RT – адрес (0-31)
//SA – подадрес (0-31)
//RTR_MC, SAR_MCD - адрес ОУ получателя для mspM_RTtoRT
//                - код и данные для mspM_MODECODE_XXXX
//dataWordCount – число слов данных.
//data – данные. Может быть NULL, 
//               в этом случае поле buffer->data не инициализируется.
//bccw - упарвляющее слово КШ (bitmapped). 3 мл. разряда игнорируются.
//Возвращает: *buffer.

//Макросы сокращенного обращения к msp_FornatMessage
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

//Константы для BCCW:
//В msp_CreateMessage Биты 0-2 заполняются автоматически согласно buffer->type
//Не надо их задавать
//BCCW_EX используется только в msp_FormatMessage и не запоминается в msp_Message
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
//Заданное значение будет комбинироваться по OR с параметром bccw
//при каждом обращении к msp_FormatMessage

msp_MSGHANDLE msp_CreateMessage(msp_DEVHANDLE device, msp_Message* buffer);
//Создание сообщения в ОЗУ МСП.
//device – идентификатор устройства. 
//buffer – заготовка сообщения
//Возвращает: идентификатор (handle) сообщения.

#define msp_DestroyMessage(message) msp_DestroyHandle(message)
//Уничтожение сообщения в ОЗУ МСП.

msp_ERROR msp_ReadBCMessage(msp_MSGHANDLE message, msp_Message* buffer);
//Копирует (с преобразованием формата) указаное сообщение из ОЗУ МСП
//в структуру msp_Message, включая поля StatusWord1/2, loopback. 
//Преобразование фактически сводится к измнению порядка слов с 
//зависящего от типа сообщения (в ОЗУ) на фиксированный (в buffer).
//message – ид. (handle) сообщения
//buffer – структура куда копировать

msp_BYTE msp_ReadMessageData(msp_MSGHANDLE message, msp_WORD* buffer, msp_BYTE wordcount);
//Копирование слов данных сообщения из ОЗУ МСП

msp_BYTE msp_WriteMessageData(msp_MSGHANDLE message, msp_WORD* buffer, msp_BYTE wordcount);
//Копирование слов данных сообщения в ОЗУ МСП
//message - сообщение
//buffer - 

msp_WORD msp_ReadMessageWord(msp_MSGHANDLE message, msp_BYTE word);
//Чтение отдельных слов сообщения из ОЗУ МСП.
//message - сообщение
//word - указатель слова. 
//Допустимы значения 0-31 (смещение слова данных) или константы msp_MW_XXXX

msp_ERROR msp_WriteMessageWord(msp_MSGHANDLE message, msp_BYTE word, msp_WORD value);
//Запись отдельных слов сообщения в ОЗУ МСП.
//message - сообщение
//word - указатель слова. 
//value - новое значение
//Допустимы значения 0-31 (смещение слова данных) или константы msp_MW_XXXX

#define msp_MW_BCCW			32
#define msp_MW_CMD1			33
#define msp_MW_CMD2			34
#define msp_MW_STATUS1		35
#define msp_MW_STATUS2		36
#define msp_MW_LOOPBACK		37
#define msp_MW_WORDCOUNT	38
#define msp_MW_MODECODE		39
//msp_MW_WORDCOUNT, msp_MW_MODECODE - не слова, 5-битные поля в CMD1

/***************************************************************
   Работа с кадрами: создание, удаление, заполнение сообщениями,
   инспекция, модификация
 ***************************************************************/

msp_FRMHANDLE msp_CreateFrame(msp_DEVHANDLE device, msp_WORD FrameTime, msp_WORD MessageCount);
//Создает кадр на заданное число сообщений, исходно пустой.
//device
//FrameTime – длительность кадра в единицах по 100 мкс(?).
//MessageCount – число сообщений в кадре.
//Возврат: идент. (handle) кадра.

#define msp_DestroyFrame(frame) msp_DestroyHandle(frame)
//Удаляет кадр

msp_ERROR msp_AddMessage(msp_FRMHANDLE frame, msp_MSGHANDLE message, msp_WORD msggap);
//Добавление сообщений в кадр
//framе – кадр
//message – сообщение
//msggap – интервал между началом данного и началом следующего сообщения, мкс
//Одно и то же сообщение может быть одновременно добавлено в разные кадры или
//несколько раз в один кадр

msp_ERROR msp_AddMessages(msp_FRMHANDLE frame, msp_MSGHANDLE *messages, msp_WORD *msggaps);
//Добавление последовательности сообщений в кадр
//framе – кадр
//message - массив (хендлов) сообщений.
//			последний элемент должен содержать значение msp_NOHANDLE
//msggaps - массив интервалов времени. 
//			м.б. NULL, тогда msggap устанавливается в 0

msp_ERROR msp_AddMessagesIndirect(msp_FRMHANDLE frame, msp_MSGHANDLE **messages, msp_WORD *msggaps);
//Добавление последовательности сообщений в кадр
//framе – кадр
//messages - массив указателей на (хендлы) сообщений
//			последний элемент должен содержать значение NULL
//msggaps - массив интервалов времени. 
//			м.б. NULL, тогда msggap устанавливается в 0

msp_ERROR msp_AddMessagesIndirect2(msp_FRMHANDLE frame, msp_WORD *indexes, msp_MSGHANDLE *messages, msp_WORD *msggaps);
//Добавление последовательности сообщений в кадр
//framе – кадр
//indexes - массив индексов сообщений из пула messages.
//			последний элемент должен содержать значение 0xFFFF
//message - пул (массив) хендлов сообщений, выбираются по индексам
//msggaps - массив интервалов времени. 
//			м.б. NULL, тогда msggap устанавливается в 0

msp_BIT msp_VerifyFrameTime(msp_FRMHANDLE frame, msp_BIT adjust);
//Проверка и исправление длительности кадра
//Возврат: 1 - ОК, 0 - сумма интервалов сообщений больше
//					заданной длительности кадра
//adjust !=0 && Возврат == 0 - длительность заменяется на вычисленную
//framе – кадр

msp_MSGHANDLE msp_GetFrameMessage(msp_FRMHANDLE frame, int entry);
//Возвращает хендл сообщения по его номер в кадре
//framе – кадр
//entry - номер позиции в кадре

msp_MSGHANDLE msp_ReplaceFrameMessage(msp_FRMHANDLE frame, int entry, msp_MSGHANDLE newmessage);
//Заменяет сообщение в заданной позиции кадра другим
//Возвращает хендл сообщения старого сообщения
//framе – кадр
//entry - номер позиции в кадре
//newmessage - хендл нового сообщения

msp_WORD msp_GetFrameProp(msp_FRMHANDLE frame, msp_BYTE Property);
//Чтение характеристик кадра
//framе – кадр
//Property - указатель характеристики
//может быть одним из значений
//msp_FD_FrameTime
//msp_FD_MessageCount
//msp_FD_MaxMessgeCount

msp_ERROR msp_SetFrameProp(msp_FRMHANDLE frame, msp_BYTE Property, msp_WORD value);
//Изменение характеристик кадра
//framе – кадр
//Property - указатель характеристики
//допистимо только значение
//msp_FD_FrameTime

#define msp_FD_FrameTime		0
#define msp_FD_MessageCount		1
#define msp_FD_MaxMessgeCount	2

/***************************************************************
   Загрузка (указателя) данного кадра в стек для исполнения.
 ***************************************************************/

msp_ERROR msp_LoadFrame(msp_FRMHANDLE frame, int flags);
//Загрузка данного кадра в указатели стека А или B. 
//frame – кадр
//flags – комбинация значений (msp_STK_A и msp_STK_B несовместны)
//msp_STK_A – загрузить в стэк A
//msp_STK_B – загрузить в стэк B
//msp_AUTOREPEAT – дополнительно загружаются регистры для
//автоматического повтора кадра
//и устанавливается флажок mspF_FRAME_AUTOREPEAT

//Запуск кадра на исполнение осущесвляется функцикй msp_Command()

#define msp_AUTOREPEAT	0x0002

msp_ERROR msp_ResetFrame(msp_FRMHANDLE frame);
//Установка указателя сообзения в начало для повторного запуска кадра
//frame - кадр
//Кадр д.б. заружен

/***************************************************************
   Функции анализа состояния сообщений кадра
 ***************************************************************/

#define msp_ReadFrameWord(frame, entry, offset) msp_ReadStackWord(frame, entry, offset)
//Псевдо:
//msp_WORD msp_ReadFrameWord(msp_FRMHANDLE frame, int entry, msp_BYTE offset);
//
//Считывание слова из ОЗУ МСП, принадлежащему данному кадру.
//frame – кадр
//entry – номер дескриптора сообщения в кадре
//offset – номер слова дескриптора, может принимать значения
//msp_FD_BSW – слово состояния блока
//msp_FD_TIMETAG – временная метка
//msp_FD_MSGGAP – временной интервал до следующего сообщения
//msp_FD_MSGADDR – адрес блока сообщения
//Возврат: затребованное слово.

msp_ERROR msp_BCRetrieveMessage(msp_FRMHANDLE frame, int entry, msp_Message* buffer);
//Считывание сообщения из ОЗУ МСП в ОЗУ хоста, совместно со словами состояния из дескриптора сообщения в данном кадре.
//frame – кадр
//entry – номер дескриптора сообщения в кадре
//buffer – буфер для считывания сообщения. В буфере заполняются дополнительные поля StatusWord1/2, loopback, BSW, timetag.
//Возврат: Код ошибки или 0.
//Полный аналог msp_RetrieveMessage, но только для BC

#ifdef __cplusplus
}
#endif

#endif
