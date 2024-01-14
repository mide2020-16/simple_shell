#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @str1: the first string
 * @str2: the second string
 * @Return: 0 on success
*/

int _strcmp(char *str1, char *str2)
{
	int i;

	i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		++i;
	}

	if (str1[i] == '\0' && str2[i] != '\0')
		return (str1[i - 1] - str2[i]);

	if (str1[i] != '\0' && str2[i] == '\0')
		return (str1[i] - str2[i - 1]);

	return (0);
}
