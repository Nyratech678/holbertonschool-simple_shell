#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * launch_process - Creates a child process and executes command
 * @full_path: The path to the executable command
 * @args: Arguments for the command
 *
 * Return: 1 on success, -1 on failure
 */
int launch_process(char *full_path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror(args[0]);
			_exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		free(full_path);
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		free(full_path);
	}
	return (1);
}

/**
 * execute - Handles execution of builtins or external commands
 * @args: The arguments for the command
 *
 * Return: 1 on success, -1 on failure
 */
int execute(char **args)
{
	char *full_path;

	if (args == NULL || args[0] == NULL)
		return (1);

	if (handle_builtin(args))
		return (1);

	full_path = find_path(args[0]);
	if (full_path == NULL)
		return (-1);

	return (launch_process(full_path, args));
}
