#include <stdio.h>

/**
 * _atoi - convert stringed number to integer
 * @str: the string
 * Return: the converted type
*/

int _atoi(const char *str)
{
	int result = 0, sign = 1;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	return (sign * result);
}
