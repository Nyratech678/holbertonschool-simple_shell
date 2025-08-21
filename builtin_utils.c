#include "shell.h"

/**
 * handle_builtin - Handle builtin commands
 * @args: Command arguments
 * Return: 1 if builtin handled, 0 otherwise
 */
int handle_builtin(char **args)
{
	if (!args || !args[0])
		return (0);

	if (_strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	if (_strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}

/**
 * find_path - Find command in PATH (not needed for basic exercise)
 * @cmd: Command to find
 * Return: Full path or NULL
 */
char *find_path(char *cmd)
{
	(void)cmd;
	return (NULL);
}
