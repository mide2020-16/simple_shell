
/**
 * _exec_path - Execute with path
 * @path: path
 * @user_args: user args
 * @child_pid: child process
 * @envp: env variables
 * @status: status
 * Return: Nothing
*/
void _exec_path(char *path, char **user_args, pid_t child_pid, char **envp, int status)
{
  if (path == NULL)
  {
    free_user_args(user_args);
    return;
  }
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
						wait(&status);
				}
}