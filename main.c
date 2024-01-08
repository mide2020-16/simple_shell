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
	char *buffer, *token, **array, *path;
	size_t n;
	ssize_t nread;
	pid_t child_pid;
	int status, i;

	(void)argc, (void)argv;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		buffer = NULL;
		i = 0;

		nread = getline(&buffer, &n, stdin);

		if (nread == -1)
			exit(1);

		token = strtok(buffer, " \n");

		array = malloc(sizeof(char *) * MAX_LEN);

		if (array == NULL)
		{
			perror("Memory allocation failed\n");
			return (-1);
		}

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, " \n");
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