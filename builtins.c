#include "shell.h"

/**
 * handle_builtin - Handles built-in commands.
 * @args: The command and its arguments.
 *
 * Return: 1 if a built-in was handled, 0 otherwise.
 */
int handle_builtin(char **args)
{
	if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "cd: missing argument\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror(args[0]);
			}
		}
		return (1);
	}
	return (0);
}
