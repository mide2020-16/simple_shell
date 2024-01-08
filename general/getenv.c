#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	name_length = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_length) == 0 && environ[i][name_length] == '=')
			return (environ[i] + name_length + 1);
		i++;
	}
	return (NULL);
}

/**
 * main - Entry point
 * @ac: the count
 * @av: the vector
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	const char *name;
	char *value;

	if (ac < 2)
	{
		printf("Usage: %s <name>\n", av[0]);
		return (1);
	}

	name = av[1];

	if ((value = _getenv(name)) != NULL)
		printf("%s = %s\n", name, value);
	else
		printf("%s not found in the environment\n", name);

	return (0);
}
