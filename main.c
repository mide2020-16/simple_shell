#include "main.h"


int main(int argc, char *argv[])
{
  char *buffer;
  size_t n;
  ssize_t nread;
  pid_t child_pid;
  int status;
  char *token;
  char **array;
  int i;
  char *path;

  (void)argc, (void)argv;

  while (1)
  {
    write(STDOUT_FILENO, "$ ", 2);

    nread = getline(&buffer, &n, stdin);

    if (nread == -1)
    {
      perror("getline");
      exit(1);
    }

    token = strtok(buffer, " \n");

    array = malloc(sizeof(char *) * MAX_LEN);

    if (array == NULL)
    {
      perror("Memory allocation failed\n");
      return (-1);
    }

    i = 0;

    while (token)
    {
      array[i] = token;
      token = strtok(NULL, " \n");
      i++;
    }

    array[i] = NULL;

    path = get_file_path(array[0]);

    if (path != NULL)
    {
      child_pid = fork();
    }

    if (child_pid == -1)
    {
      perror("fork");
      exit(41);
    }

    if (child_pid == 0)
    {
      if (execve(path, array, NULL) == -1)
      {
        perror("execve");
        exit(97);
      }
    }
    else
    {
      wait(&status);
    }
    
  }

  free(array);
  free(buffer);
  return (0);
}