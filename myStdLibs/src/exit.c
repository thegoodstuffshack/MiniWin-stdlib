// windows c only

#include "miniWin_stdlib.h"
#include "malloc.h"

/**
 * Windows API call
 * Exit the process cleanly
*/
__declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int ExitCode);

extern void handle_atexit();

void exit(unsigned int exitCode)
{
	handle_atexit();

	changeHeap(NULL);
	if (destroyHeap() == false)
	{
		// printf("Heap Not Destroyed with Error: %d", GetLastError());
		abort(-5);
	}

	ExitProcess(exitCode);
}
