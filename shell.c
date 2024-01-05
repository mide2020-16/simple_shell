#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>

/*#include "shell.h"*/

#define MAX_LENGTH 1024

int main(void)
{
	char *line = NULL, *token, cwd[MAX_LENGTH];
	int status;
	size_t line_len = 0;
	ssize_t read_line;

	pid_t process;
	char *const args[MAX_LENGTH] = {NULL, NULL};

	while (1)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("Failed to get the current working directory");
			break;
		}

		printf("$ ");

		if ((read_line = getline(&line, &line_len, stdin)) != -1)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			perror(line);
			break;
		}

		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		token = strtok(line, " ");
		args[0] = token;

		process = fork();

		if (process < 0)
		{
			perror("Unable to create a new process");
			break;
		}
		else if (process == 0)
		{
			if (access(line, X_OK) == 0)
			{
				execve(token, command, NULL);
				perror(token);
				_exit(EXIT_FAILURE);
			}
			else
			{
				perror(token);
				_exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}

	free(line);
	return (0);
}
