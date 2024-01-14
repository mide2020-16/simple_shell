#include "shell.h"

/**
 * _unsetenv - Unsets a variable from the environment
 * @name: the name of the variable
 * Return: 0 on Success
*/

int _unsetenv(const char *name)
{
	int i = 0, j;

	while (environ[i] != NULL)
	{
		if (strcmp(environ[i], name) == 0 && environ[i][strlen(name)] == '=')
		{
			for (j = i; environ[j] != NULL; ++j)
				environ[j] = environ[j + 1];
			return (0);
		}
		i++;
	}
	return (-1);
}
