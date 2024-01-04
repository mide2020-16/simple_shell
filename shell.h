#ifndef SHELL_H
#define SHELL_H

extern char **environ;

/**
 * struct Node - A environ node
 * @directory: the directory
 * @next: next struct
 */

struct Node
{
  char *directory;
  struct Node *next;
};

#endif /*SHELL_H*/