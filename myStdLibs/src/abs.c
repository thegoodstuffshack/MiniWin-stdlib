// windows c only

#include "miniWin_stdlib.h"


int abs(int num)
{
	return num < 0 ? -num : num;
}

long int labs(long int num)
{
	return num < 0 ? -num : num;
}