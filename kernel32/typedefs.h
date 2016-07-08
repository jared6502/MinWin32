#ifndef __TYPEDEFS_H__
#define __TYPEDEFS_H__

//assume windows visual c++ compiler is being used

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#ifndef APIENTRY
#define APIENTRY WINAPI
#endif

#ifndef CALLBACK
#define CALLBACK WINAPI
#endif

#ifndef CONST
#define CONST const
#endif

//#include <stdint.h>

//define some basic types
#define int8_t signed char
#define int16_t signed short
#define int32_t signed int
#define int64_t signed long long

#define uint8_t unsigned char
#define uint16_t unsigned short
#define uint32_t unsigned int
#define uint64_t unsigned long long

typedef float single_t;
typedef double double_t;

typedef int8_t INT8;
typedef int16_t INT16;
typedef int32_t INT32;
typedef int32_t LONG32;
typedef int64_t INT64;
typedef int64_t LONG64;

typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef uint32_t ULONG;
typedef uint32_t ULONG32;
typedef uint64_t UINT64;
typedef uint64_t ULONG64;
typedef uint64_t ULONGLONG;

typedef CONST void *LPCVOID;
typedef void VOID;
typedef void *PVOID;
typedef void *LPVOID;

//define other types in terms of basic types
typedef uint16_t wchar_t;
typedef uint8_t BYTE;
typedef uint8_t UCHAR;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint32_t DWORD32;
typedef uint64_t DWORDLONG;
typedef int32_t BOOL;
typedef int8_t CCHAR;
typedef int8_t CHAR;
typedef int16_t SHORT;
typedef uint16_t USHORT;
typedef uint32_t UINT;
typedef uint32_t DWORD32;
typedef uint64_t DWORD64;
typedef single_t FLOAT;
typedef int32_t HFILE;
typedef int32_t LONG;
typedef int32_t INT;
typedef uint64_t QWORD;

#define TRUE 1
#define FALSE 0

#ifdef _WIN64
typedef int32_t HALF_PTR;
#else
typedef int16_t HALF_PTR;
#endif

#ifdef _WIN64 
typedef int64_t INT_PTR;
#else 
typedef int32_t INT_PTR;
#endif

#ifdef _WIN64
typedef uint64_t UINT_PTR;
#else
typedef uint32_t UINT_PTR;
#endif

#if !defined(_M_IX86)
typedef int64_t LONGLONG;
#else
typedef double LONGLONG;
#endif

#if defined(_WIN64)
typedef int64_t LONG_PTR;
#else
typedef int32_t LONG_PTR;
#endif

#if defined(_WIN64)
typedef uint64_t ULONG_PTR;
#else
typedef uint32_t ULONG_PTR;
#endif

//define types in terms of windows specific types
typedef BYTE BOOLEAN;

typedef WORD ATOM;
typedef WORD LANGID;

typedef wchar_t WCHAR;

typedef DWORD COLORREF;
typedef DWORD LCID;
typedef DWORD LCTYPE;
typedef DWORD LGRPID;
typedef DWORD *LPCOLORREF;

typedef LONG HRESULT;

typedef LONG_PTR LPARAM;
typedef ULONG_PTR DWORD_PTR;

typedef LONG_PTR SSIZE_T;
typedef ULONG_PTR SIZE_T;

typedef PVOID HANDLE;
typedef HANDLE HACCEL;
typedef HANDLE HBITMAP;
typedef HANDLE HBRUSH;
typedef HANDLE HCOLORSPACE;
typedef HANDLE HCONV;
typedef HANDLE HCONVLIST;
typedef HANDLE HDC;
typedef HANDLE HDDEDATA;
typedef HANDLE HDESK;
typedef HANDLE HDROP;
typedef HANDLE HDWP;
typedef HANDLE HENHMETAFILE;
typedef HANDLE HFONT;
typedef HANDLE HGDIOBJ;
typedef HANDLE HGLOBAL;
typedef HANDLE HHOOK;
typedef HANDLE HICON;
typedef HANDLE HINSTANCE;
typedef HANDLE HKEY;
typedef HANDLE HKL;
typedef HANDLE HLOCAL;
typedef HANDLE HMENU;
typedef HANDLE HMETAFILE;
typedef HANDLE HMONITOR;
typedef HANDLE HPALETTE;
typedef HANDLE HPEN;
typedef HANDLE HRGN;
typedef HANDLE HRSRC;
typedef HANDLE HSZ;
typedef HANDLE HWINSTA;
typedef HANDLE HWND;
typedef HANDLE SC_HANDLE;
typedef HANDLE SERVICE_STATUS_HANDLE;

typedef HINSTANCE HMODULE;
typedef HICON HCURSOR;

typedef BOOL *PBOOL;
typedef BOOL *LPBOOL;
typedef BOOLEAN *PBOOLEAN;
typedef BYTE *PBYTE;
typedef BYTE *LPBYTE;
typedef CHAR *PCHAR;
typedef CONST CHAR *PSTR;
typedef CONST CHAR *PCSTR;
typedef CHAR *LPSTR;
typedef CHAR *LPCSTR;
typedef WCHAR *PWSTR;
typedef CONST WCHAR *PCWSTR;
typedef CONST WCHAR *LPWSTR;
typedef CONST WCHAR *LPCWSTR;
typedef WORD *PWORD;
typedef WORD *LPWORD;
typedef SHORT *PSHORT;
typedef DWORD *PDWORD;
typedef DWORD *LPDWORD;
typedef DWORD32 *PDWORD32;
typedef DWORDLONG *PDWORDLONG;
typedef DWORD64 *PDWORD64;
typedef HANDLE *PHANDLE;
typedef HANDLE *LPHANDLE;
typedef int32_t *LPINT;
typedef int32_t *LPLONG;
typedef DWORD_PTR *PDWORD_PTR;
typedef FLOAT *PFLOAT;
typedef HKEY *PHKEY;
typedef int32_t *PINT;
typedef INT_PTR *PINT_PTR;
typedef INT8 *PINT8;
typedef INT16 *PINT16;
typedef INT32 *PINT32;
typedef INT64 *PINT64;
typedef PDWORD PLCID;
typedef LONG *PLONG;
typedef LONGLONG *PLONGLONG;
typedef LONG_PTR *PLONG_PTR;
typedef LONG32 *PLONG32;
typedef LONG64 *PLONG64;
typedef LPVOID SC_LOCK;
typedef LONGLONG USN;

#ifdef _WIN64
#define POINTER_32 __ptr32
#else
#define POINTER_32
#endif

#ifdef _WIN64
typedef HALF_PTR *PHALF_PTR;
#else
typedef HALF_PTR *PHALF_PTR;
#endif

#ifdef _WIN64
#define POINTER_64 __ptr64
#else
#define POINTER_64
#endif

#define POINTER_SIGNED __sptr
#define POINTER_UNSIGNED __uptr
typedef SIZE_T *PSIZE_T;
typedef SSIZE_T *PSSIZE_T;
typedef UCHAR *PUCHAR;

#ifdef _WIN64
typedef unsigned int UHALF_PTR;
#else
typedef unsigned short UHALF_PTR;
#endif

#ifdef _WIN64
typedef UHALF_PTR *PUHALF_PTR;
#else
typedef UHALF_PTR *PUHALF_PTR;
#endif

typedef UINT *PUINT;
typedef UINT_PTR *PUINT_PTR;
typedef UINT8 *PUINT8;
typedef UINT16 *PUINT16;
typedef UINT32 *PUINT32;
typedef UINT64 *PUINT64;
typedef ULONG *PULONG;
typedef ULONGLONG *PULONGLONG;

typedef ULONG_PTR *PULONG_PTR; 
typedef ULONG32 *PULONG32;
typedef ULONG64 *PULONG64;
typedef USHORT *PUSHORT;
typedef WCHAR *PWCHAR;
typedef UINT_PTR WPARAM;

typedef struct _UNICODE_STRING
{
	USHORT  Length;
	USHORT  MaximumLength;
	PWSTR  Buffer;
} UNICODE_STRING;

typedef UNICODE_STRING *PUNICODE_STRING;
typedef const UNICODE_STRING *PCUNICODE_STRING;

typedef struct
{
	uint16_t id;
	void *next; //pointer to next atom value
	uint32_t refcount;   //reference count
	wchar_t String[256]; //allocate enough space for UCS-2 string of 255 + null
} StringAtomTableEntry;

typedef struct
{
	uint16_t id;
	void *next;          //pointer to next atom value
	uint16_t value;      //int atom value
} IntAtomTableEntry;

typedef short VARIANT_BOOL;
#define VARIANT_TRUE ((VARIANT_BOOL)-1)
#define VARIANT_FALSE ((VARIANT_BOOL)0)

//struct allocated on load, contains all data specific to that process
//such as pointers to lists, structs needed by K32
typedef struct
{
	HINSTANCE hinstDLL;
	IntAtomTableEntry *LocalIntAtomTable;
	StringAtomTableEntry *LocalStringAtomTable;
	HANDLE CurrentThread;
} ProcessData;

//struct generated per-thread
typedef struct
{
	uint32_t hnd;
	void *heap;
	void *next;
} ThreadData;

#endif
