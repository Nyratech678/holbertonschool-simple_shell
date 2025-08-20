#include "shell.h"

/**
 * display_prompt - Displays the shell prompt.
 *
 * Description: This function writes the prompt string to standard output.
 * Return: Nothing
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}