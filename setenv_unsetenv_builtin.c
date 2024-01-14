#include "shell.h"

/**
 * setenv_builtin - Set a new environment variable or modify an existing one
 * @variable: the name of the environment variable
 * @value: the value to set the environment variable to
 * @overwrite: flag to overwrite existing variable
 * Return: 0 on success, -1 on failure
 */

int setenv_builtin(const char *variable, const char *value, int overwrite)
{
		if (variable == NULL || value == NULL)
		{
			fprintf(stderr, "setenv: Invalid arguments\n");
			return (-1);
		}

		if (_setenv(variable, value, overwrite) != 0)
		{
			fprintf(stderr, "setenv: Failed to set environment variable\n");
			return (-1);
		}

		return (0);
}

/**
 * unsetenv_builtin - Unset an environment variable
 * @variable: the name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */

int unsetenv_builtin(const char *variable)
{
		if (variable == NULL)
		{
			fprintf(stderr, "unsetenv: Invalid argument\n");
			return (-1);
		}

		if (_unsetenv(variable) != 0)
		{
			fprintf(stderr, "unsetenv: Failed to unset environment variable\n");
			return (-1);
		}

		return (0);
}
