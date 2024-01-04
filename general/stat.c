#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * main - Entry point
 * @argc: the count
 * @argv: the vector
 * Return: 0 on Success
 */

int main(int argc, char *argv[])
{
	unsigned int i;
	struct stat st;

	if (argc < 2)
	{
		printf("Usage: %s path_to_file ... \n", argv[0]);
		return (1);
	}

	i = 1;

	while (argv[i])
	{
		printf("%s\n", argv[i]);

		if (stat(argv[i], &st) == 0)
			printf("FOUND\n");
		else
			printf("NOT FOUND\n");

		i++;
	}

	return (0);
}
