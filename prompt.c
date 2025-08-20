#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 *
 * This function writes the prompt string to standard output.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}