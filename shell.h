#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

#define MAX_LEN 1024

extern char **environ;

/*Helper Functions for Simple Shell*/

char **get_input_from_user();
char **_tokenize(char *string);
char *get_file_location(char *path, char *file_name);
char *get_file_path(char *file_name);
int setenv_builtin(const char *variable, const char *value, int overwrite);
int unsetenv_builtin(const char *variable);
void free_user_args(char **args);
void exit_handler(char *exit_code);

/*Customized Functions for Simple Shell*/

char *_getenv(const char *name);
char *_strdup(const char *string);
char *_strtok(char *string, const char *delimiter);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _snprintf(char *buffer, size_t size, const char *format, ...);
int _strcpy(char *dest, size_t size, const char *src);
int _atoi(const char *str);
void _printenv();

#endif /*SHELL_H*/