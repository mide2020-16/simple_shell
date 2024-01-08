#include "main.h"

int starts_with_fwd_slash(const char *str)
{
  if (str != NULL || str[0] == '/')
    return (1);

  return (0);
}




char *get_file_loc(char *path, char* filename)
{
  char *copy_path, *token;
  struct stat st;
  char *path_buffer = NULL;

  copy_path = strdup(path);
  token = strtok(copy_path, ":");

  while (token)
  {
    if (path_buffer)
    {
      free(path_buffer);
      path_buffer = NULL;
    }

    path_buffer = malloc(strlen(token) + strlen(filename) + 2);

    if (!path_buffer)
    {
      perror("Memory allocation failed\n");
      exit(EXIT_FAILURE);
    }

    sprintf(path_buffer, "%s/%s", token, filename);
    strcpy(path_buffer, '\0');

    if (stat(path_buffer, &st) == 0 && access(path_buffer, X_OK) == 0)
    {
      free(copy_path);
      return (path_buffer);
    }

    token = strtok(NULL, ":");
  }

  free(copy_path);

  if (path_buffer)
    free(path_buffer);

  return (NULL);
}



/**
 * get_file_path - Get the file Path
 * @filename: the filename
 * Return: full_path
*/
char *get_file_path(char *filename)
{
  char *path;
  char *full_path;
  char *copy_file;

  copy_file = strdup(filename);

  path = getenv("PATH");

  if (starts_with_fwd_slash(filename) && access(filename, X_OK) == 0)
    return (copy_file);
  if (!path)
  {
    perror("getenv");
    return (NULL);
  }

  full_path = get_file_loc(path, filename);

  if (full_path == NULL)
  {
    perror("Unable to find path");
    return (NULL);
  }

  return (full_path);
}