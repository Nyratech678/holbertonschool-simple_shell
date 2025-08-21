#include "shell.h"

/**
 * read_input - Reads a line of input from stdin
 *
 * Return: Pointer to the input string, or NULL on failure
 */
char *read_input(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		if (line)
			free(line);
		return (NULL);
	}

	return (line);
}
