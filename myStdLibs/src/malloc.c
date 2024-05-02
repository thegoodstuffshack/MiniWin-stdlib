// windows c only

#include "miniWin_stdlib.h"
#include "malloc.h"

/**
 * Windows API Calls
 * Heap Management Functions
*/
__declspec(dllimport) void* __stdcall HeapAlloc  (void *hHeap, unsigned int dwFlags, size_t dwBytes);
__declspec(dllimport) void* __stdcall HeapCreate (unsigned int flOptions, size_t dwInitialSize, size_t dwMaximumSize);
__declspec(dllimport) BOOL  __stdcall HeapDestroy(void *hHeap);
__declspec(dllimport) BOOL  __stdcall HeapFree   (void *hHeap, unsigned int dwFlags, void *lpMem);
__declspec(dllimport) void* __stdcall HeapReAlloc(void *hHeap, unsigned int dwFlags, void *lpMem, size_t dwBytes);


static void *pHeap = NULL;
static void *defaultHeap = NULL;
BOOL isDefaultHeap = true;

/**
 * initialises a private heap through windows api
 * returns pointer to the heap or NULL if unsuccessful
 * call destroyHeap() to free the heap
 * the first successful heap initialised becomes the default heap
*/
void *initHeap()
{
	unsigned int flOptions = 0;
	size_t dwInitialSize = 0; // default to one page
	size_t dwMaximumSize = 0; // default to growable heap

	#if HEAPFLAG_EXECUTABLE
		flOptions = flOptions | 0x00040000;
	#endif
	#if HEAPFLAG_GEN_EXCEPTIONS
		flOptions = flOptions | 0x00000004;
	#endif
	#if HEAPFLAG_NO_SERIALIZE
		flOptions = flOptions | 0x00000001;
	#endif

	#ifdef HEAP_INITIALSIZE
		dwInitialSize = HEAP_INITIALSIZE;
	#endif

	#ifdef HEAP_MAXSIZE
		dwMaximumSize = HEAP_MAXSIZE;
	#endif

	pHeap = HeapCreate(flOptions, dwInitialSize, dwMaximumSize);
	if (pHeap == NULL)
	{
		return NULL; //GetLastError();
	}
	if (isDefaultHeap == true)
	{
		defaultHeap = pHeap;
		isDefaultHeap = false;
	}

	return pHeap;
}

BOOL destroyHeap()
{
	if (HeapDestroy(pHeap) == false)
	{
		return false;
	}
	return true;
}

/**
 * changes the private heap that is being accessed
 * a NULL input sets the ptr to the main processes heap
*/
BOOL changeHeap(void *heap)
{
	if (heap == NULL)
	{
		pHeap = defaultHeap;
	}
	else 
	{
		pHeap = heap;
	}
	
	if (pHeap == NULL)
	{
		return false;
	} 

	return true;
}

void *calloc(size_t nElements, size_t elementSize)
{
	unsigned int dwFlags = 0;

	// zero the memory
	dwFlags = dwFlags | 0x00000008;

	#if HEAPFLAG_GEN_EXCEPTIONS
		dwFlags = dwFlags | 0x00000004;
	#endif
	#if HEAPFLAG_NO_SERIALIZE
		dwFlags = dwFlags | 0x00000001;
	#endif

	size_t size = nElements * elementSize;

	return HeapAlloc(pHeap, dwFlags, size);
}

void free(void *pMem)
{
	HeapFree(pHeap, 0, pMem);
}

void *malloc(size_t size)
{
	unsigned int dwFlags = 0;

	#if HEAPFLAG_GEN_EXCEPTIONS
		dwFlags = dwFlags | 0x00000004;
	#endif
	#if HEAPFLAG_NO_SERIALIZE
		dwFlags = dwFlags | 0x00000001;
	#endif

	return HeapAlloc(pHeap, dwFlags, size);
}

void *realloc(void *pMem, size_t size)
{
	if (size == 0 && pMem != NULL)
	{
		free(pMem);
		return NULL;
	}

	if (pMem == NULL)
	{
		return malloc(size);
	}

	unsigned int dwFlags = 0;

	#if HEAPFLAG_GEN_EXCEPTIONS
		dwFlags = dwFlags | 0x00000004;
	#endif
	#if HEAPFLAG_NO_SERIALIZE
		dwFlags = dwFlags | 0x00000001;
	#endif

	return HeapReAlloc(pHeap, dwFlags, pMem, size);
}