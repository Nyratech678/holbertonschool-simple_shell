#include "shell.h"

/**
 * _strlen - Calculate length of string
 * @s: String to measure
 * Return: Length of string
 */
int _strlen(const char *s)
{
	int len = 0;

	if (!s)
		return (0);

	while (s[len])
		len++;
	return (len);
}

/**
 * _strdup - Duplicate a string
 * @s: String to duplicate
 * Return: Pointer to new string
 */
char *_strdup(const char *s)
{
	char *dup;
	int len, i;

	if (!s)
		return (NULL);

	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	for (i = 0; i <= len; i++)
		dup[i] = s[i];

	return (dup);
}

/**
 * _strcpy - Copy string
 * @dest: Destination
 * @src: Source
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenate strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = _strlen(dest);
	int i = 0;

	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compare strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if equal, negative if s1 < s2, positive if s1 > s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
