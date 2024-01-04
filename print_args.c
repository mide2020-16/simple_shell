#include <stdio.h>

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
*/

int main(int ac, char **av)
{
	int i;

	if (ac < 2)
		perror("Usage: ./exec <args>\n");

	for (i = 1; i < ac; i++)
	{
		if (i == 1)
			printf("The first argument is: %s\n", av[i]);
		else if (i == 2)
			printf("The second argument is: %s\n", av[i]);
		else if (i == 3)
			printf("The second argument is: %s\n", av[i]);
		else
			printf("The %dth argument is: %s\n", i, av[i]);
	}
	return (0);
}
