#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @ac: the count
 * @av: the vector
 * Return: 0 on Success
*/

int main(int ac, char **av)
{
	char *str1, *str2, *token, *subtoken;
	char *saveptr1, *saveptr2;
	int i;

	if (ac != 4)
	{
		fprintf(stderr, "Usage: %s string delimiter, subtoken\n", av[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 0, str1 = av[1];; i++, str1 = NULL)
	{
		token = strtok_r(str1, av[2], &saveptr1);
		if (token == NULL)
		{
			break;
		}
		printf("%d: %s\n", i, token);

		for (str2 = token;; str2 = NULL)
		{
			subtoken = strtok_r(str2, av[3], &saveptr2);
			if (subtoken == NULL)
			{
				break;
			}
			printf("\t--> %s\n", subtoken);
		}
	}
	return (0);
}
