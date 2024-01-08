#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LEN 1024


char *get_file_loc(char *path, char* filename);
char *get_file_path(char *filename);
int starts_with_fwd_slash(const char *str);

#endif /*MAIN_H*/