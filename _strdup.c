#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(const char *s)
{
	char *dup;
	int len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);

	_strcpy(dup, s);
	return (dup);
}
