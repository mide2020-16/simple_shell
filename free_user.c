#include "shell.h"

/**
 * free_user_args - Free user arguments accordinlgy
 * @args: the tokenised argument
*/

void free_user_args(char **args)
{
	int i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);

		++i;
	}

	free(args);
}
