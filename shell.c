#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include "shell.h"

#define MAX_LENGTH 1024

int main(void)
{
  char *line = NULL;
  const char *command;
  int status;
  size_t line_len = 0;
  ssize_t read_line;
  pid_t process;

  while (1)
  {
  printf("$ ");

  while((read_line = getline(&line, &line_len, stdin)) != -1)
  {
    command = strdup(line);
    if (command == NULL)
    {
      perror("Unable to duplicate line\n");
      free(line);
      break;
    }
    if (command[strlen(command) - 1] == '\n')
    {
      command[strlen(command) - 1] = '\0';
    }
    if (read_line == -1)
    {
      perror("Unable to get the command\n");
      free(read_line);
      break;
    }
  }

  process = fork();
  if (process == 0)
  {
    execve(command, (char *const *)command, NULL);
  }
  else if (process < 0)
  {
    perror("Unable to create a new process");
    break;
  }
  else
  {
    wait(&status);
  }
  free(line);
  }


  return (0);
}