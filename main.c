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

	(void)argc;

	while (1)
	{
		/* Display prompt only in interactive mode */
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
			fflush(stdout);
		}

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

		/* Skip empty lines and trim spaces */
		if (line[0] == '\0')
			continue;

		/* Trim leading and trailing spaces */
		{
			char *trimmed = line;
			int len;
			char *args[1024];
			int argc = 0;
			char *token;
			
			while (*trimmed == ' ' || *trimmed == '\t')
				trimmed++;
			
			if (*trimmed == '\0')
				continue;

			len = strlen(trimmed);
			while (len > 0 && (trimmed[len - 1] == ' ' || trimmed[len - 1] == '\t'))
			{
				trimmed[len - 1] = '\0';
				len--;
			}

			/* Parse arguments */
			token = strtok(trimmed, " \t");
			while (token != NULL && argc < 1023)
			{
				args[argc] = token;
				argc++;
				token = strtok(NULL, " \t");
			}
			args[argc] = NULL;

			if (argc == 0)
				continue;

			/* Fork and execute */
			pid = fork();
			if (pid == 0)
			{
				/* Child process */
				if (execve(args[0], args, environ) == -1)
				{
					fprintf(stderr, "%s: No such file or directory\n", argv[0]);
					_exit(127);
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
	}

	free(line);
	return (0);
}
