#include <stdlib.h>
#include <string.h>
#include "shell.h"

/**
 * free_args - Frees an array of strings.
 * @args: The array of strings to free.
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
