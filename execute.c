#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * execute - forks a process to execute a command
 * @args: The arguments for the command
 * Return: 1 on success, -1 on failure
 */
int execute(char **args)
{
	pid_t pid;
	int status;
	char *full_path;

	if (args == NULL || args[0] == NULL)
		return (1);

	/* Handle built-in commands */
	if (handle_builtin(args))
		return (1);

	/* Find the full path of the command */
	full_path = find_path(args[0]);
	if (full_path == NULL)
		return (-1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror(args[0]);
			free(full_path);
			exit(EXIT_FAILURE);
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
