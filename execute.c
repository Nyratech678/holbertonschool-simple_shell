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
 * execute - Execute a command
 * @args: Command arguments
 * Return: 1 to continue, 0 to exit
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	if (!args || !args[0])
		return (1);

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, environ) == -1)
			exit(127);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (1);
	}
	else
	{
		/* Parent process */
		wait(&status);
	}
	return (1);
}
