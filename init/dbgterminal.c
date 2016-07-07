//handle display and keyboard unless replaced by other components

//need these to allow proper replacement after load while leaving original intact for early errors
typedef void *(ConsoleWrite)(const wchar_t c);
typedef wchar_t *(ConsoleRead)();

void ConsoleWriteLine(const wchar_t *s)
{
	return;
}

void ConsoleReadLine(const wchar_t *s)
{
	return;
}