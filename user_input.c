#include "shell.h"

/**
 * get_input_from_user - Gets input from user on
 * the terminal and uses the tokenizer to break
 * it down then put it in a NULL terminable array
 *
 * Return: NULL terminated string
*/

char **get_input_from_user()
{
	char *lineptr, **tokenized_input;
	size_t n = 0;
	ssize_t bytes_read;
	int compare_str;

	lineptr = NULL;

	bytes_read = getline(&lineptr, &n, stdin);

	if (bytes_read == -1)
	{
		free(lineptr);
		exit(0);
	}

	if (lineptr[bytes_read - 1] == '\n')
		lineptr[bytes_read - 1] = '\0';

	compare_str = _strcmp("exit\n", lineptr);

	if (compare_str == 0)
	{
		free(lineptr);
		exit(0);
	}

	tokenized_input = _tokenize(lineptr);

	if (tokenized_input == NULL)
		return (NULL);

	return (tokenized_input);
}
