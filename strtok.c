#include "shell.h"

/**
 * _strtok - Tokenize a string
 * @string: the string
 * @delimiter: the token to use
 * Return: return the token
 */

char *_strtok(char *string, const char *delimiter)
{
	static char *lasttoken = NULL, *endtoken;

	if (string == NULL)
		string = lasttoken;

	if (string == NULL)
		return (NULL);

	string += strspn(string, delimiter);

	if (*string == '\0')
	{
		lasttoken = NULL;
		return (NULL);
	}

	endtoken = string + strcspn(string, delimiter);

	if (*endtoken != '\0')
	{
		*endtoken = '\0';
		lasttoken = endtoken + 1;
	}
	else
		lasttoken = NULL;

	return (string);
}
