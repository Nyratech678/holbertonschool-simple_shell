#include "shell.h"

/**
 * loop - Main loop of the shell
 *
 * Description: Continuously displays a prompt, reads user input,
 * and processes commands until EOF (Ctrl+D) or an error occurs.
 * Return: Nothing.
 */

void loop(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int count = 0;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read = getline(&line, &len, stdin);

		if (read == -1)
		{
			if (feof(stdin))
			{
				free(line);
				break;
			}
			perror(argv[0]);
			free(line);
			break;
		}

		args = parse_line(line);

		if (args == NULL)
			continue;

		if (args[0] == NULL)
		{
			free_args(args);
			continue;
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
	}

	free(line);
}
