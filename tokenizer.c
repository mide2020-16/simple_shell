#include "shell.h"

/**
 * _tokenize - This tokenize a string twice
 *
 * @string: the string to tokenize
 *
 * Return: the tokenized string if successful
*/

char **_tokenize(char *string)
{
	char *dup_str, *token, **tokenised_string;
	int size = 0, i = 0;

	dup_str = _strdup(string);
	token = _strtok(dup_str, " ;");
	while (token != NULL)
	{
		size++;
		token = _strtok(NULL, " ;");
	}
	free(dup_str);
	tokenised_string = malloc(sizeof(char *) * (size + 1));
	if (tokenised_string == NULL)
	{
		free(string);
		return (NULL);
	}
	token = _strtok(string, " \t;");
	if (token == NULL)
	{
		free(tokenised_string);
		free(string);
		return (NULL);
	}
	while (token != NULL)
	{
		tokenised_string[i] = _strdup(token);
		i++;
		token = _strtok(NULL, " \t;");
	}
	tokenised_string[i] = NULL;
	while (i > 0)
		free(tokenised_string[--i]);
	free(tokenised_string);
	free(string);
	return (tokenised_string);
}
