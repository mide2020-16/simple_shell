#include "shell.h"

/**
 * _fprintf - Fprintf
 * Return: -1
 */

int _fprintf(void)
{
	return (-1);
}

/**
 * _perror - Perror
 * @message: message
 * @path: path
 * Return: -1
 */

int _perror(char *message, char *path)
{
	perror(message);
	free(path);
	return (-1);
}

/**
 * _cd - changes the directory
 * @directory: the directory to change to
 * Return: 0 on Success
 */

int _cd(char *directory)
{
	char *new_path, cwd[MAX_LEN];

	if (directory == NULL)
	{
		new_path = _getenv("HOME");

		if (new_path == NULL)
			_fprintf();
		else if (_strcmp(directory, "-") == 0)
		{
			new_path = _getenv("OLDPWD");
			if (new_path == NULL)
				_fprintf();
		}
		else
			new_path = _strdup(directory);

		if (chdir(new_path) != 0)
			_perror("cd", new_path);

		if (getcwd(cwd, sizeof(cwd)) == NULL)
			_perror("getcwd", new_path);

		setenv_builtin("PWD", cwd, 1);
		setenv_builtin("OLDPWD", _getenv("PWD"), 1);

		free(new_path);
	}
	return (0);
}
