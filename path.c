#include "shell.h"

/**
 * find_path - Finds the full path of a command.
 * @cmd: The command to find.
 *
 * Return: The full path of the command if found, otherwise NULL.
 */
char *find_path(char *cmd)
{
	char *path_copy;
	char *path = getenv("PATH");
	char *dir;
	char *full_path = NULL;

	if (access(cmd, X_OK) == 0)
		return (strdup(cmd));

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (full_path)
		{
			sprintf(full_path, "%s/%s", dir, cmd);
			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}