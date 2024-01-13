#include "shell.h"


/**
 * _strdup - Duplicates a string and give it memory
 * @string: the string to duplicate
 * Return: duplicated string
*/

char *_strdup(const char *string)
{
	char *dupped_str;
	int length, j;

	if (string == NULL)
		return (NULL);

	length = _strlen(string);

	dupped_str = malloc(sizeof(char *) * (length + 1));

	if (dupped_str == NULL)
		return (NULL);

	for (j = 0; string[j] != '\0'; ++j)
		dupped_str[j] = string[j];

	dupped_str[j] = '\0';

	return (dupped_str);
}
