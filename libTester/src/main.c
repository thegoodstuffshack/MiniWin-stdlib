#include "miniWin_stdlib.h"
#include "malloc.h"
// #include <stdlib.h>

int _main();


// code starts here
void _start()
{
	// add handling of arguments here by:
	/**
	 * Initialise the Heap
	 * Get argc and argv (put into heap)
	*/
	void *_heap = initHeap();
	if (changeHeap(_heap) == false)
	{
		abort(-5);
	}

	unsigned int errorCode = _main();

	exit(errorCode);
}



void test_atexit(void)
{
	// abort(337);
	int tree = 3;
}
void test2_atexit(void)
{
	int tree = 3;
}
void test3_atexit(void)
{
	int tree = 3;
	// abort(420);
}


// pseudo main function
int _main()
{
	char *str = calloc(3, sizeof(char));
	if (str == NULL)
	{
		return -1;
	}
	str = realloc(str, 8 * sizeof(char));
	if (str == NULL)
	{
		return -1;
	}
	// const char* str = "1000000";
	str[0] = '-';
	str[1] = '1';
	str[2] = '2';
	str[3] = '6';
	str[4] = '3';
	str[5] = '4';
	str[6] = '5';
	str[7] = '\0';

	char* buf = getenv("PATH");
	if (buf == NULL)
	{
		abort(-6);
	}

	// int status = buf[5];
	long int status = atof(str);
	status = labs(status);
	// status = ldiv(status, 3).rem;

	free(str);

	if (atexit(test3_atexit) != 0)
	{
		abort(-2);
	}
	if (atexit(test_atexit) != 0)
	{
		abort(-2);
	}
	if (atexit(test2_atexit) != 0)
	{
		abort(-2);
	}

	// unsigned long i = 0;
	// while ( i < 1000000000)
	// {
	// 	*str = i;
	// 	i++;
	// }


	// exit(-1);
	return status;
}
