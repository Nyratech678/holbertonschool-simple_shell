#include "shell.h"

/**
 * print_error - Prints an error message to stderr.
 * @prog: The name of the program.
 * @cmd: The command that was not found.
 * @count: The command count.
 * @msg: The error message.
 */
void print_error(char *prog, char *cmd, unsigned int count, char *msg)
{
	fprintf(stderr, "%s: %u: %s: %s\n", prog, count, cmd, msg);
}
