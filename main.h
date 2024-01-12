#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_LEN 1024

extern char **environ;

/*Helper Functions*/
char *get_file_location(char *path, char *file_name);
char *get_file_path(char *filename);
int starts_with_fwd_slash(const char *str);

/*Customized Functions*/
char *_strtok(char *string, const char *delimiter);

#endif /*MAIN_H*/