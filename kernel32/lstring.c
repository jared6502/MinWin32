#include "k32.h"

//function definitions
char * APIENTRY lstrcatA(char *lpString1, char *lpString2);
wchar_t * APIENTRY lstrcatW(wchar_t *lpString1, wchar_t *lpString2);
int32_t APIENTRY lstrcmpA(char *lpString1, char *lpString2);
int32_t APIENTRY lstrcmpW(wchar_t *lpString1, wchar_t *lpString2);
int32_t APIENTRY lstrcmpiA(char *lpString1, char *lpString2);
int32_t APIENTRY lstrcmpiW(wchar_t *lpString1, wchar_t *lpString2);
char * APIENTRY lstrcpyA(char *lpString1, char *lpString2);
wchar_t * APIENTRY lstrcpyW(wchar_t *lpString1, wchar_t *lpString2);
char * APIENTRY lstrcpynA(char *lpString1, char *lpString2, int32_t count);
wchar_t * APIENTRY lstrcpynW(wchar_t *lpString1, wchar_t *lpString2, int32_t count);
int32_t APIENTRY lstrlenA(char *lpString);
int32_t APIENTRY lstrlenW(wchar_t *lpString);

char *Ucs22Ansi(wchar_t *lpstring);
wchar_t *Ansi2Ucs2(char *lpString);
wchar_t *ConvertStrWstr(char *lpString);

//code
char * APIENTRY lstrcatA (char *lpString1, char *lpString2)
{
	int i;
	int j;

	for (i = 0; lpString1[i] != 0; i++);

	for (j = 0; lpString2[j] != 0; j++)
	{
		lpString1[i] = lpString2[j];
		i++;
	}

	lpString1[i] = 0;

	return lpString1;
}

wchar_t * APIENTRY lstrcatW(wchar_t *lpString1, wchar_t *lpString2)
{
	int i;
	int j;

	for (i = 0; lpString1[i] != L'\0'; i++);

	for (j = 0; lpString2[j] != L'\0'; j++)
	{
		lpString1[i] = lpString2[j];
		i++;
	}

	lpString1[i] = L'\0';

	return lpString1;
}

int32_t APIENTRY lstrcmpA(char *lpString1, char *lpString2)
{
	int i;
	int j;

	for (i = 0; lpString1[i] != 0 && lpString2[i] != 0; i++)
	{
		if (lpString1[i] != lpString2[i])
		{
			j = lpString1[i] - lpString2[i];
			return j;
		}
	}

	return 0;
}

int32_t APIENTRY lstrcmpW(wchar_t *lpString1, wchar_t *lpString2)
{
	int i;
	int j;

	for (i = 0; lpString1[i] != L'\0' && lpString2[i] != L'\0'; i++)
	{
		if (lpString1[i] != lpString2[i])
		{
			j = lpString1[i] - lpString2[i];
			return j;
		}
	}

	return 0;
}

int32_t APIENTRY lstrcmpiA(char *lpString1, char *lpString2)
{
	int i;
	int j;

	for (i = 0; lpString1[i] != 0 && lpString2[i] != 0; i++)
	{
		if (ToUpper[lpString1[i]] != ToUpper[lpString2[i]])
		{
			j = ToUpper[lpString1[i]] - ToUpper[lpString2[i]];
			return j;
		}
	}

	return 0;
}

int32_t APIENTRY lstrcmpiW(wchar_t *lpString1, wchar_t *lpString2)
{
	int i;
	int j;

	for (i = 0; lpString1[i] != L'\0' && lpString2[i] != L'\0'; i++)
	{
		if (ToUpper[lpString1[i]] != ToUpper[lpString2[i]])
		{
			j = ToUpper[lpString1[i]] - ToUpper[lpString2[i]];
			return j;
		}
	}

	return 0;
}

char * APIENTRY lstrcpyA(char *lpString1, char *lpString2)
{
	int i;

	for (i = 0; lpString2 != 0; i++)
	{
		lpString1[i] = lpString2[i];
	}

	i++;
	lpString1[i] = lpString2[i];

	return lpString1;
}

wchar_t * APIENTRY lstrcpyW(wchar_t *lpString1, wchar_t *lpString2)
{
	int i;

	for (i = 0; lpString2[i] != L'\0'; i++)
	{
		lpString1[i] = lpString2[i];
	}

	i++;
	lpString1[i] = lpString2[i];

	return lpString1;
}

char * APIENTRY lstrcpynA(char *lpString1, char *lpString2, int32_t count)
{
	if (count < 1) return 0;

	int i;

	for (i = 0; i < count; i++)
	{
		lpString1[i] = lpString2[i];
	}

	return lpString1;
}

wchar_t * APIENTRY lstrcpynW(wchar_t *lpString1, wchar_t *lpString2, int32_t count)
{
	if (count < 1) return 0;

	int i;

	for (i = 0; i < count; i++)
	{
		lpString1[i] = lpString2[i];
	}

	return lpString1;
}

int32_t APIENTRY lstrlenA(char *lpString)
{
	int32_t i;
	i = 0;

	while (lpString[i] != 0)
	{
		i++;
	}

	return i;
}

int32_t APIENTRY lstrlenW(wchar_t *lpString)
{
	int32_t i;
	i = 0;

	while (lpString[i] != L'\0')
	{
		i++;
	}

	return i;
}

wchar_t *Ansi2Ucs2(char *lpString)
{
	wchar_t *str;
	int32_t len;
	int32_t i;

	len = lstrlenA(lpString) + 1; //chars + null
	str = (wchar_t *)malloc(len * sizeof(wchar_t)); //allocate buffer to contain converted string

	for (i = 0; i < len; i++) str[i] = ToUCS2[lpString[i]];
	return str;
}

char *Ucs22Ansi(wchar_t *lpString)
{
	char *str;
	int32_t len;
	int32_t i;

	len = lstrlenW(lpString) + 1; //chars + null
	str = (char *)malloc(len * sizeof(char)); //allocate buffer to contain converted string

	for (i = 0; i < len; i++) str[i] = ToANSI[lpString[i]];
	return str;
}

wchar_t *ConvertStrWstr(char *lpString)
{
	int i;
	int j;
	wchar_t *cvt;
	for (i = 0; lpString[i] != 0; i++);
	i++;
	cvt = (wchar_t *)malloc((i * 2));
	if (cvt == 0) return 0;
	for (j = 0; j < i; j++)
	{
		cvt[j] = 0;
		cvt[j] = lpString[j];
	}
	free(lpString);
	return cvt;
}