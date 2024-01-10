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

size_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;
	size_t new_size;
	char *new_line;

	if (*lineptr == NULL || n == NULL|| stream == NULL)
		return (-1);

	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = (char *)malloc(INIT_BUF);
		if (*lineptr == NULL)
		{
			return (-1);
			exit(EXIT_FAILURE);
		}
		*n = INIT_BUF;
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i == *n - 1)
		{
			new_size = *n * 2;
			new_line = (char *)realloc(*lineptr, new_size);
			if (new_line == NULL)
			{
				return (-1);
				exit(EXIT_FAILURE);
			}
			free(*lineptr);
			*lineptr = new_line;
			*n = new_size;
		}
		(*lineptr)[i++] = (char)c;
	}

	if (c == EOF && i == 0)
		return (-1);

	(*lineptr)[i] = '\0';

	return (i);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0, unary = (size_t)-1;
	size_t chars_read;
	FILE *file;

	printf("Test 1:\n");
	printf("$ ");
	chars_read = get_line(&line, &len, stdin);
	if (chars_read != unary)
		printf("Read %u characters: %s", chars_read, line);
	else
		perror("Error reading input");
	free(line);
	printf("\n\n");

	printf("Test 2:\n");
	printf("$ ");
	chars_read = get_line(&line, &len, stdin);
	if (chars_read != unary)
		printf("Read %u characters: %s", chars_read, line);
	else
		perror("Error reading input");
	free(line);
	printf("\n\n");

	printf("Test 3:\n");
	printf("$ ");
	chars_read = get_line(&line, &len, stdin);
	if (chars_read != unary)
		printf("Read %u characters: %s", chars_read, line);
	else
		perror("Error reading input");
	free(line);
	printf("\n\n");

	printf("Test 4 (Reading from file):\n");
	file = fopen("testfile.txt", "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	chars_read = get_line(&line, &len, file);
	if (chars_read != unary)
		printf("Read %u characters: %s", chars_read, line);
	else
		perror("Error reading input");
	free(line);
	fclose(file);
	printf("\n");

	return 0;
}
