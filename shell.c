#include "shell.h"

/**
 * execute_commands - Execute a single command
 * @user_args: The arguments of the command
 * @envp: The environment variables
 */
void execute_commands(char **user_args, char **envp)
{
    pid_t child_pid;
    int status;
    char *path_to_exec, *path;

    if (_strcmp(user_args[0], "exit") == 0)
        exit_handler(user_args[1]);
    else if (_strcmp(user_args[0], "env\n") == 0)
        _printenv();
    else if (_strcmp(user_args[0], "setenv") == 0)
        setenv_builtin(user_args[1], user_args[2], 1);
    else if (_strcmp(user_args[0], "unsetenv") == 0)
        unsetenv_builtin(user_args[1]);
    else if (_strcmp(user_args[0], "cd") == 0)
        cd_builtin(user_args[1]);
    else
    {
        path_to_exec = _strdup(user_args[0]);
        path = get_file_path(path_to_exec);

        if (path == NULL)
        {
            free_user_args(user_args);
            return;
        }

        free(user_args[0]);

        if (path != NULL)
        {
            child_pid = fork();

            if (child_pid == -1)
            {
                perror("fork");
                return;
            }

            if (child_pid == 0)
            {
                execve(path, user_args, envp);
                perror(path);
            }
            else
            {
                wait(&status);
            }
        }

        free(path_to_exec);
    }
}

/**
 * main - Entry point into the shell
 * @argc: The number of arguments passed into the main
 * @argv: Vector of arguments passed to main
 * @envp: The environmental variable for the main process
 */
int main(int argc, char **argv, char **envp)
{
    char **user_args, **commands, *command;
    int i;

    (void)argc;

    while (1)
    {
        print_prompt("$ ", _strlen("$ "));

        user_args = get_input_from_user();

        if (user_args == NULL)
            continue;

        commands = _tokenize(user_args);

        for (i = 0; commands[i] != NULL; i++)
        {
            command = _strdup(commands[i]);
            user_args = _tokenize(command);
            execute_commands(user_args, envp);
            free(command);
        }

        free_user_args(commands);
    }

    free(user_args);
    return 0;
}
