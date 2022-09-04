/***************************************************************
	rt.h
	Поддержка режима ОУ.

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Гурьев, 2000.
	По заказу НТЦ Модуль.
 ***************************************************************/
/***************************************************************
	История изменений:

 ***************************************************************/

#ifndef RT_H
#define RT_H

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
	Простые типы данных
 ***************************************************************/

typedef msp_HANDLE  msp_BUFHANDLE;
typedef msp_BYTE    msp_SUBADDRESS;

/***************************************************************
    Константы и макросы формирования упр. слова ПА (УСПА)
 ***************************************************************/

//Типоразмер буфера
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

//Флажки буфера или ПА
//8,16,32 - совпадают по позициям с одноименными аппаратными
//флажками в УСПА.
#define msp_SA_ROLLOVER_INT                         8
    //Прерывание по переходу в начало кольцевого буфера
#define msp_SA_EOM_INT                                      16
    //Прерывание по концу сообщения
#define msp_SA_DOUBLE_BUFFERING                     32
    //Включение двойной буферизации для данного буфера
    //Особенность: в УСПА физически только один флажок
    //Если к ПА подключено 2 двойных буфера, физический
    //флажок устанавливается, если ОБА буфера установили
    //флажок в 1
#define msp_SA_STREAMING                            64
    //Включение потоковых операций (влияет только на RTL)
#define msp_SA_BUSY									128
	//Выставление признака занятости для ПА через дескриптор
	//буфера. Учитывается, если только установлен флаг
	//mspFS_SET_BUSY_VIA_BUFFER_HANDLE

#define msp_SA_FLAG_mask                            0xF8

/***************************************************************
    Управляющие флажки (опции) для п\п ОУ
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
    Создание буфера для ПА
 ***************************************************************/

msp_BUFHANDLE msp_CreateBuffer(msp_DEVHANDLE device,
                                                       msp_BYTE BufferSize,
                                                       msp_BYTE BufferFlags);
//Создание буфера для данных сообщения ОУ.
//device – устройство
//BufferSize – размер буфера - одна из констант
//                                  msp_SA_SINGLE_BUFFER
//                                  msp_SA_DOUBLE_BUFFER
//                                  msp_SA_CIRCULAR_BUFFER_128 - msp_SA_CIRCULAR_BUFFER_8192
//BufferFlags - флажки используются для формирования УСПА,
//                                  когда буфер подключается к ПА; одна из констант
//                                  msp_SA_ROLLOVER_INT
//                                  msp_SA_EOM_INT
//                          флажки msp_SA_DOUBLE_BUFFERING, msp_SA_STREAMING устанавливаются
//                          автоматически в зависимости от типоразмера буфера

#define msp_DestroyBuffer(buffer) msp_DestroyHandle(buffer)
//Уничтожение (освобождение) буфера. 

/***************************************************************
	Подключение буфера к ПА.
 ***************************************************************/

msp_ERROR msp_SetSABuffer(msp_DEVHANDLE device,
                                              msp_SUBADDRESS subaddress,
                                              msp_DIR dir,
                                              msp_BUFHANDLE buffer,
                                              int flags);
//Установка или замена буфера для ПА.
//device – устройство
//subaddress – ПА
//dir - направление передачи, одна из констант
//  msp_DIR_TX – замена буфера для передачи
//  msp_DIR_RX – замена буфера для приема
//  msp_DIR_BCST – замена буфера для приема широковещаетельных сообщений
//buffer – ид. (handle) области ОЗУ МСП
//flags – дополнительные параметры операции, комбинация следующих констант
//  msp_STK_A – данные заносятся в lookup table A
//  msp_STK_B – данные заносятся в lookup table B; несовместно с msp_STK_A;
//          Если не указано ни msp_STK_A, ни msp_STK_B, считается msp_STK_A
//  msp_SA_FREE_RAM – автоматически освобождается прежний буфер
//  msp_SA_RETURN_IF_BUSY - проверка, не используется ли ПА в данный момент и выход
//  msp_SA_WAIT_IF_BUSY - проверка, не используется ли ПА в данный момент и
//                                          ожидание освобождения (цикл опроса)

msp_BUFHANDLE msp_GetSABuffer(msp_DEVHANDLE device, msp_SUBADDRESS subaddress,
                                                      msp_DIR dir, int flags);
//Считывание идентификатора буфера для данного ПА.
//device – устройство
//subaddress – ПА
//dir - направление передачи, одна из констант
//  msp_DIR_TX – выбор буфера для передачи
//  msp_DIR_RX – выбор буфера для приема
//  msp_DIR_BCST – выбор буфера для приема широковещаетельных сообщений
//flags – дополнительные параметры операции, комбинация следующих констант
//  msp_STK_A – данные из lookup table A
//  msp_STK_B – данные из lookup table B; несовместно с msp_STK_A;
//  Если нет ни msp_STK_A, ни msp_STK_B, считается msp_STK_A
//Возврат: идентификатор (handle) области ОЗУ МСП.

/***************************************************************
	Типы и макросы для конфигрурирования ПА в стиле "Indirect" 
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
	Конфигурирование ПА.
 ***************************************************************/

msp_ERROR msp_ConfigureSA(
                    msp_DEVHANDLE device,
                    msp_SUBADDRESS subaddress,
                    msp_BUFHANDLE rxbuffer,
                    msp_BUFHANDLE txbuffer,
                    msp_BUFHANDLE bcstbuffer,
                    int flags);
//Установка всех буферов ПА
//device – устройство
//subaddress – ПА
//txbuffer,
//rxbuffer,
//bcstbuffer – идентификаторы (handle) буферов
//flags – дополнительные параметры операции, комбинация следующих констант
//          msp_STK_A – данные заносятся в lookup table A
//          msp_STK_B – данные заносятся в lookup table B
//          msp_SA_FREE_RAM – автоматически освобождаются старые буфера

msp_ERROR msp_ConfigureSAIndirect(
                    msp_DEVHANDLE device,
                    msp_SUBADDRESS subaddress,
                    MSP_CONST msp_SAConfig *config,
                    msp_SABuffers *buffers,
                    int flags);
//device – устройство
//subaddress – ПА
//config - конфигурация ПА
//buffers - буфера ПА. М.б. NULL. Если не NULL, используются указанные
//                  буфера; проверяются на соответствие config. Если к-либо буфер
//                  есть msp_NOHANDLE, ф-я создает буфер автоматически, и возвращает
//                  handle в соотв. поле. Если буфер для данного направления не
//                  нужен (msp_SA_NO_BUFFER), соотв. поле должно быть NULL.
//flags – дополнительные параметры операции, комбинация следующих констант
//          msp_STK_A – данные заносятся в lookup table A
//          msp_STK_B – данные заносятся в lookup table B
//          msp_SA_FREE_RAM – автоматически освобождаются старые буфера

msp_ERROR msp_ConfigureAllSAIndirect(
                    msp_DEVHANDLE device,
                    MSP_CONST msp_SAConfig *configs,
                    msp_SABuffers *buffers,
                    int flags);
//Конфигурироувание всех 32 ПА
//device – устройство
//config - конфигурации ПА (массив из 32 элементов), каждый используется
//                  как в msp_ConfigureSAIndirect
//buffers - массив 32 групп буферов ПА. Каждый элемент используется как
//                  в msp_ConfigureSAIndirect. М.б. NULL.
//flags – дополнительные параметры операции, комбинация следующих констант
//          msp_STK_A – данные заносятся в lookup table A
//          msp_STK_B – данные заносятся в lookup table B
//          msp_SA_FREE_RAM – автоматически освобождаются старые буфера

/***************************************************************
	П\п для доступа к флажкам буфера
 ***************************************************************/

msp_ERROR msp_SetBufferFlag(msp_BUFHANDLE buffer, msp_BYTE flagid,
                                                    msp_BIT value);
//Установка флажков буфера.
//Флажки буфера влияют на УСПА. Если буфер подключен (msp_SetSABuffer())
//УСПА обновляется немедленно.
//buffer - буфер
//flagid - идент. флажка, одно из значений msp_SA_XXXX
//value - новое значение, одна из констант 0 или 1

msp_BIT msp_GetBufferFlag(msp_BUFHANDLE buffer, msp_BYTE flagid);
//Чтенин флажков буфера.
//Если буфер подключен (msp_SetSABuffer()), считываются фактические
//значения из УСПА
//buffer - буфер
//flagid - идент. флажка, одно из значений msp_SA_XXXX
//          для флажка msp_SA_DOUBLE_BUFFERING считанное
//          значение может отличаться от значения, заданного
//          в msp_SetBufferFlags (это не ошибка а систеиная функция)

/***************************************************************
	Пересылка данных из\в буфер
 ***************************************************************/

msp_WORD msp_ReadSAData(msp_BUFHANDLE sabuffer, msp_WORD* buffer,
                                            msp_WORD offset, msp_WORD wordcount, int flags);
//Чтение данных из буфера
//sabuffer – идентификатор (handle) буфера в ОЗУ МСП
//offset - смещение 1-го читаемого слова в sabuffer
//buffer – область ОЗУ хоста для считывания
//wordcounut – сколько слов считать
//flags – дополнительные параметры операции для режима двойной буферизации,
//  комбинаций следующих  значений:
//  msp_SA_ACTIVE_BUFFER – из активного буфера
//                  (смещение считается от начала активной половины)
//  msp_SA_INACTIVE_BUFFER – из неактивного буфера
//                  (смещение считается от начала неактивной половины)
//                  если для msp_SA_DOUBLE_BUFFER не указано ни
//                  msp_SA_ACTIVE_BUFFER, ни msp_SA_INACTIVE_BUFFER,
//                  смещение - от начала как, как в обычном буфере
//  msp_SA_INACTIVE_BUFFER + msp_SA_SAFE_READ
//                  – из неактивного буфера,
//                    выполнять процедуру “безопасного чтения”
//  msp_SA_RETURN_IF_BUSY - проверка, не используется ли ПА в данный момент и выход
//  msp_SA_WAIT_IF_BUSY - проверка, не используется ли ПА в данный момент и
//                                          ожидание освобождения (цикл опроса)
//Возврат: число фактически прочитанных слов; при ошибке - 0;


msp_WORD msp_WriteSAData(msp_BUFHANDLE sabuffer, msp_WORD* buffer,
                                             msp_WORD offset, msp_WORD wordcount, int flags);
//Запись данных в буфер
//sabuffer – идентификатор (handle) буфера в ОЗУ МСП
//buffer – область ОЗУ хоста с данными
//offset - смещение 1-го записываемого слова в sabuffer
//wordcounut – сколько слов записать
//flags – дополнительные параметры операции для режима двойной буферизации,
//  комбинаций следующих  значений:
//  msp_SA_ACTIVE_BUFFER – в активный буфер
//                  (смещение считается от начала активной половины)
//  msp_SA_INACTIVE_BUFFER – в неактивный буфер
//                  (смещение считается от начала неактивной половины)
//                  если для msp_SA_DOUBLE_BUFFER не указано ни
//                  msp_SA_ACTIVE_BUFFER, ни msp_SA_INACTIVE_BUFFER,
//                  смещение - от начала как, как в обычном буфере
//  msp_SA_SWAP_BUFFER - после записи активный и неактивный буфера
//					меняются ролями
//  msp_SA_RETURN_IF_BUSY - проверка, не используется ли ПА в данный момент и выход
//  msp_SA_WAIT_IF_BUSY - проверка, не используется ли ПА в данный момент и
//Возврат: число фактически записаных слов.

/***************************************************************
	Пересылка данных из\в буфер - потоковый режим
 ***************************************************************/

msp_WORD msp_ReadSAStream(msp_BUFHANDLE sabuffer, msp_WORD* buffer, msp_WORD wordcount);
//Чтение данных из буфера в потоковом режиме
//sabuffer – идентификатор (handle) буфера в ОЗУ МСП
//                  (предполагается msp_SA_CIRCULLAR_BUFFER_XXXXXXX)
//buffer – область ОЗУ хоста для считывания
//wordcounut – сколько слов считать
//Возврат: число фактически прочитанных слов;
// = 0 если в буфер не поступило дополнительных данных,
//     а тскже при ошибке

msp_WORD msp_WriteSAStream(msp_BUFHANDLE sabuffer, msp_WORD* buffer, msp_WORD wordcount);
//Запись данных в буфер в потоковом режиме
//sabuffer – идентификатор (handle) буфера в ОЗУ МСП
//                  (предполагается msp_SA_CIRCULLAR_BUFFER_XXXXXXX)
//buffer – область ОЗУ хоста с данными
//wordcounut – сколько слов записать
//Возврат: число фактически записанных слов;
// = 0 если в буфере нет места для новых данных,
//     а тскже при ошибке

msp_ERROR msp_MarkSAStream(msp_BUFHANDLE sabuffer, int flags);
//Later.
//Flags:
#define msp_STREAM_READ     1
#define msp_STREAM_WRITTEN  2
#define msp_STREAM_EMPTY    3

#define msp_ResetSAStream msp_ResetSABuffer
//Доходчивый псевдоним. См. msp_ResetSABuffer

/***************************************************************
	Очистка и установка начальной позиции буфера
 ***************************************************************/

msp_ERROR msp_ResetSABuffer(msp_BUFHANDLE sabuffer, msp_WORD offset);
//Установка указателей текущей позиции буфера в заданное значение
//sabuffer - идентификатор (handle) буфера в ОЗУ МСП
//offset - смещение текущей позиции от начала буфера
//			для msp_SA_DOUBLE_BUFFER допустимы значения 0 и 32
//			для msp_SA_CIRCULAR_BUFFER_ХХХХ - любые, не выходящие за пределы буфера
//			для msp_SA_SINGLE_BUFFER - вызывать запрещено

/***************************************************************
	Типы и константы для конфигурирования управляющих таблиц
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
	Конфигурирование таблицы запрета команд (illegalizetion)
 ***************************************************************/

msp_ERROR msp_SetIllegalCommands(msp_DEVHANDLE device, msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, msp_BIT illegal);
//Запрещение/разрешение* группы команд
//device - устройство
//rangeCmdWord0,
//rangeCmdWord1 - образцы команд 1553, определяющие область действия операции
//          для каждого подполя команды sampleCmdWord1 задает начальное
//          значение, а sampleCmdWord2 - конечное
//          Используются подполя:
//          <RT> :  = 31 - операция относится к широковещательным командам,
//                          любое другое значение - операция относится к командам,
//                          адресованным данному ОУ
//          <TX> :  передача/прием
//          <SA> :  № ПА
//          <WC/MC> : число слов/код режима (mode code)
//illegal - значение признака запрещения команды

msp_ERROR msp_SetIllegalCommandsDW(msp_DEVHANDLE device, msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, msp_DWORD illegal);
//Как msp_SetIllegalCommands(), только подполе <WC/MC> игнорируется,
//а illegal содержит битовую маску для всех 32х возможных <WC/MC>

msp_BIT msp_IsIllegalCommand(msp_DEVHANDLE device, msp_WORD CmdWord);
//Запрещена ли данная команда

#define msp_SetIllegalCommand(device, cmd, illegal) \
	msp_SetIllegalCommands(device, cmd, cmd, illegal)

msp_ERROR msp_SetIllegalCommandsIndirect(
    msp_DEVHANDLE device,
    msp_rangeCmdWords *ranges,
    int count,
    msp_BIT illegal);
//Запрещение/разрешение* группы команд
//device - устройство
//ranges - массив пар граничных команд (используются как в msp_SetIllegalCommands)
//count - длина этого массива
//illegal - значение признака запрещения команды

msp_ERROR msp_IllegalizeForBuffer(msp_BUFHANDLE buffer, msp_BYTE lowlen, msp_BYTE highlen);
//Запрещение/разрешение группы команд, связанных с данным буфером
//Требует предварительной установки флага mspFS_RT_ILLEGALIZE_FOR_BUFFER
//Для подключенного буфера отрабатывает немендленно, для неподключенного -
//в момент подключения
//Все команды, в заданном интервале числа слов данных объявляются
//разрешенными, остальные - запрещенными
//buffer - дескриптор буфера
//lowlen - мин. число слов данных
//highlen - макс. число слов данных

/***************************************************************
	Конфигурирование таблицы неготовности ПА
 ***************************************************************/

msp_ERROR msp_SetBusySA(msp_DEVHANDLE device, msp_WORD rangeCmdWord0, msp_WORD rangeCmdWord1, msp_BIT busy);
//Установка признака занятосьт группы ПА
//device - устройство
//rangeCmdWord0,
//rangeCmdWord1 - образцы команд, определяющие область действия операции
//          для каждого подполя команды sampleCmdWord1 задает начальное
//          значение, а sampleCmdWord2 - конечное
//          Используются подполя:
//          <RT> :  = 31 - операция относится к широковещательным командам,
//                          любое другое значение - операция относится к командам,
//                          адресованным данному ОУ
//          <TX> :  передача/прием
//          <SA> :  № ПА
//busy - значение признака занятости ПА

msp_BIT msp_GetBusySA(msp_DEVHANDLE device, msp_WORD CmdWord);
//Опрос признака занятосьт ПА

msp_ERROR msp_SetBusySAIndirect(
    msp_DEVHANDLE device,
    msp_rangeCmdWords *ranges,
    int count,
    msp_BIT busy);
//Установка признака занятосьт группы ПА
//device - устройство
//ranges - массив пар граничных команд (используются как в msp_SetBusySA)
//count - длина этого массива
//busy - значение признака занятости ПА

/***************************************************************
	Конфигурирование таблиц для автоматической обработки
	сообщений mode code
 ***************************************************************/

msp_ERROR msp_SetModeCodeData(msp_DEVHANDLE device, msp_WORD CmdWord, msp_WORD data);
//Установка слова данных для команд mode code
//device - устройство
//CmdWord - команда, для которой устанавливаются данные.Используются подполя:
//          <RT> :  = 31 - операция относится к широковещательным командам,
//                          любое другое значение - операция относится к командам,
//                          адресованным данному ОУ
//          <TX> :  передача/прием
//          <MC> :  код режима (mode code)
//data - значение слова данных

msp_WORD  msp_GetModeCodeData(msp_DEVHANDLE device, msp_WORD CmdWord);
//Выборка слова данны для команд mode code
//device - устройство
//CmdWord - команда, для которой считываются данные.
//                  Используется как в msp_SetModeCodeData
//Возврат: значение слова данных

msp_ERROR msp_SetModeCodeDataIndirect(
    msp_DEVHANDLE device,
    msp_ModeCodeInitData *data);
//Установка слов данных для группы команд mode code
//device - устройство
//data - массив пар <команда, данные>. Каждая пара обрабатывается
//                  аналогично параметрам msp_SetModeCodeData(). Признак конца
//                  массива - нулевое CmdWord

msp_ERROR msp_SetModeCodeInt(msp_DEVHANDLE device, msp_WORD CmdWord, msp_BIT enable);
//Разрешение прерывания по конкретной команде mode code
//device - устройство
//CmdWord - команда, для которой разрешается/запрещается прерывание
//                  Используется как в msp_SetModeCodeData
//enable - значение признака разрешения прерывания

msp_BIT msp_GetModeCodeInt(msp_DEVHANDLE device, msp_WORD CmdWord);
//Разрешено ли прерывания по конкретной команде mode code
//device - устройство
//CmdWord - команда, для которой разрешается/запрещается прерывание
//                  Используется как в msp_SetModeCodeData

msp_ERROR msp_SetModeCodeIntIndirect(
    msp_DEVHANDLE device,
    msp_WORD *CmdWords,
    msp_BIT enable);
//Разрешение прерывания для группы конкретных команд mode code
//device - устройство
//CmdWords - массив команд, каждая используется как в msp_SetModeCodeData;
//                          признак конца массива - значение 0

/***************************************************************
	Работа со стеком команд
 ***************************************************************/

msp_STKHANDLE msp_CreateStack(msp_DEVHANDLE device);
//Создание стека команд ОУ (резервирование области ОЗУ).
//Размер стека определяется текущими установками устройства.
//Для стека резервируется область, выравненная на границу, равную размеру. ???
//device – устройство
//Возврат: идентификатор (handle) стека.

#define msp_DestroyStack(stack) msp_DestroyHandle(stack)
//Уничтожение стека.
//stack – идентификатор (handle) стека

msp_ERROR msp_RTLoadStack(msp_STKHANDLE stack, int flags);
//Загрузка данного стека в качестве стека A или B.
//stack – идентификатор (handle) стека
//flags – одно из значений
//  msp_STK_A – загрузить в стэк A
//  msp_STK_B – загрузить в стэк B

msp_ERROR msp_RTLoadStackWithOffset(msp_STKHANDLE stack, int start, int flags);
//Загрузка данного стека в качестве стека A или B.
//с установкой начального номера сообщения
//stack – идентификатор (handle) стека
//start - начальный номер сообщения
//flags – одно из значений
//	msp_STK_A – загрузить в стэк A
//	msp_STK_B – загрузить в стэк B

//See also msp_SetStkStart (config.h)

/***************************************************************
   Анализ состояния обработки сообщений
 ***************************************************************/

msp_ERROR msp_RTRetrieveMessage(msp_STKHANDLE stack, int index, msp_Message* buffer);
//То же, что msp_RetrieveMessage, но только для стека команд RT

msp_ERROR msp_RetrieveMCMessage(msp_STKHANDLE stack, int index, msp_WORD* CmdWord, msp_WORD* DataWord);
//Выборка сообщения “mode code” из стэка КШ.
//stack – стек
//index – порядковый номер события в стэке или спец. значение
//                  msp_NEXT_MESSAGE,
//                  msp_SAME_MESSAGE
//                  msp_LAST_RECEIVED (см. msp_RetrieveMessage())
//CmdWord – командное слово (буфер для чтения)
//DataWord – слово данных (буфер для чтения)
//Если текущее сообщение - не "mode code", возврат с кодом msp_ERROR_NOT_MODECODE,
//позиция чтения из стека не изменяется.

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
//Аналогично msp_RTRetrieveMessage, но вместо самого сообщения
//выбираеются данные "о нем" в стр-ру msp_MessageInfo.
// - Для того, чтобы можно было сделать SAFE_READ из буфера.

#ifdef __cplusplus
}
#endif

#endif
