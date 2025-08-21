#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		display_prompt();
		read = getline(&line, &len, stdin);
		if (read == -1) /* EOF (Ctrl+D) */
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		execute_command(line);
	}

	free(line);
	return (0);
}
