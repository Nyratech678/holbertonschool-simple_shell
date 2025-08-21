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

	if (isatty(STDIN_FILENO))
		printf("$ ");

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
	if (args == NULL)
		return (0);

	if (args[0] == NULL)
	{
		free_args(args);
		return (0);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		free(line);
		exit(EXIT_SUCCESS);
	}

	if (execute(args) == -1)
		print_error(argv[0], args[0], count, "not found");

	free_args(args);
	return (0);
}

/**
 * loop - Main loop of the shell
 * @argv: command line arguments
 *
 * Description: Continuously displays a prompt, reads user input,
 * and processes commands until EOF (Ctrl+D) or an error occurs.
 * Return: Nothing.
 */
void loop(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	int count = 0;

	while (1)
	{
		count++;

		if (handle_input(&line, &len, argv) == -1)
			break;

		args = parse_line(line);
		process_command(args, argv, count, line);
	}

	free(line);
}
