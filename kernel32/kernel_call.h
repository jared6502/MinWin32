#ifndef __KERNEL_CALL_H__
#define __KERNEL_CALL_H__

#include "typedefs.h"

#define K_ALLOC_MEM 0x00000001

extern int KCall(void *data);
extern void *PKCall(void *data);

typedef struct
{
	uint32_t FunctionCode;
	uint32_t ByteCount;
} k_alloc_mem;


#endif
