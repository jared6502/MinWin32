#ifndef __MEM_H__
#define __MEM_H__

#include "typedefs.h"

#define MEM_COMMIT 0x00001000
#define MEM_RESERVE 0x00002000
#define MEM_RESET 0x00080000
#define MEM_TOP_DOWN 0x00100000
#define MEM_WRITE_WATCH 0x00200000
#define MEM_PHYSICAL 0x00400000
#define MEM_RESET_UNDO 0x1000000
#define MEM_LARGE_PAGES 0x20000000

#define PAGE_NOACCESS 0x01
#define PAGE_READONLY 0x02
#define PAGE_READWRITE 0x04
#define PAGE_WRITECOPY 0x08
#define PAGE_EXECUTE 0x10
#define PAGE_EXECUTE_READ 0x20
#define PAGE_EXECUTE_READWRITE 0x40
#define PAGE_EXECUTE_WRITECOPY 0x80

#define PAGE_GUARD 0x100
#define PAGE_NOCACHE 0x200
#define PAGE_WRITECOMBINE 0x400

#define PAGE_TARGETS_INVALID 0x40000000
#define PAGE_TARGETS_NO_UPDATE 0x40000000

#ifdef _WIN64
extern void *malloc(uint64_t count);
#else
extern void *malloc(uint32_t count);
#endif

extern void free(void *mem_handle);

extern void *GlobalAlloc();
extern void *GlobalFree();

extern void *HeapAlloc();
extern void *HeapFree();

extern void *LocalAlloc();
extern void *LocalFree();

extern void *VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD  flAllocationType, DWORD  flProtect);
extern void *VirtualFree();

#endif
