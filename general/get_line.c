#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * main - Customized getline function
 * Return: 0 on success
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		if (nread == -1)
		{
			perror("Error");
			free(line);
			break;
		}
		printf("%s\n", line);
		printf("$ ");
	}

	if (ferror(stdin))
	{
		perror("Error reading input");
		free(line);
		exit(EXIT_FAILURE);
	}

	printf("\n");
	free(line);

	return (0);
}
