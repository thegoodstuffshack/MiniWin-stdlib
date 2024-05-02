// windows c only

#include "miniWin_stdlib.h"


long atol(const char *str)
{
	long value = 0;
	unsigned int i = 0;
	int letter;
	int sign = 1;

	letter = str[i];
	if (letter == '-')
	{
		sign = -1;
		i++;
		letter = str[i];
	}
	else if (letter == '+')
	{
		i++;
		letter = str[i];
	}

	
	while (letter >= '0' && letter <= '9')
	{
		value = (letter - '0') + value * 10;
		i++;
		letter = str[i];
	}

	value *= sign;

	return value;
}
