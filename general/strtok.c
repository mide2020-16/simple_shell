#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _strtok - Tokenize a string
 * @str: the string
 * @delim: the token to use
 * Return: return str
*/

char *_strtok(char *str, const char *delim)
{
	char *lasttoken = NULL;
	char *endtoken;

	if (str == NULL)
	{
		str = lasttoken;
		return (NULL);
	}

	str = str + strspn(str, delim);
	endtoken = str + strcspn(str, delim);

	if (endtoken != '\0')
	{
		endtoken = '\0';
		lasttoken = endtoken + 1;
	}
	else
		lasttoken = NULL;

	return (str);
}
