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
  char cwd[MAX_LENGTH];
  char *const *command;
  int status;
  size_t line_len = 0;
  ssize_t read_line;

  pid_t process;

  while (1)
  {
  if (getcwd(cwd, sizeof(cwd)) == NULL)
  {
    perror("Failed to get the current working directory");
    break;
  }
  
  printf("$ ");

  if ((read_line = getline(&line, &line_len, stdin)) != -1)
  {
    if (line[strlen(line) - 1] == '\n')
      line[strlen(line) - 1] = '\0';

    command = {line, NULL};
    process = fork();
    if (process < 0)
    {
      perror("Unable to create a new process");
      break;
    }
    else if (process == 0)
    {
      execve(command[0], (char *const *)command, NULL);
    }
    else
    {
      wait(&status);
    }

  }
  if (read_line == -1)
  {
    perror("Unable to read line");
    free(line);
    break;
  }

  printf("\n");

  }

  free(line);
  return (0);
}