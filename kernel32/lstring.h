#ifndef __LSTRING_H__
#define __LSTRING_H__

extern char * APIENTRY lstrcatA(char *lpString1, char *lpString2);
extern wchar_t * APIENTRY lstrcatW(wchar_t *lpString1, wchar_t *lpString2);
extern int32_t APIENTRY lstrcmpA(char *lpString1, char *lpString2);
extern int32_t APIENTRY lstrcmpW(wchar_t *lpString1, wchar_t *lpString2);
extern int32_t APIENTRY lstrcmpiA(char *lpString1, char *lpString2);
extern int32_t APIENTRY lstrcmpiW(wchar_t *lpString1, wchar_t *lpString2);
extern char * APIENTRY lstrcpyA(char *lpString1, char *lpString2);
extern wchar_t * APIENTRY lstrcpyW(wchar_t *lpString1, wchar_t *lpString2);
extern char * APIENTRY lstrcpynA(char *lpString1, char *lpString2, int32_t count);
extern wchar_t * APIENTRY lstrcpynW(wchar_t *lpString1, wchar_t *lpString2, int32_t count);
extern int32_t APIENTRY lstrlenA(char *lpString);
extern int32_t APIENTRY lstrlenW(wchar_t *lpString);

extern wchar_t *Ansi2Ucs2(char *lpString);
extern char *Ucs22Ansi(wchar_t *lpstring);

extern wchar_t *ConvertStrWstr(char *lpString);

#endif
