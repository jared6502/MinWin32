#include "k32.h"

#include "ansi_cp.h"
#include "ucs2_cp.h"
#include "ucase_cp.h"
#include "lcase_cp.h"

//variable declarations
ProcessData *ProcData;
ThreadData *ThdData;

k_alloc_mem InitMem;

uint32_t ThreadID;

//function definitions
BOOL APIENTRY K32_Entry(HINSTANCE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved);

//code
BOOL APIENTRY K32_Entry(HINSTANCE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	//stub
	void *Tdata;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		//allocate ProcessData structure
		//ProcData = (ProcessData *)malloc(sizeof(ProcessData));
		InitMem.FunctionCode = K_ALLOC_MEM;
		InitMem.ByteCount = sizeof(ProcessData);
		ProcData = PKCall(&InitMem);
		ThdData = 0;
		ThreadID = 0;
		break;

	case DLL_THREAD_ATTACH:
		//allocate a new thread data structure
		Tdata = malloc(sizeof(ThreadData));

		//check for memory allocation error
		if (Tdata == 0) return FALSE;

		((ThreadData *)Tdata)->hnd = ThreadID;
		((ThreadData *)Tdata)->next = 0;

		ThreadID++;

		if (ThdData == 0)
		{
			//add thread data list root entry
			ThdData = Tdata;
			return TRUE;
		}
		else
		{
			ThreadData *thread;
			thread = ThdData;
			//add the new thread data structure into the list
			while (thread->next != 0)
			{
				thread = thread->next;
			}
			thread->next = Tdata;
			return TRUE;
		}
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		//begin cleanup of process data

		//clean up atom lists
		FreeAtoms();

		//clean up thread(s)

		//finally, delete ProcessData structure itself
		free(ProcData);
		break;
	}

	

	//everything's good, return
	return TRUE;
}
