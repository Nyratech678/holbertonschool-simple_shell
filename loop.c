#include "shell.h"

/**
 * handle_input - Handles reading input from stdin
 * @line: pointer to input line buffer
 * @len: pointer to buffer length
 * @argv: command line arguments
 *
 * Return: length of input read, or -1 on error/EOF
 */
ssize_t handle_input(char **line, size_t *len, char **argv)
{
	ssize_t read;

	read = getline(line, len, stdin);

	if (read == -1)
	{
		if (feof(stdin))
		{
			return (-1);
		}
		perror(argv[0]);
		return (-1);
	}

	return (read);
}

/**
 * process_command - Processes a parsed command
 * @args: parsed command arguments
 * @argv: program arguments
 * @count: command counter
 * @line: the input line to free on exit
 *
 * Return: 1 if should exit, 0 otherwise
 */
int process_command(char **args, char **argv, int count, char *line)
{
	(void)line;

	if (args == NULL)
		return (0);

	if (args[0] == NULL)
	{
		return (0);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (execute(args) == -1)
		print_error(argv[0], args[0], count, "not found");

	return (0);
}

/**
 * loop - Main shell loop
 * @argv: Program arguments for error messages
 */
void loop(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 1;
	unsigned int count = 0;

	while (status)
	{
		count++;
		if (isatty(STDIN_FILENO))
			display_prompt();

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		args = parse_line(line);
		if (args && args[0])
		{
			process_command(args, argv, count, line);
		}
		free_args(args);
	}
	free(line);
}
