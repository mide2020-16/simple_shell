#include "shell.h"

/**
 * starts_with_fwd_slash - Checks if the command
 * starts with a forward slash
 *
 * @string: The file executable name
 * Return: 0 on false and 1 on true
*/

int starts_with_fwd_slash(const char *string)
{
	if (string != NULL && string[0] == '/')
		return (1);

	return (0);
}

/**
 * get_file_path - Get the PATH from the
 * environment variables
 *
 * @file_name: the file_name
 * Return: full_path
*/
char *get_file_path(char *file_name)
{
	char *path, *full_path, *copy_file;

	copy_file = _strdup(file_name);

	path = _getenv("PATH");

	if (starts_with_fwd_slash(file_name) && access(file_name, X_OK) == 0)
	{
		return (copy_file);
	}

	free(copy_file);

	if (!path)
	{
		return (NULL);
	}

	full_path = get_file_location(path, file_name);

	if (full_path == NULL)
	{
		return (NULL);
	}

	return (full_path);
}
