#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Entry point
 * @ac: the count
 * @av: the vector
 * @env: the environment
 * Return: 0 on Success
*/

int main(int ac, char **av, char **env)
{
	int ***myAdd;
	int ***my_env_add;

	if (ac < 1)
	{
		printf("Usage: %s", av[0]);
		return (1);
	}

	myAdd = (int ***)&env[0];
	my_env_add = (int ***)&environ[0];

	printf("envp address is: %p\n", (void *)myAdd);
	printf("environ address is: %p\n", (void *)my_env_add);

	return (0);
}
