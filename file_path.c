#include "main.h"

/**
 * starts_with_fwd_slash - Checks if the command
 * starts with a forward slash
 *
 * @str: The file executable name
 * Return: 0 on false and 1 on true
*/
int starts_with_fwd_slash(const char *str)
{
	if (str != NULL && str[0] == '/')
		return (1);

	return (0);
}



/**
 * get_file_location - This gets file path, verify that
 * it is executable and also get the file information
 *
 * @path: the path to check
 * @file_name: the name of the executable file
 * Return: the path if conditions are met
*/

char *get_file_location(char *path, char* file_name)
{
	char *copy_path, *token;
	struct stat st;
	char *path_buffer;

	copy_path = strdup(path);
	token = strtok(copy_path, ":");

	while (token)
	{

		path_buffer = malloc(strlen(token) + strlen(file_name) + 2);

		if (path_buffer == NULL)
		{
			perror("Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}

		sprintf(path_buffer, "%s/%s", token, file_name);

		if (stat(path_buffer, &st) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(copy_path);
			return (path_buffer);
		}

		token = strtok(NULL, ":");
	}

	free(copy_path);
	free(path_buffer);

	return (NULL);
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
	char *path;
	char *full_path;
	char *copy_file;

	copy_file = strdup(file_name);

	path = getenv("PATH");

	if (starts_with_fwd_slash(file_name) && access(file_name, X_OK) == 0)
	{
		return (copy_file);
	}
	if (!path)
	{
		perror("getenv");
		return (NULL);
	}

	full_path = get_file_location(path, file_name);

	if (full_path == NULL)
	{
		perror("Unable to find path");
		return (NULL);
	}

	free(copy_file);
	return (full_path);
}