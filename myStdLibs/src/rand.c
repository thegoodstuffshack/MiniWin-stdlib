// windows c only

#include "miniWin_stdlib.h"


int rand(void)
{
	int rNum;
	// 0 - RAND_MAX;

	rNum = rNum % (RAND_MAX + 1);

	return rNum;
}