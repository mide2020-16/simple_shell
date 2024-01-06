#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 * Return: 0 on Success
 */

int main(void)
{
	int i, status;
	pid_t pid;
	char *const newargv;

	for (i = 0; i < 5; ++i)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("Fork Failed:");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			printf("Child process %d running ls -l /tmp", i + 1);

			newargv[] = {"ls", "-l", "/tmp", NULL};

			if (execve("/bin/ls", newargv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			printf("Waiting for child to exit\n");
		}
	}
	return (0);
}
