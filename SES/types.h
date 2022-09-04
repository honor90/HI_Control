/***************************************************************
	types.h
	Определения примитивных типов.

	RTL2 - Библиотека времени выполнения МСП/ПМКО.

	(с) Д.Гурьев, 2000.
	По заказу НТЦ Модуль.
 ***************************************************************/
/***************************************************************
	История изменений:

 ***************************************************************/

#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>

typedef unsigned int    msp_ERROR;
typedef unsigned int    msp_DWORD;
typedef unsigned short  msp_WORD;
typedef unsigned char   msp_BYTE;
typedef unsigned char   msp_BIT; //Sorry
typedef signed int      msp_SIGNED_DWORD;
typedef signed short    msp_SIGNED_WORD;
typedef signed char     msp_SIGNED_BYTE;
#if defined(__LP64__) || defined(_WIN64)
typedef unsigned	long long	msp_QWORD;
#endif

#ifndef HANDLE
typedef void*	HANDLE;
#endif

#ifdef _MSP_INTERNAL_
	typedef void*	msp_HANDLE;
#else
	typedef struct msp_HANDLE_s { msp_DWORD msp_opaque; }*	msp_HANDLE;
#endif

#define msp_NOHANDLE	((msp_HANDLE) NULL)

typedef msp_WORD			msp_MODE;
typedef msp_BYTE			msp_DIR;
#define msp_BOOL			msp_BYTE
#define msp_FALSE			0
#define msp_TRUE			1

typedef wchar_t msp_WCHAR;

#ifdef __cplusplus
#define MSP_CONST const
#else
#define MSP_CONST
#endif

#endif
