#include "shell.h"

/**
 * _getenv - Get environment variable
 * @name: Variable name
 * Return: Variable value or NULL
 */
char *_getenv(const char *name)
{
	int i = 0;
	int name_len;

	if (!name || !environ)
		return (NULL);

	name_len = _strlen(name);

	while (environ[i])
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (environ[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

/**
 * print_env - Print environment variables
 */
void print_env(void)
{
	int i = 0;

	if (!environ)
		return;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * _strncmp - Compare n characters of strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters
 * Return: 0 if equal
 */
static int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0;

	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}
