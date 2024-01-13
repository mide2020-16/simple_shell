#include "shell.h"

/**
 * get_file_location - This gets file path, verify that
 * it is executable and also get the file information
 * @path: the path to check
 * @file_name: the name of the executable file
 * Return: the path if conditions are met
 */

char *get_file_location(char *path, char *file_name)
{
	char *copy_path, *token;
	struct stat st;
	char *path_buffer;
	size_t buffer_size;

	copy_path = _strdup(path);
	token = _strtok(copy_path, ":");

	while (token)
	{
		buffer_size = _strlen(token) + _strlen(file_name) + 2;

		path_buffer = malloc(_strlen(token) + _strlen(file_name) + 2);

		if (path_buffer == NULL)
		{
			exit(EXIT_FAILURE);
		}

		_snprintf(path_buffer, buffer_size, "%s/%s", token, file_name);

		if (stat(path_buffer, &st) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(copy_path);
			return (path_buffer);
		}

		free(path_buffer);
		token = strtok(NULL, ":");
	}

	free(copy_path);
	return (NULL);
}
