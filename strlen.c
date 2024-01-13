#include "shell.h"

/**
 * _strlen - Returns the length of characters in a string
 * @str: the string to print
 * Return: the length of str
*/

int _strlen(const char *str)
{
	int i, length = 0;

	for (i = 0; str[i] != '\0'; i++)
		++length;

	return (length);
}
