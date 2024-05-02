// windows c only

#include "miniWin_stdlib.h"


// large string inputs aren't handled
// inf and nan cases return 0.0

double atof(const char *str)
{
	double value = 0.0;
	unsigned int i = 0;
	int letter;
	int expon = 0;        // exponential counter from main digits
	int Eexpon = 0;       // exponential counter from E digits
	int sign = 1;         // main value sign
	int exponsign = 1;    // exponential sign

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

	
	i++;
	while (letter >= '0' && letter <= '9')
	{
		value = (letter - '0') + value * 10.0;
		letter = str[i];
		i++;
	}

	if (letter == '.')
	{
		letter = str[i];
		while (letter >= '0' && letter <= '9')
		{
			expon--;
			value = (letter - '0') + value * 10.0;
			i++;
			letter = str[i];
		}
	}

	if (letter == 'e' || letter == 'E')
	{
		i++;
		letter = str[i];
		if (letter == '-')
		{
			exponsign = -1;
			i++;
		}
		else if (letter == '+')
		{
			i++;
		}

		letter = str[i];
		i++;

		while (letter >= '0' && letter <= '9')
		{
			Eexpon = (letter - '0') + Eexpon * 10.0;
			letter = str[i];
			i++;
		}
		expon += Eexpon * exponsign;
	}

	// apply exponential to value
	while (expon > 0)
	{
		value *= 10.0;
		expon--;
	}
	while (expon < 0)
	{
		value *= 0.1;
		expon++;
	}

	value *= sign;

	return value;
}
