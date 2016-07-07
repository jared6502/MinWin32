#include "structs.h"
#include "dbgterminal.h"
#include "mem.h"
#include "fs.h"

#define __BITS_32__
#undef __BITS_64__

void kmain
{
	//load core components to the appropriate absolute memory location
	LoadCore();
	
	//set up descriptor tables
	SetupGDT();
	SetupLDT();
	SetupIDT();
	
	return;
}

//
// this routine is called from the assembly code and will read an int to get the correct info
//

//Interrupt is accessed by the assembly code
int Interrupt;

void InterruptHandler
{
	switch(Interrupt)
	{
		
	}
	return;
}
