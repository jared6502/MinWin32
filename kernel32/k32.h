#ifndef __K32_H__
#define __K32_H__

#include "typedefs.h"
#include "globals.h"
#include "cp.h"

#include "kthrow.h"
#include "atom.h"
#include "lstring.h"
#include "mem.h"
#include "kernel_call.h"

#define DLL_PROCESS_ATTACH 1
#define DLL_THREAD_ATTACH 2
#define DLL_THREAD_DETACH 3
#define DLL_PROCESS_DETACH 0

extern BOOL APIENTRY K32_Entry(HINSTANCE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);
extern ProcessData *ProcData;
extern ThreadData *ThdData;

#endif
