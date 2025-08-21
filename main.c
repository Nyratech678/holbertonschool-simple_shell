#include "shell.h"

/**
 * main - Entry point of the simple shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	(void)argc;

	loop(argv);
	return (0);
}
