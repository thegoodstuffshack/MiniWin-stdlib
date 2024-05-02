// windows c only

#include "miniWin_stdlib.h"
#include "malloc.h"

BOOL atexit_init = false;
static void *atexit_heap = NULL;
static size_t *atexit_array = NULL;
int atexit_index = -1;
unsigned int atexit_array_size = 0;


int atexit(void (*function)(void))
{
	if (atexit_init == false)
	{
		#define HEAPFLAG_EXECUTABLE     false
		#define HEAPFLAG_GEN_EXCEPTIONS false
		#define HEAPFLAG_NO_SERIALIZE   false
		#define HEAP_INITIALSIZE 0
		#define HEAP_MAXSIZE     0
		atexit_heap = initHeap();
		if (atexit_heap == NULL)
		{
			return -4;
		}
		atexit_init = true;
	}

	if (function == NULL)
	{
		return -2;
	}

	atexit_array_size++;
	atexit_index++;

	changeHeap(atexit_heap);
	atexit_array = realloc(atexit_array, atexit_array_size * sizeof(size_t));
	changeHeap(NULL);

	if ( atexit_array == NULL )
	{
		return -1;
	}

	atexit_array[atexit_index] = (size_t) function;

	return 0;
}

/**
 * calls functions indexed by atexit() in the appropriate order
 * destroys the atexit() heap
*/
void handle_atexit()
{
	if (atexit_array == NULL || atexit_array_size == 0)
	{
		return;
	}

	void (*function)(void);

	while ( atexit_index >= 0 )
	{
		function = (void (*)(void)) atexit_array[atexit_index];

		atexit_index--;

		(*function)();
	}
	
	changeHeap(atexit_heap);
	if (destroyHeap() == false)
	{
		// printf("Heap Not Destroyed with Error: %d", GetLastError());
	}
}
