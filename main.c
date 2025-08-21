#include "shell.h"

/**
 * main - Entry point for the simple shell program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * @envp: Array of environment variables
 *
 * Description: Initializes program name and starts the main shell loop.
 * Return: 0 on success, or an error code on failure.
 */
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)envp;

	loop(argv);
	return (0);
}
