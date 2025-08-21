#include "shell.h"

#define MAX_ARGS 64

/**
 * parse_line - Tokenizes the input line into an array of arguments
 * @line: The input string to tokenize
 *
 * Return: Pointer to an array of strings (tokens), or NULL on failure
 */
char **parse_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	if (line == NULL || *line == '\0')
		return (NULL);

	tokens = malloc(MAX_ARGS * sizeof(char *));
	if (tokens == NULL)
		return (NULL);

	token = strtok(line, " \t\r\n");
	while (token != NULL && i < (MAX_ARGS - 1))
	{
		tokens[i] = _strdup(token);
		if (tokens[i] == NULL)
		{
			free_args(tokens);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
