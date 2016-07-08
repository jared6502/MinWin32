int KCall(void *data);
void *PKCall(void *data);

extern int KCall(void *data)
{
	//stub
	int retval;

	retval = 0;

	__asm
	{
		mov eax, data;
		int 0x2E;
		mov retval, eax;
	}

	return retval;
}

extern void *PKCall(void *data)
{
	//stub
	void *retval;

	retval = 0;

	__asm
	{
		mov eax, data;
		int 0x2E;
		mov retval, eax;
	}

	return retval;
}
