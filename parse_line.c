#include "shell.h"

/**
 * parse_line - Parse input line into arguments
 * @line: Input line to parse
 * Return: Array of arguments
 */
char **parse_line(char *line)
{
	char **args = malloc(2 * sizeof(char *));

	if (!args)
		return (NULL);

	if (!line || *line == '\0')
	{
		args[0] = NULL;
		return (args);
	}

	args[0] = _strdup(line);
	args[1] = NULL;

	return (args);
}
