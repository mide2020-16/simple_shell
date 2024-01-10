#include "main.h"


/**
 * perr_exit - Prints error message and exit with code
 * @message: The message to print
 * @exit_code: the exit code
*/
void perr_exit(char *message, int exit_code)
{
	perror(message);
	exit(exit_code);
}

/**
 * main - Entry point to the shell
 * @argc: Argument count to the shell
 * @argv: Argument vector to the shell
 * Return: 0 Always on Success
*/
int main(int argc, char *argv[])
{
	char *buffer, *token, **array, *path, **env;
	size_t n;
	ssize_t nread;
	pid_t child_pid;
	int status, i, j;

	(void)argc, (void)argv;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		buffer = NULL;
		i = 0;

		nread = getline(&buffer, &n, stdin);

		if (nread == -1)
			perr_exit("Unable to read the line\n", 1);
		
		if (strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(buffer, "env\n") == 0)
		{
			env = environ;
			j = 0;

			while(env[j] != NULL)
			{
				write(STDOUT_FILENO, env[j], strlen(env[j]));
				write(STDOUT_FILENO, "\n", 1);
				j++;
			}

			free(buffer);
			continue;
		}

		if (feof(stdin) == 0)
		{
			free(buffer);
			exit(1);
		}
		token = _strtok(buffer, " \n");

		array = malloc(sizeof(* array) * MAX_LEN);

		if (array == NULL)
			perr_exit("Memory allocation failed\n", 1);

		while (token)
		{
			array[i] = token;
			token = _strtok(NULL, " \n");
			i++;
		}

		array[i] = NULL;

		path = get_file_path(array[0]);

		if (path != NULL)
			child_pid = fork();

		if (child_pid == -1)
			perr_exit("Invalid path\n", 41);

		if (child_pid == 0)
		{
			if (execve(path, array, NULL) == -1)
				perr_exit("./hsh", 97);
		}
		else
			wait(&status);
		
		free(array);
	}

	free(buffer);
	return (0);
}

