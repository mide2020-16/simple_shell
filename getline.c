#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define INIT_BUF 1024

/**
 * get_line - Gets a line from stream
 * @lineptr: where to put the content
 * @n: size of line
 * @stream: the file to target
 * Return: i on Success
*/

size_t get_line(char **lineptr, size_t n, FILE *stream)
{
	int c;
	size_t i = 0;
	size_t new_size;
	char *new_line;

	if (*lineptr == NULL || n == 0 || stream == NULL)
		return (-1);

	if (*lineptr == NULL || n == 0)
	{
		*lineptr = (char *)malloc(INIT_BUF);
		if (*lineptr == NULL)
			return (-1);
		n = INIT_BUF;
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i == n - 1)
		{
			new_size = n * 2;
			new_line = (char *)realloc(*lineptr, new_size);
			if (new_line == NULL)
				return (-1);
			*lineptr = new_line;
			n = new_size;
		}
		(*lineptr)[i++] = (char)c;
	}

	if (c == EOF && i == 0)
		return (-1);

	(*lineptr)[i] = '\0';

	return (i);
}





/**
 * main - Entry point
 * Return: 0 on Success
*/

int main(void)
{
	char *line = NULL;
	size_t len = 0, unary = -1;

	printf("$ ");

	size_t chars_read = get_line(&line, len, stdin);

	if (chars_read == unary)
	{
		perror("Error reading input");
		free(line);
		exit(EXIT_FAILURE);
	}

	printf("Read %d characters: %s", chars_read, line);

	free(line);

	return (0);
}
