// windows c only

#include "miniWin_stdlib.h"

/**
 * Windows API call
 * Terminate the process unconditionally
*/
__declspec(dllimport) __declspec(noreturn) BOOL __stdcall TerminateProcess(void *pProcess, unsigned int ExitCode);
/**
 * Windows API call
 * Returns pointer to current process
*/
__declspec(dllimport) void* __stdcall GetCurrentProcess();


// void abort()
// {
// 	TerminateProcess(GetCurrentProcess(), -5);

// 	// try again
// 	TerminateProcess(GetCurrentProcess(), -5);

// 	// time to commit a deadly sin
// 	int sin = 1 / 0;
// }

void abort(unsigned int exitCode)
{
	TerminateProcess(GetCurrentProcess(), exitCode);

	// try again
	TerminateProcess(GetCurrentProcess(), exitCode);

	// time to commit a deadly sin
	int sin = 1 / 0;
}
