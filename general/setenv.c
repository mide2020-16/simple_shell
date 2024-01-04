#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv - Set a variable in the environ
 * @name: the variable name
 * @value: the value to set the variable to
 * @overwrite: the amount to overwrite
 * Return: 0 on Success
*/

int _setenv(const char *name, const char *value, int overwrite)
{
	char *new_var_env;
	char *existing_var;

	new_var_env = (char *)malloc(strlen(name) + strlen(value) + 2);
	if (new_var_env == NULL)
	{
		perror("Unable to allocate memory\n");
		return (-1);
	}

	sprintf(new_var_env, "%s=%s\n", name, value);

	existing_var = getenv(name);

	if (existing_var == NULL || overwrite)
	{
		if (putenv(new_var_env) != 0)
		{
			perror("Unable to add variable");
			free(new_var_env);
			return (-1);
		}
	}
	else
	{
		free(new_var_env);
		return (-1);
	}

	return (0);
}





/**
 * main - Entry point
 * @ac: the count
 * @av: the vector
 * Return: 0 on Success
*/

int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Usage: %s <variable> <value>\n", av[0]);
		return (1);
	}

	_setenv(av[1], av[2], 1);
	printf("%s = %s\n", av[1], getenv(av[1]));

	return (0);
}
