#include "shell.h"

int _cd(char *directory)
{
		char *new_path, cwd[MAX_LEN];


		if (directory == NULL)
		{
				new_path = _getenv("HOME");

				if (new_path == NULL)
				{
						fprintf(stderr, "cd: No home directory found\n");
						return -1;
				}
		}
		else if (_strcmp(directory, "-") == 0)
		{
				new_path = _getenv("OLDPWD");

				if (new_path == NULL)
				{
						fprintf(stderr, "cd: Previous directory not set\n");
						return -1;
				}
		}
		else
		{
				new_path = _strdup(directory);
		}

		if (chdir(new_path) != 0)
		{
				perror("cd");
				free(new_path);
				return -1;
		}

		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
				perror("getcwd");
				free(new_path);
				return -1;
		}

		setenv_builtin("PWD", cwd, 1);
		setenv_builtin("OLDPWD", _getenv("PWD"), 1);

		free(new_path);
		return 0;
}
