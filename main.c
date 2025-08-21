#include "shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	pid_t pid;
	int status;
	unsigned int count = 0;

	(void)argc;

	while (1)
	{
		count++;

		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		/* Read input */
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Remove newline */
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		/* Skip empty lines */
		if (line[0] == '\0')
			continue;

		/* Handle exit */
		if (strcmp(line, "exit") == 0)
			break;

		/* Fork and execute */
		pid = fork();
		if (pid == 0)
		{
			/* Child process */
			char *args[2];
			args[0] = line;
			args[1] = NULL;
			if (execve(line, args, environ) == -1)
			{
				fprintf(stderr, "%s: %u: %s: not found\n", argv[0], count, line);
				exit(127);
			}
		}
		else if (pid < 0)
		{
			perror("fork");
		}
		else
		{
			/* Parent process */
			wait(&status);
		}
	}

	free(line);
	return (0);
}
