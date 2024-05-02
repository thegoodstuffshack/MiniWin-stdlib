// windows c only

#include "miniWin_stdlib.h"

#ifdef UNICODE
	__declspec(dllimport) unsigned int __stdcall GetEnvironmentVariableW(const char* name, char *buffer, unsigned int bufSize);
	#define GetEnvironmentVariable  GetEnvironmentVariableW
#else
	__declspec(dllimport) unsigned int __stdcall GetEnvironmentVariableA(const char* name, char *buffer, unsigned int bufSize);
	#define GetEnvironmentVariable  GetEnvironmentVariableA
#endif

/**
 * max size in chars
 * size limit of 32,767
 * includes null-terminating char
 * */ 
#define GETENV_MAX_BUFFER_SIZE 800

char buffer[GETENV_MAX_BUFFER_SIZE];

char *getenv(const char *envName)
{
	unsigned int nChars;

	nChars = GetEnvironmentVariable(envName, buffer, GETENV_MAX_BUFFER_SIZE);

	if (nChars == 0)
	{
		// printf("ERROR: getenv(%s): %s\n", envName, GetLastError());
		return NULL;
	}

	if (nChars >= GETENV_MAX_BUFFER_SIZE)
	{
		// printf("Buffer Size Too Small For Environment Variable\n");
		return NULL;
	}

	return buffer;
}
