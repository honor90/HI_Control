/* -*- mode:c; coding:windows-1251; -*- */
/***************************************************************
	errors.h
	П/п индикации ошибок.

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Гурьев, 2000-2008.
	По заказу НТЦ Модуль.
 ***************************************************************/
/***************************************************************
	История изменений:
	14.01.2002 Чихичин Д.А.
		дополнено макросами определения ошибок для модуля gsw
	23.09.2003 Чихичин Д.А.
		дополнено макросами определения ошибок для модуля gsw
 ***************************************************************/

#ifndef ERRORS_H
#define ERRORS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

msp_ERROR msp_GetLastError();
//Возвращает код ошибки последней операции.
int msp_GetSystemError();
//Возвращает код системной ошибки последней операции.
msp_ERROR msp_WasError();
//Возвращает код ошибки последней операции, завершившейся с ошибкой.

typedef long msp_SSError;

msp_SSError msp_GetSubsystemError();
//Возвращает код ошибки нижележащей подсистемы (в данный момент - только код ошибки visa)

#define msp_NOERROR						0
#define msp_ERROR_INVALID_DEVICE_HANDLE	1
#define msp_ERROR_INVALID_PARAMETER		2
#define msp_ERROR_NOT_INITIALIZED		3
#define msp_ERROR_DEVICE_BUSY			5
#define msp_ERROR_SYSTEM_ERROR			4
#define msp_ERROR_INTERNAL_ACCESS_ERROR	6
#define msp_ERROR_NO_HOST_MEMORY		7
#define msp_ERROR_ADDRESS_OUT_OF_RAM	8
#define msp_ERROR_IRQ_BUSY				9
#define msp_ERROR_IRQ_CANCELLED			10
#define msp_ERROR_INTERNAL_INTEGRITY_ERROR 11
#define msp_ERROR_MISSING_DELAY_FUNC    12
#define msp_ERROR_UNSUPPORTED_FUNCTION  13
#define msp_ERROR_UNKNOWN_DEVICE_TYPE	14
#define msp_ERROR_UNSUPPORTED_DRIVER_TYPE	15
#define msp_ERROR_UNSUPPORTED_BUS_TYPE	16
#define msp_ERROR_DRIVER_NOT_FOUND		17

#define msp_ERROR_NO_FREE_RAM			20
#define msp_ERROR_INVALID_RAM_HANDLE	21
#define msp_ERROR_ILLEGAL_HANDLE_TYPE	22
#define msp_ERROR_HANDLE_OUT_OF_SCOPE	23
#define msp_ERROR_HANDLE_IN_USE			24
#define msp_ERROR_ADDRESS_OUT_OF_OBJECT	25

#define msp_ERROR_INVALID_FLAG			30
#define msp_ERROR_INVALID_VREG			31
#define msp_ERROR_UNSUPPORTED_MODE		32
#define msp_ERROR_MODE_NOT_SELECTED		33
#define msp_ERROR_INCOMPATIBLE_MODE		34
#define msp_ERROR_INCOMPATIBLE_CONFIGURATION	35
#define msp_ERROR_FRAM_NOT_RESERVED		36

#define msp_ERROR_INCOMPATIBLE_STACK	40
#define msp_ERROR_INCOMPATIBLE_FRAME	40
#define msp_ERROR_NOT_LOADED			41
#define msp_ERROR_INDEX_OUT_OF_RANGE	42
#define msp_ERROR_NO_NEXT_MESSAGE		43
#define msp_ERROR_MESSAGE_IN_PROGRESS	44

#define msp_ERROR_INVALID_MESSAGE_FORMAT	50
#define msp_ERROR_MESSAGE_FIELD_NOT_EXISTS	51
#define msp_ERROR_FRAME_EXCEEDS_SIZE_LIMIT	52

#define msp_ERROR_INCOMPATIBLE_BUFFER	60
#define msp_ERROR_BUFFER_NOT_CONNECTED  61
#define msp_ERROR_BUFFER_BUSY_SAFE		62
#define msp_ERROR_BUFFER_BUSY_UNSAFE	63
#define msp_ERROR_STREAM_DISABLED		64
#define msp_ERROR_STREAM_IN_USE			65
#define msp_ERROR_STREAM_CORRUPTED		66
#define msp_ERROR_ILLEGAL_COMMAND_WORD	67
#define msp_ERROR_NOT_MODE_CODE			68

////////// Дополнения для ГСП ////////////////
#define msp_ERROR_TOO_MANY_FRAMES			70
#define msp_ERROR_INVALID_MESSAGE_HANDLE	71
#define msp_ERROR_INVALID_FRAME_HANDLE		72

#define msp_ERROR_ANSWER_NOT_MATCH			80
#define msp_ERROR_ANSWER_MISSING_WORDS		81
#define msp_ERROR_ANSWER_EXTRA_WORDS		82
#define msp_ERROR_INVALID_MESSAGE			83
#define msp_ERROR_ANSWER_ERROR				84
#define msp_ERROR_ANSWER_ANOTHER_CHANNEL	85
#define msp_ERROR_ANSWER_RT_BUSY			86 //07.05.2007

#define msp_ERROR_INTERNAL_ALGORITHM		90


/////////// Дополнения для USB ////////////////
#define msp_ERROR_EMPTY_FRAME				100
#define msp_ERROR_OVERLOAD_BUFFERS			101
#define msp_ERROR_INVALID_REQUEST			102

#define msp_ERROR_USB_EXCHANGE				200
#define msp_ERROR_USB_NOT_SUPPORT			201
#define msp_ERROR_USB_ACCESS				202
#define msp_ERROR_USB_FTDI_ERROR			203
#define msp_ERROR_USB_RESPONSE_TIMEOUT      204
#define msp_ERROR_USB_RESPONSE_FAILURE      205

#define msp_ERROR_DEVICES_NOT_FOUND			210
///
#define msp_ERROR_IMPOSING_IS_IMPOSSIBLE    220

////////// Дополнения для модуля cash /////////////
#define msp_ERROR_CASH_DEVICE_TABLE_OVERLOAD	301
#define msp_ERROR_DEVICE_NOT_INTO_CASH			302
#define msp_ERROR_CASH_INCORRECT_CALL_FUNCTION	303

#define msp_ERROR_VXI_ERROR					320

#ifdef __cplusplus
}
#endif

#endif
