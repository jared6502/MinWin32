#include "k32.h"

#ifdef _WIN64
void *malloc(uint64_t count);
#else
void *malloc(uint32_t count);
#endif

void free(void *mem_handle);

#ifdef _WIN64
void *malloc(uint64_t count)
#else
void *malloc(uint32_t count)
#endif
{
	//stub

	//check for 0 length allocation
	if (count == 0) return 0;

	return 0;
}

void free(void *mem_handle)
{
	//stub
	return;
}