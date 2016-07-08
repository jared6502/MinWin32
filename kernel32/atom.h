#ifndef __ATOM_H__
#define __ATOM_H__

#include "k32.h"

#define MIN_ATOM 0x0000
#define MAX_ATOM 0xC000
#define STRING_ATOM 0x0000
#define INT_ATOM 0x0001
#define BAD_ATOM 0x0002

extern uint16_t APIENTRY AddAtom(char *lpString);
extern uint16_t APIENTRY AddAtomA(char *lpString);
extern uint16_t APIENTRY AddAtomW(wchar_t *lpString);

extern int AtomType(char *lpString);
extern int AtomTypeA(char *lpString);
extern int AtomTypeW(wchar_t *lpString);

extern StringAtomTableEntry *CreateLocalAtomEntry();

extern void SetIntAtomTablePtr(void *AtomTableLocation);
extern void SetStringAtomTablePtr(void *AtomTableLocation);

extern void *GetIntAtomTablePtr();
extern void *GetStringAtomTablePtr();

extern void FreeAtoms();

#endif
