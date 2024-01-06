#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define MAX_LENGTH 1024

/*volatile sig_atomic_t child_pid;*/

/**
 * sigint_handler - This helps to handle Ctrl+C
 * @sigmun: this is a void variable
*/

/*void sigint_handler(int signum)
{
	(void)signum;

	if (child_pid > 0)
	{
		kill(child_pid, SIGKILL);
		printf("\nChild process terminated by Ctrl+C\n");
	}

	fflush(stdout);
}*/

/**
 * print_error - Prints error message
 * @operation: the operation
 * @message: the message to pass
 */

void print_error(const char *operation)
{
		perror(operation);
}

/**
 * print_error_exit - Prints error message and exit
 * @operation: the operation
 * @message: The message to pass
 */

void print_error_exit(const char *operation)
{
	print_error(operation);
	exit(EXIT_FAILURE);
}

/**
 * wait_signal - Signals during wait
 * @status: the status of child process
 */

/*void wait_signal(int status)
{
	if (WIFEXITED(status))
		printf("The child process exited with status %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("The child process terminated by signal %d\n", WTERMSIG(status));
	else
		printf("The child process did not terminate properly\n");
}
*/

/**
 * main - Entry point
 * Return: 0 on success
 */

int main(void)
{
	int i = 0, status, k;
	pid_t pid;
	char command[MAX_LENGTH], *token, *newargv[MAX_LENGTH], *exec_argv[MAX_LENGTH], cwd[MAX_LENGTH], *line;
	size_t len = 0, j;

	while (1)
	{
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			print_error("getcwd");
			exit(EXIT_FAILURE);
		}

		printf("$ ");

		if (getline(&line, &len, stdin) == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		if (line == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		for (j = 0; j < strlen(line); j++)
			command[j++] = *line;

		command[j] = '\0';

		if (command[strlen(command) - 1] == '\n')
			command[strlen(command) - 1] = '\0';

		for (token = strtok(command, " "); token != NULL; token = strtok(NULL, " "))
		{
			if (i >= MAX_LENGTH - 1)
			{
				print_error("Tokenization");
				free(line);
				break;
			}

			newargv[i++] = token;
		}

		newargv[i] = NULL;

		if (i == 0)
			continue;

		for (k = 0; k < i; k++)
			exec_argv[k] = newargv[k];

		exec_argv[i] = NULL;

		if (strcmp(newargv[0], "exit") == 0)
			break;

		pid = fork();

		if (pid < 0)
			print_error_exit("fork");
		else if (pid == 0)
		{
			/*signal(SIGINT, SIG_DFL);*/
			if (execve(newargv[0], (char *const *)exec_argv, NULL) == -1)
			{
				print_error_exit("execve");
			}
			free(line);
		}
		else
		{
			/*child_pid = pid;*/
			/*signal(SIGINT, sigint_handler);*/
			wait(&status);
			/*wait_signal(status);*/
			/*child_pid = 0;*/
		}
	}

	free(line);

	return (0);
}
