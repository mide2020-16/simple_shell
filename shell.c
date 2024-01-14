#include "shell.h"

/**
 * print_prompt - Prints a prompt
 * @c: the character to print out
 * @len: the length of the character to print
 */
void print_prompt(char *c, int len)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, c, len);
	}
}

/**
 * command_handlers - distinct commands
 * @user_args: user arguments
 */

void command_handlers(char **user_args)
{
	if (_strcmp(user_args[0], "exit") == 0)
		exit_handler(user_args[1]);
	else if (_strcmp(user_args[0], "env\n") == 0)
		_printenv();
	else if (_strcmp(user_args[0], "setenv") == 0)
		setenv_builtin(user_args[1], user_args[2], 1);
	else if (_strcmp(user_args[0], "unsetenv") == 0)
		unsetenv_builtin(user_args[1]);
	else if (_strcmp(user_args[0], "cd") == 0)
		_cd(user_args[1]);
}

/**
 * _exec_path - Execute with path
 * @path: path
 * @user_args: user args
 * @child_pid: child process
 * @envp: env variables
 * @status: status
 * Return: Nothing
*/
void _exec_path(char *path, char **user_args, pid_t child_pid, char **envp, int status)
{
  if (path == NULL)
  {
    free_user_args(user_args);
    return;
  }
  if (path != NULL)
				{
					child_pid = fork();

					if (child_pid == -1)
					{
						perror("fork");
						return;
					}

					if (child_pid == 0)
					{
						execve(path, user_args, envp);
						perror(path);
					}
					else
						wait(&status);
				}
}


/**
 * execute_commands - Execute a single command
 * @user_args: The arguments of the command
 * @envp: The environment variables
 */

void execute_commands(char **user_args, char **envp)
{
	pid_t child_pid;
	int status, i;
	char *path_to_exec, *path;

	command_handlers(user_args);
	else
	{
		i = 0;
		while (user_args[i] != NULL)
		{
			if (_strcmp(user_args[i], "&&") == 0)
			{
				if (status == 0)
					i++;
				else
					return;
			}
			else if (_strcmp(user_args[i], "||") == 0)
			{
				if (status != 0)
					i++;
				else
					return;
			}
			else
			{
				path_to_exec = _strdup(user_args[i]);
				path = get_file_path(path_to_exec);

				free(user_args[i]);
				_exec_path(path, user_args, child_pid, envp, status);
				free(path_to_exec);
				i++;
			}
		}
	}
}

/**
 * main - Entry point into the shell
 * @argc: The number of arguments passed into the main
 * @argv: Vector of arguments passed to main
 * @envp: The environmental variable for the main process
 * Return: 0 on Success
 */

int main(int argc, char **argv, char **envp)
{
	char **user_args, **commands, *command, **single_command;
	int i, j;

	(void)argc, (void)argv;

	while (1)
	{
		print_prompt("$ ", _strlen("$ "));

		user_args = get_input_from_user();

		if (user_args == NULL)
			continue;

		for (i = 0; user_args[i] != NULL; i++)
		{
			commands = _tokenize(user_args[i]);
			for (j = 0; commands[j] != NULL; j++)
			{
				command = _strdup(commands[j]);
				single_command = _tokenize(command);
				execute_commands(single_command, envp);
				free(command);
				free_user_args(single_command);
			}
			free_user_args(commands);
		}

		free_user_args(user_args);
	}

	free(user_args);
	return (0);
}
