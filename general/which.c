#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define MAX_LENGTH 1024

int main(void)
{
	char *cwd[MAX_LENGTH];
	char *line;
	size_t len;
	ssize_t nread, j;
	int i, status;
	char *command[MAX_LENGTH];
	char *token;
	char *new_argv;
	pid_t create_process;

	while (1)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd");
			break;
		}

		write(stdout, "$ ", 2);

		if ((nread = getline(&line, &len, stdin)) != -1)
		{
			for (j = 0; j < nread; j++)
			{
				command[j++] = line[j];
			}

			if (command[strlen(command) - 1] == '\n')
			{
				command[strlen(command) - 1] = '\0';
			}
		}

		perror("getline");

		for (token = strtok(command, " "); token != NULL; token = strtok(NULL, " "), i++)
		{
			if (i >= MAX_LENGTH - 1)
			{
				perror("strtok");
				break;
			}
			new_argv[i] = *token;

		}
		new_argv[i] = NULL;

		if (i == 0)
		{
			continue;
		}

		if (strcmp(new_argv[0], "exit"))
		{
			write(stdout, "\n", 1);
			exit(EXIT_FAILURE);
		}

		create_process = fork();

		if (create_process < 0)
		{
			perror("fork");
		}
		else if (create_process == 0)
		{
			if (execve(new_argv[0], (char *const *)new_argv, NULL) == -1)
			{
				perror("execve");
			}

		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}