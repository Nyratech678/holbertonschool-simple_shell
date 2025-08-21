#include "shell.h"

/**
 * process_command - Process and execute command
 * @args: Command arguments
 * @argv: Program arguments for error messages
 * @count: Command count for error messages
 * @line: Original input line
 * Return: 1 to continue, 0 to exit
 */
int process_command(char **args, char **argv, int count, char *line)
{
	struct stat st;

	(void)line;

	if (!args || !args[0])
		return (1);

	/* Check if command exists */
	if (stat(args[0], &st) == 0)
	{
		return (execute(args));
	}
	else
	{
		print_error(argv[0], args[0], count, "not found");
		return (1);
	}
}