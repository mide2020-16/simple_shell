#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _unsetenv - Unsets a variable from the environment
 * @name: the name of the variable
 * Return: 0 on Success
*/

int _unsetenv(const char *name)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=')
		{
			for (int j = i; environ[j] != NULL; ++j)
				environ[j] = environ[j + 1];
			break;
		}
		i++;
	}
	return (0);
}



/**
 * main - Entry point
 * Return: 0 on Success
*/

int main(void)
{
	putenv("SAMPLE_VAR=sample_value");

	for (char **env = environ; *env != NULL; env++)
		printf("%s\n", *env);

	_unsetenv("SAMPLE_VAR");

	for (char **env = environ; *env != NULL; env++)
		printf("%s\n", *env);

	if (getenv("SAMPLE_VAR") == NULL)
		printf("SAMPLE_VAR is NULL\n");

	return (0);
}
