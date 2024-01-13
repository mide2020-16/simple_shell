#include "shell.h"

int _strcpy(char *dest, size_t size, const char *src)
{
	int len = 0;

	while(*src != '\0' && (size_t)len < size)
	{
		dest[len++] = *src++;
	}

	dest[len] = '\0';

	return (len);
}
