
#ifndef NULLDEV_H
#define NULLDEV_H

#include "types.h"
#include "errors.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
Это callback-ф-ции, которые должны определить приложения (или .dll), для имитации устройств.
Это недокументированные функции.
*/

typedef msp_ERROR (*null_Open)(int DrvDevNo, int flags);
typedef msp_ERROR (*null_Close)(int DrvDevNo);
typedef enum null_bank_t { null_Regs, null_Ram, null_XRam } null_bank;
typedef msp_WORD (*null_Read)(int DrvDevNo, null_bank bank, msp_DWORD address);
typedef msp_ERROR (*null_Write)(int DrvDevNo, null_bank bank, msp_DWORD address, msp_WORD data);

typedef msp_ERROR (*null_GetDeviceInfo)(int DrvDevNo, msp_DeviceInfo **I, msp_DWORD *BoardTypeId);
typedef msp_ERROR (*null_GetDeviceInfoEx)(int DrvDevNo, msp_DeviceInfo **I, msp_DeviceTypeInfo **TI);
typedef int (*null_GetNumberOfDevices)(void);

typedef struct {
  null_Open  Open;
  null_Close Close;
  null_Read Read;
  null_Write Write;
  null_GetNumberOfDevices GetNumberOfDevices;
  null_GetDeviceInfo GetDeviceInfo;      // | access: if (GetDeviceInfoEx) GetDeviceInfoEx();
  null_GetDeviceInfoEx GetDeviceInfoEx;  // |         else if (GetDeviceInfo) GetDeviceInfo();
} null_Callbacks;

void null_SetSimulator(null_Callbacks *entries);
void null_SetError(msp_ERROR e);
msp_DeviceTypeInfo *null_GetDeviceTypeInfo(int DeviceTypeId);

#ifdef __cplusplus
}
#endif

#endif

