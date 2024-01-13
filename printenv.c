#include "shell.h"

/**
 * _printenv - Prints the variables of the current process
*/
void _printenv()
{
	int j = 0, length;

	while (environ[j] != NULL)
	{
		length = _strlen(environ[j]);

		write(STDOUT_FILENO, environ[j], length);
		/*Error checking*/
		write(STDOUT_FILENO, "\n", 1);
		/*Error checking*/
		j++;
	}
}
