#include "shell.h"

/**
 * exit_handler - Exit with a status code
 * @exit_code: the code
*/

void exit_handler(char *exit_code)
{
	int exit_status;

	if (exit_code != NULL)
	{
		exit_status = _atoi(exit_code);
		exit(exit_status);
	}
	else
		exit(0);
}
