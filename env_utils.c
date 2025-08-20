#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Pointer to the value (do not free), or NULL if not found
 */
char *_getenv(const char *name)
{
	int i;

	if (name == NULL || *name == '\0')
		return (NULL);

	if (strchr(name, '=') != NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, strlen(name)) == 0 &&
		    environ[i][strlen(name)] == '=')
		{
			return (&environ[i][strlen(name) + 1]);
		}
	}
	return (NULL);
}

/**
 * print_env - Prints all environment variables
 *
 * Return: Nothing
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
