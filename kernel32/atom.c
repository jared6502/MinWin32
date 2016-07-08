#include "k32.h"

//variable declarations

//function definitions
uint16_t APIENTRY AddAtom(char *lpString);
uint16_t APIENTRY AddAtomA(char *lpString);
uint16_t APIENTRY AddAtomW(wchar_t *lpString);

int AtomType(char *lpString);
int AtomTypeA(char *lpString);
int AtomTypeW(wchar_t *lpString);

StringAtomTableEntry *CreateLocalAtomEntry();
void Init_Atom_table();
uint16_t NextAtom();

void SetIntAtomTablePtr(void *AtomTableLocation);
void SetStringAtomTablePtr(void *AtomTableLocation);

void *GetIntAtomTablePtr();
void *GetStringAtomTablePtr();

void FreeAtoms();

//code
uint16_t APIENTRY AddAtom(char *lpString)
{
	return AddAtomW(Ansi2Ucs2(lpString));
}

uint16_t APIENTRY AddAtomA(char *lpString)
{
	return AddAtomW(Ansi2Ucs2(lpString));
}

uint16_t APIENTRY AddAtomW(wchar_t *lpString)
{
	if (lpString == 0) return 0; //null pointer, return error

	StringAtomTableEntry *atom;
	StringAtomTableEntry *newatom;
	wchar_t *AtomName;

	AtomName = (wchar_t *)malloc(lstrlenW(lpString) * sizeof(wchar_t));

	AtomName = lstrcpyW(AtomName, lpString);

	switch (AtomTypeW(lpString))
	{
	case STRING_ATOM:

		//check if entry already exists
		atom = ProcData->LocalStringAtomTable;

		while (atom != 0)
		{
			if (lstrcmpiW(atom->String, lpString) == 0)
			{
				//string matched
				//increment refcount
				atom->refcount++;
				free(AtomName);
				return atom->id;
			}
			else
			{
				//string did not match, go to next entry
				atom = atom->next;
			}
		}
		//did not find the entry
		//create it
		if (ProcData->LocalStringAtomTable == 0) ProcData->LocalStringAtomTable = CreateLocalAtomEntry();
		atom = ProcData->LocalStringAtomTable;

		int i;

		while (atom->next != 0)
		{
			//place new atom into list
			if ((((StringAtomTableEntry *)(atom->next))->id - atom->id) == 1)
			{
				//move to next atom
				atom = atom->next;
			}
			else if ((((StringAtomTableEntry *)(atom->next))->id - atom->id) == 0)
			{
				//this should never happen.
				//if it does, this indicates a huge error.
				//this means two entries have the same ID.
				//should probably terminate the program right here
				free(AtomName);
				kthrow(K32_DUPLICATE_ATOM_DEFINITIONS);
			}
			else
			{
				//found the first smaller atom number
				//insert new atom into atom list at this point
				newatom = CreateLocalAtomEntry();

				if (newatom == 0) return 0; //space not allocated, return error

				//add new atom into atom list
				newatom->id = atom->id + 1;
				newatom->next = atom->next;
				newatom->refcount = 1;
				//newatom->String = lstrcpyW(newatom->String, AtomName);
				lstrcpyW(newatom->String, AtomName);
				free(AtomName);
				atom->next = newatom;
				return newatom->id;
			}
		}

		//reached the end of the list, add a new atom
		newatom = CreateLocalAtomEntry();

		if (newatom == 0) return 0; //space not allocated, return error

		//add new atom into atom list
		newatom->id = atom->id + 1;
		newatom->next = atom->next;
		newatom->refcount = 1;
		//newatom->String = lstrcpyW(newatom->String, AtomName);
		lstrcpyW(newatom->String, AtomName);
		free(AtomName);
		atom->next = newatom;
		return newatom->id;

		break;

	case INT_ATOM:
		//convert the string into a number as best as possible
		break;

	default:
		break;
	}

	free(AtomName);
	return 0;
}

int AtomType(char *lpString)
{
	return AtomTypeW(Ansi2Ucs2(lpString));
}

int AtomTypeA(char *lpString)
{
	return AtomTypeW(Ansi2Ucs2(lpString));
}

int AtomTypeW(wchar_t *lpString)
{
	//stub
	return BAD_ATOM;
}

StringAtomTableEntry *CreateLocalAtomEntry()
{
	StringAtomTableEntry *entry;
	entry = (StringAtomTableEntry *)malloc(sizeof(StringAtomTableEntry));
	entry->id = 0;
	entry->next = 0;
	entry->refcount = 0;
	return entry;
}

void DeleteLocalAtomEntry(uint16_t id)
{
	StringAtomTableEntry *atom;
	atom = ProcData->LocalStringAtomTable;

	StringAtomTableEntry *lastatom;
	lastatom = 0;

	//first entry is the one being deleted
	if (atom->id == id)
	{
		ProcData->LocalStringAtomTable = atom->next;
		free(atom);
		return;
	}

	while (atom->next != 0)
	{
		if (atom->id == id)
		{
			//got a match
			lastatom->next = atom->next;
			free(atom);
			return;
		}
		else
		{
			//no match, go to next entry
			lastatom = atom;
			atom = atom->next;
		}
	}

	//got to end of list
	//check the last entry
	if (atom->id == id)
	{
		lastatom->next = 0;
		free(atom);
	}

	return;
}

void *GetIntAtomTablePtr()
{
	return (void *)(ProcData->LocalIntAtomTable);
}

void *GetStringAtomTablePtr()
{
	return (void *)(ProcData->LocalStringAtomTable);
}

void SetIntAtomTablePtr(void *AtomTableLocation)
{
	ProcData->LocalIntAtomTable = AtomTableLocation;
	return;
}

void SetStringAtomTablePtr(void *AtomTableLocation)
{
	ProcData->LocalStringAtomTable = AtomTableLocation;
	return;
}

void FreeAtoms()
{
	void *atom;
	void *nextatom;

	//get pointer to local string atom table
	atom = GetStringAtomTablePtr();

	//step through the list, delete all atom entries
	while (atom != 0)
	{
		nextatom = ((StringAtomTableEntry *)atom)->next;
		free(atom);
		atom = nextatom;
	}

	SetStringAtomTablePtr(0);

	//get pointer to local int atom table
	atom = GetIntAtomTablePtr();

	//step through the list, delete all atom entries
	while (atom != 0)
	{
		nextatom = ((IntAtomTableEntry *)atom)->next;
		free(atom);
		atom = nextatom;
	}

	SetIntAtomTablePtr(0);
	return;
}