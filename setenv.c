#include "shell.h"

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
	size_t buffer_size;
	char *name_1;

	name_1 = name;
	new_var_env = (char *)malloc(_strlen(name_1) + _strlen(value) + 2);
	buffer_size = _strlen(name_1) + _strlen(value) + 2;

	if (new_var_env == NULL)
	{
		return (-1);
	}

	_snprintf(new_var_env, buffer_size, "%s=%s\n", name_1, value);

	existing_var = _getenv(name_1);

	if (existing_var == NULL || overwrite)
	{
		if (putenv(new_var_env) != 0)
		{
			free(new_var_env);
			return (-1);
		}
	}
	else
	{
		free(new_var_env);
		return (-1);
	}

	free(new_var_env);
	return (0);
}
