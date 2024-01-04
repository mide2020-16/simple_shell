#include <stdio.h>
#include "shell.h"

/**
 * main - Entry point
 * Return: 0 on Success
*/
int main(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);

		i++;
	}

	return (0);
}
