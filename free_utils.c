#include "shell.h"

/**
 * free_args - Free argument array
 * @args: Array to free
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
