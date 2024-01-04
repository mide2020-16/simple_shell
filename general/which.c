#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * which - Get the path of a file
 * @command: the file to search
*/

void which(char *command)
{
	char *path;
	char *token;
	char full_path[BUFSIZ];

	path = getenv("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);

		if (access(full_path, F_OK) == 0)
		{
			printf("%s", full_path);
			return;
		}
	}

	token = strtok(NULL, ":");

	printf("Path does not exist");
}

/**
 * main - Entry point
 * @argc: the count
 * @argv: the vector
 * Return: 0 on Success
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		return (EXIT_FAILURE);
	}

	which(argv[1]);

	return (EXIT_SUCCESS);
}
