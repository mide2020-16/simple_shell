#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t process_id, parent_process_id;

	process_id = getpid();
	parent_process_id = getppid();

	printf("pid: %u\n", process_id);
	printf("ppid: %u\n", parent_process_id);

	return (0);
}
