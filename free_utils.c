#include "shell.h"

/**
 * free_args - Frees an array of strings.
 * @args: The array of strings to free.
 *
 * Return: Nothing
 */
void free_args(char **args)
{
	char **temp = args;

	if (!args)
		return;

	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(args);
}
