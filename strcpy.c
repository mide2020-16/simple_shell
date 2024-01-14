#include "shell.h"

/**
 * _strcpy - Copy string to a destination
 * @dest: the dstination
 * @size: the size
 * @src: the source
 * Return: len
*/
int _strcpy(char *dest, size_t size, const char *src)
{
	int len = 0;

	while (*src != '\0' && (size_t)len < size)
	{
		dest[len++] = *src++;
	}

	dest[len] = '\0';

	return (len);
}
