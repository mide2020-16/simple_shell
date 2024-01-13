#include "shell.h"

/**
 * _getenv - Gets the value of an environment variable
 * @name: The variable to search
 * Return: NULL on Failure
 */

char *_getenv(const char *name)
{
	int i = 0;
	size_t name_length;
	char name_1;

	name_1 = name;

	name_length = _strlen(name_1);

	while (environ[i] != NULL)
	{
		if (strcmp(environ[i], name) == 0 && environ[i][name_length] == '=')
			return (environ[i] + name_length + 1);
		i++;
	}

	return (NULL);
}
