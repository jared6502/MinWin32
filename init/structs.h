#ifndef __STRUCTS_H__
#define __STRUCTS_H__

typedef struct
{
	uint16_t Limit0_15;
	uint16_t Base0_15;
	uint8_t Base16_23;
	uint8_t Access;
	uint8_t Limit16_19_Flags;
	uint8_t Base24_31;
} GDTEntry;

typedef struct
{
	void *Next;
	void *Prev;
	uint64_t Size;
	void *Item;
} ListEntry;

typedef struct
{
	ListEntry *Items;
	uint64_t ItemCount;
} List;

typedef struct
{
	List Nodes;
	wchar_t *Name;
	wchar_t *Desc;
	void *Object;
} TreeNode;

#endif
