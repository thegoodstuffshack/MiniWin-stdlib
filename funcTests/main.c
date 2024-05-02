#include <stdlib.h>
#include <stdio.h>
#include <windows.h>


double atof(const char*);

int main()
{
	printf("size: %d", sizeof(size_t));
	const char* string = "9823.300e-2";
	double status = atof(string);
	
	printf("output: %f", status);

	atexit(atof);
	return 0;
}



// convert input string into double floating point
double atof(const char *str)
{
	printf("input:  %s\n", str);

	double value = 0.0;
	unsigned int i = 0;
	int letter = 0;
	int expon = 0;        // exponential counter from main digits
	int Eexpon = 0;       // exponential counter from E digits
	int sign = 1;         // main value sign
	int exponsign = 1;    // exponential sign

	if (letter == '-')
	{
		sign = -1;
		i++;
	}
	else if (letter == '+')
	{
		i++;
	}


	letter = str[i];
	i++;
	printf("pre-decimal: ");
	// process all digits until decimal or NULL, break as soon as non-digit encountered
	while (letter >= '0' && letter <= '9')
	{
		printf("%d, ", (letter - '0'));
		// value = value * 10.0 + letter;
		value = (letter - '0') + value * 10.0;
		letter = str[i];
		i++;
	}
	printf("\n");
	printf("val: %f\n", value);

	printf("post-decimal: ");
	// check to see if the next letter is decimal, if '.' or NULL continue, else check for e
	if (letter == '.')
	{
		letter = str[i];
		while (letter >= '0' && letter <= '9')
		{
			printf("%d, ", (letter - '0'));
			expon--;
			value = (letter - '0') + value * 10.0;
			i++;
			letter = str[i];
		}
		printf("\n");
	}
	printf("val: %f\n", value);
	printf("exp: %d\n", expon);

	// if e, process, else end
	if (letter == 'e' || letter == 'E')
	{
		printf("E: ");
		i++;
		letter = str[i];
		if (letter == '-')
		{
			exponsign = -1;
			i++;
			printf("%d, ", letter);
			printf("HERE");
		}
		else if (letter == '+')
		{
			i++;
			printf("%d, ", letter);
		}

		letter = str[i];
		i++;
		printf("%d, ", letter);
		while (letter >= '0' && letter <= '9')
		{
			Eexpon = (letter - '0') + Eexpon * 10.0;
			letter = str[i];
			printf("%d, ", letter);
			i++;
		}
		expon += Eexpon * exponsign;
		printf("\n");
	}
	printf("val: %f\n", value);
	printf("exp: %d\n", expon);

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

	printf("NULL?: %d\n", letter);
	if (letter != 0)
	{
		return 0.0;
	}

	// handle negative case here

	return value;
}
