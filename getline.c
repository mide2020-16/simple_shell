#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUF 1024

/*
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	size_t bytesRead;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return 1;
	}

	bytesRead = _getline(&line, &len, file);

	if (bytesRead != (size_t)-1)
	{
		printf("Bytes read: %lu\n", bytesRead);
		printf("Line: %s\n", line);
	}
	else
	{
		printf("Error reading line\n");
	}

	free(line);
	fclose(file);
	return 0;
}
*/

/**
 * alloc_mem - Allocate memory and also give size to n
 * @lineptr: the pointer to the pointer of a line
 * @n: pointer to the length 
 * @i: an indexing i
 * Return: n on Success
*/
size_t alloc_mem(char **lineptr, size_t *n, static size_t i)
{
	if (*lineptr == NULL)
	{
		*lineptr = malloc(*n + MAX_BUF);

		if (*lineptr == NULL)
			perr_return("Memory allocation failed\n", -1);

		*n = MAX_BUF;
		i = 0;

		return (*n);
	}
}
/**
 * perr_return - Prints error and return
 * @message: the message to print
 * @num: return digit
 * Return: int
 */
int perr_return(char *message, int num)
{
	perror(message);
	return (num);
}

/**
 * _getline - A simple implementation of getline()
 * @lineptr: a pointer to the output
 * @n: size of bytes to read
 * @stream: the fildes
 * Return: number of bytes read
*/
size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static size_t i;
	static char buffer[MAX_BUF];
	size_t read_bytes, j, z;

	if (*lineptr == NULL || *n == 0 || stream == NULL)
		return (-1);

	alloc_mem(*lineptr, n, i);
	
	while ((read_bytes = read(fileno(stream), buffer, sizeof(buffer))) > 0)
	{
		for (j = 0; j < read_bytes; j++)
		{
			if (i >= *n - 1)
			{
				*lineptr = realloc(*lineptr, *n + MAX_BUF);
				if (*lineptr == NULL)
					perr_return("Memory allocation failed\n", -1);

				*n += MAX_BUF;
			}

			(*lineptr)[i++] = buffer[j];

			if (buffer[j] == '\n')
			{
				(*lineptr)[i] = '\0';
				return (i);
			}
		}
	}

	z = 0;

	if (read_bytes < z)
		perr_return("Error reading from stream\n", -1);

	return (i);
}
